//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_ENTITYVALIDATOR_H
#define LAB_7_8_ENTITYVALIDATOR_H

#include <map>
#include "../Domain/Entity.h"

class EntityValidator {
private:
    Entity entity;
    const std::map<int, int> MONTH_DAYS = {
            {1, 31},
            {2, 28},
            {3, 31},
            {4, 30},
            {5, 31},
            {6, 30},
            {7, 31},
            {8, 31},
            {9, 30},
            {10, 31},
            {11, 30},
            {12, 31}
    };
public:
    EntityValidator();
    explicit EntityValidator(Entity entity);
    EntityValidator(const EntityValidator& other);
    EntityValidator& operator=(const EntityValidator& other);
    ~EntityValidator();
    void validate(Entity entity);

};


#endif //LAB_7_8_ENTITYVALIDATOR_H
