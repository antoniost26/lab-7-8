//
// Created by Antonio on 4/3/2022.
//
#include "../Domain/Vector.h"
#include "../Domain/Entity.h"

#ifndef LAB_7_8_ENTITYREPOSITORY_H
#define LAB_7_8_ENTITYREPOSITORY_H


template <class T> class EntityRepository {
private:
    int size;
    int capacity;
    static const int DEFAULT_CAPACITY = 10;
    static const int BATCH_SIZE = 1024;
    Vector<Entity> entities;
    void resize();
public:
    EntityRepository();
    EntityRepository(int capacity);
    ~EntityRepository();
    void addElem(Entity entity);
    void remove(int index);
    Entity getAll(int index);
    int getSize();
    int getCapacity();
};


#endif //LAB_7_8_ENTITYREPOSITORY_H
