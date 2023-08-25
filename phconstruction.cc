#include "phconstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();

    G4double energy[3] = {1.239841939*eV/0.5, 1.239841939*eV/0.425, 1.239841939*eV/0.4};
    G4double scint[3] = {0.02, 1.0, 0.08};
    G4double rindexScintillator[3] = {1.58, 1.58, 1.58};
    G4double rindexWorld[3] = {1.0, 1.0, 1.0};
    G4double atnl[3] = {380.*cm, 380.*cm, 380.*cm};
    G4double rindexLead[3] = {1.7, 1.7, 1.7};

//Definir Mundo


    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 3);

    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

//Definir Material Cintilador

    G4Material *scintillator = nist->BuildMaterialWithNewDensity("scintillator","G4_PLASTIC_SC_VINYLTOLUENE", 1.023*g/cm3);

    G4MaterialPropertiesTable *mptScintillator = new G4MaterialPropertiesTable();

    //mptScintillator = scintillator->GetMaterialPropertiesTable();

    mptScintillator->AddProperty("SCINTILLATIONCOMPONENT1", energy, scint, 3);
    mptScintillator->AddProperty("RINDEX", energy, rindexScintillator, 3);
    mptScintillator->AddProperty("ABSLENGTH", energy, atnl, 3);
    mptScintillator->AddConstProperty("SCINTILLATIONYIELD", 10000. / MeV);
    mptScintillator->AddConstProperty("RESOLUTIONSCALE", 1.0);
    mptScintillator->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 2.1 * ns);
    mptScintillator->AddConstProperty("SCINTILLATIONRISETIME1", 0.9 * ns);
    mptScintillator->AddConstProperty("SCINTILLATIONYIELD1", 1.0);

    scintillator->SetMaterialPropertiesTable(mptScintillator);
    

//Definir Cintilador

    //G4Box *solidScintillator1 = new G4Box("solidScintillator1", 0.1265*m, 0.05*m, 0.0026*m); //cintilador pequeno
    G4Box *solidScintillator1 = new G4Box("solidScintillator1", 0.158*m, 0.126*m, 0.025*m); //cintilador grande

    G4LogicalVolume* logicScintillator1 = new G4LogicalVolume(solidScintillator1, scintillator, "logicScintillator1");

    G4VPhysicalVolume *physScintillator1 = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicScintillator1, "physScintillator1", logicWorld, false, 0, true);


    G4Material *pmtMat = nist->FindOrBuildMaterial("G4_Pb");

    G4MaterialPropertiesTable *mptPMT = new G4MaterialPropertiesTable();
    mptPMT->AddProperty("RINDEX", energy, rindexLead, 3);

    pmtMat->SetMaterialPropertiesTable(mptPMT);



//Definir PMT Direito

    //G4Box* solidPMT1 = new G4Box("solidPMT1", 0.001*m, 0.025*m, 0.0026*m); //cintilador pequeno
    G4Box* solidPMT1 = new G4Box("solidPMT1", 0.001*m, 0.025*m, 0.025*m); //cintilador grande

    logicPMT1 = new G4LogicalVolume(solidPMT1, pmtMat, "logicPMT1");

    //G4VPhysicalVolume* physPMT1 = new G4PVPlacement(0, G4ThreeVector(0.1275*m, 0., 0.), logicPMT1, "physPMT1", logicWorld, false, 0, true); //cintilador pequeno
    G4VPhysicalVolume* physPMT1 = new G4PVPlacement(0, G4ThreeVector(0.1585*m, 0., 0.), logicPMT1, "physPMT1", logicWorld, false, 0, true); //cintilador grande


//Definir PMT Esquerdo

    //G4Box* solidPMT2 = new G4Box("solidPMT2", 0.001*m, 0.025*m, 0.0026*m); //cintilador pequeno
    G4Box* solidPMT2 = new G4Box("solidPMT2", 0.001*m, 0.025*m, 0.025*m); //cintilador grande

    logicPMT2 = new G4LogicalVolume(solidPMT2, pmtMat, "logicPMT2");

    //G4VPhysicalVolume* physPMT2 = new G4PVPlacement(0, G4ThreeVector(-0.1275*m, 0., 0.), logicPMT2, "physPMT2", logicWorld, false, 0, true); //cintilador pequeno
    G4VPhysicalVolume* physPMT2 = new G4PVPlacement(0, G4ThreeVector(-0.1585*m, 0., 0.), logicPMT2, "physPMT2", logicWorld, false, 0, true); //cintilador grande



    ConstructSDandField();

    return physWorld;
}


void MyDetectorConstruction::ConstructSDandField()
{

    mySensitiveDetector = new MySensitiveDetector("SensitiveDetector");
    logicPMT1->SetSensitiveDetector(mySensitiveDetector);
    logicPMT2->SetSensitiveDetector(mySensitiveDetector);

    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    sdManager->AddNewDetector(mySensitiveDetector);


}