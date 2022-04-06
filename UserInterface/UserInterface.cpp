//
// Created by Antonio on 4/3/2022.
//

#include "UserInterface.h"

void UserInterface::run() {
    std::cout << "Welcome to the User Interface!" << std::endl;
    std::cout << "To view the command menu, type 'menu'" << std::endl;

    std::string input;
    do{
        std::cout << "Waiting for input..." << std::endl;
        try {
            std::getline(std::cin, input);
            this->runCommand(input);
        }
        catch (std::out_of_range &e) {
            std::cout << "Out of range: " << e.what() << std::endl;
        }
        catch (std::invalid_argument &e) {
            std::cout << "Invalid argument: " << e.what() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } while (input != "quit");
}

void UserInterface::printMenu() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "add <apartment-number> <sum-of-expense> <type-of-expense> \n\t adds an expense" << std::endl;
    std::cout << "delete <apartment-number> \n\t deletes all expenses for a given apartment number" << std::endl;
    std::cout << "delete <apartment-number> <expense-type> \n\t deletes all expenses for a given apartment number and type" << std::endl;
    std::cout << "delete <expense-type> \n\t deletes all expenses for a given type (for all apartment numbers)" << std::endl;
    std::cout << "delete <apartment-number> to <apartment-number> \n\t deletes all expenses for all apartment number in between" << std::endl;
    std::cout << "delete all \n\t deletes all expenses" << std::endl;
    std::cout << "edit <apartment-number> <expense-type> <new-value> \n\t edits the sum for all apartment expenses with new value" << std::endl;
    std::cout << "print \n\t prints all apartment expenses" << std::endl;
    std::cout << "print <apartment-number> \n\t print all expenses for a given apartment number" << std::endl;
    std::cout << "print <filter-type> <filter-value> \n\t prints all expenses for a given filter" << std::endl;
    std::cout << "sum <expense-type> <apartment-number?> \n\t prints the sum of all type related expenses for all or for a given apartment number" << std::endl;
    std::cout << "sum <apartment-number> \n\t prints the sum of all expenses for a given apartment number" << std::endl;
    std::cout << "max <apartment-number> \n\t prints the maximum expense for a given apartment number" << std::endl;
    std::cout << "sort <expense-type> \n\t sorts for descending order the expenses of a given expense type" << std::endl;
    std::cout << "filter <expense-type> \n\t filters the expenses by the given type and deletes all non-related types" << std::endl;
    std::cout << "filter <sum> \n\t filters the expenses by the given sum and deletes all expenses for which sum is greater than the given one" << std::endl;
    std::cout << "menu \n\t prints command menu" << std::endl;
    std::cout << "quit \n\t quits the program" << std::endl;
    std::cout << "********************************************************" << std::endl;
    std::cout << "Allowed expense types: water, electricity, gas, warmth, other" << std::endl;
    std::cout << "Filter types: <, <=, >, >=, =" << std::endl;
    std::cout << "Valid fields: apartment-number, expense-type, sum-of-expense" << std::endl;
    std::cout << "Good to know: argument followed by ? is optional." << std::endl;
    std::cout << "You can generate entries by typing 'generate <number of generations>'" << std::endl;
}

void UserInterface::runCommand(std::string input) {
    std::vector<std::string> command = this->split(input, ' ');
    if (command.at(0) == "add") {
        command.erase(command.begin());
        this->handleAddExpense(command);
    } else if (command.at(0) == "delete") {
        command.erase(command.begin());
        this->handleDeleteExpense(command);
    } else if (command.at(0) == "edit") {
        command.erase(command.begin());
        this->handleEditExpense(command);
    } else if (command.at(0) == "print") {
        command.erase(command.begin());
        this->handlePrintExpenses(command);
    } else if (command.at(0) == "sum") {
        command.erase(command.begin());
        this->handleSumExpenses(command);
    } else if (command.at(0) == "max") {
        command.erase(command.begin());
        this->handleMaxExpense(command);
    } else if (command.at(0) == "sort") {
        command.erase(command.begin());
        this->handleSortExpenses(command);
    } else if (command.at(0) == "filter") {
        command.erase(command.begin());
        this->handleFilterExpenses(command);
    } else if (command.at(0) == "menu") {
        command.erase(command.begin());
        this->printMenu();
    } else if (command.at(0) == "generate") {
        command.erase(command.begin());
        this->handleGenerateEntries(command);
    } else if (command.at(0) == "undo"){
        this->handleUndo();
    } else if (command.at(0) == "quit") {
        std::cout << "Thanks for using my app! Goodbye." << std::endl;
    } else {
        std::cout << "Invalid command!" << std::endl;
    }
}

