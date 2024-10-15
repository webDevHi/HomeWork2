#ifndef CONCERT_H
#define CONCERT_H

#include "Event.h"

class Concert : public Event {
private:
    std::string bandName;
    std::string genre;

public:
    Concert(std::string name, int day, std::string organizer, std::string band, std::string gen)
        : Event(name, day, organizer), bandName(band), genre(gen) {}

    std::string getDetails() const override {
        return Event::getDetails() + "\nType: Concert\n"
               "Band: " + bandName + "\n"
               "Genre: " + genre;
    }

    std::string getBandName() const { return bandName; }
    std::string getGenre() const { return genre; }
};

class ConcertCreator : public EventCreator {
public:
    std::unique_ptr<Event> createEvent(const std::string& name, int day, const std::string& location) const override {
        return std::make_unique<Concert>(name, day, "Default Organizer", "The Band", "Rock");
    }
};

#endif
