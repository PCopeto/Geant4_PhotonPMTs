#include "phevent.hh"

MyEventAction::MyEventAction()
{}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{}

void MyEventAction::EndOfEventAction(const G4Event*)
{

    G4AnalysisManager* man = G4AnalysisManager::Instance();

    // Get the MySensitiveDetector instance
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    MySensitiveDetector* mySensitiveDetector = dynamic_cast<MySensitiveDetector*>(sdManager->FindSensitiveDetector("SensitiveDetector"));

    if (mySensitiveDetector) {
        G4int totalHitsPMT1 = mySensitiveDetector->getHits1();
        G4int totalHitsPMT2 = mySensitiveDetector->getHits2();
        G4int diffHits = totalHitsPMT1 - totalHitsPMT2;

        G4double totalEnergyDepositedPMT1 = mySensitiveDetector->getEnergy1();
        G4double totalEnergyDepositedPMT2 = mySensitiveDetector->getEnergy2();
        G4double diffEnergy = totalEnergyDepositedPMT1 - totalEnergyDepositedPMT2;
        

        // G4cout << "Total Hits on Right PMT: " << totalHitsPMT1 << G4endl;
        // G4cout << "Total Hits on Left PMT: " << totalHitsPMT2 << G4endl;
        // G4cout << "Difference Right-Left: " << diffHits << G4endl;

        man->FillNtupleIColumn(0, totalHitsPMT1);
        man->FillNtupleIColumn(1, totalHitsPMT2);
        man->FillNtupleIColumn(2, diffHits);
        man->FillNtupleDColumn(3, totalEnergyDepositedPMT1);
        man->FillNtupleDColumn(4, totalEnergyDepositedPMT2);
        man->FillNtupleDColumn(5, diffEnergy);


        man->AddNtupleRow(0);

        mySensitiveDetector->ResetHits();
    }
}
