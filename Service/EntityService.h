//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_ENTITYSERVICE_H
#define LAB_7_8_ENTITYSERVICE_H


#include "../Domain/Entity.h"
#include "../Repository/EntityRepository.h"

template <class T> class EntityService {
private:
    EntityRepository<T> repository;
public:
    EntityService();

    explicit EntityService(EntityRepository<T> repository);

    void add(T entity);

    void remove(T entity);

    void update(T entity);

    Vector<T> getAll();
};


#endif //LAB_7_8_ENTITYSERVICE_H
