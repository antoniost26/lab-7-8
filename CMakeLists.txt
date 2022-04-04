cmake_minimum_required(VERSION 3.21)
project(lab_7_8)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_7_8 main.cpp Domain/Entity.cpp Domain/Entity.h Repository/EntityRepository.h Service/EntityService.cpp Service/EntityService.h Domain/Vector.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h EntityValidator/EntityValidator.cpp EntityValidator/EntityValidator.h Tests/Test.h)
