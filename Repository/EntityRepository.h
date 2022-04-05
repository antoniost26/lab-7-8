//
// Created by Antonio on 4/3/2022.
//
#include "../Domain/EntityVector.h"
#include "../Domain/Apartment.h"
#include <random>

#ifndef LAB_7_8_ENTITYREPOSITORY_H
#define LAB_7_8_ENTITYREPOSITORY_H


template <class T> class EntityRepository {
private:
    EntityVector<T> entities;
public:
    ~EntityRepository() = default;

    EntityRepository() {
        entities = EntityVector<T>();
    }

    EntityRepository(const EntityRepository &other) {
        this->entities = other.entities;
    }

    explicit EntityRepository(const EntityVector<T> &other) {
        this->entities = other;
    }

    explicit EntityRepository(int capacity) {
        entities = EntityVector<T>(capacity);
    }

    void addElem(T entity) {
        entities.push_back(entity);
    }

    void remove(int index) {
        entities.erase(index);
    }

    void edit (int index, T entity) {
        entities.erase(index);
        entities.insert(index, entity);
    }

    EntityVector<T> getAll() {
        return this->entities;
    }

    int getSize() {
        return this->entities.getSize();
    }

    int getCapacity() {
        return this->entities.getCapacity();
    }
};


#endif //LAB_7_8_ENTITYREPOSITORY_H
