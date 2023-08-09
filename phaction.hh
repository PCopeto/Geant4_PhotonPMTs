#ifndef PHACTION_HH
#define PHACTION_HH

#include "G4VUserActionInitialization.hh"

#include "phgenerator.hh"
#include "phrun.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
    MyActionInitialization();
    ~MyActionInitialization();

    virtual void Build() const;

};

#endif