//
// Created by Antonio on 4/3/2022.
//
#include <iostream>

#ifndef LAB_7_8_ENTITY_H
#define LAB_7_8_ENTITY_H

class Entity {
private:
    unsigned int id;
public:
    Entity();

    explicit Entity(int id);

    Entity(const Entity& other);

     ~Entity();

     void setId(int id);

     unsigned int getId();

};

#endif //LAB_7_8_ENTITY_H
