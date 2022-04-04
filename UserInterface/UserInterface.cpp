//
// Created by Antonio on 4/3/2022.
//

#include "UserInterface.h"
#include <iostream>

void UserInterface::run() {
    std::cout << "Welcome to the User Interface!" << std::endl;
    std::cout << "To view the list of commands, type 'p'" << std::endl;

    char input = 'x';
    while (input != 'q') {
        this->readCommand(input);
        this->runCommand(input);
    }
}

void UserInterface::printMenu() {
    std::cout << "Commands:" << std::endl;
    std::cout << "a - Add a new entity" << std::endl;
    std::cout << "d - Delete an entity" << std::endl;
    std::cout << "e - Edit an entity" << std::endl;
    std::cout << "l - List all entities" << std::endl;
}

void UserInterface::runCommand(char i) {
    switch (i) {
        case 'a': {
            std::cout << "You entered 'a'" << std::endl;
            break;
        }
        case 'r': {
            std::cout << "You entered 'r'" << std::endl;
            break;
        }
        case 'u': {
            std::cout << "You entered 'u'" << std::endl;
            break;
        }
        case 'd': {
            std::cout << "You entered 'd'" << std::endl;
            break;
        }
        case 'p': {
            UserInterface::printMenu();
            break;
        }
        default: {
            std::cout << "Invalid command" << std::endl;
            break;
        }
    }
}

void UserInterface::readCommand(char &i) {
    std::cout << "Enter a command: ";
    std::cin >> i;
}

UserInterface::UserInterface() = default;

/*
#include "menu.h"

menu::menu() {
    //this->serv = serv;
}

menu::~menu() = default;

void menu::print_menu() {
    std::cout << std::endl;
    std::cout << "help\n\t print this menu" << std::endl;
    std::cout << "exit\n\t exit the program" << std::endl;
    std::cout << std::endl;

    std::cout << "add <id>\n\t add a new transaction with the given arguments"
              << std::endl;
    std::cout << "get <id>\n\t get the transaction with the given id"
              << std::endl;
    std::cout
            << "remove <id>\n\t remove the transaction corresponding to the given id"
            << std::endl;
    std::cout << "undo\n\t undo the last transaction" << std::endl;
    std::cout << "redo\n\t redo the last undone transaction" << std::endl;
    std::cout
            << "properties\n\t print the available formats for the property argument"
            << std::endl;
    std::cout
            << "list [sum|sort|max|min] [propriety]\n\t print the transactions respecting the given property"
            << "\n\tsum - print the sum of the transactions following the given property"
            << "\n\tsort - print the transactions following the given property in descending order"
            << "\n\tmax - print the maximum of the transactions following the given property"
            << "\n\tmin - print the minimum of the transactions following the given property"
            << "\n\tif no property is given, use all transaction"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout
            << "filter <propriety>\n\t remove the transactions not respecting the given property"
            << "\n\tfor the available properties, type properties"
            << std::endl;
    std::cout << std::endl;

    std::cout << "<arg> means the argument is required" << std::endl;
    std::cout << "[arg] means the argument is optional" << std::endl;
    std::cout << "arg1|arg2 means at most one of the arguments can be used"
              << std::endl;
    std::cout << std::endl;
}

void menu::print_property_arguments() {
    std::cout << "The following arguments can be combined however you want\n"
              << std::endl;
    std::cout << "desc <description>\n\t description of the transaction"
              << std::endl;
    std::cout << "type <in|out>\n\t type of the transaction" << std::endl;
    std::cout << "day <day>\n\t day of the transaction" << std::endl;
    std::cout
            << "< <value>\n\t transactions with a value less than the given one"
            << std::endl;
    std::cout
            << "> <value>\n\t transactions with a value greater than the given one"
            << std::endl;
    std::cout
            << "= <value>\n\t transactions with a value equal to the given one"
            << std::endl;
    std::cout << std::endl;
}

void menu::start() {
    std::cout << "Welcome, for a help menu, type help" << std::endl;
    std::string command;

    print_menu();
}
*/