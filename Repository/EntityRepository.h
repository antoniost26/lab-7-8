//
// Created by Antonio on 4/3/2022.
//
#include "../Domain/Vector.h"
#include "../Domain/Entity.h"

#ifndef LAB_7_8_ENTITYREPOSITORY_H
#define LAB_7_8_ENTITYREPOSITORY_H


template <class T> class EntityRepository {
private:
    Vector<T> entities;
public:
    EntityRepository();
    explicit EntityRepository(int capacity);
    EntityRepository(const EntityRepository& other);
    explicit EntityRepository(const Vector<T>& other);
    ~EntityRepository();
    void addElem(T entity);
    void remove(int index);
    Vector<T> getAll(int index);
    int getSize();
    int getCapacity();
};


#endif //LAB_7_8_ENTITYREPOSITORY_H
