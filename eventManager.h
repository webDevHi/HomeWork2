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

