#include <iostream>
#include <memory>
#include <string>

// Базовий клас Transport
class Transport {
public:
    virtual void drive() const = 0;
    virtual ~Transport() = default;
};

// Клас Car, який наслідує Transport
class Car : public Transport {
public:
    void drive() const override {
        std::cout << "Driving a car!" << std::endl;
    }
};

// Клас Bike, який наслідує Transport
class Bike : public Transport {
public:
    void drive() const override {
        std::cout << "Riding a bike!" << std::endl;
    }
};

// Фабричний клас TransportFactory
class TransportFactory {
public:
    static std::unique_ptr<Transport> createTransport(const std::string& type) {
        if (type == "car") {
            return std::make_unique<Car>();
        }
        else if (type == "bike") {
            return std::make_unique<Bike>();
        }
        else {
            return nullptr;
        }
    }
};

// Основна функція
int main() {
    // Використання фабричного методу для створення об'єктів
    auto car = TransportFactory::createTransport("car");
    auto bike = TransportFactory::createTransport("bike");

    if (car) {
        car->drive();
    }

    if (bike) {
        bike->drive();
    }

    return 0;
}
