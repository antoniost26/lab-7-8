//
// Created by Antonio on 4/3/2022.
//
#include "../Domain/Vector.h"
#include "../Domain/Apartment.h"
#include <random>

#ifndef LAB_7_8_ENTITYREPOSITORY_H
#define LAB_7_8_ENTITYREPOSITORY_H


template <class T> class EntityRepository {
private:
    Vector<T> entities;
public:
    ~EntityRepository() = default;

    EntityRepository() {
        entities = Vector<T>();
    }

    EntityRepository(const EntityRepository &other) {
        this->entities = other.entities;
    }

    explicit EntityRepository(const Vector<T> &other) {
        this->entities = other;
    }

    explicit EntityRepository(int capacity) {
        entities = Vector<T>(capacity);
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

    Vector<T> getAll() {
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
