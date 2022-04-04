//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_TEST_H
#define LAB_7_8_TEST_H
#include <cassert>
#include <chrono>
#include <thread>
#include "../Domain/Entity.h"
#include "../Repository/EntityRepository.h"

class Test {
public:
    static void testRepository() {
        EntityRepository<Entity> repo;
        assert(repo.getSize() == 0);
        assert(repo.getAll().getSize() == 0);
        repo.addElem(Entity(1));
        assert(repo.getSize() == 1);
        assert(repo.getAll().getSize() == 1);
        assert(repo.getCapacity() == 10);
        repo.addElem(Entity(2));
        assert(repo.getSize() == 2);
        assert(repo.getAll().getSize() == 2);
        assert(repo.getCapacity() == 10);
        EntityRepository<Entity> repo2(repo);
        assert(repo2.getSize() == 2);
        assert(repo2.getAll().getSize() == 2);
        assert(repo2.getCapacity() == 10);
        repo2.addElem(Entity(3));
        assert(repo2.getSize() == 3);
        assert(repo2.getAll().getSize() == 3);
        assert(repo2.getCapacity() == 10);
    }

    static void testService() {

    }

    static void testEntity() {
        Entity entity;
        assert(entity.getId() == 0);
        entity.setId(1);
        assert(entity.getId() == 1);
        entity.setId(2);
        assert(entity.getId() == 2);
    }

    static void testAll() {
        std::cout << "Running tests..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Test::testEntity();
        Test::testRepository();
        std::cout << "Tests passed!" << std::endl;
    }
};


#endif //LAB_7_8_TEST_H
