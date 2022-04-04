#include <iostream>
#include <thread>
#include <chrono>
#include "UserInterface/UserInterface.h"
#include "Tests/Test.h"

int main() {
    Test::testAll();
    UserInterface console;
    console.run();
    return 0;
}
