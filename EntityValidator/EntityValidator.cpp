//
// Created by Antonio on 4/3/2022.
//

#include "EntityValidator.h"

void EntityValidator::validate(Entity entity) {
    time_t theTime = time(nullptr);
    struct tm *aTime = localtime(&theTime);

    int month = aTime->tm_mon + 1;

    if (entity.getId() < 1 || entity.getId() >  this->MONTH_DAYS.at(month)) {
        throw std::invalid_argument("Invalid day");
    }
}

EntityValidator::EntityValidator() {
    this->entity = Entity();
}

EntityValidator::EntityValidator(Entity entity) {
    this->entity = entity;
}

EntityValidator::EntityValidator(const EntityValidator &other) {
    this->entity = other.entity;
}

EntityValidator &EntityValidator::operator=(const EntityValidator &other) {
    this->entity = other.entity;
    return *this;
}

EntityValidator::~EntityValidator() {
    this->entity.~Entity();
};
