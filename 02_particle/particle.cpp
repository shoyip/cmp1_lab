#include <vector>
#include <iostream>

// Visualization
#include "TH1F.h"
#include "TCanvas.h"

// Utilities
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
    double invmass, theta;
    double m_pi = 140; // MeV
    double m_k = 500; // MeV
    double pstar = 2607; // MeV
    double beta = 0.0567;

    TH1F hinvmass("hinvmass", "distribution of the invariant mass", 100, 3600, 3900);
    TH1F htheta("htheta", "distribution of the angle between the momenta", 100, 3., 3.2);

    tree->Branch("p4_pi", &p4_pi, "p4_pi/l");
    tree->Branch("p4_k", &p4_k, "p4_k/l");
    tree->Branch("invmass", &invmass, "invmass/D");
    tree->Branch("theta", &theta, "theta/D");

    TRandom* gen = new TRandom();
    gen->SetSeed(0);

    int nevs=10000;

    for (int iev=0; iev<nevs; iev++) {
        // Generate a random momentum vector with fixed magnitude
        gen->Sphere(px_com, py_com, pz_com, pstar);
        // Set the (+ - - -) signature TLorentzVector with component values
        p4_pi.SetPxPyPzE(px_com, py_com, pz_com, sqrt(m_pi*m_pi + px_com*px_com + py_com*py_com + pz_com*pz_com));
        p4_k.SetPxPyPzE(-px_com, -py_com, -pz_com, sqrt(m_k*m_k + px_com*px_com + py_com*py_com + pz_com*pz_com));
        // Boost the TLorentzVector on the x axis
        p4_pi.Boost(beta, 0, 0);
        p4_k.Boost(beta, 0, 0);
        // Compute the invariant mass and the angle between TLorentzVectors
        invmass = sqrt(p4_pi.M2() + p4_k.M2() + 2.*pstar*pstar);
        theta = p4_pi.Angle(p4_k.Vect());
        // Fill the histogram
        hinvmass.Fill(invmass);
        htheta.Fill(theta);
        // Fill the tree
        tree->Fill();
    }

    TCanvas canv("canv", "canvas for plotting", 1280, 1024);
    hinvmass.GetXaxis()->SetTitle("Invariant mass of the pion and kaon [MeV]");
    hinvmass.Draw();

    canv.SaveAs("./figures/invariant_mass.pdf");

    htheta.GetXaxis()->SetTitle("Angle between the momenta [rad]");
    htheta.Draw();

    canv.SaveAs("./figures/collision_angle.pdf");

    hinvmass.Write();
    htheta.Write();

    tree->Write();
    tree->Print();

    delete tree;
    orootfile->Close();

    delete orootfile;
    delete gen;

    return 0;
}