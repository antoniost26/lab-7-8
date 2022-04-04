//
// Created by Antonio on 4/3/2022.
//

#include "Entity.h"

Entity::Entity() {
    this->id = 0;
}

Entity::Entity(int id) {
    this->id = id;
}

Entity::Entity(const Entity &other) {
    this->id = other.id;
}

unsigned int Entity::getId() {
    return this->id;
}

void Entity::setId(int id) {
    this->id = id;
}

Entity::~Entity() = default;
