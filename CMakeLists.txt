cmake_minimum_required(VERSION 3.21)
project(lab_7_8)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_7_8 main.cpp Domain/Entity.cpp Domain/Entity.h Repository/EntityRepository.cpp Repository/EntityRepository.h Service/EntityService.cpp Service/EntityService.h Domain/Vector.cpp Domain/Vector.h)
