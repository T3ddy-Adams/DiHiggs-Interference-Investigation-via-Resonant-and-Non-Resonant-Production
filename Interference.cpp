//Thomas Adams
//thomas.adams@cern.ch

#include <iostream>
#include <string>

string outYaxis(TH1D* myHistogram){
    int width = myHistogram->GetXaxis()->GetBinWidth(10);
    std::string Yaxis = "Events/";
    Yaxis = Yaxis.append(to_string(width));
    Yaxis = Yaxis.append("[GeV]");
    return Yaxis;
}

int Interference(std::string histogramFile ){

    std::string histFileName;
    std::string pdfFileName = "InterferencePlots.pdf";

    //m300
        //HH_0SM
        histFileName = "run_XHH_bbtt_m300_hadhad_narrow_0SM_histogram.root";
        TFile* histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m300Histonarrow_0SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m300Histonarrow_0SM->SetDirectory(0);
        histFile->Close();

        //HH_SM
        histFileName = "run_XHH_bbtt_m300_hadhad_narrow_SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m300Histonarrow_SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m300Histonarrow_SM->SetDirectory(0);
        histFile->Close();

        //HH_nom
        histFileName = "run_XHH_bbtt_m300_hadhad_narrow_nom_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m300Histonarrow_nom = (TH1D*)histFile->Get(histogramFile.c_str());
        m300Histonarrow_nom->SetDirectory(0);
        histFile->Close();

    //m500
        //HH_0SM
        histFileName = "run_XHH_bbtt_m500_hadhad_narrow_0SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m500Histonarrow_0SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m500Histonarrow_0SM->SetDirectory(0);
        histFile->Close();

        //HH_SM
        histFileName = "run_XHH_bbtt_m500_hadhad_narrow_SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m500Histonarrow_SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m500Histonarrow_SM->SetDirectory(0);
        histFile->Close();

        //HH_nom
        histFileName = "run_XHH_bbtt_m500_hadhad_narrow_nom_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m500Histonarrow_nom = (TH1D*)histFile->Get(histogramFile.c_str());
        m500Histonarrow_nom->SetDirectory(0);
        histFile->Close();

    //m1000
        //HH_0SM
        histFileName = "run_XHH_bbtt_m1000_hadhad_narrow_0SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m1000Histonarrow_0SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m1000Histonarrow_0SM->SetDirectory(0);
        histFile->Close();

        //HH_SM
        histFileName = "run_XHH_bbtt_m1000_hadhad_narrow_SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m1000Histonarrow_SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m1000Histonarrow_SM->SetDirectory(0);
        histFile->Close();

        //HH_nom
        histFileName = "run_XHH_bbtt_m1000_hadhad_narrow_nom_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m1000Histonarrow_nom = (TH1D*)histFile->Get(histogramFile.c_str());
        m1000Histonarrow_nom->SetDirectory(0);
        histFile->Close();

    //m1500
        //HH_0SM
        histFileName = "run_XHH_bbtt_m1500_hadhad_narrow_0SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m1500Histonarrow_0SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m1500Histonarrow_0SM->SetDirectory(0);
        histFile->Close();

        //HH_SM
        histFileName = "run_XHH_bbtt_m1500_hadhad_narrow_SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m1500Histonarrow_SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m1500Histonarrow_SM->SetDirectory(0);
        histFile->Close();

        //HH_nom
        histFileName = "run_XHH_bbtt_m1500_hadhad_narrow_nom_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m1500Histonarrow_nom = (TH1D*)histFile->Get(histogramFile.c_str());
        m1500Histonarrow_nom->SetDirectory(0);
        histFile->Close();

    //m2000
        //HH_0SM
        histFileName = "run_XHH_bbtt_m2000_hadhad_narrow_0SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m2000Histonarrow_0SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m2000Histonarrow_0SM->SetDirectory(0);
        histFile->Close();

        //HH_SM
        histFileName = "run_XHH_bbtt_m2000_hadhad_narrow_SM_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m2000Histonarrow_SM = (TH1D*)histFile->Get(histogramFile.c_str());
        m2000Histonarrow_SM->SetDirectory(0);
        histFile->Close();

        //HH_nom
        histFileName = "run_XHH_bbtt_m2000_hadhad_narrow_nom_histogram.root";
        histFile = TFile::Open(histFileName.c_str(),"READ");
        TH1D* m2000Histonarrow_nom = (TH1D*)histFile->Get(histogramFile.c_str());
        m2000Histonarrow_nom->SetDirectory(0);
        histFile->Close();

    TCanvas canvas("Canvas");
    canvas.SetLogy();
    canvas.cd();

    canvas.Print(Form("%s[",pdfFileName.c_str()));

    auto legend = new TLegend(0.88,0.7,0.68,0.9);

    m300Histonarrow_0SM->SetStats(0);
    m300Histonarrow_SM->SetStats(0);
    m300Histonarrow_nom->SetStats(0);

    m500Histonarrow_0SM->SetStats(0);
    m500Histonarrow_SM->SetStats(0);
    m500Histonarrow_nom->SetStats(0);

    m1000Histonarrow_0SM->SetStats(0);
    m1000Histonarrow_SM->SetStats(0);
    m1000Histonarrow_nom->SetStats(0);

    m1500Histonarrow_0SM->SetStats(0);
    m1500Histonarrow_SM->SetStats(0);
    m1500Histonarrow_nom->SetStats(0);

    m2000Histonarrow_0SM->SetStats(0);
    m2000Histonarrow_SM->SetStats(0);
    m2000Histonarrow_nom->SetStats(0);

    //m300
    m300Histonarrow_nom->Scale(2);
    m300Histonarrow_nom->SetLineColor(kBlue);
    m300Histonarrow_nom->GetYaxis()->SetTitle(outYaxis(m300Histonarrow_nom).c_str());
    m300Histonarrow_nom->GetXaxis()->SetTitle("[GeV]");
    double Xmin = m300Histonarrow_nom->GetXaxis()->GetXmin();
    double Xmax = m300Histonarrow_nom->GetXaxis()->GetXmax();
    double Ymin = 0.1;
    double Ymax = m300Histonarrow_nom->GetMaximum();
    m300Histonarrow_nom->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histonarrow_nom->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    TH1D* m300Histonarrow_0SM_SM = (TH1D*)m300Histonarrow_0SM->Clone();
    m300Histonarrow_0SM_SM->Add(m300Histonarrow_SM);
    m300Histonarrow_0SM_SM->SetLineColor(kRed);
    m300Histonarrow_0SM_SM->GetYaxis()->SetTitle(outYaxis(m300Histonarrow_0SM_SM).c_str());
    m300Histonarrow_0SM_SM->GetXaxis()->SetTitle("[GeV]");
    Xmin = m300Histonarrow_0SM_SM->GetXaxis()->GetXmin();
    Xmax = m300Histonarrow_0SM_SM->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m300Histonarrow_0SM_SM->GetMaximum();
    m300Histonarrow_0SM_SM->SetAxisRange(Xmin, 5*Xmax, "X");
    m300Histonarrow_0SM_SM->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m300Histonarrow_nom->Draw("h");
    m300Histonarrow_0SM_SM->Draw("h,same");

    legend->SetHeader("300 point mass Interference","C");
    legend->AddEntry(m300Histonarrow_0SM_SM, "0SM + SM", "l");
    legend->AddEntry(m300Histonarrow_nom, "nom", "l");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());


    //m500
    m500Histonarrow_nom->Scale(2);
    m500Histonarrow_nom->SetLineColor(kBlue);
    m500Histonarrow_nom->GetYaxis()->SetTitle(outYaxis(m500Histonarrow_nom).c_str());
    m500Histonarrow_nom->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histonarrow_nom->GetXaxis()->GetXmin();
    Xmax = m500Histonarrow_nom->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m500Histonarrow_nom->GetMaximum();
    m500Histonarrow_nom->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histonarrow_nom->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    TH1D* m500Histonarrow_0SM_SM = (TH1D*)m500Histonarrow_0SM->Clone();
    m500Histonarrow_0SM_SM->Add(m500Histonarrow_SM);
    m500Histonarrow_0SM_SM->SetLineColor(kRed);
    m500Histonarrow_0SM_SM->GetYaxis()->SetTitle(outYaxis(m500Histonarrow_0SM_SM).c_str());
    m500Histonarrow_0SM_SM->GetXaxis()->SetTitle("[GeV]");
    Xmin = m500Histonarrow_0SM_SM->GetXaxis()->GetXmin();
    Xmax = m500Histonarrow_0SM_SM->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m500Histonarrow_0SM_SM->GetMaximum();
    m500Histonarrow_0SM_SM->SetAxisRange(Xmin, 5*Xmax, "X");
    m500Histonarrow_0SM_SM->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m500Histonarrow_nom->Draw("h");
    m500Histonarrow_0SM_SM->Draw("h,same");

    legend->SetHeader("500 point mass Interference","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    //m1000
    m1000Histonarrow_nom->Scale(2);
    m1000Histonarrow_nom->SetLineColor(kBlue);
    m1000Histonarrow_nom->GetYaxis()->SetTitle(outYaxis(m1000Histonarrow_nom).c_str());
    m1000Histonarrow_nom->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histonarrow_nom->GetXaxis()->GetXmin();
    Xmax = m1000Histonarrow_nom->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m1000Histonarrow_nom->GetMaximum();
    m1000Histonarrow_nom->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histonarrow_nom->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    TH1D* m1000Histonarrow_0SM_SM = (TH1D*)m1000Histonarrow_0SM->Clone();
    m1000Histonarrow_0SM_SM->Add(m1000Histonarrow_SM);
    m1000Histonarrow_0SM_SM->SetLineColor(kRed);
    m1000Histonarrow_0SM_SM->GetYaxis()->SetTitle(outYaxis(m1000Histonarrow_0SM_SM).c_str());
    m1000Histonarrow_0SM_SM->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1000Histonarrow_0SM_SM->GetXaxis()->GetXmin();
    Xmax = m1000Histonarrow_0SM_SM->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m1000Histonarrow_0SM_SM->GetMaximum();
    m1000Histonarrow_0SM_SM->SetAxisRange(Xmin, 5*Xmax, "X");
    m1000Histonarrow_0SM_SM->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m1000Histonarrow_nom->Draw("h");
    m1000Histonarrow_0SM_SM->Draw("h,same");

    legend->SetHeader("1000 point mass Interference","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    //m1500
    m1500Histonarrow_nom->Scale(2);
    m1500Histonarrow_nom->SetLineColor(kBlue);
    m1500Histonarrow_nom->GetYaxis()->SetTitle(outYaxis(m1500Histonarrow_nom).c_str());
    m1500Histonarrow_nom->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histonarrow_nom->GetXaxis()->GetXmin();
    Xmax = m1500Histonarrow_nom->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m1500Histonarrow_nom->GetMaximum();
    m1500Histonarrow_nom->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histonarrow_nom->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    TH1D* m1500Histonarrow_0SM_SM = (TH1D*)m1500Histonarrow_0SM->Clone();
    m1500Histonarrow_0SM_SM->Add(m1500Histonarrow_SM);
    m1500Histonarrow_0SM_SM->SetLineColor(kRed);
    m1500Histonarrow_0SM_SM->GetYaxis()->SetTitle(outYaxis(m1500Histonarrow_0SM_SM).c_str());
    m1500Histonarrow_0SM_SM->GetXaxis()->SetTitle("[GeV]");
    Xmin = m1500Histonarrow_0SM_SM->GetXaxis()->GetXmin();
    Xmax = m1500Histonarrow_0SM_SM->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m1500Histonarrow_0SM_SM->GetMaximum();
    m1500Histonarrow_0SM_SM->SetAxisRange(Xmin, 5*Xmax, "X");
    m1500Histonarrow_0SM_SM->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m1500Histonarrow_nom->Draw("h");
    m1500Histonarrow_0SM_SM->Draw("h,same");

    legend->SetHeader("1500 point mass Interference","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    //m2000
    m2000Histonarrow_nom->Scale(2);
    m2000Histonarrow_nom->SetLineColor(kBlue);
    m2000Histonarrow_nom->GetYaxis()->SetTitle(outYaxis(m2000Histonarrow_nom).c_str());
    m2000Histonarrow_nom->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histonarrow_nom->GetXaxis()->GetXmin();
    Xmax = m2000Histonarrow_nom->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m2000Histonarrow_nom->GetMaximum();
    m2000Histonarrow_nom->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histonarrow_nom->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    TH1D* m2000Histonarrow_0SM_SM = (TH1D*)m2000Histonarrow_0SM->Clone();
    m2000Histonarrow_0SM_SM->Add(m2000Histonarrow_SM);
    m2000Histonarrow_0SM_SM->SetLineColor(kRed);
    m2000Histonarrow_0SM_SM->GetYaxis()->SetTitle(outYaxis(m2000Histonarrow_0SM_SM).c_str());
    m2000Histonarrow_0SM_SM->GetXaxis()->SetTitle("[GeV]");
    Xmin = m2000Histonarrow_0SM_SM->GetXaxis()->GetXmin();
    Xmax = m2000Histonarrow_0SM_SM->GetXaxis()->GetXmax();
    Ymin = 0.1;
    Ymax = m2000Histonarrow_0SM_SM->GetMaximum();
    m2000Histonarrow_0SM_SM->SetAxisRange(Xmin, 5*Xmax, "X");
    m2000Histonarrow_0SM_SM->SetAxisRange(Ymin, 1.4*Ymax, "Y");

    m2000Histonarrow_nom->Draw("h");
    m2000Histonarrow_0SM_SM->Draw("h,same");

    legend->SetHeader("2000 point mass Interference","C");
    legend->Draw();
    canvas.Print(pdfFileName.c_str());

    //ratio plot

    auto legend2 = new TLegend(0.88,0.7,0.68,0.9);

    TH1D* m300Histonarrow_ratio = (TH1D*)m300Histonarrow_0SM_SM->Clone();
    m300Histonarrow_ratio->Divide(m300Histonarrow_nom);
    m300Histonarrow_ratio->SetLineColor(kBlue);
    m300Histonarrow_ratio->GetYaxis()->SetTitle("Ratio [(0SM+SM)/nom]");

    TH1D* m500Histonarrow_ratio = (TH1D*)m500Histonarrow_0SM_SM->Clone();
    m500Histonarrow_ratio->Divide(m500Histonarrow_nom);
    m500Histonarrow_ratio->SetLineColor(kMagenta);
    m500Histonarrow_ratio->GetYaxis()->SetTitle("Ratio [(0SM+SM)/nom]");


    TH1D* m1000Histonarrow_ratio = (TH1D*)m1000Histonarrow_0SM_SM->Clone();
    m1000Histonarrow_ratio->Divide(m1000Histonarrow_nom);
    m1000Histonarrow_ratio->SetLineColor(kRed);
    m1000Histonarrow_ratio->GetYaxis()->SetTitle("Ratio [(0SM+SM)/nom]");


    TH1D* m1500Histonarrow_ratio = (TH1D*)m1500Histonarrow_0SM_SM->Clone();
    m1500Histonarrow_ratio->Divide(m1500Histonarrow_nom);
    m1500Histonarrow_ratio->SetLineColor(kBlack);
    m1500Histonarrow_ratio->GetYaxis()->SetTitle("Ratio [(0SM+SM)/nom]");


    TH1D* m2000Histonarrow_ratio = (TH1D*)m2000Histonarrow_0SM_SM->Clone();
    m2000Histonarrow_ratio->Divide(m2000Histonarrow_nom);
    m2000Histonarrow_ratio->SetLineColor(kCyan+2);
    m2000Histonarrow_ratio->GetYaxis()->SetTitle("Ratio [(0SM+SM)/nom]");


    m300Histonarrow_ratio->Draw("h");
    m500Histonarrow_ratio->Draw("h,same");
    m1000Histonarrow_ratio->Draw("h,same");
    m1500Histonarrow_ratio->Draw("h,same");
    m2000Histonarrow_ratio->Draw("h,same");

    legend2->SetHeader("Ratio (0SM+SM)/nom","C");
    legend2->AddEntry(m300Histonarrow_ratio, "300 Point Mass", "l");
    legend2->AddEntry(m500Histonarrow_ratio, "500 Point Mass", "l");
    legend2->AddEntry(m1000Histonarrow_ratio, "1000 Point Mass", "l");
    legend2->AddEntry(m1500Histonarrow_ratio, "1500 Point Mass", "l");
    legend2->AddEntry(m2000Histonarrow_ratio, "2000 Point Mass", "l");
    legend2->Draw();
    canvas.Print(pdfFileName.c_str());
    
    canvas.Print(Form("%s]",pdfFileName.c_str())); //Closes plot file

    return 0;
}