std::vector<std::string> UserInterface::split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

UserInterface::UserInterface() = default;

void UserInterface::handleAddExpense(std::vector<std::string> args) {
    try {
        if (args.size() != 3 ) {
            throw std::invalid_argument("Invalid command! Try using add <apartment-number> <sum-of-expense> <expense-type>.");
        }
        if (std::stoi(args.at(0)) <= 0 ) {
            throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
        }
        if (std::stoi(args.at(1)) <= 0) {
            throw std::invalid_argument("Invalid sum of expense! Should be a positive integer.");
        }
        if (args.at(2) != "water" && args.at(2) != "electricity" && args.at(2) != "gas" && args.at(2) != "warmth" && args.at(2) != "other") {
            throw std::invalid_argument("Invalid expense type! Should be water, electricity, gas, warmth or other.");
        }

        char expenseType[15];
        unsigned int apartmentNumber = std::stoi(args.at(0));
        unsigned int expenseValue = std::stoi(args.at(1));
        strcpy(expenseType, args.at(2).c_str());

        this->apartmentService.add(ApartmentExpense(apartmentNumber, expenseValue, expenseType));
    }
    catch (std::invalid_argument &e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
}

void UserInterface::handleDeleteExpense(std::vector<std::string> args) {
    if (args.empty() || args.size() > 3) {
        throw std::invalid_argument("Invalid command! Try using delete <apartment-number>.");
    }
    if (args.size() == 1) {
        if (args.at(0) == "all") {
            this->apartmentService.deleteAll();
        } else if (this->isNumber(args.at(0))) {
            if (std::stoi(args.at(0)) <= 0) {
                throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
            }
            this->apartmentService.remove(std::stoi(args.at(0)));
        } else {
            char expenseType[15];
            strcpy(expenseType, args.at(0).c_str());
            this->apartmentService.remove(expenseType);
        }
    } else if (args.size() == 2) {
        std::string firstCommand = args.at(0);
        if (!this->isNumber(args.at(0)) || std::stoi(args.at(0)) <= 0) {
            throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
        } else if (args.at(1) != "water" && args.at(1) != "electricity" && args.at(1) != "gas" && args.at(1) != "warmth" && args.at(1) != "other") {
            throw std::invalid_argument("Invalid expense type! Should be water, electricity, gas, warmth or other.");
        } else {
            char expenseType[15];
            strcpy(expenseType, args.at(1).c_str());
            this->apartmentService.remove(std::stoi(args.at(0)), expenseType);
        }
    } else if (args.size() == 3) {
        std::string firstCommand = args.at(0);
        if (!this->isNumber(args.at(0)) || !this->isNumber(args.at(2))) {
            throw std::invalid_argument("Invalid apartment number/s! Should be positive integer/s.");
        } else if (args.at(1) != "to") {
            throw std::invalid_argument("Invalid command! Try using delete <apartment-number> to <apartment-number>.");
        } else {
            this->apartmentService.remove(std::stoi(args.at(0)), std::stoi(args.at(2)));
        }
    }
}
void UserInterface::handleEditExpense(std::vector<std::string> args) {
    if (args.size() != 3) {
        throw std::invalid_argument("Invalid command! Try using edit <apartment-number> <expense-type> <new-value>.");
    }
    if (!this->isNumber(args.at(0)) || std::stoi(args.at(0)) <= 0) {
        throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
    }
    if (args.at(1) != "water" && args.at(1) != "electricity" && args.at(1) != "gas" && args.at(1) != "warmth" && args.at(1) != "other") {
        throw std::invalid_argument("Invalid expense type! Should be water, electricity, gas, warmth or other.");
    }
    if (std::stoi(args.at(2)) <= 0) {
        throw std::invalid_argument("Invalid new value! Should be a positive integer.");
    }
    char expenseType[15];
    strcpy(expenseType, args.at(1).c_str());
    this->apartmentService.edit(std::stoi(args.at(0)), expenseType, std::stoi(args.at(2)));
}

void UserInterface::handlePrintExpenses(std::vector<std::string> args) {
    std::cout << "Printing expenses..." << std::endl;
    if (this->apartmentService.getAll().getSize() == 0) {
        std::cout << "No apartments added yet!" << std::endl;
        return;
    }
    if (args.empty()) {
        std::cout << this->apartmentService.getAll() << std::endl;
    } else if (args.size() == 1) {
        if (!isNumber(args.at(0))) {
            throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
        }
        std::cout << this->apartmentService.get(std::stoi(args.at(0))) << std::endl;
    } else if (args.size() == 2) {
        if (!isNumber(args.at(1))) {
            throw std::invalid_argument("Invalid value! Should be a positive integer.");
        }
        if (args.at(0).length() > 2) {
            throw std::invalid_argument("Invalid filter type! Please take a look at 'menu'.");
        }
        char filterType[2];
        strcpy(filterType, args.at(0).c_str());
        std::cout << this->apartmentService.get(filterType, std::stoi(args.at(1))) << std::endl;
    } else {
        throw std::invalid_argument("Invalid command! Try using print or print <apartment-number> or print <filter-type> <value>.");
    }
}

void UserInterface::handleSumExpenses(std::vector<std::string> args) {
    if (args.empty()) {
        throw std::invalid_argument("Invalid command! Try using sum <apartment-number> <expense-type>.");
    }
    if (this->apartmentService.getAll().getSize() == 0) {
        std::cout << "No apartments added yet!" << std::endl;
        return;
    }
    if (args.size() == 1) {
        if (isNumber(args.at(0))) {
            if (std::stoi(args.at(0)) <= 0) {
                throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
            }
            std::cout << this->apartmentService.sum(std::stoi(args.at(0))) << std::endl;
        } else {
            char type[15];
            strcpy(type, args.at(0).c_str());
            std::cout << this->apartmentService.sum(type) << std::endl;
        }
    } else if (args.size() == 2) {
        if (!isNumber(args.at(1))) {
            throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
        }
        char type[15];
        strcpy(type, args.at(0).c_str());
        std::cout << this->apartmentService.sum(std::stoi(args.at(1)), type) << std::endl;
    } else {
        throw std::invalid_argument("Invalid command! Try using sum <apartment-number> <expense-type>.");
    }
}

void UserInterface::handleMaxExpense(std::vector<std::string> args) {
    if (this->apartmentService.getAll().getSize() == 0) {
        std::cout << "No apartments added yet!" << std::endl;
        return;
    }
    if (args.empty() || args.size() > 1) {
        throw std::invalid_argument("Invalid command! Try using max <apartment-number>.");
    }
    if (!isNumber(args.at(0))) {
        throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
    }
    if (std::stoi(args.at(0)) <= 0) {
        throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
    }
    std::cout << this->apartmentService.getMax(std::stoi(args.at(0))) << std::endl;
}

void UserInterface::handleSortExpenses(std::vector<std::string> args) {
    if (this->apartmentService.getAll().getSize() == 0) {
        std::cout << "No apartments added yet!" << std::endl;
        return;
    }
    if (args.empty()) {
        throw std::invalid_argument("Invalid command! Try using sort <apartment-number>.");
    }
    char type[15];
    strcpy(type, args.at(0).c_str());
    std::cout << this->apartmentService.sort(type) << std::endl;
}
void UserInterface::handleFilterExpenses(std::vector<std::string> args) {
    if (this->apartmentService.getAll().getSize() == 0) {
        std::cout << "No apartments added yet!" << std::endl;
        return;
    }
    if (args.empty()) {
        throw std::invalid_argument("Invalid command! Try using filter <apartment-number>.");
    }
    if (!isNumber(args.at(0))) {
        char type[15];
        strcpy(type, args.at(0).c_str());
        this->apartmentService.filter(type);
    } else if (std::stoi(args.at(0)) <= 0) {
        throw std::invalid_argument("Invalid apartment number! Should be a positive integer.");
    } else {
        this->apartmentService.filter(std::stoi(args.at(0)));
    }
}

void UserInterface::handleUndo() {
    this->apartmentService.undo();
}

bool UserInterface::isNumber(std::string s) {
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

void UserInterface::handleGenerateEntries(std::vector<std::string> args) {
    if (!this->isNumber(args.at(0))) {
        throw std::invalid_argument("Invalid number of entries! Should be a positive integer.");
    }
    this->apartmentService.generate(std::stoi(args.at(0)));
}
