cmake_minimum_required(VERSION 3.21)
project(lab_7_8)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_7_8 main.cpp Domain/ApartmentExpense.cpp Domain/ApartmentExpense.h Repository/EntityRepository.h Service/ApartmentService.cpp Service/ApartmentService.h Domain/EntityVector.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h Tests/Test.h)
