from MadGraphControl.MadGraphUtils import *

mode=0
mhh=1000

#---------------------------------------------------------------------------------------------------
# Setting mHH and WHH for param_card.dat
#---------------------------------------------------------------------------------------------------
parameters={'1560':'1000', #MHH
            '1561':'10', #WHH
            '188':'1.0', #ctr (trilinear coupling, default 1.0)
            '189':'1.0', #cy (top Yukawa coupling, default 1.0)
            '190':'1.0',  #ctrH (hhH coupling, default 1.0)
            '191':'100.0'  #cyH (H Yukawa coupling, default 1.0)
            }

#---------------------------------------------------------------------------------------------------
# Setting higgs mass to 125 GeV for param_card.dat
#---------------------------------------------------------------------------------------------------
higgsMass={'25':'125'} #MH

#---------------------------------------------------------------------------------------------------
# Setting some parameters for run_card.dat: Parton shower is PYTHIA8
#---------------------------------------------------------------------------------------------------
extras = { 'lhe_version':'2.0',
           'cut_decays':'F',
           'pdlabel':"'nn23lo1'",
           'lhaid':'247000',
           'scale':'500', #MHH/2
           'dsqrt_q2fact1':'500', #MHH/2
           'dsqrt_q2fact2':'500', #MHH/2      
           #'parton_shower':'PYTHIA8',
           'ptj':'0',
           'ptb':'0',
           'pta':'0',
           'ptjmax':'-1',
           'ptbmax':'-1',
           'ptamax':'-1',
           'etaj':'-1',
           'etab':'-1',
           'etaa':'-1',
           'etajmin':'0',
           'etabmin':'0',
           'etaamin':'0',
           'mmaa':'0',
           'mmaamax':'-1',
           'mmbb':'0',
           'mmbbmax':'-1',
           'drjj':'0',
           'drbb':'0',
           'draa':'0',
           'drbj':'0',
           'draj':'0',
           'drab':'0',
           'drjjmax':'-1',
           'drbbmax':'-1',
           'draamax':'-1',
           'drbjmax':'-1',
           'drajmax':'-1',
           'drabmax':'-1' }

#---------------------------------------------------------------------------------------------------
# Generating di-higgs through Heavy Higgs resonance with MadGraph
#---------------------------------------------------------------------------------------------------
fcard = open('proc_card_mg5.dat','w')
if (runArgs.runNumber == 999999):
    fcard.write("""
    import model sm
    define p = g u c d s u~ c~ d~ s~
    define j = g u c d s u~ c~ d~ s~
    import model HeavyHiggsTHDM
    generate p p > h h 
    output -f""")
    fcard.write('set Mhh %s \n'%(mhh))
    fcard.close()
else: 
    raise RuntimeError("runNumber %i not recognised in these jobOptions."%runArgs.runNumber)

beamEnergy=-999
if hasattr(runArgs,'ecmEnergy'):
    beamEnergy = runArgs.ecmEnergy / 2.
else: 
    raise RuntimeError("No center of mass energy found.")

#---------------------------------------------------------------------------------------------------
# Filter efficiency is low
# Thus, setting the number of generated events to 100 times maxEvents,
# to avoid crashing due to not having enough events
# Also putting protection to avoid from crashing when maxEvents=-1
#---------------------------------------------------------------------------------------------------
safefactor=10
nevents=20000*safefactor
if runArgs.maxEvents > 0:
    nevents=runArgs.maxEvents*safefactor

runName='run_01'
process_dir = new_process(card_loc='proc_card_mg5.dat')

#---------------------------------------------------------------------------------------------------
# Using the helper function from MadGraphControl for setting up the param_card
# Build a new param_card.dat from an existing one
# Used values given in "parameters" for MHH and WHH, if not set there, default values are used
# Higgs mass is set to 125 GeV by "higgsMass"
#---------------------------------------------------------------------------------------------------
build_param_card(param_card_old='param_card.HeavyScalar.dat',param_card_new='param_card_new.dat',masses=higgsMass,extras=parameters)

#---------------------------------------------------------------------------------------------------
# Using the helper function from MadGraphControl for setting up the run_card
# Build a new run_card.dat from an existing one
# Using the values given in "extras" above for the selected parameters when setting up the run_card
# If not set in "extras", default values are used 
#---------------------------------------------------------------------------------------------------

