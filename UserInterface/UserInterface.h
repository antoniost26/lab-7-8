//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_USERINTERFACE_H
#define LAB_7_8_USERINTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include "../Tests/Test.h"
#include "../Domain/ApartmentExpense.h"
#include "../Service/ApartmentService.h"

class UserInterface {
private:
    ApartmentService apartmentService;
public:
    UserInterface();

    void run();

    static void printMenu();

    void runCommand(std::string i);

    void readCommand(std::string &i);

    std::vector<std::string> split(const std::string& s, char delimiter);

    void handleAddExpense(std::vector<std::string> args);

    void handleDeleteExpense(std::vector<std::string> args);

    void handleEditExpense(std::vector<std::string> args);

    void handlePrintExpenses(std::vector<std::string> args);

    void handleSumExpenses(std::vector<std::string> args);

    void handleMaxExpense(std::vector<std::string> args);

    void handleSortExpenses(std::vector<std::string> args);

    void handleFilterExpenses(std::vector<std::string> args);

    void handleUndo();

    bool isNumber(std::string s);

    void handleGenerateEntries(std::vector<std::string> args);
};


#endif //LAB_7_8_USERINTERFACE_H
