#ifndef PRIMARY_GENERATOR_ACTION_HH
#define PRIMARY_GENERATOR_ACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();
    void GeneratePrimaries(G4Event* event) override;

private:
    G4ParticleGun* particleGun;
};

#endif
