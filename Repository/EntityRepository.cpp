//
// Created by Antonio on 4/3/2022.
//

#include "EntityRepository.h"

template<class T>
EntityRepository<T>::~EntityRepository() {
    entities.~Vector();
}

template<class T>
EntityRepository<T>::EntityRepository() {
    entities = Vector<T>();
}

template<class T>
EntityRepository<T>::EntityRepository(int capacity) {
    entities = Vector<T>(capacity);
}

template<class T>
void EntityRepository<T>::addElem(T entity) {
    entities.push_back(entity);
}

template<class T>
void EntityRepository<T>::remove(int index) {
    entities.erase(index);
}

template<class T>
Vector<T> EntityRepository<T>::getAll(int index) {
    return this->entities;
}

template<class T>
int EntityRepository<T>::getSize() {
    return this->entities.getSize();
}

template<class T>
int EntityRepository<T>::getCapacity() {
    return this->entities.getCapacity();
}

template<class T>
EntityRepository<T>::EntityRepository(const EntityRepository &other) {
    this->entities = other.entities;
}

template<class T>
EntityRepository<T>::EntityRepository(const Vector<T> &other) {
    this->entities = other;
}
