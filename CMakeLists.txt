cmake_minimum_required(VERSION 3.21)
project(lab_7_8)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_7_8 main.cpp Domain/Apartment.cpp Domain/Apartment.h Repository/EntityRepository.h Service/ApartmentService.cpp Service/ApartmentService.h Domain/Vector.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h EntityValidator/EntityValidator.cpp EntityValidator/EntityValidator.h Tests/Test.h)
