#include "transport.hpp"

int main() {
    std::vector<std::unique_ptr<transport>> transports;
    transports.push_back(std::make_unique<car>());
    transports.push_back(std::make_unique<bike>());
    transports.push_back(std::make_unique<train>());
    transports.push_back(std::make_unique<plane>());

    std::cout << "Moving all transports:\n";
    for (const auto& transport : transports) {
        transport->move();
    }

   
    std::cout << "\nRefueling transports that need fuel:\n";
    for (const auto& transport : transports) {
        if (auto* Car = dynamic_cast<car*>(transport.get())) {
            Car->refuel();
        } else if (auto* Train = dynamic_cast<train*>(transport.get()))
        {
            Train->refuel();
        } else if (auto* Plane = dynamic_cast<plane*>(transport.get())) {
            Plane->refuel();
        }
    }

    return 0;
}