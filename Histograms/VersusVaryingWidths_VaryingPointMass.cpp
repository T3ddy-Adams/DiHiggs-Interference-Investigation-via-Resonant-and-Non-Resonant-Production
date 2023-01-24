//Thomas Adams
//thomas.adams@cern.ch

//To run:
    //root -l "VersusVaryingWidths_VaryingPointMass.cpp()"
    //root -l -b -q "VersusVaryingWidths_VaryingPointMass.cpp()"
        //prevents the bash that pops up and quites root
        //input histogram type you which to look at

#include <iostream>
#include <string>

string outFile(std::string inFileName){
    std::string fileName = inFileName.append("_VaryingWidths.pdf");
    return fileName;
}

string outYaxis(TH1D* myHistogram){
    int width = myHistogram->GetXaxis()->GetBinWidth(10);
    std::string Yaxis = "Events/";
    Yaxis = Yaxis.append(to_string(width));
    Yaxis = Yaxis.append("[GeV]");
    return Yaxis;
}


int VersusVaryingWidths_VaryingPointMass(std::string histogramFile){

    std::string histFileName;
    std::string pdfFileName = outFile(histogramFile);
    
    //m300 mass points
    histFileName = "run_XHH_bbtt_m300_hadhad_01p_50BSM_histogram.root";
    TFile* histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo01p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo01p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_02p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo02p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo02p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_03p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo03p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo03p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_05p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo05p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m300_hadhad_10p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo10p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_15p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo15p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_20p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo20p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_30p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histo30p = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_narrow_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m300Histonarrow = (TH1D*)histFile->Get(histogramFile.c_str());
    m300Histonarrow->SetDirectory(0);
    histFile->Close();

    TCanvas canvas("Canvas");
    canvas.SetLogy();
    canvas.cd();

    canvas.Print(Form("%s[",pdfFileName.c_str()));

    auto legend = new TLegend(0.88,0.7,0.68,0.9);

    m300Histo01p->SetStats(0);
    m300Histo02p->SetStats(0);
    m300Histo03p->SetStats(0);
    m300Histo05p->SetStats(0); 
    m300Histo10p->SetStats(0); 
    m300Histo15p->SetStats(0); 
    m300Histo20p->SetStats(0); 
    m300Histo30p->SetStats(0); 
    m300Histonarrow->SetStats(0); 


    //Histo01p
    m300Histo01p->SetLineColor(kPink+9);
    m300Histo01p->GetYaxis()->SetTitle(outYaxis(m300Histo01p).c_str());
    m300Histo01p->GetXaxis()->SetTitle("[GeV]");

    //Histo02p
    m300Histo02p->SetLineColor(kViolet+1);
    m300Histo02p->GetYaxis()->SetTitle(outYaxis(m300Histo02p).c_str());
    m300Histo02p->GetXaxis()->SetTitle("[GeV]");

    //Histo03p
    m300Histo03p->SetLineColor(kGreen+4);
    m300Histo03p->GetYaxis()->SetTitle(outYaxis(m300Histo03p).c_str());
    m300Histo03p->GetXaxis()->SetTitle("[GeV]");

    //Histo05p->SetLineWidth(2);
    m300Histo05p->SetLineColor(kRed);
    m300Histo05p->GetYaxis()->SetTitle(outYaxis(m300Histo05p).c_str());
    m300Histo05p->GetXaxis()->SetTitle("[GeV]");
    double Xmin = m300Histo05p->GetXaxis()->GetXmin();
    double Xmax = m300Histo05p->GetXaxis()->GetXmax();
    double Ymin = 0.1; // 0.1; // m300Histo05p->GetMinimum();
    double Ymax = m300Histo05p->GetMaximum();
    m300Histo05p->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histo05p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo10p->SetLineWidth(2);
    m300Histo10p->SetLineColor(kBlack);
    m300Histo10p->GetYaxis()->SetTitle(outYaxis(m300Histo10p).c_str());
    m300Histo10p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m300Histo10p->GetXaxis()->GetXmin();
    Xmax = m300Histo10p->GetXaxis()->GetXmax();
    Ymin = 0.1; // 0.1; // m300Histo10p->GetMinimum();
    Ymax = m300Histo10p->GetMaximum();
    m300Histo10p->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histo10p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo15p->SetLineWidth(2);
    m300Histo15p->SetLineColor(kCyan+2);
    m300Histo15p->GetYaxis()->SetTitle(outYaxis(m300Histo15p).c_str());
    m300Histo15p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m300Histo15p->GetXaxis()->GetXmin();
    Xmax = m300Histo15p->GetXaxis()->GetXmax();
    Ymin = 0.1; // 0.1; // m300Histo15p->GetMinimum(); 
    Ymax = m300Histo15p->GetMaximum();
    m300Histo15p->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histo15p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo20p->SetLineWidth(2);
    m300Histo20p->SetLineColor(kOrange);
    m300Histo20p->GetYaxis()->SetTitle(outYaxis(m300Histo20p).c_str());
    m300Histo20p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m300Histo20p->GetXaxis()->GetXmin();
    Xmax = m300Histo20p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m300Histo20p->GetMinimum(); 
    Ymax = m300Histo20p->GetMaximum();
    m300Histo20p->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histo20p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo30p->SetLineWidth(2);
    m300Histo30p->SetLineColor(kMagenta);
    m300Histo30p->GetYaxis()->SetTitle(outYaxis(m300Histo30p).c_str());
    m300Histo30p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m300Histo30p->GetXaxis()->GetXmin();
    Xmax = m300Histo30p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m300Histo30p->GetMinimum(); 
    Ymax = m300Histo30p->GetMaximum();
    m300Histo30p->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histo30p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histonarrow->SetLineWidth(2);
    m300Histonarrow->SetLineColor(kBlue);
    m300Histonarrow->GetYaxis()->SetTitle(outYaxis(m300Histonarrow).c_str());
    m300Histonarrow->GetXaxis()->SetTitle("[GeV]");
    Xmin = m300Histonarrow->GetXaxis()->GetXmin();
    Xmax = m300Histonarrow->GetXaxis()->GetXmax();
    Ymin = 0.1; // m300Histonarrow->GetMinimum(); 
    Ymax = m300Histonarrow->GetMaximum();
    m300Histonarrow->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histonarrow->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m300Histonarrow->Draw("h");
    m300Histo01p->Draw("h,same");
    m300Histo02p->Draw("h,same");
    m300Histo03p->Draw("h,same");
    m300Histo30p->Draw("h,same");
    m300Histo05p->Draw("h,same");
    m300Histo10p->Draw("h,same");
    m300Histo15p->Draw("h,same");
    m300Histo20p->Draw("h,same");
    //canvas.Print(pdfFileName.c_str());

    
    legend->SetHeader("300 point mass varying widths","C"); // option "C" allows to center the header
    legend->AddEntry(m300Histonarrow ,"narrow Width","l");
    legend->AddEntry(m300Histo01p, "1% Width","l");
    legend->AddEntry(m300Histo02p, "2% Width","l");
    legend->AddEntry(m300Histo03p, "3% Width","l");
    legend->AddEntry(m300Histo05p ,"5% Width","l");
    legend->AddEntry(m300Histo10p,"10% Width","l");
    legend->AddEntry(m300Histo15p,"15% Width","l");
    legend->AddEntry(m300Histo20p ,"20% Width","l");
    legend->AddEntry(m300Histo30p ,"30% Width","l");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());


    //canvas.Print(Form("%s]",pdfFileName.c_str())); //Closes plot file

    //m500 mass points

    histFileName = "run_XHH_bbtt_m500_hadhad_01p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo01p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo01p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_02p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo02p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo02p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_03p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo03p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo03p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_05p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo05p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m500_hadhad_10p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo10p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_15p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo15p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_20p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo20p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_30p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histo30p = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histo30p->SetDirectory(0);
    histFile->Close();


    histFileName = "run_XHH_bbtt_m500_hadhad_narrow_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m500Histonarrow = (TH1D*)histFile->Get(histogramFile.c_str());
    m500Histonarrow->SetDirectory(0);
    histFile->Close();

    //TCanvas canvas("Canvas");
    //canvas.cd();

    //canvas.Print(Form("%s[",pdfFileName.c_str()));

    m500Histo01p->SetStats(0);
    m500Histo02p->SetStats(0);
    m500Histo03p->SetStats(0);
    m500Histo05p->SetStats(0); 
    m500Histo10p->SetStats(0); 
    m500Histo15p->SetStats(0); 
    m500Histo20p->SetStats(0); 
    m500Histo30p->SetStats(0); 
    m500Histonarrow->SetStats(0); 

    //Histo01p
    m500Histo01p->SetLineColor(kPink+9);
    m500Histo01p->GetYaxis()->SetTitle(outYaxis(m500Histo01p).c_str());
    m500Histo01p->GetXaxis()->SetTitle("[GeV]");

    //Histo02p
    m500Histo02p->SetLineColor(kViolet+1);
    m300Histo02p->GetYaxis()->SetTitle(outYaxis(m500Histo02p).c_str());
    m300Histo02p->GetXaxis()->SetTitle("[GeV]");

    //Histo03p
    m500Histo03p->SetLineColor(kGreen+4);
    m500Histo03p->GetYaxis()->SetTitle(outYaxis(m500Histo03p).c_str());
    m500Histo03p->GetXaxis()->SetTitle("[GeV]");

    //Histo05p->SetLineWidth(2);
    m500Histo05p->SetLineColor(kRed);
    m500Histo05p->GetYaxis()->SetTitle(outYaxis(m500Histo05p).c_str());
    m500Histo05p->GetXaxis()->SetTitle("[GeV]");
    m500Histo05p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histo05p->GetXaxis()->GetXmin();
    Xmax = m500Histo05p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m500Histo05p->GetMinimum(); 
    Ymax = m500Histo05p->GetMaximum();
    m500Histo05p->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histo05p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo10p->SetLineWidth(2);
    m500Histo10p->SetLineColor(kBlack);
    m500Histo10p->GetYaxis()->SetTitle(outYaxis(m500Histo10p).c_str());
    m500Histo10p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histo10p->GetXaxis()->GetXmin();
    Xmax = m500Histo10p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m500Histo10p->GetMinimum(); 
    Ymax = m500Histo10p->GetMaximum();
    m500Histo10p->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histo10p->SetAxisRange(Ymin, 1.4*Ymax, "Y");


    //Histo15p->SetLineWidth(2);
    m500Histo15p->SetLineColor(kCyan+2);
    m500Histo15p->GetYaxis()->SetTitle(outYaxis(m500Histo15p).c_str());
    m500Histo15p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histo15p->GetXaxis()->GetXmin();
    Xmax = m500Histo15p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m500Histo15p->GetMinimum(); 
    Ymax = m500Histo15p->GetMaximum();
    m500Histo15p->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histo15p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo20p->SetLineWidth(2);
    m500Histo20p->SetLineColor(kOrange);
    m500Histo20p->GetYaxis()->SetTitle(outYaxis(m500Histo20p).c_str());
    m500Histo20p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histo20p->GetXaxis()->GetXmin();
    Xmax = m500Histo20p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m500Histo20p->GetMinimum(); 
    Ymax = m500Histo20p->GetMaximum();
    m500Histo20p->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histo20p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo30p->SetLineWidth(2);
    m500Histo30p->SetLineColor(kMagenta);
    m500Histo30p->GetYaxis()->SetTitle(outYaxis(m500Histo30p).c_str());
    m500Histo30p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histo30p->GetXaxis()->GetXmin();
    Xmax = m500Histo30p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m500Histo30p->GetMinimum(); 
    Ymax = m500Histo30p->GetMaximum();
    m500Histo30p->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histo30p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histonarrow->SetLineWidth(2);
    m500Histonarrow->SetLineColor(kBlue);
    m500Histonarrow->GetYaxis()->SetTitle(outYaxis(m500Histonarrow).c_str());
    m500Histonarrow->GetXaxis()->SetTitle("[GeV]");
    m500Histonarrow->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histonarrow->GetXaxis()->GetXmin();
    Xmax = m500Histonarrow->GetXaxis()->GetXmax();
    Ymin = 0.1; // m500Histonarrow->GetMinimum(); 
    Ymax = m500Histonarrow->GetMaximum();
    m500Histonarrow->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histonarrow->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m500Histonarrow->Draw("h");
    m500Histo01p->Draw("h,same");
    m500Histo02p->Draw("h,same");
    m500Histo03p->Draw("h,same");
    m500Histo30p->Draw("h,same");
    m500Histo05p->Draw("h,same");
    m500Histo10p->Draw("h,same");
    m500Histo15p->Draw("h,same");
    m500Histo20p->Draw("h,same");

    legend->SetHeader("500 point mass varying widths","C"); // option "C" allows to center the header
    legend->Draw();

    canvas.Print(pdfFileName.c_str());

    //m1000 mass points
    histFileName = "run_XHH_bbtt_m1000_hadhad_01p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo01p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo01p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_02p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo02p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo02p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_03p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo03p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo03p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_05p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo05p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m1000_hadhad_10p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo10p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_15p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo15p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_20p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo20p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_30p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histo30p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_narrow_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1000Histonarrow = (TH1D*)histFile->Get(histogramFile.c_str());
    m1000Histonarrow->SetDirectory(0);
    histFile->Close();

    //TCanvas canvas("Canvas");
    //canvas.cd();

    //canvas.Print(Form("%s[",pdfFileName.c_str()));

    m1000Histo01p->SetStats(0);
    m1000Histo02p->SetStats(0);
    m1000Histo03p->SetStats(0);
    m1000Histo05p->SetStats(0); 
    m1000Histo10p->SetStats(0); 
    m1000Histo15p->SetStats(0); 
    m1000Histo20p->SetStats(0); 
    m1000Histo30p->SetStats(0); 
    m1000Histonarrow->SetStats(0); 

    //Histo01p
    m1000Histo01p->SetLineColor(kPink+9);
    m1000Histo01p->GetYaxis()->SetTitle(outYaxis(m1000Histo01p).c_str());
    m1000Histo01p->GetXaxis()->SetTitle("[GeV]");

    //Histo02p
    m1000Histo02p->SetLineColor(kViolet+1);
    m1000Histo02p->GetYaxis()->SetTitle(outYaxis(m1000Histo02p).c_str());
    m1000Histo02p->GetXaxis()->SetTitle("[GeV]");

    //Histo03p
    m1000Histo03p->SetLineColor(kGreen+4);
    m1000Histo03p->GetYaxis()->SetTitle(outYaxis(m1000Histo03p).c_str());
    m1000Histo03p->GetXaxis()->SetTitle("[GeV]");

    //Histo05p->SetLineWidth(2);
    m1000Histo05p->SetLineColor(kRed);
    m1000Histo05p->GetYaxis()->SetTitle(outYaxis(m1000Histo05p).c_str());
    m1000Histo05p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histo05p->GetXaxis()->GetXmin();
    Xmax = m1000Histo05p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1000Histo05p->GetMinimum(); 
    Ymax = m1000Histo05p->GetMaximum();
    m1000Histo05p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histo05p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo10p->SetLineWidth(2);
    m1000Histo10p->SetLineColor(kBlack);
    m1000Histo10p->GetYaxis()->SetTitle(outYaxis(m1000Histo10p).c_str());
    m1000Histo10p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histo10p->GetXaxis()->GetXmin();
    Xmax = m1000Histo10p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1000Histo10p->GetMinimum(); 
    Ymax = m1000Histo10p->GetMaximum();
    m1000Histo10p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histo10p->SetAxisRange(Ymin, 1.4*Ymax, "Y");


    //Histo15p->SetLineWidth(2);
    m1000Histo15p->SetLineColor(kCyan+2);
    m1000Histo15p->GetYaxis()->SetTitle(outYaxis(m1000Histo15p).c_str());
    m1000Histo15p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histo15p->GetXaxis()->GetXmin();
    Xmax = m1000Histo15p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1000Histo15p->GetMinimum(); 
    Ymax = m1000Histo15p->GetMaximum();
    m1000Histo15p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histo15p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo20p->SetLineWidth(2);
    m1000Histo20p->SetLineColor(kOrange);
    m1000Histo20p->GetYaxis()->SetTitle(outYaxis(m1000Histo20p).c_str());
    m1000Histo20p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histo20p->GetXaxis()->GetXmin();
    Xmax = m1000Histo20p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1000Histo20p->GetMinimum(); 
    Ymax = m1000Histo20p->GetMaximum();
    m1000Histo20p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histo20p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo30p->SetLineWidth(2);
    m1000Histo30p->SetLineColor(kMagenta);
    m1000Histo30p->GetYaxis()->SetTitle(outYaxis(m1000Histo30p).c_str());
    m1000Histo30p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histo30p->GetXaxis()->GetXmin();
    Xmax = m1000Histo30p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1000Histo30p->GetMinimum(); 
    Ymax = m1000Histo30p->GetMaximum();
    m1000Histo30p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histo30p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histonarrow->SetLineWidth(2);
    m1000Histonarrow->SetLineColor(kBlue);
    m1000Histonarrow->GetYaxis()->SetTitle(outYaxis(m1000Histonarrow).c_str());
    m1000Histonarrow->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histonarrow->GetXaxis()->GetXmin();
    Xmax = m1000Histonarrow->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1000Histonarrow->GetMinimum(); 
    Ymax = m1000Histonarrow->GetMaximum();
    m1000Histonarrow->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histonarrow->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m1000Histonarrow->Draw("h");
    m1000Histo01p->Draw("h,same");
    m1000Histo02p->Draw("h,same");
    m1000Histo03p->Draw("h,same");
    m1000Histo30p->Draw("h,same");
    m1000Histo05p->Draw("h,same");
    m1000Histo10p->Draw("h,same");
    m1000Histo15p->Draw("h,same");
    m1000Histo20p->Draw("h,same");

    legend->SetHeader("1000 point mass varying widths","C"); // option "C" allows to center the header
    legend->Draw();

    canvas.Print(pdfFileName.c_str());

    //m1500 mass points
    histFileName = "run_XHH_bbtt_m1500_hadhad_01p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo01p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo01p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_02p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo02p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo02p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_03p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo03p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo03p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_05p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo05p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m1500_hadhad_10p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo10p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_15p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo15p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_20p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo20p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo20p->SetDirectory(0);
    histFile->Close();


    histFileName = "run_XHH_bbtt_m1500_hadhad_30p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histo30p = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histo30p->SetDirectory(0);
    histFile->Close();


    histFileName = "run_XHH_bbtt_m1500_hadhad_narrow_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m1500Histonarrow = (TH1D*)histFile->Get(histogramFile.c_str());
    m1500Histonarrow->SetDirectory(0);
    histFile->Close();

    //TCanvas canvas("Canvas");
    //canvas.cd();

    //canvas.Print(Form("%s[",pdfFileName.c_str()));

    m1500Histo01p->SetStats(0);
    m1500Histo02p->SetStats(0);
    m1500Histo03p->SetStats(0);
    m1500Histo05p->SetStats(0); 
    m1500Histo10p->SetStats(0); 
    m1500Histo15p->SetStats(0); 
    m1500Histo20p->SetStats(0); 
    m1500Histo30p->SetStats(0); 
    m1500Histonarrow->SetStats(0); 

    //Histo01p
    m1500Histo01p->SetLineColor(kPink+9);
    m1500Histo01p->GetYaxis()->SetTitle(outYaxis(m1500Histo01p).c_str());
    m1500Histo01p->GetXaxis()->SetTitle("[GeV]");

    //Histo02p
    m1500Histo02p->SetLineColor(kViolet+1);
    m1500Histo02p->GetYaxis()->SetTitle(outYaxis(m1500Histo02p).c_str());
    m1500Histo02p->GetXaxis()->SetTitle("[GeV]");

    //Histo03p
    m1500Histo03p->SetLineColor(kGreen+4);
    m1500Histo03p->GetYaxis()->SetTitle(outYaxis(m1500Histo03p).c_str());
    m1500Histo03p->GetXaxis()->SetTitle("[GeV]");

    //Histo05p->SetLineWidth(2);
    m1500Histo05p->SetLineColor(kRed);
    m1500Histo05p->GetYaxis()->SetTitle(outYaxis(m1500Histo05p).c_str());
    m1500Histo05p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histo05p->GetXaxis()->GetXmin();
    Xmax = m1500Histo05p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1500Histo05p->GetMinimum(); 
    Ymax = m1500Histo05p->GetMaximum();
    m1500Histo05p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histo05p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo10p->SetLineWidth(2);
    m1500Histo10p->SetLineColor(kBlack);
    m1500Histo10p->GetYaxis()->SetTitle(outYaxis(m1500Histo10p).c_str());
    m1500Histo10p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histo10p->GetXaxis()->GetXmin();
    Xmax = m1500Histo10p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1500Histo10p->GetMinimum(); 
    Ymax = m1500Histo10p->GetMaximum();
    m1500Histo10p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histo10p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo15p->SetLineWidth(2);
    m1500Histo15p->SetLineColor(kCyan+2);
    m1500Histo15p->GetYaxis()->SetTitle(outYaxis(m1500Histo15p).c_str());
    m1500Histo15p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histo15p->GetXaxis()->GetXmin();
    Xmax = m1500Histo15p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1500Histo15p->GetMinimum(); 
    Ymax = m1500Histo15p->GetMaximum();
    m1500Histo15p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histo15p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo20p->SetLineWidth(2);
    m1500Histo20p->SetLineColor(kOrange);
    m1500Histo20p->GetYaxis()->SetTitle(outYaxis(m1500Histo20p).c_str());
    m1500Histo20p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histo20p->GetXaxis()->GetXmin();
    Xmax = m1500Histo20p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1500Histo20p->GetMinimum(); 
    Ymax = m1500Histo20p->GetMaximum();
    m1500Histo20p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histo20p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo30p->SetLineWidth(2);
    m1500Histo30p->SetLineColor(kMagenta);
    m1500Histo30p->GetYaxis()->SetTitle(outYaxis(m1500Histo30p).c_str());
    m1500Histo30p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histo30p->GetXaxis()->GetXmin();
    Xmax = m1500Histo30p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1500Histo30p->GetMinimum(); 
    Ymax = m1500Histo30p->GetMaximum();
    m1500Histo30p->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histo30p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histonarrow->SetLineWidth(2);
    m1500Histonarrow->SetLineColor(kBlue);
    m1500Histonarrow->GetYaxis()->SetTitle(outYaxis(m1500Histonarrow).c_str());
    m1500Histonarrow->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histonarrow->GetXaxis()->GetXmin();
    Xmax = m1500Histonarrow->GetXaxis()->GetXmax();
    Ymin = 0.1; // m1500Histonarrow->GetMinimum(); 
    Ymax = m1500Histonarrow->GetMaximum();
    m1500Histonarrow->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histonarrow->SetAxisRange(Ymin, 4*Ymax, "Y");

    m1500Histonarrow->Draw("h");
    m1500Histo01p->Draw("h,same");
    m1500Histo02p->Draw("h,same");
    m1500Histo03p->Draw("h,same");
    m1500Histo30p->Draw("h,same");
    m1500Histo05p->Draw("h,same");
    m1500Histo10p->Draw("h,same");
    m1500Histo15p->Draw("h,same");
    m1500Histo20p->Draw("h,same");

    legend->SetHeader("1500 point mass varying widths","C"); // option "C" allows to center the header
    legend->Draw();

    canvas.Print(pdfFileName.c_str());

    //m2000 mass points
    histFileName = "run_XHH_bbtt_m2000_hadhad_01p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo01p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo01p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_02p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo02p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo02p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_03p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo03p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo03p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_05p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo05p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m2000_hadhad_10p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo10p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_15p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo15p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_20p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo20p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_30p_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histo30p = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_narrow_50BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH1D* m2000Histonarrow = (TH1D*)histFile->Get(histogramFile.c_str());
    m2000Histonarrow->SetDirectory(0);
    histFile->Close();

    //TCanvas canvas("Canvas");
    //canvas.cd();

    //canvas.Print(Form("%s[",pdfFileName.c_str()));

    m2000Histo01p->SetStats(0);
    m2000Histo02p->SetStats(0);
    m2000Histo03p->SetStats(0);
    m2000Histo05p->SetStats(0); 
    m2000Histo10p->SetStats(0); 
    m2000Histo15p->SetStats(0); 
    m2000Histo20p->SetStats(0); 
    m2000Histo30p->SetStats(0); 
    m2000Histonarrow->SetStats(0); 

    //Histo01p
    m2000Histo01p->SetLineColor(kPink+9);
    m2000Histo01p->GetYaxis()->SetTitle(outYaxis(m2000Histo01p).c_str());
    m2000Histo01p->GetXaxis()->SetTitle("[GeV]");

    //Histo02p
    m2000Histo02p->SetLineColor(kViolet+1);
    m2000Histo02p->GetYaxis()->SetTitle(outYaxis(m2000Histo02p).c_str());
    m2000Histo02p->GetXaxis()->SetTitle("[GeV]");

    //Histo03p
    m2000Histo03p->SetLineColor(kGreen+4);
    m2000Histo03p->GetYaxis()->SetTitle(outYaxis(m2000Histo03p).c_str());
    m2000Histo03p->GetXaxis()->SetTitle("[GeV]");

    //Histo05p->SetLineWidth(2);
    m2000Histo05p->SetLineColor(kRed);
    m2000Histo05p->GetYaxis()->SetTitle(outYaxis(m2000Histo05p).c_str());
    m2000Histo05p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histo05p->GetXaxis()->GetXmin();
    Xmax = m2000Histo05p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m2000Histo05p->GetMinimum(); 
    Ymax = m2000Histo05p->GetMaximum();
    m2000Histo05p->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histo05p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo10p->SetLineWidth(2);
    m2000Histo10p->SetLineColor(kBlack);
    m2000Histo10p->GetYaxis()->SetTitle(outYaxis(m2000Histo10p).c_str());
    m2000Histo10p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histo10p->GetXaxis()->GetXmin();
    Xmax = m2000Histo10p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m2000Histo10p->GetMinimum(); 
    Ymax = m2000Histo10p->GetMaximum();
    m2000Histo10p->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histo10p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo15p->SetLineWidth(2);
    m2000Histo15p->SetLineColor(kCyan+2);
    m2000Histo15p->GetYaxis()->SetTitle(outYaxis(m2000Histo15p).c_str());
    m2000Histo15p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histo15p->GetXaxis()->GetXmin();
    Xmax = m2000Histo15p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m2000Histo15p->GetMinimum(); 
    Ymax = m2000Histo15p->GetMaximum();
    m2000Histo15p->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histo15p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo20p->SetLineWidth(2);
    m2000Histo20p->SetLineColor(kOrange);
    m2000Histo20p->GetYaxis()->SetTitle(outYaxis(m2000Histo20p).c_str());
    m2000Histo20p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histo20p->GetXaxis()->GetXmin();
    Xmax = m2000Histo20p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m2000Histo20p->GetMinimum(); 
    Ymax = m2000Histo20p->GetMaximum();
    m2000Histo20p->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histo20p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histo30p->SetLineWidth(2);
    m2000Histo30p->SetLineColor(kMagenta);
    m2000Histo30p->GetYaxis()->SetTitle(outYaxis(m2000Histo30p).c_str());
    m2000Histo30p->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histo30p->GetXaxis()->GetXmin();
    Xmax = m2000Histo30p->GetXaxis()->GetXmax();
    Ymin = 0.1; // m2000Histo30p->GetMinimum(); 
    Ymax = m2000Histo30p->GetMaximum();
    m2000Histo30p->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histo30p->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    //Histonarrow->SetLineWidth(2);
    m2000Histonarrow->SetLineColor(kBlue);
    m2000Histonarrow->GetYaxis()->SetTitle(outYaxis(m2000Histonarrow).c_str());
    m2000Histonarrow->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histonarrow->GetXaxis()->GetXmin();
    Xmax = m2000Histonarrow->GetXaxis()->GetXmax();
    Ymin = 0.1; // m2000Histonarrow->GetMinimum(); 
    Ymax = m2000Histonarrow->GetMaximum();
    m2000Histonarrow->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histonarrow->SetAxisRange(Ymin, 4*Ymax, "Y");

    m2000Histonarrow->Draw("h");
    m2000Histo01p->Draw("h,same");
    m2000Histo02p->Draw("h,same");
    m2000Histo03p->Draw("h,same");
    m2000Histo30p->Draw("h,same");
    m2000Histo05p->Draw("h,same");
    m2000Histo10p->Draw("h,same");
    m2000Histo15p->Draw("h,same");
    m2000Histo20p->Draw("h,same");

    legend->SetHeader("2000 point mass varying widths","C"); // option "C" allows to center the header
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    //Widths with varying point masses
    auto legend2 = new TLegend(0.88,0.7,0.68,0.9);

    //narrow width
    m300Histonarrow->SetLineColor(kRed);
    m500Histonarrow->SetLineColor(kBlack);
    m1000Histonarrow->SetLineColor(kCyan+2);
    m1500Histonarrow->SetLineColor(kOrange);
    m2000Histonarrow->SetLineColor(kMagenta);

    m300Histonarrow->Draw("h");
    m2000Histonarrow->Draw("h,same");
    m500Histonarrow->Draw("h,same");
    m1000Histonarrow->Draw("h,same");
    m1500Histonarrow->Draw("h,same");

    legend2->SetHeader("Narrow Width","C");
    legend2->AddEntry(m300Histonarrow ,"300 Point Mass","l");
    legend2->AddEntry(m500Histonarrow,"500 Point Mass","l");
    legend2->AddEntry(m1000Histonarrow,"1000 Point Mass","l");
    legend2->AddEntry(m1500Histonarrow ,"1500 Point Mass","l");
    legend2->AddEntry(m2000Histonarrow ,"2000 Point Mass","l");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());


    //1% width
    m300Histo01p->SetLineColor(kRed);
    m500Histo01p->SetLineColor(kBlack);
    m1000Histo15p->SetLineColor(kCyan+2);
    m1500Histo01p->SetLineColor(kOrange);
    m2000Histo01p->SetLineColor(kMagenta);
    
    m300Histo01p->Draw("h");
    m2000Histo15p->Draw("h,same");
    m500Histo01p->Draw("h,same");
    m1000Histo01p->Draw("h,same");
    m1500Histo01p->Draw("h,same");

    legend2->SetHeader("1% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //2% width
    m300Histo02p->SetLineColor(kRed);
    m500Histo02p->SetLineColor(kBlack);
    m1000Histo02p->SetLineColor(kCyan+2);
    m1500Histo02p->SetLineColor(kOrange);
    m2000Histo02p->SetLineColor(kMagenta);
    
    m300Histo02p->Draw("h");
    m2000Histo02p->Draw("h,same");
    m500Histo02p->Draw("h,same");
    m1000Histo02p->Draw("h,same");
    m1500Histo02p->Draw("h,same");

    legend2->SetHeader("2% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //3% width
    m300Histo03p->SetLineColor(kRed);
    m500Histo03p->SetLineColor(kBlack);
    m1000Histo03p->SetLineColor(kCyan+2);
    m1500Histo03p->SetLineColor(kOrange);
    m2000Histo03p->SetLineColor(kMagenta);
    
    m300Histo03p->Draw("h");
    m2000Histo03p->Draw("h,same");
    m500Histo03p->Draw("h,same");
    m1000Histo03p->Draw("h,same");
    m1500Histo03p->Draw("h,same");

    legend2->SetHeader("3% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //5% width
    m300Histo05p->SetLineColor(kRed);
    m500Histo05p->SetLineColor(kBlack);
    m1000Histo05p->SetLineColor(kCyan+2);
    m1500Histo05p->SetLineColor(kOrange);
    m2000Histo05p->SetLineColor(kMagenta);
    
    m300Histo05p->Draw("h");
    m2000Histo05p->Draw("h,same");
    m500Histo05p->Draw("h,same");
    m1000Histo05p->Draw("h,same");
    m1500Histo05p->Draw("h,same");

    legend2->SetHeader("5% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //10% width
    m300Histo10p->SetLineColor(kRed);
    m500Histo10p->SetLineColor(kBlack);
    m1000Histo10p->SetLineColor(kCyan+2);
    m1500Histo10p->SetLineColor(kOrange);
    m2000Histo10p->SetLineColor(kMagenta);

    m300Histo10p->Draw("h");
    m2000Histo10p->Draw("h,same");
    m500Histo10p->Draw("h,same");
    m1000Histo10p->Draw("h,same");
    m1500Histo10p->Draw("h,same");

    legend2->SetHeader("10% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //15% width
    m300Histo15p->SetLineColor(kRed);
    m500Histo15p->SetLineColor(kBlack);
    m1000Histo15p->SetLineColor(kCyan+2);
    m1500Histo15p->SetLineColor(kOrange);
    m2000Histo15p->SetLineColor(kMagenta);

    m300Histo15p->Draw("h");
    m2000Histo15p->Draw("h,same");
    m500Histo15p->Draw("h,same");
    m1000Histo15p->Draw("h,same");
    m1500Histo15p->Draw("h,same");

    legend2->SetHeader("15% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //20% width
    m300Histo20p->SetLineColor(kRed);
    m500Histo20p->SetLineColor(kBlack);
    m1000Histo20p->SetLineColor(kCyan+2);
    m1500Histo20p->SetLineColor(kOrange);
    m2000Histo20p->SetLineColor(kMagenta);

    m300Histo20p->Draw("h");
    m2000Histo20p->Draw("h,same");
    m500Histo20p->Draw("h,same");
    m1000Histo20p->Draw("h,same");
    m1500Histo20p->Draw("h,same");

    legend2->SetHeader("20% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //30% width
    m300Histo30p->SetLineColor(kRed);
    m500Histo30p->SetLineColor(kBlack);
    m1000Histo30p->SetLineColor(kCyan+2);
    m1500Histo30p->SetLineColor(kOrange);
    m2000Histo30p->SetLineColor(kMagenta);

    m300Histo30p->Draw("h");
    m2000Histo30p->Draw("h,same");
    m500Histo30p->Draw("h,same");
    m1000Histo30p->Draw("h,same");
    m1500Histo30p->Draw("h,same");

    legend2->SetHeader("30% Width","C");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());

    //TGraphs for varying widths 
    float y[9] = {0.1, 1.00, 2.00, 3.00, 5.00,10.00,15.00,20.0,30.0};


    //m300
    int bins = m300Histo01p->GetNbinsX()+1;
    int pointMassBin = m300Histo01p->FindBin(300);
    int X1 = m300Histo01p->FindBin(300*0.90);
    int X2 = m300Histo01p->FindBin(300*1.10);
    double Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo01p->GetBinContent(i);
    }
    float Fractionm300Histo01p = Numerator / m300Histo01p->Integral(0,bins);

    bins = m300Histo02p->GetNbinsX()+1;
    pointMassBin = m300Histo02p->FindBin(300);
    X1 = m300Histo02p->FindBin(300*0.90);
    X2 = m300Histo02p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo02p->GetBinContent(i);
    }
    float Fractionm300Histo02p = Numerator / m300Histo02p->Integral(0,bins);

    bins = m300Histo03p->GetNbinsX()+1;
    pointMassBin = m300Histo03p->FindBin(300);
    X1 = m300Histo03p->FindBin(300*0.90);
    X2 = m300Histo03p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo03p->GetBinContent(i);
    }
    float Fractionm300Histo03p = Numerator / m300Histo03p->Integral(0,bins);

    bins = m300Histo05p->GetNbinsX()+1;
    pointMassBin = m300Histo05p->FindBin(300);
    X1 = m300Histo05p->FindBin(300*0.90);
    X2 = m300Histo05p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo05p->GetBinContent(i);
    }
    float Fractionm300Histo05p = Numerator / m300Histo05p->Integral(0,bins);

    bins = m300Histo10p->GetNbinsX()+1;
    pointMassBin = m300Histo10p->FindBin(300);
    X1 = m300Histo10p->FindBin(300*0.90);
    X2 = m300Histo10p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo10p->GetBinContent(i);
    }
    float Fractionm300Histo10p = Numerator / m300Histo10p->Integral(0,bins);

    bins = m300Histo15p->GetNbinsX()+1;
    pointMassBin = m300Histo15p->FindBin(300);
    X1 = m300Histo15p->FindBin(300*0.90);
    X2 = m300Histo15p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo15p->GetBinContent(i);
    }
    float Fractionm300Histo15p = Numerator / m300Histo15p->Integral(0,bins);

    bins = m300Histo20p->GetNbinsX()+1;
    pointMassBin = m300Histo20p->FindBin(300);
    X1 = m300Histo20p->FindBin(300*0.90);
    X2 = m300Histo20p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo20p->GetBinContent(i);
    }
    float Fractionm300Histo20p = Numerator / m300Histo20p->Integral(0,bins);

    bins = m300Histo30p->GetNbinsX()+1;
    pointMassBin = m300Histo30p->FindBin(300);
    X1 = m300Histo30p->FindBin(300*0.90);
    X2 = m300Histo30p->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histo30p->GetBinContent(i);
    }
    float Fractionm300Histo30p = Numerator / m300Histo30p->Integral(0,bins);

    bins = m300Histonarrow->GetNbinsX()+1;
    pointMassBin = m300Histonarrow->FindBin(300);
    X1 = m300Histonarrow->FindBin(300*0.90);
    X2 = m300Histonarrow->FindBin(300*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m300Histonarrow->GetBinContent(i);
    }
    float Fractionm300Histonarrow = Numerator / m300Histonarrow->Integral(0,bins);
    
    float x300[9] = {Fractionm300Histonarrow, Fractionm300Histo01p, Fractionm300Histo02p, Fractionm300Histo03p ,Fractionm300Histo05p, Fractionm300Histo10p, Fractionm300Histo15p, Fractionm300Histo20p, Fractionm300Histo30p};


    //m500
    bins = m500Histo01p->GetNbinsX()+1;
    pointMassBin = m500Histo01p->FindBin(500);
    X1 = m500Histo01p->FindBin(500*0.90);
    X2 = m500Histo01p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo01p->GetBinContent(i);
    }
    float Fractionm500Histo01p = Numerator / m500Histo01p->Integral(0,bins);

    bins = m500Histo02p->GetNbinsX()+1;
    pointMassBin = m500Histo02p->FindBin(500);
    X1 = m500Histo02p->FindBin(500*0.90);
    X2 = m500Histo02p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo02p->GetBinContent(i);
    }
    float Fractionm500Histo02p = Numerator / m500Histo02p->Integral(0,bins);

    bins = m500Histo03p->GetNbinsX()+1;
    pointMassBin = m500Histo03p->FindBin(500);
    X1 = m500Histo03p->FindBin(500*0.90);
    X2 = m500Histo03p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo03p->GetBinContent(i);
    }
    float Fractionm500Histo03p = Numerator / m500Histo03p->Integral(0,bins);

    bins = m500Histo05p->GetNbinsX()+1;
    pointMassBin = m500Histo05p->FindBin(500);
    X1 = m500Histo05p->FindBin(500*0.90);
    X2 = m500Histo05p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo05p->GetBinContent(i);
    }
    float Fractionm500Histo05p = Numerator / m500Histo05p->Integral(0,bins);

    bins = m500Histo10p->GetNbinsX()+1;
    pointMassBin = m500Histo10p->FindBin(500);
    X1 = m500Histo10p->FindBin(500*0.90);
    X2 = m500Histo10p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo10p->GetBinContent(i);
    }
    float Fractionm500Histo10p = Numerator / m500Histo10p->Integral(0,bins);

    bins = m500Histo15p->GetNbinsX()+1;
    pointMassBin = m500Histo15p->FindBin(500);
    X1 = m500Histo15p->FindBin(500*0.90);
    X2 = m500Histo15p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo15p->GetBinContent(i);
    }
    float Fractionm500Histo15p = Numerator / m500Histo15p->Integral(0,bins);

    bins = m500Histo20p->GetNbinsX()+1;
    pointMassBin = m500Histo20p->FindBin(500);
    X1 = m500Histo20p->FindBin(500*0.90);
    X2 = m500Histo20p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo20p->GetBinContent(i);
    }
    float Fractionm500Histo20p = Numerator / m500Histo20p->Integral(0,bins);

    bins = m500Histo30p->GetNbinsX()+1;
    pointMassBin = m500Histo30p->FindBin(500);
    X1 = m500Histo30p->FindBin(500*0.90);
    X2 = m500Histo30p->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histo30p->GetBinContent(i);
    }
    float Fractionm500Histo30p = Numerator / m500Histo30p->Integral(0,bins);

    bins = m500Histonarrow->GetNbinsX()+1;
    pointMassBin = m500Histonarrow->FindBin(500);
    X1 = m500Histonarrow->FindBin(500*0.90);
    X2 = m500Histonarrow->FindBin(500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m500Histonarrow->GetBinContent(i);
    }
    float Fractionm500Histonarrow = Numerator / m500Histonarrow->Integral(0,bins);
    
    float x500[9] = {Fractionm500Histonarrow , Fractionm500Histo01p, Fractionm500Histo02p, Fractionm500Histo03p, Fractionm500Histo05p, Fractionm500Histo10p, Fractionm500Histo15p, Fractionm500Histo20p, Fractionm500Histo30p};


    //m1000

    bins = m1000Histo01p->GetNbinsX()+1;
    pointMassBin = m1000Histo01p->FindBin(1000);
    X1 = m1000Histo01p->FindBin(1000*0.90);
    X2 = m1000Histo01p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo01p->GetBinContent(i);
    }
    float Fractionm1000Histo01p = Numerator / m1000Histo01p->Integral(0,bins);

    bins = m1000Histo02p->GetNbinsX()+1;
    pointMassBin = m1000Histo02p->FindBin(1000);
    X1 = m1000Histo02p->FindBin(1000*0.90);
    X2 = m1000Histo02p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo02p->GetBinContent(i);
    }
    float Fractionm1000Histo02p = Numerator / m1000Histo02p->Integral(0,bins);

    bins = m1000Histo03p->GetNbinsX()+1;
    pointMassBin = m1000Histo03p->FindBin(1000);
    X1 = m1000Histo03p->FindBin(1000*0.90);
    X2 = m1000Histo03p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo03p->GetBinContent(i);
    }
    float Fractionm1000Histo03p = Numerator / m1000Histo03p->Integral(0,bins);

    bins = m1000Histo05p->GetNbinsX()+1;
    pointMassBin = m1000Histo05p->FindBin(1000);
    X1 = m1000Histo05p->FindBin(1000*0.90);
    X2 = m1000Histo05p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo05p->GetBinContent(i);
    }
    float Fractionm1000Histo05p = Numerator / m1000Histo05p->Integral(0,bins);

    bins = m1000Histo10p->GetNbinsX()+1;
    pointMassBin = m1000Histo10p->FindBin(1000);
    X1 = m1000Histo10p->FindBin(1000*0.90);
    X2 = m1000Histo10p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo10p->GetBinContent(i);
    }
    float Fractionm1000Histo10p = Numerator / m1000Histo10p->Integral(0,bins);

    bins = m1000Histo15p->GetNbinsX()+1;
    pointMassBin = m1000Histo15p->FindBin(1000);
    X1 = m1000Histo15p->FindBin(1000*0.90);
    X2 = m1000Histo15p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo15p->GetBinContent(i);
    }
    float Fractionm1000Histo15p = Numerator / m1000Histo15p->Integral(0,bins);

    bins = m1000Histo20p->GetNbinsX()+1;
    pointMassBin = m1000Histo20p->FindBin(1000);
    X1 = m1000Histo20p->FindBin(1000*0.90);
    X2 = m1000Histo20p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo20p->GetBinContent(i);
    }
    float Fractionm1000Histo20p = Numerator / m1000Histo20p->Integral(0,bins);

    bins = m1000Histo30p->GetNbinsX()+1;
    pointMassBin = m1000Histo30p->FindBin(1000);
    X1 = m1000Histo30p->FindBin(1000*0.90);
    X2 = m1000Histo30p->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histo30p->GetBinContent(i);
    }
    float Fractionm1000Histo30p = Numerator / m1000Histo30p->Integral(0,bins);

    bins = m1000Histonarrow->GetNbinsX()+1;
    pointMassBin = m1000Histonarrow->FindBin(1000);
    X1 = m1000Histonarrow->FindBin(1000*0.90);
    X2 = m1000Histonarrow->FindBin(1000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1000Histonarrow->GetBinContent(i);
    }
    float Fractionm1000Histonarrow = Numerator / m1000Histonarrow->Integral(0,bins);

    float x1000[9] = {Fractionm1000Histonarrow , Fractionm1000Histo01p, Fractionm1000Histo02p, Fractionm1000Histo03p ,Fractionm1000Histo05p, Fractionm1000Histo10p, Fractionm1000Histo15p, Fractionm1000Histo20p, Fractionm1000Histo30p};


    //m1500
    bins = m1500Histo01p->GetNbinsX()+1;
    pointMassBin = m1500Histo01p->FindBin(1500);
    X1 = m1500Histo01p->FindBin(1500*0.90);
    X2 = m1500Histo01p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo01p->GetBinContent(i);
    }
    float Fractionm1500Histo01p = Numerator / m1500Histo01p->Integral(0,bins);

    bins = m1500Histo02p->GetNbinsX()+1;
    pointMassBin = m1500Histo02p->FindBin(1500);
    X1 = m1500Histo02p->FindBin(1500*0.90);
    X2 = m1500Histo02p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo02p->GetBinContent(i);
    }
    float Fractionm1500Histo02p = Numerator / m1500Histo02p->Integral(0,bins);

    bins = m1500Histo03p->GetNbinsX()+1;
    pointMassBin = m1500Histo03p->FindBin(1500);
    X1 = m1500Histo03p->FindBin(1500*0.90);
    X2 = m1500Histo03p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo03p->GetBinContent(i);
    }
    float Fractionm1500Histo03p = Numerator / m1500Histo03p->Integral(0,bins);

    bins = m1500Histo05p->GetNbinsX()+1;
    pointMassBin = m1500Histo05p->FindBin(1500);
    X1 = m1500Histo05p->FindBin(1500*0.90);
    X2 = m1500Histo05p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo05p->GetBinContent(i);
    }
    float Fractionm1500Histo05p = Numerator / m1500Histo05p->Integral(0,bins);

    bins = m1500Histo10p->GetNbinsX()+1;
    pointMassBin = m1500Histo10p->FindBin(1500);
    X1 = m1500Histo10p->FindBin(1500*0.90);
    X2 = m1500Histo10p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo10p->GetBinContent(i);
    }
    float Fractionm1500Histo10p = Numerator / m1500Histo10p->Integral(0,bins);

    bins = m1500Histo15p->GetNbinsX()+1;
    pointMassBin = m1500Histo15p->FindBin(1500);
    X1 = m1500Histo15p->FindBin(1500*0.90);
    X2 = m1500Histo15p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo15p->GetBinContent(i);
    }
    float Fractionm1500Histo15p = Numerator / m1500Histo15p->Integral(0,bins);

    bins = m1500Histo20p->GetNbinsX()+1;
    pointMassBin = m1500Histo20p->FindBin(1500);
    X1 = m1500Histo20p->FindBin(1500*0.90);
    X2 = m1500Histo20p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo20p->GetBinContent(i);
    }
    float Fractionm1500Histo20p = Numerator / m1500Histo20p->Integral(0,bins);

    bins = m1500Histo30p->GetNbinsX()+1;
    pointMassBin = m1500Histo30p->FindBin(1500);
    X1 = m1500Histo30p->FindBin(1500*0.90);
    X2 = m1500Histo30p->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histo30p->GetBinContent(i);
    }
    float Fractionm1500Histo30p = Numerator / m1500Histo30p->Integral(0,bins);

    bins = m1500Histonarrow->GetNbinsX()+1;
    pointMassBin = m1500Histonarrow->FindBin(1500);
    X1 = m1500Histonarrow->FindBin(1500*0.90);
    X2 = m1500Histonarrow->FindBin(1500*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m1500Histonarrow->GetBinContent(i);
    }
    float Fractionm1500Histonarrow = Numerator / m1500Histonarrow->Integral(0,bins);

    float x1500[9] = {Fractionm1500Histonarrow , Fractionm1500Histo01p, Fractionm1500Histo02p, Fractionm1500Histo03p, Fractionm1500Histo05p, Fractionm1500Histo10p, Fractionm1500Histo15p, Fractionm1500Histo20p, Fractionm1500Histo30p};


    //m2000
    bins = m2000Histo01p->GetNbinsX()+1;
    pointMassBin = m2000Histo01p->FindBin(2000);
    X1 = m2000Histo01p->FindBin(2000*0.90);
    X2 = m2000Histo01p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo01p->GetBinContent(i);
    }
    float Fractionm2000Histo01p = Numerator / m2000Histo01p->Integral(0,bins);

    bins = m2000Histo02p->GetNbinsX()+1;
    pointMassBin = m2000Histo02p->FindBin(2000);
    X1 = m2000Histo02p->FindBin(2000*0.90);
    X2 = m2000Histo02p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo02p->GetBinContent(i);
    }
    float Fractionm2000Histo02p = Numerator / m2000Histo02p->Integral(0,bins);

    bins = m2000Histo03p->GetNbinsX()+1;
    pointMassBin = m2000Histo03p->FindBin(2000);
    X1 = m2000Histo03p->FindBin(2000*0.90);
    X2 = m2000Histo03p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo03p->GetBinContent(i);
    }
    float Fractionm2000Histo03p = Numerator / m2000Histo03p->Integral(0,bins);

    bins = m2000Histo05p->GetNbinsX()+1;
    pointMassBin = m2000Histo05p->FindBin(2000);
    X1 = m2000Histo05p->FindBin(2000*0.90);
    X2 = m2000Histo05p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo05p->GetBinContent(i);
    }
    float Fractionm2000Histo05p = Numerator / m2000Histo05p->Integral(0,bins);

    bins = m2000Histo10p->GetNbinsX()+1;
    pointMassBin = m2000Histo10p->FindBin(2000);
    X1 = m2000Histo10p->FindBin(2000*0.90);
    X2 = m2000Histo10p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo10p->GetBinContent(i);
    }
    float Fractionm2000Histo10p = Numerator / m2000Histo10p->Integral(0,bins);

    bins = m2000Histo15p->GetNbinsX()+1;
    pointMassBin = m2000Histo15p->FindBin(2000);
    X1 = m2000Histo15p->FindBin(2000*0.90);
    X2 = m2000Histo15p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo15p->GetBinContent(i);
    }
    float Fractionm2000Histo15p = Numerator / m2000Histo15p->Integral(0,bins);

    bins = m2000Histo20p->GetNbinsX()+1;
    pointMassBin = m2000Histo20p->FindBin(2000);
    X1 = m2000Histo20p->FindBin(2000*0.90);
    X2 = m2000Histo20p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo20p->GetBinContent(i);
    }
    float Fractionm2000Histo20p = Numerator / m2000Histo20p->Integral(0,bins);

    bins = m2000Histo30p->GetNbinsX()+1;
    pointMassBin = m2000Histo30p->FindBin(2000);
    X1 = m2000Histo30p->FindBin(2000*0.90);
    X2 = m2000Histo30p->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histo30p->GetBinContent(i);
    }
    float Fractionm2000Histo30p = Numerator / m2000Histo30p->Integral(0,bins);

    bins = m2000Histonarrow->GetNbinsX()+1;
    pointMassBin = m2000Histonarrow->FindBin(2000);
    X1 = m2000Histonarrow->FindBin(2000*0.90);
    X2 = m2000Histonarrow->FindBin(2000*1.10);
    Numerator = 0;
    for(int i = X1; i <= X2; i++){
        Numerator = Numerator + m2000Histonarrow->GetBinContent(i);
    }
    float Fractionm2000Histonarrow = Numerator / m2000Histonarrow->Integral(0,bins);

    float x2000[9] = {Fractionm2000Histonarrow , Fractionm2000Histo01p, Fractionm2000Histo02p, Fractionm2000Histo03p, Fractionm2000Histo05p, Fractionm2000Histo10p, Fractionm2000Histo15p, Fractionm2000Histo20p, Fractionm2000Histo30p};

    //Plot TGraph data
    auto a = new TGraph(6, y, x300);
    a->SetTitle("10 Percent Fraction of m_{300}");
    a->GetYaxis()->SetTitle("Fraction");
    //a->GetXaxis()->SetRangeUser(-0.1,1.1);
    a->GetXaxis()->SetTitle("Widths");    
    a->Draw("AC*");
    canvas.Print(pdfFileName.c_str());

    auto b = new TGraph(6, y, x500);
    b->SetTitle("10 Percent Fraction of m_{500}");
    b->GetYaxis()->SetTitle("Fraction");
    //b->GetXaxis()->SetRangeUser(-0.1,1.1);
    b->GetXaxis()->SetTitle("Widths");    
    b->Draw("AC*");
    canvas.Print(pdfFileName.c_str());

    auto c = new TGraph(6, y, x1000);
    c->SetTitle("10 Percent Fraction of m_{1000}");
    c->GetYaxis()->SetTitle("Fraction");
    //c->GetXaxis()->SetRangeUser(-0.1,1.1); 
    c->GetXaxis()->SetTitle("Widths");    
    c->Draw("AC*");
    canvas.Print(pdfFileName.c_str());

    auto d = new TGraph(6, y, x1500);
    d->SetTitle("10 Percent Fraction of m_{1500}");
    d->GetYaxis()->SetTitle("Fraction");
    //d->GetXaxis()->SetRangeUser(-0.1,1.1);
    d->GetXaxis()->SetTitle("Widths");       
    d->Draw("AC*");
    canvas.Print(pdfFileName.c_str());

    auto e = new TGraph(6, y, x2000);
    e->SetTitle("10 Percent Fraction of m_{2000}");
    e->GetYaxis()->SetTitle("Fraction");
    //e->GetXaxis()->SetRangeUser(-0.1,1.1);
    e->GetXaxis()->SetTitle("Widths");    
    e->Draw("AC*");
    canvas.Print(pdfFileName.c_str());

    auto legend3= new TLegend(0.88,0.7,0.68,0.9);

    auto mg = new TMultiGraph();
    mg->SetTitle("Fraction within 10 Percent Point Mass Vs. Variable Width");
    a->SetLineColor(kBlue);
    b->SetLineColor(kRed);
    c->SetLineColor(kBlack);
    d->SetLineColor(kOrange);
    e->SetLineColor(kMagenta);
    mg->Add(a);
    mg->Add(b);
    mg->Add(c);
    mg->Add(d);
    mg->Add(e);
    
    //canvas.Print(pdfFileName.c_str());
    
    legend3->SetHeader("Point Mass","C"); // option "C" allows to center the header
    legend3->AddEntry(a ,"300","l");
    legend3->AddEntry(b ,"500","l");
    legend3->AddEntry(c ,"1000","l");
    legend3->AddEntry(d ,"1500","l");
    legend3->AddEntry(e ,"2000","l");

    mg->Draw("apl");
    legend3->Draw();
    canvas.Print(pdfFileName.c_str());

    canvas.Print(Form("%s]",pdfFileName.c_str())); //Closes plot file

    return 0;
}