//
// Created by Antonio on 4/3/2022.
//

#include <stdexcept>
#include "Vector.h"

template<class T>
void Vector<T>::resize() {
    this->capacity *= GROWTH_FACTOR;
    T *newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] this->data;
    this->data = newData;
}

template<class T>
Vector<T>::Vector() {
    this->size = 0;
    this->capacity = DEFAULT_CAPACITY;
    this->data = new T[capacity];
}

template<class T>
Vector<T>::Vector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->data = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[capacity];
    for (int i = 0; i < size; i++) {
        this->data[i] = other.data[i];
    }
}

template<class T>
Vector<T>::~Vector() {
    delete[] this->data;
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->clear();
    for (int i = 0; i < size; i++) {
        this->data[i] = other.data[i];
    }
    return *this;
}

template<class T>
T &Vector<T>::operator[](int index) {
    return data[index];
}

template<class T>
int Vector<T>::getSize() const {
    return this->size;
}

template<class T>
int Vector<T>::getCapacity() const {
    return this->capacity;
}

template<class T>
void Vector<T>::push_back(T value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template<class T>
void Vector<T>::pop_back() {
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    this->erase(size - 1);
    size--;
}

template<class T>
void Vector<T>::insert(int index, T value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (size == capacity) {
        resize();
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

template<class T>
void Vector<T>::erase(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

template<class T>
void Vector<T>::clear() {
    delete[] data;
    size = 0;
    data = new T[capacity];
}
