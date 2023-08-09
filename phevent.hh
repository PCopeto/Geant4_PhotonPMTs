#ifndef PHEVENT_HH
#define PHEVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"

#include "phdetector.hh"

class MyEventAction : public G4UserEventAction
{
public:
    MyEventAction();
    ~MyEventAction();
    
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
};

#endif
