//
// Created by Antonio on 4/3/2022.
//
#include <iostream>

#ifndef LAB_7_8_ENTITY_H
#define LAB_7_8_ENTITY_H

class Apartment {
private:
    unsigned int apartmentNumber;
public:
    /**
     * Constructor
     */
    Apartment();

    /**
     * Constructor
     * @param apartmentNumber - apartment number
     */
    explicit Apartment(int apartmentNumber);

    /**
     * Copy constructor
     * @param other the object to copy
     */
    Apartment(const Apartment& other);

    /**
     * Destructor
     */
     ~Apartment();

     /**
      * Setter for id
      * @param id the id to set
      */
     void setId(int id);

     /**
      * Getter for id
      * @return the id
      */
     unsigned int getApartmentNumber() const;

     /**
      * Overload of the operator <<
      * @param os the output stream
      * @param entity the entity to print
      * @return the output stream
      */
     friend std::ostream& operator<<(std::ostream& os, const Apartment& entity);

     /**
      * Overload of the operator >>
      * @param is the input stream
      * @param entity the other entity
      * @return the input stream
      */
     friend std::istream& operator>>(std::istream& is, Apartment& entity);
};

#endif //LAB_7_8_ENTITY_H
