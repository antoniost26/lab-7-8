//
// Created by Antonio on 4/3/2022.
//

#include "ApartmentService.h"

ApartmentService::ApartmentService(EntityRepository<Apartment> repository) {
    this->repository = repository;
}

void ApartmentService::add(Apartment entity) {
    this->repository.addElem(entity);
}

void ApartmentService::remove(int index) {
    this->repository.remove(index);
}

Vector<Apartment> ApartmentService::getAll() {
    Vector<Apartment> apartments = this->repository.getAll();
    return apartments;
}

ApartmentService::ApartmentService() {
    this->repository = EntityRepository<Apartment>();
}

void ApartmentService::generate(int numberOfGenerations) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 100.0);
        for (int i = 0; i < numberOfGenerations; i++) {
            this->repository.addElem(Apartment(floor(dist(mt))));
        }
}

Apartment ApartmentService::find(int apartmentNumber) {
    Vector<Apartment> apartments = this->repository.getAll();
    for (int i = 0; i < apartments.getSize(); i++) {
        if (apartments[i].getApartmentNumber() == apartmentNumber) {
            return apartments[i];
        }
    }
    return Apartment(-1);
}

void ApartmentService::edit(int index, Apartment entity) {
    this->repository.edit(index, entity);
}
