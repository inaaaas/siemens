#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class flightMechanism {
public:
    void fly() const;
};

class Fuel {
public:
    virtual void refuel() const = 0;
    virtual ~Fuel() = default;
};

class diesel : public Fuel {
public:
    void refuel() const override;
};

class jet : public Fuel {
    void refuel() const override;
};


class transport {
public:
   virtual void move() const = 0;
   virtual ~transport() = default;
};

class car : public transport {
    std::unique_ptr<Fuel> fuel;
public: 
    car();
    void move() const override;
    void refuel() const;
};

class bike : public transport {
public:
    void move() const override;
};

class train : public transport {
    std::unique_ptr<Fuel> fuel;
public:
    train();
    void move() const override;
    void refuel() const;
};

class plane : public transport, public flightMechanism {
    std::unique_ptr<flightMechanism> flight;
    std::unique_ptr<Fuel> fuel;
public:
    plane();
    void move() const override;
    void refuel() const;
};
#endif