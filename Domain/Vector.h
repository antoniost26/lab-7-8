//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_VECTOR_H
#define LAB_7_8_VECTOR_H


template <class T> class Vector {
private:
    T *data;
    unsigned int size;
    unsigned int capacity;
    static const int DEFAULT_CAPACITY = 10;
    static const int GROWTH_FACTOR = 2;
    void resize();
public:
    Vector();
    explicit Vector(int capacity);
    Vector(const Vector &other);
    ~Vector();
    Vector &operator=(const Vector &other);
    T &operator[](int index);
    int getSize() const;
    int getCapacity() const;
    void push_back(T value);
    void pop_back();
    void insert(int index, T value);
    void erase(int index);
    void clear();
};


#endif //LAB_7_8_VECTOR_H
