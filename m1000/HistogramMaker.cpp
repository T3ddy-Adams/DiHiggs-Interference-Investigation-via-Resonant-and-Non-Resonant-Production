//Thomas Adams
//thomas.adams@cern.ch

//to run:
    // root -l "HistogramMaker.cpp(\"run_bbtt_m1000_hadhad_10MeV")"

#include <vector>
#include <iostream>
#include <string>

TLorentzVector Leading(TLorentzVector particle0, TLorentzVector particle1){
    float particle0_pT = particle0.Pt();
    float particle1_pT = particle1.Pt();
    if(particle0_pT > particle1_pT){
        return particle0;
    }
    return particle1;
}

TLorentzVector SubLeading(TLorentzVector particle0, TLorentzVector particle1){
    float particle0_pT = particle0.Pt();
    float particle1_pT = particle1.Pt();
    if(particle0_pT < particle1_pT){
        return particle1;
    }
    return particle0;
}

TLorentzVector Smear(TLorentzVector particle, double smearAmount, TRandom *Smearing){
                                                                     //smearAmount is a decimal value
    double Smearness = Smearing->Gaus(1, smearAmount);
    TLorentzVector particleSmeared;
    particleSmeared.SetPtEtaPhiM((particle.Pt())*Smearness,particle.Eta(),particle.Phi(),particle.M());
    return particleSmeared;
    
}

string inFile(std::string inFileName){
    std::string fileName = inFileName.append(".root");
    return fileName;
}

string outFile(std::string inFileName){
    std::string fileName = inFileName.append("_histogram.root");
    return fileName;
}