build_run_card(run_card_old=get_default_runcard(proc_dir=process_dir), run_card_new='run_card.dat', xqcut=0, nevts=nevents, rand_seed=runArgs.randomSeed, beamEnergy=beamEnergy, extras=extras)

print_cards()

generate(run_card_loc='run_card.dat',param_card_loc='param_card_new.dat',mode=mode,proc_dir=process_dir,run_name=runName)

outputDS = arrange_output(run_name=runName,proc_dir=process_dir)

runArgs.inputGeneratorFile=outputDS

#---------------------------------------------------------------------------------------------------
# Pythia8 Showering with A14_NNPDF23LO
#---------------------------------------------------------------------------------------------------
include("MC15JobOptions/Pythia8_A14_NNPDF23LO_EvtGen_Common.py")
include("MC15JobOptions/Pythia8_LHEF.py")
include("MC15JobOptions/Pythia8_MadGraph.py")

#---------------------------------------------------------------------------------------------------
# EVGEN Configuration
#---------------------------------------------------------------------------------------------------
evgenConfig.generators = ["MadGraph", "Pythia8", "EvtGen"]
if (runArgs.runNumber == 999999):
    evgenConfig.description = "Di-Higgs production through 1 TeV Heavy Higgs resonance which decays to bbtautau."
    evgenConfig.keywords = ["hh","BSM", "BSMHiggs", "resonance", "tau", "bottom"]

evgenConfig.contact = ['Marisilvia Donadelli <Marisilvia.Donadelli@cern.ch>']
#evgenConfig.inputfilecheck = runName
#runArgs.inputGeneratorFile=runName+'._00001.events.tar.gz'

#---------------------------------------------------------------------------------------------------

# Decaying hh to bbtautau with Pythia8

#---------------------------------------------------------------------------------------------------

genSeq.Pythia8.Commands += ["25:oneChannel = on 0.5 100 5 -5", #bb decay
                            "25:addChannel = on 0.5 100 15 -15" ] # tautau decay

#---------------------------------------------------------------------------------------------------
# Filter for bbtautau
#---------------------------------------------------------------------------------------------------
from GeneratorFilters.GeneratorFiltersConf import ParentChildFilter
filtSeq += ParentChildFilter("HbbFilter", PDGParent = [25], PDGChild = [5])
filtSeq += ParentChildFilter("HTauTauFilter", PDGParent = [25], PDGChild = [15])

from GeneratorFilters.GeneratorFiltersConf import XtoVVDecayFilterExtended
filtSeq += XtoVVDecayFilterExtended("TauTauHadHadFilter")
filtSeq.TauTauHadHadFilter.PDGGrandParent = 25
filtSeq.TauTauHadHadFilter.PDGParent = 15
filtSeq.TauTauHadHadFilter.StatusParent = 2
filtSeq.TauTauHadHadFilter.PDGChild1 = [211,213,215,311,321,323,10232,10323,20213,20232,20323,30213,100213,100323,1000213]
filtSeq.TauTauHadHadFilter.PDGChild2 = [211,213,215,311,321,323,10232,10323,20213,20232,20323,30213,100213,100323,1000213]


#---------------------------------------------------------------------------------------------------
# Filter for 2 leptons (inc tau(had)) with pt cuts on e/mu and tau(had)
#---------------------------------------------------------------------------------------------------
from GeneratorFilters.GeneratorFiltersConf import MultiElecMuTauFilter
filtSeq += MultiElecMuTauFilter("TauPtFilter")
filtSeq.TauPtFilter.IncludeHadTaus = True
filtSeq.TauPtFilter.NLeptons = 2
filtSeq.TauPtFilter.MinPt = 13000.
filtSeq.TauPtFilter.MinVisPtHadTau = 15000.
filtSeq.TauPtFilter.MaxEta = 3.

#---------------------------------------------------------------------------------------------------
# Leading tau filter
#---------------------------------------------------------------------------------------------------
filtSeq += MultiElecMuTauFilter("LeadTauPtFilter")
filtSeq.LeadTauPtFilter.IncludeHadTaus = True
filtSeq.LeadTauPtFilter.NLeptons = 1
filtSeq.LeadTauPtFilter.MinPt = 13000.
filtSeq.LeadTauPtFilter.MinVisPtHadTau = 35000.
filtSeq.LeadTauPtFilter.MaxEta = 3.


filtSeq.Expression = "HbbFilter and HTauTauFilter and TauTauHadHadFilter and TauPtFilter and LeadTauPtFilter"

