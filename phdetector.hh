#ifndef PHDETECTOR_HH
#define PHDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"


class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();


    G4double getHits1() const {return hits1;}
    G4double getHits2() const {return hits2;}

    void ResetHits() { hits1 = 0; hits2 = 0; }


private:
    // Private attribute
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    // Add a member to store the analysis manager pointer
    G4AnalysisManager* analysisManager;

    G4int hits1;
    G4int hits2;
};

#endif