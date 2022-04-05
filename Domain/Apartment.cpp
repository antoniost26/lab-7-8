//
// Created by Antonio on 4/3/2022.
//

#include "Apartment.h"

Apartment::Apartment() {
    this->apartmentNumber = 0;
}

Apartment::Apartment(int id) {
    this->apartmentNumber = id;
}

Apartment::Apartment(const Apartment &other) {
    this->apartmentNumber = other.apartmentNumber;
}

unsigned int Apartment::getApartmentNumber() const {
    return this->apartmentNumber;
}

void Apartment::setId(int id) {
    this->apartmentNumber = id;
}

std::ostream &operator<<(std::ostream &os, const Apartment &entity) {
    os << "Apartment number: " << entity.apartmentNumber;
    return os;
}

Apartment::~Apartment() = default;

std::istream& operator>>(std::istream& is, Apartment& entity) {
    std::cout << "Apartment number: ";
    is >> entity.apartmentNumber;
    return is;
}
