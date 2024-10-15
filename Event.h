#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>

class Event {
protected:
    std::string eventName;
    int eventDay;
    std::vector<std::string> eventFunders;
    std::string eventOrganizer;
    std::vector<std::string> possibleEventOrganizers;

public:
    Event(std::string name, int day, std::string organizer)
        : eventName(name), eventDay(day), eventOrganizer(organizer) {}
    virtual ~Event() {}

    virtual std::string getDetails() const {
        std::string details = "Event: " + eventName + "\n";
        details += "Day: " + std::to_string(eventDay) + "\n";
        details += "Organizer: " + eventOrganizer + "\n";
        details += "Funders: ";
        for (const auto& funder : eventFunders) {
            details += funder + ", ";
        }
        if (!eventFunders.empty()) {
            details = details.substr(0, details.length() - 2);
        }
        return details;
    }

    bool isUpcoming() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentDay = ltm->tm_yday + 1;
        return (eventDay - currentDay >= 0 && eventDay - currentDay <= 7);
    }

    void addFunder(const std::string& funder) {
        eventFunders.push_back(funder);
    }

    void raincheck(int newDay) {
        eventDay = newDay;
    }

    void changeByPopDemand(const std::string& newOrganizer) {
        possibleEventOrganizers.push_back(newOrganizer);
        std::map<std::string, int> votes;
        
        for (const auto& org : possibleEventOrganizers) {
            votes[org]++;
            if (votes[org] > 5) {
                eventOrganizer = org;
                break;
            }
        }
    }

    std::string getName() const { return eventName; }
    int getDay() const { return eventDay; }
    std::string getOrganizer() const { return eventOrganizer; }
};

#endif

