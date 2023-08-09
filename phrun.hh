#ifndef PHRUN_HH
#define PHRUN_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4VSensitiveDetector.hh"
#include "G4VUserActionInitialization.hh"


#include "G4AnalysisManager.hh"
#include "G4SDManager.hh"

#include "phconstruction.hh"

#include "phdetector.hh"
#include "phevent.hh"


class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
    

private:
    MyEventAction* eventAction;
};

#endif