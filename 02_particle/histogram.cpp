#include <iostream>

#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "TLorentzVector.h"

int main (int argc, char* argv[]) {
    TString rootfname("./data/particle.root");
    TFile* f = new TFile(rootfname, "READ");
    TTree* pt = (TTree*)f->Get("pt");
    TLorentzVector p4_pi, p4_k;

    pt->Print();

    for (int i=0; i < pt->GetEntries(); i++) {
        pt->GetEntry(i);
        std::cout << p4_pi.M() << std::endl;
    }

    delete pt;
    f->Close();
    delete f;
    return 0;
}