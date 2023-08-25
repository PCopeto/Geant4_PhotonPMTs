#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT.hh"

#include "phconstruction.hh"
#include "phphysics.hh"
#include "phaction.hh"
#include "G4SDManager.hh"

#include "phdetector.hh"

#include <iomanip>

int main(int argc, char** argv)
{


  G4RunManager *runManager = new G4RunManager();

  runManager->SetUserInitialization(new MyDetectorConstruction());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());


  runManager->Initialize();

  G4UIExecutive *ui = new G4UIExecutive(argc, argv);

  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();

  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  // UImanager->ApplyCommand("/vis/open OGL");
  // UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
  // UImanager->ApplyCommand("/vis/drawVolume");
  // UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  // UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  // UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate -1");


  ui->SessionStart();


  delete runManager;


  return 0;
}

