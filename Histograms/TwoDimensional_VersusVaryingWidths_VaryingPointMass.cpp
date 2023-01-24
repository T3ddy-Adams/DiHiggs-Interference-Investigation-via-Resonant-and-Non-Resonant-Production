//Thomas Adams
//thomas.adams@cern.ch

//To run:
    //root -l "VersusVaryingWidths_VaryingPointMass.cpp()"
    //root -l -b -q "2D_VersusVaryingWidths_VaryingPointMass.cpp()"
        //prevents the bash that pops up and quites root
        //input histogram type you which to look at

#include <iostream>
#include <string>

string outFile(std::string inFileName){
    std::string fileName = inFileName.append("_VaryingWidths.pdf");
    return fileName;
}

string outYaxis(TH2D* myHistogram){
    int width = myHistogram->GetXaxis()->GetBinWidth(10);
    std::string Yaxis = "[GeV]";
    //Yaxis = Yaxis.append(to_string(width));
    //Yaxis = Yaxis.append("[GeV]");
    return Yaxis;
}

int TwoDimensional_VersusVaryingWidths_VaryingPointMass(std::string histogramFile){

    std::string histFileName;
    std::string pdfFileName = outFile(histogramFile);
    
    //m300 mass points
    histFileName = "run_XHH_bbtt_m300_hadhad_05p_5BSM_histogram.root";
    TFile* histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m300Histo05p = (TH2D*)histFile->Get(histogramFile.c_str());
    m300Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m300_hadhad_10p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m300Histo10p = (TH2D*)histFile->Get(histogramFile.c_str());
    m300Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_15p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m300Histo15p = (TH2D*)histFile->Get(histogramFile.c_str());
    m300Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_20p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m300Histo20p = (TH2D*)histFile->Get(histogramFile.c_str());
    m300Histo20p->SetDirectory(0);
    histFile->Close();


    histFileName = "run_XHH_bbtt_m300_hadhad_30p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m300Histo30p = (TH2D*)histFile->Get(histogramFile.c_str());
    m300Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m300_hadhad_narrow_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m300Histonarrow = (TH2D*)histFile->Get(histogramFile.c_str());
    m300Histonarrow->SetDirectory(0);
    histFile->Close();

    TCanvas canvas("Canvas");
    //canvas.SetLogy();
    canvas.cd();

    canvas.Print(Form("%s[",pdfFileName.c_str()));

    auto legend = new TLegend(0.88,0.7,0.68,0.9);

    m300Histo05p->SetStats(0); 
    m300Histo10p->SetStats(0); 
    m300Histo15p->SetStats(0); 
    m300Histo20p->SetStats(0); 
    m300Histo30p->SetStats(0); 
    m300Histonarrow->SetStats(0); 

    m300Histo05p->GetYaxis()->SetTitle(outYaxis(m300Histo05p).c_str());
    m300Histo05p->GetXaxis()->SetTitle(" [GeV]");

    legend->SetHeader("Mass 300, Width 05p","C");
    m300Histo10p->GetYaxis()->SetTitle(outYaxis(m300Histo10p).c_str());
    m300Histo10p->GetXaxis()->SetTitle(" [GeV]");


    m300Histo15p->GetYaxis()->SetTitle(outYaxis(m300Histo15p).c_str());
    m300Histo15p->GetXaxis()->SetTitle(" [GeV]");

    m300Histo20p->GetYaxis()->SetTitle(outYaxis(m300Histo20p).c_str());
    m300Histo20p->GetXaxis()->SetTitle(" [GeV]");

    m300Histo30p->GetYaxis()->SetTitle(outYaxis(m300Histo30p).c_str());
    m300Histo30p->GetXaxis()->SetTitle(" [GeV]");

    m300Histonarrow->GetYaxis()->SetTitle(outYaxis(m300Histonarrow).c_str());
    m300Histonarrow->GetXaxis()->SetTitle(" [GeV]");

    m300Histo05p->Draw("h");
    m300Histo05p->Draw("COLZ");    
    legend->SetHeader("Mass 300, Width 05p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m300Histo10p->Draw("h");
    m300Histo10p->Draw("COLZ");
    legend->SetHeader("Mass 300, Width 10p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m300Histo15p->Draw("h");
    m300Histo15p->Draw("COLZ");
    legend->SetHeader("Mass 300, Width 15p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m300Histo20p->Draw("h");
    m300Histo20p->Draw("COLZ");
    legend->SetHeader("Mass 300, Width 20p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m300Histo30p->Draw("h");
    m300Histo30p->Draw("COLZ");
    legend->SetHeader("Mass 300, Width 30p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m300Histonarrow->Draw("h");
    m300Histonarrow->Draw("COLZ");
    legend->SetHeader("Mass 300, Width narrow","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

        //m300 stacked 
        TH2D* m300Stacked = (TH2D*)m300Histo05p->Clone();
        m300Stacked->Add(m300Histo10p);
        m300Stacked->Add(m300Histo15p);
        m300Stacked->Add(m300Histo20p);
        m300Stacked->Add(m300Histo30p);
        m300Stacked->Add(m300Histonarrow);
        m300Stacked->Draw("h");
        m300Stacked->Draw("COLZ");
        legend->SetHeader("Mass 300, Variable Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());


    //m500 mass points
    histFileName = "run_XHH_bbtt_m500_hadhad_05p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m500Histo05p = (TH2D*)histFile->Get(histogramFile.c_str());
    m500Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m500_hadhad_10p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m500Histo10p = (TH2D*)histFile->Get(histogramFile.c_str());
    m500Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_15p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m500Histo15p = (TH2D*)histFile->Get(histogramFile.c_str());
    m500Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_20p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m500Histo20p = (TH2D*)histFile->Get(histogramFile.c_str());
    m500Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_30p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m500Histo30p = (TH2D*)histFile->Get(histogramFile.c_str());
    m500Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m500_hadhad_narrow_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m500Histonarrow = (TH2D*)histFile->Get(histogramFile.c_str());
    m500Histonarrow->SetDirectory(0);
    histFile->Close();


    m500Histo05p->SetStats(0); 
    m500Histo10p->SetStats(0); 
    m500Histo15p->SetStats(0); 
    m500Histo20p->SetStats(0); 
    m500Histo30p->SetStats(0); 
    m500Histonarrow->SetStats(0); 

    m500Histo05p->GetYaxis()->SetTitle(outYaxis(m500Histo05p).c_str());
    m500Histo05p->GetXaxis()->SetTitle(" [GeV]");

    m500Histo10p->GetYaxis()->SetTitle(outYaxis(m500Histo10p).c_str());
    m500Histo10p->GetXaxis()->SetTitle(" [GeV]");

    m500Histo15p->GetYaxis()->SetTitle(outYaxis(m500Histo15p).c_str());
    m500Histo15p->GetXaxis()->SetTitle(" [GeV]");

    m500Histo20p->GetYaxis()->SetTitle(outYaxis(m500Histo20p).c_str());
    m500Histo20p->GetXaxis()->SetTitle(" [GeV]");

    m500Histo30p->GetYaxis()->SetTitle(outYaxis(m500Histo30p).c_str());
    m500Histo30p->GetXaxis()->SetTitle(" [GeV]");

    m500Histonarrow->GetYaxis()->SetTitle(outYaxis(m500Histonarrow).c_str());
    m500Histonarrow->GetXaxis()->SetTitle(" [GeV]");

    m500Histo05p->Draw("h");
    m500Histo05p->Draw("COLZ");    
    legend->SetHeader("Mass 500, Width 05p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m500Histo10p->Draw("h");
    m500Histo10p->Draw("COLZ");
    legend->SetHeader("Mass 500, Width 10p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m500Histo15p->Draw("h");
    m500Histo15p->Draw("COLZ");
    legend->SetHeader("Mass 500, Width 15p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m500Histo20p->Draw("h");
    m500Histo20p->Draw("COLZ");
    legend->SetHeader("Mass 500, Width 20p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m500Histo30p->Draw("h");
    m500Histo30p->Draw("COLZ");
    legend->SetHeader("Mass 500, Width 30p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m500Histonarrow->Draw("h");
    m500Histonarrow->Draw("COLZ");
    legend->SetHeader("Mass 500, Width narrow","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

            //m500 stacked 
            TH2D* m500Stacked = (TH2D*)m500Histo05p->Clone();
            m500Stacked->Add(m500Histo10p);
            m500Stacked->Add(m500Histo15p);
            m500Stacked->Add(m500Histo20p);
            m500Stacked->Add(m500Histo30p);
            m500Stacked->Add(m500Histonarrow);
            m500Stacked->Draw("h");
            m500Stacked->Draw("COLZ");
            legend->SetHeader("Mass 500, Variable Widths Stacked", "C");
            legend->Draw();
            canvas.Print(pdfFileName.c_str());


    //m1000 mass points
    histFileName = "run_XHH_bbtt_m1000_hadhad_05p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1000Histo05p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1000Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m1000_hadhad_10p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1000Histo10p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1000Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_15p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1000Histo15p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1000Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_20p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1000Histo20p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1000Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_30p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1000Histo30p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1000Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1000_hadhad_narrow_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1000Histonarrow = (TH2D*)histFile->Get(histogramFile.c_str());
    m1000Histonarrow->SetDirectory(0);
    histFile->Close();

    m1000Histo05p->SetStats(0); 
    m1000Histo10p->SetStats(0); 
    m1000Histo15p->SetStats(0); 
    m1000Histo20p->SetStats(0); 
    m1000Histo30p->SetStats(0); 
    m1000Histonarrow->SetStats(0); 

    m1000Histo05p->GetYaxis()->SetTitle(outYaxis(m1000Histo05p).c_str());
    m1000Histo05p->GetXaxis()->SetTitle(" [GeV]");

    m1000Histo10p->GetYaxis()->SetTitle(outYaxis(m1000Histo10p).c_str());
    m1000Histo10p->GetXaxis()->SetTitle(" [GeV]");

    m1000Histo15p->GetYaxis()->SetTitle(outYaxis(m1000Histo15p).c_str());
    m1000Histo15p->GetXaxis()->SetTitle(" [GeV]");

    m1000Histo20p->GetYaxis()->SetTitle(outYaxis(m1000Histo20p).c_str());
    m1000Histo20p->GetXaxis()->SetTitle(" [GeV]");

    m1000Histo30p->GetYaxis()->SetTitle(outYaxis(m1000Histo30p).c_str());
    m1000Histo30p->GetXaxis()->SetTitle(" [GeV]");

    m1000Histonarrow->GetYaxis()->SetTitle(outYaxis(m1000Histonarrow).c_str());
    m1000Histonarrow->GetXaxis()->SetTitle(" [GeV]");

    m1000Histo05p->Draw("h");
    m1000Histo05p->Draw("COLZ");    
    legend->SetHeader("Mass 1000, Width 05p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1000Histo10p->Draw("h");
    m1000Histo10p->Draw("COLZ");
    legend->SetHeader("Mass 1000, Width 10p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1000Histo15p->Draw("h");
    m1000Histo15p->Draw("COLZ");
    legend->SetHeader("Mass 1000, Width 15p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1000Histo20p->Draw("h");
    m1000Histo20p->Draw("COLZ");
    legend->SetHeader("Mass 1000, Width 20p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1000Histo30p->Draw("h");
    m1000Histo30p->Draw("COLZ");
    legend->SetHeader("Mass 1000, Width 30p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1000Histonarrow->Draw("h");
    m1000Histonarrow->Draw("COLZ");
    legend->SetHeader("Mass 1000, Width narrow","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

            //m1000 stacked 
            TH2D* m1000Stacked = (TH2D*)m1000Histo05p->Clone();
            m1000Stacked->Add(m1000Histo10p);
            m1000Stacked->Add(m1000Histo15p);
            m1000Stacked->Add(m1000Histo20p);
            m1000Stacked->Add(m1000Histo30p);
            m1000Stacked->Add(m1000Histonarrow);
            m1000Stacked->Draw("h");
            m1000Stacked->Draw("COLZ");
            legend->SetHeader("Mass 1000, Variable Widths Stacked", "C");
            legend->Draw();
            canvas.Print(pdfFileName.c_str());


    //m1500 mass points
    histFileName = "run_XHH_bbtt_m1500_hadhad_05p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1500Histo05p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1500Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m1500_hadhad_10p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1500Histo10p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1500Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_15p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1500Histo15p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1500Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_20p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1500Histo20p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1500Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m1500_hadhad_30p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1500Histo30p = (TH2D*)histFile->Get(histogramFile.c_str());
    m1500Histo30p->SetDirectory(0);
    histFile->Close();


    histFileName = "run_XHH_bbtt_m1500_hadhad_narrow_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m1500Histonarrow = (TH2D*)histFile->Get(histogramFile.c_str());
    m1500Histonarrow->SetDirectory(0);
    histFile->Close();

    m1500Histo05p->SetStats(0); 
    m1500Histo10p->SetStats(0); 
    m1500Histo15p->SetStats(0); 
    m1500Histo20p->SetStats(0); 
    m1500Histo30p->SetStats(0); 
    m1500Histonarrow->SetStats(0); 

    m1500Histo05p->GetYaxis()->SetTitle(outYaxis(m1500Histo05p).c_str());
    m1500Histo05p->GetXaxis()->SetTitle(" [GeV]");

    m1500Histo10p->GetYaxis()->SetTitle(outYaxis(m1500Histo10p).c_str());
    m1500Histo10p->GetXaxis()->SetTitle(" [GeV]");

    m1500Histo15p->GetYaxis()->SetTitle(outYaxis(m1500Histo15p).c_str());
    m1500Histo15p->GetXaxis()->SetTitle(" [GeV]");

    m1500Histo20p->GetYaxis()->SetTitle(outYaxis(m1500Histo20p).c_str());
    m1500Histo20p->GetXaxis()->SetTitle(" [GeV]");

    m1500Histo30p->GetYaxis()->SetTitle(outYaxis(m1500Histo30p).c_str());
    m1500Histo30p->GetXaxis()->SetTitle(" [GeV]");

    m1500Histonarrow->GetYaxis()->SetTitle(outYaxis(m1500Histonarrow).c_str());
    m1500Histonarrow->GetXaxis()->SetTitle(" [GeV]");

    m1500Histo05p->Draw("h");
    m1500Histo05p->Draw("COLZ");    
    legend->SetHeader("Mass 1500, Width 05p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1500Histo10p->Draw("h");
    m1500Histo10p->Draw("COLZ");
    legend->SetHeader("Mass 1500, Width 10p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1500Histo15p->Draw("h");
    m1500Histo15p->Draw("COLZ");
    legend->SetHeader("Mass 1500, Width 15p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1500Histo20p->Draw("h");
    m1500Histo20p->Draw("COLZ");
    legend->SetHeader("Mass 1500, Width 20p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1500Histo30p->Draw("h");
    m1500Histo30p->Draw("COLZ");
    legend->SetHeader("Mass 1500, Width 30p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m1500Histonarrow->Draw("h");
    m1500Histonarrow->Draw("COLZ");
    legend->SetHeader("Mass 1500, Width narrow","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

            //m1500 stacked 
            TH2D* m1500Stacked = (TH2D*)m1500Histo05p->Clone();
            m1500Stacked->Add(m1500Histo10p);
            m1500Stacked->Add(m1500Histo15p);
            m1500Stacked->Add(m1500Histo20p);
            m1500Stacked->Add(m1500Histo30p);
            m1500Stacked->Add(m1500Histonarrow);
            m1500Stacked->Draw("h");
            m1500Stacked->Draw("COLZ");
            legend->SetHeader("Mass 1500, Variable Widths Stacked", "C");
            legend->Draw();
            canvas.Print(pdfFileName.c_str());

    //m2000 mass points
    histFileName = "run_XHH_bbtt_m2000_hadhad_05p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m2000Histo05p = (TH2D*)histFile->Get(histogramFile.c_str());
    m2000Histo05p->SetDirectory(0);
    histFile->Close();
    
    histFileName = "run_XHH_bbtt_m2000_hadhad_10p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m2000Histo10p = (TH2D*)histFile->Get(histogramFile.c_str());
    m2000Histo10p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_15p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m2000Histo15p = (TH2D*)histFile->Get(histogramFile.c_str());
    m2000Histo15p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_20p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m2000Histo20p = (TH2D*)histFile->Get(histogramFile.c_str());
    m2000Histo20p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_30p_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m2000Histo30p = (TH2D*)histFile->Get(histogramFile.c_str());
    m2000Histo30p->SetDirectory(0);
    histFile->Close();

    histFileName = "run_XHH_bbtt_m2000_hadhad_narrow_5BSM_histogram.root";
    histFile = TFile::Open(histFileName.c_str(),"READ");
    TH2D* m2000Histonarrow = (TH2D*)histFile->Get(histogramFile.c_str());
    m2000Histonarrow->SetDirectory(0);
    histFile->Close();

    m2000Histo05p->SetStats(0); 
    m2000Histo10p->SetStats(0); 
    m2000Histo15p->SetStats(0); 
    m2000Histo20p->SetStats(0); 
    m2000Histo30p->SetStats(0); 
    m2000Histonarrow->SetStats(0); 

    m2000Histo05p->GetYaxis()->SetTitle(outYaxis(m2000Histo05p).c_str());
    m2000Histo05p->GetXaxis()->SetTitle(" [GeV]");

    m2000Histo10p->GetYaxis()->SetTitle(outYaxis(m2000Histo10p).c_str());
    m2000Histo10p->GetXaxis()->SetTitle(" [GeV]");

    m2000Histo15p->GetYaxis()->SetTitle(outYaxis(m2000Histo15p).c_str());
    m2000Histo15p->GetXaxis()->SetTitle(" [GeV]");

    m2000Histo20p->GetYaxis()->SetTitle(outYaxis(m2000Histo20p).c_str());
    m2000Histo20p->GetXaxis()->SetTitle(" [GeV]");

    m2000Histo30p->GetYaxis()->SetTitle(outYaxis(m2000Histo30p).c_str());
    m2000Histo30p->GetXaxis()->SetTitle(" [GeV]");

    m2000Histonarrow->GetYaxis()->SetTitle(outYaxis(m2000Histonarrow).c_str());
    m2000Histonarrow->GetXaxis()->SetTitle(" [GeV]");

    m2000Histo05p->Draw("h");
    m2000Histo05p->Draw("COLZ");    
    legend->SetHeader("Mass 2000, Width 05p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m2000Histo10p->Draw("h");
    m2000Histo10p->Draw("COLZ");
    legend->SetHeader("Mass 2000, Width 10p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m2000Histo15p->Draw("h");
    m2000Histo15p->Draw("COLZ");
    legend->SetHeader("Mass 2000, Width 15p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m2000Histo20p->Draw("h");
    m2000Histo20p->Draw("COLZ");
    legend->SetHeader("Mass 2000, Width 20p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m2000Histo30p->Draw("h");
    m2000Histo30p->Draw("COLZ");
    legend->SetHeader("Mass 2000, Width 30p","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    m2000Histonarrow->Draw("h");
    m2000Histonarrow->Draw("COLZ");
    legend->SetHeader("Mass 2000, Width narrow","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

            //m2000 stacked 
            TH2D* m2000Stacked = (TH2D*)m2000Histo05p->Clone();
            m2000Stacked->Add(m2000Histo10p);
            m2000Stacked->Add(m2000Histo15p);
            m2000Stacked->Add(m2000Histo20p);
            m2000Stacked->Add(m2000Histo30p);
            m2000Stacked->Add(m2000Histonarrow);
            m2000Stacked->Draw("h");
            m2000Stacked->Draw("COLZ");
            legend->SetHeader("Mass 2000, Variable Widths Stacked", "C");
            legend->Draw();
            canvas.Print(pdfFileName.c_str());

    //Widths with varying point masses
    legend = new TLegend(0.88,0.7,0.68,0.9);

    //5% width stacked

        TH2D* p05Stacked = (TH2D*)m300Histo05p->Clone();
        p05Stacked->Add(m500Histo05p);
        p05Stacked->Add(m1000Histo05p);
        p05Stacked->Add(m1500Histo05p);
        p05Stacked->Add(m2000Histo05p);
        p05Stacked->Draw("h");
        p05Stacked->Draw("COLZ");
        legend->SetHeader("Variable Mass, 05p Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());

    //10% width stacked

        TH2D* p10Stacked = (TH2D*)m300Histo10p->Clone();
        p10Stacked->Add(m500Histo10p);
        p10Stacked->Add(m1000Histo10p);
        p10Stacked->Add(m1500Histo10p);
        p10Stacked->Add(m2000Histo10p);
        p10Stacked->Draw("h");
        p10Stacked->Draw("COLZ");
        legend->SetHeader("Variable Mass, 10p Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());

    //15% width

        TH2D* p15Stacked = (TH2D*)m300Histo15p->Clone();
        p15Stacked->Add(m500Histo15p);
        p15Stacked->Add(m1000Histo15p);
        p15Stacked->Add(m1500Histo15p);
        p15Stacked->Add(m2000Histo15p);
        p15Stacked->Draw("h");
        p15Stacked->Draw("COLZ");
        legend->SetHeader("Variable Mass, 15p Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());

    //20% width

        TH2D* p20pStacked = (TH2D*)m300Histo20p->Clone();
        p20pStacked->Add(m500Histo20p);
        p20pStacked->Add(m1000Histo20p);
        p20pStacked->Add(m1500Histo20p);
        p20pStacked->Add(m2000Histo20p);
        p20pStacked->Draw("h");
        p20pStacked->Draw("COLZ");
        legend->SetHeader("Variable Mass, 20p Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());

    //30% width

         TH2D* p30pStacked = (TH2D*)m300Histo30p->Clone();
        p30pStacked->Add(m500Histo30p);
        p30pStacked->Add(m1000Histo30p);
        p30pStacked->Add(m1500Histo30p);
        p30pStacked->Add(m2000Histo30p);
        p30pStacked->Draw("h");
        p30pStacked->Draw("COLZ");
        legend->SetHeader("Variable Mass, 30p Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());

    //narrow width

        TH2D* narrowStacked = (TH2D*)m300Histonarrow->Clone();
        narrowStacked->Add(m500Histonarrow);
        narrowStacked->Add(m1000Histonarrow);
        narrowStacked->Add(m1500Histonarrow);
        narrowStacked->Add(m2000Histonarrow);
        narrowStacked->Draw("h");
        narrowStacked->Draw("COLZ");
        legend->SetHeader("Variable Mass, narrow Widths Stacked", "C");
        legend->Draw();
        canvas.Print(pdfFileName.c_str());

    canvas.Print(Form("%s]",pdfFileName.c_str())); //Closes plot file

    return 0;
}
