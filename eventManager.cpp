#include "EventManager.h"
#include <iostream>

void EventManager::addEvent(std::unique_ptr<Event> event) {
    events.push_back(std::move(event));
}

void EventManager::displayAllEvents() const {
    for (const auto& event : events) {
        std::cout << event->getDetails() << "\n\n";
    }
}

void EventManager::setSearchStrategy(std::unique_ptr<SearchStrategy> strategy) {
    searchStrategy = std::move(strategy);
}

std::vector<Event*> EventManager::searchEvents(const std::string& criteria) const {
    if (searchStrategy) {
        return searchStrategy->search(events, criteria);
    }
    return {};
}

void EventManager::addFunderToEvent(const std::string& eventName, const std::string& funder) {
    for (auto& event : events) {
        if (event->getName() == eventName) {
            event->addFunder(funder);
            return;
        }
    }
    std::cout << "Event not found.\n";
}

void EventManager::changeEventDay(const std::string& eventName, int newDay) {
    for (auto& event : events) {
        if (event->getName() == eventName) {
            event->raincheck(newDay);
            return;
        }
    }
    std::cout << "Event not found.\n";
}

void EventManager::changeEventOrganizer(const std::string& eventName, const std::string& newOrganizer) {
    for (auto& event : events) {
        if (event->getName() == eventName) {
            event->changeByPopDemand(newOrganizer);
            return;
        }
    }
    std::cout << "Event not found.\n";
}
