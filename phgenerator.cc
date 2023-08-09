#include "phgenerator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName="muon";
    G4ParticleDefinition *particle = particleTable->FindParticle("mu-");

    //G4ThreeVector pos(-0.06325*m, 0., 0.5*m); //beam left side
    G4ThreeVector pos(0., 0., 0.5*m); //beam center
    //G4ThreeVector pos(0.06325*m, 0., 0.5*m); //beam right side
    G4ThreeVector mom(0., 0., -1.);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(5.*GeV);
    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->GeneratePrimaryVertex(anEvent);
}