#include "EventAction.hh"
#include "G4Event.hh"
#include <fstream>

void EventAction::EndOfEventAction(const G4Event* event) {
    std::ofstream outFile("../data/output.txt", std::ios::app);
    outFile << "Event " << event->GetEventID() << ": data saved" << std::endl;
    outFile.close();
}
