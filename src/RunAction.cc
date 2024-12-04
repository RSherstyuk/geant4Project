#include "RunAction.hh"
#include "G4Run.hh"
#include <iostream>

void RunAction::BeginOfRunAction(const G4Run*) {
    std::cout << "Run started!" << std::endl;
}

void RunAction::EndOfRunAction(const G4Run*) {
    std::cout << "Run ended!" << std::endl;
}
