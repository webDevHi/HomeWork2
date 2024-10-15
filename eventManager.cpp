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
