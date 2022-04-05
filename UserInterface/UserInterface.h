//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_USERINTERFACE_H
#define LAB_7_8_USERINTERFACE_H


#include "../Tests/Test.h"
#include "../Domain/Apartment.h"
#include "../Service/ApartmentService.h"

class UserInterface {
private:
    ApartmentService apartmentService;
public:
    UserInterface();

    void run();

    static void printMenu();

    void runCommand(char i);

    void readCommand(char &i);
};


#endif //LAB_7_8_USERINTERFACE_H
