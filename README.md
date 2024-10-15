# HomeWork2

#instructions
cd into project directory,
type 'make run' in terminal

#documentation
In homework 2 I created an event management system for creating, managing, and searching for different events types like concerts and workshops. To have these event types, I implement inheritance. My base class event is inherited by other event types like concerts and workshops. The basic things that every event has are in the base class 'event', and in the child classes we override the basic functions and variables for the specific event type. So for example, I may override getDetails() so depending on the event the details function will change.

I used a vector of smart pointers instead of T* so that I didn't have to manage memory leaks. I used a vector of pointers in general to store the different events (concert or differen types) in the same array, that way all events are managed the same way.

In general we use design patters to promote re-usuability, standardization, efficiency, and flexibility. The goal is to have great structure to increase maintainablity and scalability. For instance, the factory method makes things scalable by standardardizing classes and treating all of them as some abstract class, that way actual implementation is hidden and therefore more easily maintainable (coders don't need to know complex implementation details to work on things.

My biggest challenge during development was implementing strategy design patterns. I know that strategy design patterns are essentailly just higher order functions, but I was confused on how to implement them. I think thinking of them as friend funcitons helped a lot, as in ways we could include functions in other files without interacting with some complicated hiearchy.
