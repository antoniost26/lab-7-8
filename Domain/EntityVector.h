//
// Created by Antonio on 4/3/2022.
//

#ifndef LAB_7_8_ENTITYVECTOR_H
#define LAB_7_8_ENTITYVECTOR_H


template<class T>
class EntityVector {
private:
    T *data;
    unsigned int size;
    unsigned int capacity;
    static const int DEFAULT_CAPACITY = 10;
    static const int GROWTH_FACTOR = 2;

    /**
     * @brief Resizes the vector to the new capacity
     */
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
    /**
     * @brief Constructor
     */
    EntityVector() {
        this->size = 0;
        this->capacity = DEFAULT_CAPACITY;
        this->data = new T[capacity];
    }

    /**
     * @brief Constructs a vector with the given capacity
     */
    explicit EntityVector(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->data = new T[capacity];
    }

    /**
     * @brief Copy constructor
     * @param other the vector to copy
     */
    EntityVector(const EntityVector &other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->data[i] = other.data[i];
        }
    }

    /**
     * @brief Destructor
     */
    ~EntityVector() {
        delete[] this->data;
    }

    /**
     * @brief Copy constructor using = operator
     * @param other the vector to copy
     */
    EntityVector<T> &operator=(const EntityVector<T> &other) {
        this->size = other.size;
        this->capacity = other.capacity;
        delete[] this->data;
        this->data = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->data[i] = other.data[i];
        }
        return *this;
    }

    /**
     * @brief Access the element at the given index using [] operator
     * @param index the index of the element
     */
    T &operator[](int index) {
        return data[index];
    }

    /**
     * @brief Get the size of the vector
     * @return the size of the vector
     */
    int getSize() const {
        return this->size;
    }

    /**
     * @brief Get the capacity of the vector
     * @return the capacity of the vector
     */
    int getCapacity() const {
        return this->capacity;
    }

    /**
     * @brief Add an element to the end of the vector
     * @param value the element to add
     */
    void push_back(T value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    /**
     * @brief Remove the last element of the vector and return it
     * @return the last element of the vector
     */
    T pop_back() {
        if (size == 0) {
            throw std::out_of_range("EntityVector is empty");
        }
        T value = data[size - 1];
        this->erase(size - 1);
        size--;
        return value;
    }

    /**
     * @brief Insert an element at the given index
     * @param index the index to insert at
     * @param value the element to insert
     */
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

    /**
     * @brief Remove the element at the given index
     * @param index the index of the element to remove
     */
    void erase(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    /**
     * '@brief Clear the vector
     */
    void clear() {
        delete[] data;
        size = 0;
        this->capacity = DEFAULT_CAPACITY;
        data = new T[capacity];
    }

    /**
     * @brief Print the vector to ostream
     * @param os the ostream to print to
     * @param vector the vector to print
     * @return the ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const EntityVector<T> &vector) {
        for (int i = 0; i < vector.size; i++) {
            os << i << ")" << vector.data[i] << std::endl;
        }
        return os;
    }
};


#endif //LAB_7_8_ENTITYVECTOR_H
