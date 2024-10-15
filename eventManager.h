#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <vector>
#include <memory>
#include "Event.h"

class SearchStrategy {
public:
    virtual ~SearchStrategy() {}
    virtual std::vector<Event*> search(const std::vector<std::unique_ptr<Event>>& events, const std::string& criteria) const = 0;
};

class DaySearchStrategy : public SearchStrategy {
public:
    std::vector<Event*> search(const std::vector<std::unique_ptr<Event>>& events, const std::string& criteria) const override {
        std::vector<Event*> results;
        int searchDay = std::stoi(criteria);
        for (const auto& event : events) {
            if (event->getDay() == searchDay) {
                results.push_back(event.get());
            }
        }
        return results;
    }
};

class OrganizerSearchStrategy : public SearchStrategy {
public:
    std::vector<Event*> search(const std::vector<std::unique_ptr<Event>>& events, const std::string& criteria) const override {
        std::vector<Event*> results;
        for (const auto& event : events) {
            if (event->getOrganizer() == criteria) {
                results.push_back(event.get());
            }
        }
        return results;
    }
};

class EventManager {
private:
    std::vector<std::unique_ptr<Event>> events;
    std::unique_ptr<SearchStrategy> searchStrategy;

public:
    EventManager() : searchStrategy(nullptr) {}

    void addEvent(std::unique_ptr<Event> event);
    void displayAllEvents() const;
    void setSearchStrategy(std::unique_ptr<SearchStrategy> strategy);
    std::vector<Event*> searchEvents(const std::string& criteria) const;
    void addFunderToEvent(const std::string& eventName, const std::string& funder);
    void changeEventDay(const std::string& eventName, int newDay);
    void changeEventOrganizer(const std::string& eventName, const std::string& newOrganizer);
};

#endif
