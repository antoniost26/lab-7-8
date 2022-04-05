//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_APARTMENTSERVICE_H
#define LAB_7_8_APARTMENTSERVICE_H


#include "../Domain/Apartment.h"
#include "../Repository/EntityRepository.h"

class ApartmentService {
private:
    EntityRepository<Apartment> repository;
public:
    ApartmentService();

    explicit ApartmentService(EntityRepository<Apartment> repository);

    void add(Apartment entity);

    void remove(int index);

    Apartment find(int apartmentNumber);

    void edit(int index, Apartment entity);

    Vector<Apartment> getAll();

    void generate(int numberOfGenerations);
};


#endif //LAB_7_8_APARTMENTSERVICE_H
