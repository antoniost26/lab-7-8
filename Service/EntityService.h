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
    virtual void addEntity(Entity *entity) = 0;
    virtual void removeEntity(Entity *entity) = 0;
    virtual void updateEntity(Entity *entity) = 0;
    virtual void getEntity(Entity *entity) = 0;
    virtual void getAllEntities() = 0;
};


#endif //LAB_7_8_ENTITYSERVICE_H
