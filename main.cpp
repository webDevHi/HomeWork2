#include <iostream>
#include <memory>
#include <map>
#include "eventManager.h"
#include "Workshop.h"
#include "concert.h"

int main() {
    EventManager manager;
    std::map<int, std::unique_ptr<EventCreator>> creators;
    creators[1] = std::make_unique<WorkshopCreator>();
    creators[2] = std::make_unique<ConcertCreator>();
    
    while (true) {
        std::cout << "\n1. Add Event\n2. Display All Events\n3. Search Events\n"
                  << "4. Add Funder to Event\n5. Change Event Day\n"
                  << "6. Change Event Organizer\n7. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string name, location;
            int day, type;
            
            std::cout << "Enter event name: ";
            std::getline(std::cin, name);
            std::cout << "Enter event day (1-365): ";
            std::cin >> day;
            std::cin.ignore();
            std::cout << "Enter event location: ";
            std::getline(std::cin, location);
            std::cout << "Enter event type (1 for Workshop, 2 for Concert): ";
            std::cin >> type;

            auto creatorIt = creators.find(type);
            if (creatorIt != creators.end()) {
                auto event = creatorIt->second->createEvent(name, day, location);
                manager.addEvent(std::move(event));
                std::cout << "Event added successfully!\n";
            } else {
                std::cout << "Invalid event type.\n";
            }
        } else if (choice == 2) {
            manager.displayAllEvents();
        } else if (choice == 3) {
            std::cout << "Select search criteria:\n1. Day\n2. Organizer\n";
            int searchChoice;
            std::cin >> searchChoice;
            std::cin.ignore();

            std::string criteria;
            std::cout << "Enter search criteria: ";
            std::getline(std::cin, criteria);

            if (searchChoice == 1) {
                manager.setSearchStrategy(std::make_unique<DaySearchStrategy>());
            } else if (searchChoice == 2) {
                manager.setSearchStrategy(std::make_unique<OrganizerSearchStrategy>());
            } else {
                std::cout << "Invalid search choice.\n";
                continue;
            }

            auto results = manager.searchEvents(criteria);
            std::cout << "Search results:\n";
            for (const auto& event : results) {
                std::cout << event->getDetails() << "\n\n";
            }
        } else if (choice == 4) {
            std::string eventName, funder;
            std::cout << "Enter event name: ";
            std::getline(std::cin, eventName);
            std::cout << "Enter funder name: ";
            std::getline(std::cin, funder);
            manager.addFunderToEvent(eventName, funder);
        } else if (choice == 5) {
            std::string eventName;
            int newDay;
            std::cout << "Enter event name: ";
            std::getline(std::cin, eventName);
            std::cout << "Enter new day (1-365): ";
            std::cin >> newDay;
            manager.changeEventDay(eventName, newDay);
        } else if (choice == 6) {
            std::string eventName, newOrganizer;
            std::cout << "Enter event name: ";
            std::getline(std::cin, eventName);
            std::cout << "Enter new organizer: ";
            std::getline(std::cin, newOrganizer);
            manager.changeEventOrganizer(eventName, newOrganizer);
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

