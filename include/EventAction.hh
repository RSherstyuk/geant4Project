#ifndef EVENT_ACTION_HH
#define EVENT_ACTION_HH

#include "G4UserEventAction.hh"

class EventAction : public G4UserEventAction {
public:
    EventAction() {}
    virtual ~EventAction() {}
    virtual void EndOfEventAction(const G4Event*);
};

#endif
