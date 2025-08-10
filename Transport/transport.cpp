#include "transport.hpp"

void flightMechanism::fly() const {
    std::cout << "flying "<< std::endl;
}

void diesel::refuel() const {
    std::cout << "Refuel with diesel" << std::endl;
}

void jet::refuel() const {
    std::cout << "Refuel with jet" << std::endl;
}

car::car() : fuel(std::make_unique<diesel>()) {}

void car::move() const{
        std::cout << "Car is driving" << std::endl;
}

void car::refuel() const {
    fuel->refuel();
}

void bike::move() const {
    std::cout << "Bike is pedaling" << std::endl;
}

train::train() : fuel(std::make_unique<diesel>()) {}

void train::move() const {
    std::cout << "Train is moving" << std::endl;
}

void train::refuel() const {
    fuel->refuel();
}

plane::plane() : flight(std::make_unique<flightMechanism>()),
                 fuel(std::make_unique<jet>()) {}

void plane::move() const {
    flight->fly();
}

void plane::refuel() const {
    fuel->refuel();
}


