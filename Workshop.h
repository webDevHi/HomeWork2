#ifndef WORKSHOP_H
#define WORKSHOP_H

#include "Event.h"

class Workshop : public Event {
private:
    int duration;
    std::string instructor;

public:
    Workshop(std::string name, int day, std::string organizer, int dur, std::string inst)
        : Event(name, day, organizer), duration(dur), instructor(inst) {}

    std::string getDetails() const override {
        return Event::getDetails() + "\nType: Workshop\n"
               "Duration: " + std::to_string(duration) + " hours\n"
               "Instructor: " + instructor;
    }

    int getDuration() const { return duration; }
    std::string getInstructor() const { return instructor; }
};

class WorkshopCreator : public EventCreator {
public:
    std::unique_ptr<Event> createEvent(const std::string& name, int day, const std::string& location) const override {
        return std::make_unique<Workshop>(name, day, "Default Organizer", 3, "John Doe");
    }
};

#endif

