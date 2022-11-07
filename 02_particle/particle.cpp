#include <vector>
#include <iostream>

#include "TRandom.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"


int main (int argc, char* argv[]) {
    TString rootfname("./data/particle.root");
    TFile* orootfile = new TFile(rootfname, "RECREATE");
    if (!orootfile->IsOpen()) {       
        std::cout << "Problem opening file." << std::endl;
        exit(-1);
    }
    std::cout << "Storing output in root file" << std::endl;

    // Create TTree
    TTree* tree = new TTree("pt", "Tree containing our particle data");

    TLorentzVector p4_pi, p4_k;
    double px_com, py_com, pz_com;
    double m_pi = 140; // MeV
    double m_k = 500; // MeV
    double pstar = 2607; // MeV
    double beta = 0.0567;

    tree->Branch("p4_pi", &p4_pi, "p4_pi/l");
    tree->Branch("p4_k", &p4_k, "p4_k/l");

    TRandom* gen = new TRandom();
    gen->SetSeed(0);

    int nevs=400000;

    for (int iev=0; iev<nevs; iev++) {
        gen->Sphere(px_com, py_com, pz_com, pstar);
        p4_pi.SetPxPyPzE(px_com, py_com, pz_com, sqrt(m_pi*m_pi + px_com*px_com + py_com*py_com + pz_com*pz_com));
        p4_k.SetPxPyPzE(-px_com, -py_com, -pz_com, sqrt(m_k*m_k + px_com*px_com + py_com*py_com + pz_com*pz_com));
        p4_pi.Boost(beta, 0, 0);
        p4_k.Boost(beta, 0, 0);
        tree->Fill();
    }

    tree->Write();
    tree->Print();

    delete tree;
    orootfile->Close();

    delete orootfile;
    delete gen;

    return 0;
}