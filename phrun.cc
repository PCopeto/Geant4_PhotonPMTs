#include "phrun.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{
    delete eventAction;
}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();


    man->OpenFile("phoutput.root");

    man->SetVerboseLevel(1);
    man->SetNtupleMerging(1); 
    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("HitsRightPMT");
    man->CreateNtupleIColumn("HitsLeftPMT");
    man->CreateNtupleIColumn("DifferenceRightLeft");
    man->CreateNtupleDColumn("EnergyDepositedRightPMT");
    man->CreateNtupleDColumn("EnergyDepositedLeftPMT");
    man->CreateNtupleDColumn("DifferenceEnergyDepositedRightLeft");



    
    man->FinishNtuple(0);

}

void MyRunAction::EndOfRunAction(const G4Run*)
{
   

    G4AnalysisManager* man = G4AnalysisManager::Instance();



    man->Write();
    man->CloseFile();

}