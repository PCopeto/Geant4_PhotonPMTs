#include "phdetector.hh"




MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name), hits1(0), hits2(0), totalEnergyPMT1(0.0), totalEnergyPMT2(0.0)
{}

MySensitiveDetector::~MySensitiveDetector()
{}



G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{


    G4Track *track = aStep->GetTrack();

    //track->SetTrackStatus(fStopAndKill);

    // G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    // G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

    // G4ThreeVector posPhoton = preStepPoint->GetPosition();

    //G4cout << "Photon position: " << posPhoton << G4endl;

    // const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

    // G4int copyNo = touchable->GetCopyNumber();

    //G4cout << "Copy number: " << copyNo << G4endl;


    // G4VPhysicalVolume *physVol = touchable->GetVolume();
    G4String volName = aStep->GetTrack()->GetTouchable()->GetVolume()->GetName();
    // G4ThreeVector posDetector = physVol->GetTranslation();

    // G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4String particleName = track->GetParticleDefinition()->GetParticleName();
    G4double energy = aStep->GetTotalEnergyDeposit();
    //G4double energy = track->GetTotalEnergy();


 
    // G4cout << "Particle Name: " << particleName << G4endl;
    // G4cout << "Volume name: " << volName << G4endl;
    // G4cout << "Energy deposited: " << energy << G4endl;
    // G4cout << "" << G4endl;




    if (volName == "physPMT1") {
        hits1 += 1;
        totalEnergyPMT1 += energy;

    } 
    else if (volName == "physPMT2") {
        hits2 += 1;
        totalEnergyPMT2 += energy;


    }


    return true;

}