int HistogramMaker(std::string inFileName){

    TRandom *Smearing = new TRandom();

    std::string outFileName = outFile(inFileName);
    inFileName = inFile(inFileName);

    TFile* inFile = TFile::Open(inFileName.c_str(),"READ");
    TTree* tree = (TTree*)inFile->Get("analysis");

    // X particle/event data set

    int X_n;
    std::vector <float> *X_pT;
    X_pT = new std::vector<float>();
    std::vector <float> *X_eta;
    X_eta = new std::vector<float>();
    std::vector <float> *X_phi;
    X_phi = new std::vector<float>;
    std::vector <float> *X_nrg;
    X_nrg = new std::vector<float>;

    tree->SetBranchAddress("nX",&X_n);
    tree->SetBranchAddress("X_pt",&X_pT);
    tree->SetBranchAddress("X_eta",&X_eta);
    tree->SetBranchAddress("X_phi",&X_phi);
    tree->SetBranchAddress("X_e",&X_nrg);

            // Create Histograms
            TH1D mX("X_mass", "m_{X}", 10, 995,1005);    //$
            mX.Sumw2();

            TH1D pTX("X_Transverse_Momentum", "pT_{X}", 75, 0, 1500);    //$
            pTX.Sumw2();

            TH1D etaX("X_Eta","Eta_{X}",40,-7,7);        //$
            etaX.Sumw2();

            TH1D phiX("X_Phi","Phi_{X}", 40, -4, 4);     //$
            phiX.Sumw2();

    // H boson particle/event data
    
    int H_n;
    std::vector <float> *H_pT;
    H_pT = new std::vector<float>();
    std::vector <float> *H_eta;
    H_eta = new std::vector<float>();
    std::vector <float> *H_phi;
    H_phi = new std::vector<float>;
    std::vector <float> *H_nrg;
    H_nrg = new std::vector<float>;

    tree->SetBranchAddress("nH",&H_n);
    tree->SetBranchAddress("H_pt",&H_pT);
    tree->SetBranchAddress("H_eta",&H_eta);
    tree->SetBranchAddress("H_phi",&H_phi);
    tree->SetBranchAddress("H_e",&H_nrg);

        //Create the Histograms
        
        TH1D mH("diH_InvariantMass", "m_{HH}", 138, 240, 3000);      //$
        mH.Sumw2();

        TH1D Smeared_mH("Smeared_diH_InvariantMass","m_{Smeared HH}",138, 240, 3000);
        Smeared_mH.Sumw2();

        TH1D H_L_m("Leading_Higgs_Mass","m_{Leading H}, Leading",40,  50, 250);
        H_L_m.Sumw2();

        TH1D H_L_pT("Leading_Higgs_TransverseMomentum","pT_{H}, Leading", 80, 0, 2000);   //$
        H_L_pT.Sumw2();

        TH1D H_L_eta("Leading_Higgs_Eta","Eta_{Leading Higgs}, Leading", 40, -7,7);   //$
        H_L_eta.Sumw2();

        TH1D H_L_phi("Leading_Higgs_Phi","Phi_{Leading Higgs}, Leading", 40, -7, 7);  //$
        H_L_phi.Sumw2();

        TH1D H_SL_m("Sub-Leading_Higgs_Mass","m_{Sub-Leading H}, Sub-Leading", 40, 50, 250);

        TH1D H_SL_pT("Sub-Leading_Higgs_TransverseMomentum","pT_{H}, Sub-Leading", 75, 0, 2000);      //$
        H_SL_pT.Sumw2();

        TH1D H_SL_eta("Sub-Leading_Higgs_Eta","Eta_{Sub-Leading Higgs}, Sub-Leading", 40, -7,7);      //$
        H_SL_eta.Sumw2();

        TH1D H_SL_phi("Sub-Leading_Higgs_Phi","Phi_{Sub-Leading Higgs}, Sub-Leading", 40, -7, 7);     //$
        H_SL_phi.Sumw2();

        TH1D diH_pT("diHiggs_TransverseMomentum","pT_{di-Higgs}, diParticle", 75, 0, 2500);   //$
        diH_pT.Sumw2();

        TH1D diH_eta("diHiggs_Eta","Eta_{di-Higgs}, di-Higgs", 40, -7, 7);    //$
        diH_eta.Sumw2();

        TH1D diH_phi("diHiggs_Phi","Phi_{di-Higgs}, di-Higgs", 40, -7, 7);    //$
        diH_phi.Sumw2();

    //Htautau even data set
    
    float Htautau_pT;
    float Htautau_eta;
    float Htautau_phi;
    float Htautau_nrg;

    tree->SetBranchAddress("Htautau_pt",&Htautau_pT);
    tree->SetBranchAddress("Htautau_eta",&Htautau_eta);
    tree->SetBranchAddress("Htautau_phi",&Htautau_phi);
    tree->SetBranchAddress("Htautau_e",&Htautau_nrg);

        TH1D mHtt("Htautau_Mass", "m_{Htt}", 10, 120, 130 );    //$
        mHtt.Sumw2();

        TH1D Htt_pTP("Htautau_TranverseMomentum","pT_{Htt}", 75, -200, 2500);    //$
        Htt_pTP.Sumw2();

        TH1D Htt_etaP("Htautau_Eta","Eta_{Htt}", 40, -7,7);  //$
        Htt_etaP.Sumw2();

        TH1D Htt_phiP("Htautau_Phi","Phi_{Htt}, Leading", 40, -7, 7); //$
        Htt_phiP.Sumw2();

    // Hbb event data set

    float Hbb_pT;
    float Hbb_eta;
    float Hbb_phi;
    float Hbb_nrg;

    tree->SetBranchAddress("Hbb_pt",&Hbb_pT);
    tree->SetBranchAddress("Hbb_eta",&Hbb_eta);
    tree->SetBranchAddress("Hbb_phi",&Hbb_phi);
    tree->SetBranchAddress("Hbb_e",&Hbb_nrg);

        TH1D mHbb("Hbb_Mass", "m_{Hbb}", 10, 124, 126);     //$
        mHbb.Sumw2();

        TH1D Hbb_pTP("Hbb_TransverseMomentum","pT_{Hbb}", 75, 0, 2000); //$
        Hbb_pTP.Sumw2();

        TH1D Hbb_etaP("Hbb_Eta","Eta_{Hbb}", 40, -4, 4);   //$
        Hbb_etaP.Sumw2();

        TH1D Hbb_phiP("Hbb_phi","Phi_{Hbb}", 40, -4, 4);     //$
        Hbb_phiP.Sumw2();

    // tau particle data set

        int tau_n;
        std::vector <float> *tau_pT;
        tau_pT = new std::vector<float>();
        std::vector <float> *tau_eta;
        tau_eta = new std::vector<float>();
        std::vector <float> *tau_phi;
        tau_phi = new std::vector<float>;
        std::vector <float> *tau_nrg;
        tau_nrg = new std::vector<float>;

        tree->SetBranchAddress("ntau",&tau_n);
        tree->SetBranchAddress("tau_pt",&tau_pT);
        tree->SetBranchAddress("tau_eta",&tau_eta);
        tree->SetBranchAddress("tau_phi",&tau_phi);
        tree->SetBranchAddress("tau_e",&tau_nrg);

            TH1D mtau("tau_InvariantMass","m_{t}", 26, 0, 130);  //$
            mtau.Sumw2();

            TH1D tau_L_m("Leading_tau_Mass","mass_{tau}, Leading", 10, 0, 4);
            tau_L_m.Sumw2();

            TH1D tau_L_pT("Leading_tau_TransverseMomentum","pT_{tau}, Leading", 80, 0, 2000); //$
            tau_L_pT.Sumw2();

            TH1D tau_L_eta("Leading_tau_Eta","Eta_{tau}, Leading", 40, -4,4);       //$
            tau_L_eta.Sumw2();

            TH1D tau_L_phi("Leading_tau_Phi","Phi_{tau}, Leading",40,-4,4);           //$
            tau_L_phi.Sumw2();

            TH1D tau_SL_m("Sub-Leading_tau_Mass","m_{Sub-Leading tau}, Sub-Leading", 10, 0,4);
            tau_SL_m.Sumw2();

            TH1D tau_SL_pT("Sub-Leading_tau_TransverseMomentum","pT_{tau}, Sub-Leading", 75, 0, 2000);    //$
            tau_SL_pT.Sumw2();
                    
            TH1D tau_SL_eta("Sub-Leading_tau_Eta","Eta_{tau}, Sub-Leading", 40, -4,4);  //$
            tau_SL_eta.Sumw2();

            TH1D tau_SL_phi("Sub-Leading_tau_Phi","Phi_{tau}, Sub-Leading",40,-4,4);      //$
            tau_SL_phi.Sumw2();

            TH1D ditau_pT("di-Tau_TransverseMomentum","pT_{di-tau}", 75, 0,2000); //$
            ditau_pT.Sumw2();

            TH1D ditau_eta("di-Tau_Eta","Eta_{di-tau}", 40, -4,4);   //$
            ditau_eta.Sumw2();

            TH1D ditau_phi("di-tau_Phi","Phi_{di-tau}",40, -4,4);    //$
            ditau_phi.Sumw2();

    // b particle data set

        int b_n;
        std::vector <float> *b_pT;
        b_pT = new std::vector<float>();
        std::vector <float> *b_eta;
        b_eta = new std::vector<float>();
        std::vector <float> *b_phi;
        b_phi = new std::vector<float>;
        std::vector <float> *b_nrg;
        b_nrg = new std::vector<float>;

        tree->SetBranchAddress("nb",&b_n);
        tree->SetBranchAddress("b_pt",&b_pT);
        tree->SetBranchAddress("b_eta",&b_eta);
        tree->SetBranchAddress("b_phi",&b_phi);
        tree->SetBranchAddress("b_e",&b_nrg);

            TH1D mb("b_InvariantMass","m_{b}", 10, 124, 126);    //$
            mb.Sumw2();

            TH1D b_L_m("Leading_b_Mass","m_{Leading b}", 10, 0 ,10);
            b_L_m.Sumw2();

            TH1D b_L_pT("Leading_b_TranverseMomentum","pT_{b}, Leading", 80, 0, 2000);    //$
            b_L_pT.Sumw2();

            TH1D b_L_eta("Leading_b_Eta","Eta_{b}, Leading", 40, -7,7);   //$
            b_L_eta.Sumw2();

            TH1D b_L_phi("Leading_b_Phi","Phi_{b}, Leading", 40, -7, 7);  //$
            b_L_phi.Sumw2();

            TH1D b_SL_m("Sub-Leading_b_Mass","m_{Sub-Leading b}, Sub-Leading", 20, 0, 10);
            b_SL_m.Sumw2();

            TH1D b_SL_pT("Sub-Leading_b_TranverseMomentum","pT_{b}, Sub-Leading", 75, 0, 2000);   //$
            b_SL_pT.Sumw2();

            TH1D b_SL_eta("Sub-Leading_b_Eta","Eta_{b}, Sub-Leading", 40, -7, 7); //$
            b_SL_eta.Sumw2();

            TH1D b_SL_phi("Sub-Leading_b_Phi","Phi_{b}, Sub-Leading", 40, -7, 7); //$
            b_SL_phi.Sumw2();

            TH1D dib_pT("di-b_TransverseMomentum","pT_{di-b}", 75, 0, 2000); //$
            dib_pT.Sumw2();

            TH1D dib_eta("di-b_Eta","Eta_{di-b}", 40, -7, 7);  //$
            dib_eta.Sumw2();

            TH1D dib_phi("di-b_Phi","Phi_{di-b}", 40, -7, 7); //$   
            dib_phi.Sumw2();

        //2_D plots 
            //Hbb pT versus Htt pT
            TH2D HbbPt_HttPt("2-D_Hbb(pT)_versus_Htt(pT)","pT_{Hbb} v. pT_{Htt}",400, 0, 2000, 400, 0 , 2000);
            HbbPt_HttPt.Sumw2();

            //Hbb pT versus the delta r of the two b's
            TH2D HbbPt_bbDeltaR("2-D_Hbb(pT)_versus_b(DeltaR)","pT_{Hbb} v. DeltaR_{b}", 400, 0, 2000, 150, 0, 5);
            HbbPt_bbDeltaR.Sumw2();

            TH2D bbm_bbpT("dib_Mass_Versus_dib_TransverseMomentum","M_{bb} v. pT_{bb}", 40,  50, 250, 80, 0, 2000);
            bbm_bbpT.Sumw2();

            TH2D tautaum_tautaupT("ditau_Mass_Versus_ditau_TransverseMomentum","M_{tautau} v. pT_{tautau}", 40,  50, 250, 80, 0, 2000);
            tautaum_tautaupT.Sumw2();

            TH2D Smeared_bbm_bbpT("Smeared:dib_Mass_Versus_dib_TransverseMomentum","M_{bb} v. pT_{bb}", 40,  50, 250, 80, 0, 2000);
            Smeared_bbm_bbpT.Sumw2();

            TH2D Smeared_tautaum_tautaupT("Smeared:ditau_Mass_Versus_ditau_TransverseMomentum","M_{tautau} v. pT_{tautau}", 40,  50, 250, 80, 0, 2000);
            Smeared_tautaum_tautaupT.Sumw2();  

        //1-D plot
            // bb + tt to X
            TH1D bbtt_X_m("bb+tt->X_Mass","m_{bbtt->X}", 69, 240, 3000);   
            bbtt_X_m.Sumw2();
        
        //1-D smeared plots
            //tau leading pT
            TH1D Smeared_t_L_pT("Smeared_Leading_tau_TransverseMomentum","pT_{Smeared Leading tau}", 75, 0,2000);
            Smeared_t_L_pT.Sumw2();

            //tau leading mass
            TH1D Smeared_t_L_m("Smeared_Leading_tau_Mass","m_{Smeared Leading tau}", 10, 0, 4);
            Smeared_t_L_m.Sumw2();

            //tau sub-leading pT
            TH1D Smeared_t_SL_pT("Smeared_Sub-Leading_tau_TranverseMomentum","pT_{Smeared Sub-Leading tau}", 75, 0, 2000);
            Smeared_t_SL_pT.Sumw2();

            //tau subleading mass
            TH1D Smeared_t_SL_m("Smeared_Sub-Leading_tau_Mass","m_{Smeared Sub-Leading tau}", 10, 0, 4);
            Smeared_t_SL_m.Sumw2();

            //tau tau -> Higgs, mass
            TH1D Smeared_tt_m("Smeared_tt->H_Mass","m_{tau tau}",40, 50, 200);
            Smeared_tt_m.Sumw2();

            //b leading pT
            TH1D Smeared_b_L_pT("Smeared_Leading_b_TranverseMomentum","pT_{Leading b}", 75, 0, 2000);
            Smeared_b_L_pT.Sumw2();

            //b leading mass
            TH1D Smeared_b_L_m("Smeared_Leading_b_Mass","m_{Leading b}", 10, 0, 10);
            Smeared_b_L_m.Sumw2();

            //b subleading pT
            TH1D Smeared_b_SL_pT("Smeared_Sub-Leading_b_TransverseMomentum","pT_{Sub-Leading b}",75,  0, 2000);
            Smeared_b_SL_pT.Sumw2();

            //b subleading mass
            TH1D Smeared_b_SL_m("Smeared_Sub-Leading_b_Mass","m_{Sub-Leading b}",10,0,10);
            Smeared_b_SL_m.Sumw2();

            //b b -> Higgs
            TH1D Smeared_bb_m("Smeared_bb->H_Mass","m_{bb}",40, 50,200);
            Smeared_bb_m.Sumw2();

            //bbtt -> X, mass
            TH1D Smeared_bbtt_m("Smeared_bbtt->X_Mass","m_{bbtt}",138, 240, 3000);
            Smeared_bbtt_m.Sumw2();

    for(Long64_t entry = 0; entry < tree->GetEntries(); ++entry){
           tree->GetEntry(entry);

    //Fill the X Histrograms
            if (X_pT->size()!=0){

                TLorentzVector X_particle;
                X_particle.SetPtEtaPhiE((X_pT->at(0))/1000, X_eta->at(0), X_phi->at(0), (X_nrg->at(0))/1000); //Divide by a thousand to convert our units from MeV to GeV
                double X_particleMass = X_particle.M(); //yeilds invariant mass 
                    //Plot Pt, eta, and phi infromation of the TLorentz Vector 

                mX.Fill(X_particleMass);

                double XpT = X_particle.Pt();
                pTX.Fill(XpT);

                double Xeta = X_particle.Eta();
                etaX.Fill(Xeta);   

                double Xphi = X_particle.Phi();
                phiX.Fill(Xphi);
        }

    // FILL THE H HISTOGRAM
            if( H_n != 2){
                continue;
            }

            TLorentzVector H_particle0, H_particle1;
            H_particle0.SetPtEtaPhiE((H_pT->at(0))/1000, H_eta->at(0), H_phi->at(0), (H_nrg->at(0))/1000);
            H_particle1.SetPtEtaPhiE((H_pT->at(1))/1000, H_eta->at(1), H_phi->at(1), (H_nrg->at(1))/1000);

            TLorentzVector H_diparticle = H_particle0 + H_particle1;
            double H_diparticleMass = H_diparticle.M();

            mH.Fill(H_diparticleMass);

            TLorentzVector H_L = Leading(H_particle0 , H_particle1);
            TLorentzVector H_SL = SubLeading(H_particle0, H_particle1);

            H_L_m.Fill(H_L.M());
            
            double leading = H_L.Pt();
            H_L_pT.Fill(leading);

            leading = H_L.Eta();
            H_L_eta.Fill(leading);

            leading = H_L.Phi();
            H_L_phi.Fill(leading);

            H_SL_m.Fill(H_SL.M());

            double subleading = H_SL.Pt();
            H_SL_pT.Fill(subleading);

            subleading = H_SL.Eta();
            H_SL_eta.Fill(subleading);

            subleading = H_SL.Phi();
            H_SL_phi.Fill(subleading);

            double diH_data = H_diparticle.Pt();
            diH_pT.Fill(diH_data);

            diH_data = H_diparticle.Eta();
            diH_eta.Fill(diH_data);

            diH_data = H_diparticle.Phi();
            diH_phi.Fill(diH_data);

            TLorentzVector Smeared_H_particle0 = Smear(H_particle0,0.1, Smearing);
            TLorentzVector Smeared_H_particle1 = Smear(H_particle1,0.1, Smearing);
            TLorentzVector Smeared_diH_particle = Smeared_H_particle0 + Smeared_H_particle1;
            
            Smeared_mH.Fill(Smeared_diH_particle.M());
        
    //Fill in H tau tau Histograms

        TLorentzVector Htautau_particle;
        Htautau_particle.SetPtEtaPhiE(Htautau_pT/1000, Htautau_eta, Htautau_phi, Htautau_nrg/1000);

        mHtt.Fill(Htautau_particle.M());
        Htt_pTP.Fill(Htautau_particle.Pt());
        Htt_etaP.Fill(Htautau_particle.Eta());
        Htt_phiP.Fill(Htautau_particle.Phi());

    //Fill in H b b Histograms

        TLorentzVector Hbb_particle;
        Hbb_particle.SetPtEtaPhiE(Hbb_pT/1000, Hbb_eta, Hbb_phi, Hbb_nrg/1000);

        mHbb.Fill(Hbb_particle.M()); 
        Hbb_pTP.Fill(Hbb_particle.Pt());
        Hbb_etaP.Fill(Hbb_particle.Eta());
        Hbb_phiP.Fill(Hbb_particle.Phi());

    //FILL IN TAU HISTOGRAM

        if(tau_n != 2){
            continue;
        }
        
        TLorentzVector tau_particle0, tau_particle1;
        tau_particle0.SetPtEtaPhiE((tau_pT->at(0))/1000,tau_eta->at(0),tau_phi->at(0),(tau_nrg->at(0))/1000);
        tau_particle1.SetPtEtaPhiE((tau_pT->at(1))/1000,tau_eta->at(1),tau_phi->at(1),(tau_nrg->at(1))/1000);

        TLorentzVector tau_diparticle = tau_particle0 + tau_particle1;
        double tau_diParticleMass = tau_diparticle.M();
        
        mtau.Fill(tau_diParticleMass);

        TLorentzVector tau_L = Leading(tau_particle0, tau_particle1);
        TLorentzVector tau_SL = SubLeading(tau_particle0, tau_particle1);

        tau_L_m.Fill(tau_L.M());
        tau_L_pT.Fill(tau_L.Pt());
        tau_L_eta.Fill(tau_L.Eta());
        tau_L_phi.Fill(tau_L.Phi());

        tau_SL_m.Fill(tau_SL.M());
        tau_SL_pT.Fill(tau_SL.Pt());     
        tau_SL_eta.Fill(tau_SL.Eta());
        tau_SL_phi.Fill(tau_SL.Phi()); 

        ditau_pT.Fill(tau_diparticle.Pt());
        ditau_eta.Fill(tau_diparticle.Eta());
        ditau_phi.Fill(tau_diparticle.Phi());

    //FILL IN B HISTOGRAM

            if(b_n != 2){
                continue;
            }

            TLorentzVector b_particle0, b_particle1;
            b_particle0.SetPtEtaPhiE((b_pT->at(0))/1000, b_eta->at(0), b_phi->at(0), (b_nrg->at(0))/1000);
            b_particle1.SetPtEtaPhiE((b_pT->at(1))/1000, b_eta->at(1), b_phi->at(1), (b_nrg->at(1))/1000);

            TLorentzVector b_diparticle = b_particle0 + b_particle1;
            double b_diparticleMass = b_diparticle.M();

            mb.Fill(b_diparticleMass);

            TLorentzVector b_L = Leading(b_particle0, b_particle1);
            TLorentzVector b_SL = SubLeading(b_particle0, b_particle1);

            b_L_m.Fill(b_L.M());
            b_L_pT.Fill(b_L.Pt());
            b_L_eta.Fill(b_L.Eta());
            b_L_phi.Fill(b_L.Phi());

            b_SL_m.Fill(b_SL.M());
            b_SL_pT.Fill(b_SL.Pt());
            b_SL_eta.Fill(b_SL.Eta()); 
            b_SL_phi.Fill(b_SL.Phi());

            dib_pT.Fill(b_diparticle.Pt());
            dib_eta.Fill(b_diparticle.Eta());
            dib_phi.Fill(b_diparticle.Phi());

        // Fill 2-D plot of Hbb pT versus Htt pT

            HbbPt_HttPt.Fill(Hbb_particle.Pt(),Htautau_particle.Pt());

        // Fill 2-D plot of Hbb pT versus b DeltaR

            //di-b particle
            double data = b_particle0.DeltaR(b_particle1, false);
            HbbPt_bbDeltaR.Fill(Hbb_particle.Pt(),data);

        //Fill 1-D plot for bbtt to show X mass
            TLorentzVector bbtt = b_diparticle + tau_diparticle;
            bbtt_X_m.Fill(bbtt.M());

        //Lets smear some of the suckers to make it look more like actual data
            //twenty percent smear 

            TLorentzVector Smeared_tau_particle0 = Smear(tau_particle0, 0.1, Smearing);
            TLorentzVector Smeared_tau_particle1 = Smear(tau_particle1, 0.1, Smearing);
            TLorentzVector Smeared_tau_L = Leading(Smeared_tau_particle0, Smeared_tau_particle1);
            TLorentzVector Smeared_tau_SL = SubLeading(Smeared_tau_particle0, Smeared_tau_particle1);
            TLorentzVector Smeared_tau_diparticle = Smeared_tau_particle0 + Smeared_tau_particle1;

            Smeared_t_L_pT.Fill(Smeared_tau_L.Pt());
            Smeared_t_L_m.Fill(Smeared_tau_L.M());
            Smeared_t_SL_pT.Fill(Smeared_tau_SL.Pt());
            Smeared_t_SL_m.Fill(Smeared_tau_SL.M());
            Smeared_tt_m.Fill(Smeared_tau_diparticle.M());

            TLorentzVector Smeared_b_particle0 = Smear(b_particle0, 0.1, Smearing);
            TLorentzVector Smeared_b_particle1= Smear(b_particle1, 0.1, Smearing);
            TLorentzVector Smeared_b_L = Leading(Smeared_b_particle0, Smeared_b_particle1);
            TLorentzVector Smeared_b_SL = SubLeading(Smeared_b_particle0, Smeared_b_particle1);
            TLorentzVector Smeared_b_diparticle = Smeared_b_particle0 + Smeared_b_particle1;
            
            Smeared_b_L_pT.Fill(Smeared_b_L.Pt());
            Smeared_b_L_m.Fill(Smeared_b_L.M());
            Smeared_b_SL_pT.Fill(Smeared_b_SL.Pt());
            Smeared_b_SL_m.Fill(Smeared_b_SL.M());
            Smeared_bb_m.Fill(Smeared_b_diparticle.M());

            TLorentzVector Smeared_bbtt = Smeared_b_diparticle + Smeared_tau_diparticle;

            Smeared_bbtt_m.Fill(Smeared_bbtt.M());

            bbm_bbpT.Fill(b_diparticle.M(), b_diparticle.Pt());
            tautaum_tautaupT.Fill(tau_diparticle.M(), tau_diparticle.Pt());
            Smeared_bbm_bbpT.Fill(Smeared_b_diparticle.M(), Smeared_b_diparticle.Pt());
            Smeared_tautaum_tautaupT.Fill(Smeared_tau_diparticle.M(), Smeared_tau_diparticle.Pt());

            
    }

    HbbPt_HttPt.SetMarkerStyle(kFullDotMedium);

    HbbPt_bbDeltaR.SetMarkerStyle(kFullDotMedium);

    mX.SetDirectory(0);
    pTX.SetDirectory(0);
    etaX.SetDirectory(0);
    phiX.SetDirectory(0);
    
    mH.SetDirectory(0);
    Smeared_mH.SetDirectory(0);
    H_L_m.SetDirectory(0);
    H_L_pT.SetDirectory(0);
    H_L_eta.SetDirectory(0);
    H_L_phi.SetDirectory(0);
    H_SL_m.SetDirectory(0);
    H_SL_pT.SetDirectory(0);
    H_SL_eta.SetDirectory(0);
    H_SL_phi.SetDirectory(0);
    diH_pT.SetDirectory(0);
    diH_eta.SetDirectory(0);
    diH_phi.SetDirectory(0);

    mHtt.SetDirectory(0);
    Htt_pTP.SetDirectory(0);
    Htt_etaP.SetDirectory(0);
    Htt_phiP.SetDirectory(0);

    mHbb.SetDirectory(0);
    Hbb_pTP.SetDirectory(0);
    Hbb_etaP.SetDirectory(0);
    Hbb_phiP.SetDirectory(0);

    mtau.SetDirectory(0);
    tau_L_m.SetDirectory(0);
    tau_L_pT.SetDirectory(0);
    tau_L_eta.SetDirectory(0);
    tau_L_phi.SetDirectory(0);
    tau_SL_m.SetDirectory(0);
    tau_SL_pT.SetDirectory(0);
    tau_SL_eta.SetDirectory(0);
    tau_SL_phi.SetDirectory(0);
    ditau_pT.SetDirectory(0);
    ditau_eta.SetDirectory(0);
    ditau_phi.SetDirectory(0);

    mb.SetDirectory(0);
    b_L_m.SetDirectory(0);
    b_L_pT.SetDirectory(0);
    b_L_eta.SetDirectory(0);
    b_L_phi.SetDirectory(0);
    b_SL_m.SetDirectory(0);
    b_SL_pT.SetDirectory(0);
    b_SL_eta.SetDirectory(0);
    b_SL_phi.SetDirectory(0);
    dib_pT.SetDirectory(0);
    dib_eta.SetDirectory(0);
    dib_phi.SetDirectory(0);

    HbbPt_HttPt.SetDirectory(0);

    HbbPt_bbDeltaR.SetDirectory(0);

    bbtt_X_m.SetDirectory(0);

    Smeared_t_L_pT.SetDirectory(0);
    Smeared_t_L_m.SetDirectory(0);
    Smeared_t_SL_pT.SetDirectory(0);
    Smeared_t_SL_m.SetDirectory(0);
    Smeared_tt_m.SetDirectory(0);

    Smeared_b_L_pT.SetDirectory(0);
    Smeared_b_L_m.SetDirectory(0);
    Smeared_b_SL_pT.SetDirectory(0);
    Smeared_b_SL_m.SetDirectory(0);
    Smeared_bb_m.SetDirectory(0);

    Smeared_bbtt_m.SetDirectory(0);

    bbm_bbpT.SetDirectory(0);
    tautaum_tautaupT.SetDirectory(0);
    Smeared_bbm_bbpT.SetDirectory(0);
    Smeared_tautaum_tautaupT.SetDirectory(0);

    inFile->Close();

        std::cout<< " Reading from " << inFileName << " and writing to " << outFileName <<std::endl; 
        TFile* outHistFile = TFile::Open(outFileName.c_str(), "RECREATE");
        outHistFile->cd();

        mX.Write();
        pTX.Write();
        etaX.Write();
        phiX.Write();
        
        mH.Write();
        Smeared_mH.Write();
        H_L_m.Write();
        H_L_pT.Write();
        H_L_eta.Write();
        H_L_phi.Write();
        H_SL_m.Write();
        H_SL_pT.Write();
        H_SL_eta.Write();
        H_SL_phi.Write();
        diH_pT.Write();
        diH_eta.Write();
        diH_phi.Write();

        mHtt.Write();
        Htt_pTP.Write();
        Htt_etaP.Write();
        Htt_phiP.Write();

        mHbb.Write();
        Hbb_pTP.Write();
        Hbb_etaP.Write();
        Hbb_phiP.Write();

        mtau.Write();
        tau_L_m.Write();
        tau_L_pT.Write();
        tau_L_eta.Write();
        tau_L_phi.Write();
        tau_SL_m.Write();
        tau_SL_pT.Write();
        tau_SL_eta.Write();
        tau_SL_phi.Write();
        ditau_pT.Write();
        ditau_eta.Write();
        ditau_phi.Write();

        mb.Write();
        b_L_m.Write();
        b_L_pT.Write();
        b_L_eta.Write();
        b_L_phi.Write();
        b_SL_m.Write();
        b_SL_pT.Write();
        b_SL_eta.Write();
        b_SL_phi.Write();
        dib_pT.Write();
        dib_eta.Write();
        dib_phi.Write();      

        HbbPt_HttPt.Write();  

        HbbPt_bbDeltaR.Write();

        bbtt_X_m.Write();

        Smeared_t_L_pT.Write();
        Smeared_t_L_m.Write();
        Smeared_t_SL_pT.Write();
        Smeared_t_SL_m.Write();
        Smeared_tt_m.Write();

        Smeared_b_L_pT.Write();
        Smeared_b_L_m.Write();
        Smeared_b_SL_pT.Write();
        Smeared_b_SL_m.Write();
        Smeared_bb_m.Write();

        Smeared_bbtt_m.Write();
        
        bbm_bbpT.Write();
        tautaum_tautaupT.Write();
        Smeared_bbm_bbpT.Write();
        Smeared_tautaum_tautaupT.Write();

        outHistFile->Close();

    return 0;
}

//Notes:

//To access data via root without TBrowser
    //root <the file name>
    // .ls
    // <tree name>->Print()
            //or
    //<tree name>->Print("*$*"), where $ is the name or partial name of what you would like to have printed or view

//Side note: eta is not theta. Eta goes from 0 to infinity 
//Make sure to grab Eta not Theta value from TLorentzVector
