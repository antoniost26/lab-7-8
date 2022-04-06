//
// Created by Antonio on 4/3/2022.
//
#include "../Domain/EntityVector.h"
#include "../Domain/ApartmentExpense.h"
#include <random>

#ifndef LAB_7_8_ENTITYREPOSITORY_H
#define LAB_7_8_ENTITYREPOSITORY_H


template <class T> class EntityRepository {
private:
    EntityVector<T> entities;
    int findIndex(T entity) {
        for (int i = 0; i < entities.getSize(); i++) {
            if (entities[i] == entity) {
                return i;
            }
        }
        return -1;
    }
public:
    ~EntityRepository() = default;

    EntityRepository() {
        this->entities = EntityVector<T>();
    }

    EntityRepository(const EntityRepository &other) {
        this->entities = other.entities;
    }

    explicit EntityRepository(const EntityVector<T> &other) {
        this->entities = other;
    }

    explicit EntityRepository(int capacity) {
        this->entities = EntityVector<T>(capacity);
    }

    void addElem(T entity) {
        this->entities.push_back(entity);
    }

    void remove(T entity) {
        int index = this->findIndex(entity);
        if (index != -1) {
            this->entities.erase(index);
        }
    }

    void edit (T entity, T newEntity) {
        int index = this->findIndex(entity);
        entities.erase(index);
        entities.insert(index, newEntity);
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

    void deleteAll() {
        this->entities.clear();
    }

    void setAll(EntityVector<T> newVector) {
        this->entities = newVector;
    }
};


#endif //LAB_7_8_ENTITYREPOSITORY_H
