//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_APARTMENTSERVICE_H
#define LAB_7_8_APARTMENTSERVICE_H


#include "../Domain/ApartmentExpense.h"
#include "../Repository/EntityRepository.h"

class ApartmentService {
private:
    EntityRepository<ApartmentExpense> repository;
    EntityVector<ApartmentExpense> previousState;
public:
    ApartmentService();

    explicit ApartmentService(EntityRepository<ApartmentExpense> repository);

    void add(ApartmentExpense entity);

    void remove(unsigned int apartmentNumber);

    void remove(unsigned int apartmentNumber, char* type);

    void remove(char* type);

    void remove(unsigned int apartmentNumberBegin, unsigned int apartmentNumberEnd);

    EntityVector<unsigned int> getApartmentNumbers();

    EntityVector<ApartmentExpense> get(unsigned int apartmentNumber);

    EntityVector<ApartmentExpense> get(unsigned int apartmentNumberBegin, unsigned int apartmentNumberEnd);

    EntityVector<ApartmentExpense> get(char* filterType, int filterValue);

    EntityVector<ApartmentExpense> get(char* type);

    EntityVector<ApartmentExpense> get(unsigned int apartmentNumber, char* type);

    EntityVector<ApartmentExpense> getPreviousState();

    void edit(unsigned int apartmentNumber, char* typeToEdit, int newValue);

    unsigned int sum(unsigned int apartmentNumber, char* type);

    unsigned int sum(unsigned int apartmentNumber);

    unsigned int sum(char* type);

    ApartmentExpense getMax(char* type);

    ApartmentExpense getMax(unsigned int apartmentNumber, char* type);

    ApartmentExpense getMax(unsigned int apartmentNumber);

    EntityVector<ApartmentExpense> getAll();

    void generate(int numberOfGenerations);

    EntityVector<ApartmentExpense> sort(char* type);

    void filter(char* type);

    void filter(int sum);

    void deleteAll();

    void undo();
};


#endif //LAB_7_8_APARTMENTSERVICE_H
