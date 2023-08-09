#ifndef PHCONSTRUCTION_HH
#define PHCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"

#include "phdetector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();

private:
    G4LogicalVolume* logicPMT1;
    G4LogicalVolume* logicPMT2;

    MySensitiveDetector* mySensitiveDetector; // Single instance of MySensitiveDetector

    virtual void ConstructSDandField();

}; 

#endif