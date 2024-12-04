#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();

    // Материалы
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* lead = nist->FindOrBuildMaterial("G4_Pb");

    // Мировой объем
    G4Box* worldBox = new G4Box("World", 1.0 * m, 1.0 * m, 1.0 * m);
    G4LogicalVolume* worldLogic = new G4LogicalVolume(worldBox, air, "World");
    G4VPhysicalVolume* worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLogic, "World", 0, false, 0);

    // Пластина
    G4Box* plateBox = new G4Box("Plate", 10.0 * cm, 10.0 * cm, 1.0 * cm);
    G4LogicalVolume* plateLogic = new G4LogicalVolume(plateBox, lead, "Plate");
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), plateLogic, "Plate", worldLogic, false, 0);

    return worldPhys;
}
