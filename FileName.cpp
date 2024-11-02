#include <iostream>
#include <memory>
#include <string>

// ������� ���� Transport
class Transport {
public:
    virtual void drive() const = 0;
    virtual ~Transport() = default;
};

// ���� Car, ���� ������ Transport
class Car : public Transport {
public:
    void drive() const override {
        std::cout << "Driving a car!" << std::endl;
    }
};

// ���� Bike, ���� ������ Transport
class Bike : public Transport {
public:
    void drive() const override {
        std::cout << "Riding a bike!" << std::endl;
    }
};

// ��������� ���� TransportFactory
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

// ������� �������
int main() {
    // ������������ ���������� ������ ��� ��������� ��'����
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
