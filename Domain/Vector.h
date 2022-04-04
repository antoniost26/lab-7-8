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
    void resize() {
        this->capacity *= GROWTH_FACTOR;
        T *newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] this->data;
        this->data = newData;
    }
public:
    Vector() {
        this->size = 0;
        this->capacity = DEFAULT_CAPACITY;
        this->data = new T[capacity];
    }

    explicit Vector(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->data = new T[capacity];
    }

    Vector(const Vector &other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->data[i] = other.data[i];
        }
    }

    ~Vector() {
        delete[] this->data;
    }

    Vector<T> &operator=(const Vector<T> &other) {
        this->size = other.size;
        this->capacity = other.capacity;
        delete[] this->data;
        this->data = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->data[i] = other.data[i];
        }
        return *this;
    }

    T &operator[](int index) {
        return data[index];
    }

    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }

    void push_back(T value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        this->erase(size - 1);
        size--;
    }

    void insert(int index, T value) {
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

    void erase(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void clear() {
        delete[] data;
        size = 0;
        this->capacity = DEFAULT_CAPACITY;
        data = new T[capacity];
    }

};


#endif //LAB_7_8_VECTOR_H
