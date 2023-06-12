/**
 * @package "Magical_iterators_b"
 * @file sources/MagicalContainer.hpp- 
 * * declarations of MagicalContainer class
 * * include sub-classes of AscendingIterator, SideCrossIterator and PrimeIterator.
 * @class MagicalContainer- this class crieate a container of Magical objects.
 * * with his sub-classes, you can move over the container in three different ways:
 * @class AsciendingIterator- this present as iterator for the MagicalContainer object.
 * * it points to the smallest element in the container, and move over the container elemets in sort order.
 * @class SideCrossIterator- this present as iterator for the MagicalContainer object.
 * * it points to the smallest element in the container, and move over the container elemets in reverse order- 
 * * ones the smallest element in the container, and ones the largest element in the container.
 * @class PrimeIterator- this present as iterator for the MagicalContainer object. 
 * * it points to the smallest element in the container, and move only over the container elemets that are prime numbers.

 * @author Shachar Ketz
*/

#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "helper_funcs.hpp"

using namespace std;

namespace ariel{

/**
 * @class MagicalContainer
 * this class crieate a container of Magical objects.
*/
class MagicalContainer
{

public:

/*~~~~~~~AscendingIterator~~~~~~~~~*/
/**
 * @class AscendingIterator
 * this present as iterator for the MagicalContainer object.
 * * it points to the smallest element in the container, and move over the container elemets in sort order.
*/
class AscendingIterator
{
private:

/**
 * itPos is iterator of vector<int *> that point on some element in the the sortedContainer_.
*/
vector<int *>::iterator  itPos_;

/**
 * sortedContainer_- vector that hold all the addresses of the elements of the container in sort order.
 * to move over the container elemets in sort order.
*/
std::vector<int *> * sortedContainer_;

/**
 * container_- reference of MagicalContainer object.
*/
MagicalContainer& container_;

public:
/**
 * AscendingIterator constructor.
 * @param itPos iterator of vector<int *> that point on some element in the the sortedContainer_.
 * @param sortedContainer_- vector that hold all the addresses of the elements of the container in sort order.
 * to move over the container elemets in sort order.
 */
AscendingIterator(MagicalContainer& container);

/**
 * AscendingIterator operator=.
 * @param other AscendingIterator object.
 * @exception runtime_error if the contaner is diffrent from other.
*/
AscendingIterator& operator=(const AscendingIterator& other);

/**
 * copy constructor.
 * @param other AscendingIterator object.
 * create a copy of other. include other position
*/
AscendingIterator(const AscendingIterator& other);

/**
 * destructor.
*/
~AscendingIterator();

/**
 * operator<<
 * @param os - output stream.
 * @param it - AscendingIterator object.
*/
friend ostream& operator<<(ostream& os, const AscendingIterator& it)
{
    os << **(it.itPos_);
    return os;
}

/**
 * operator * 
 * @return the element pointed by AscendingIterator object.
*/
int operator*() const;

/**
 * operator ++
 * @return the pointer element pointed by AscendingIterator object.
*/
AscendingIterator& operator++();

/**
 * operator ++
 * @return the pointer element pointed by AscendingIterator object.
*/
AscendingIterator operator++(int);

/**
 * operator --
 * @return the pointer element pointed by AscendingIterator object.
*/
AscendingIterator& operator--();

/**
 * operator --
 * @return the pointer element pointed by AscendingIterator object.
*/
AscendingIterator operator--(int);

/**
 * operator ==
 * @return true if AscendingIterator object is equal to other.
*/
bool operator==(const AscendingIterator other) const;

/**
 * operator !=
 * @return true if AscendingIterator object is not equal to other.
*/
bool operator!=(const AscendingIterator other) const;

/**
 * operator <
 * @return true if AscendingIterator object is less than other.
*/
bool operator<(const AscendingIterator other) const;

/**
 * operator >
 * @return true if AscendingIterator object is greater than other.
*/
bool operator>(const AscendingIterator other) const;

/**
 * operator ==
 * @return true if AscendingIterator object is less or equal to other.
*/
bool operator<=(const AscendingIterator other) const;

/**
 * operator >=
 * @return true if AscendingIterator object is greater or equal to other.
*/
bool operator>=(const AscendingIterator other) const;

/**
 * function return the address that hold the smallest element. 
*/
AscendingIterator begin();

/**
 * function return the address that hold the end of the container.
*/
AscendingIterator end();

/**
 * function add new element to the pointer vector.
*/
void addElement();

/**
 * function remove element from the pointer vector.
*/
void removeElement(int* pdata);

};

/*~~~~~~~SideCrossIterator~~~~~~~~~*/
/**
 * @class SideCrossIterator
 * this present as iterator for the MagicalContainer object.
 * * it points to the smallest element in the container, and move over the container, 
 * * ones the smallest add elemet, ones the largest element.
*/
class SideCrossIterator
{
private:

/**
 * itPos is iterator of vector<int *> that point on some element in the the sortedContainer_.
*/
vector<int *>::iterator  itPos_;

/**
 * sidedContainer_- vector that hold all the addresses of the elements of the container in sort order.
 * to move over the container elemets in sort order.
*/
std::vector<int *> * sidedContainer_;

/**
 * container_- reference of MagicalContainer object.
*/
MagicalContainer& container_;
            
public:

/**
 * SideCrossIterator constructor.
 * @param container_- reference of MagicalContainer object.
*/
SideCrossIterator(MagicalContainer& container);

/**
 * SideCrossIterator operator=.
 * @param other SideCrossIterator object.
 * @exception runtime_error if the contaner is diffrent from other.
*/
SideCrossIterator& operator=(const SideCrossIterator& other);

/**
 * copy constructor.
 * @param other SideCrossIterator object.
 * create a copy of other. include other position
*/
SideCrossIterator(const SideCrossIterator& other);

/**
 * destructor.
*/
~SideCrossIterator();

/**
 * operator<<
 * @param os - output stream.
 * @param it - SideCrossIterator object.
*/
friend ostream& operator<<(ostream& os, const SideCrossIterator& it) {
    os << **(it.itPos_);
    return os;
}

/**
 * operator * 
 * @return the element pointed by SideCrossIterator object.
*/
int operator*() const;

/**
 * operator ++
 * @return the pointer element to the next element in the container.
*/
SideCrossIterator& operator++();

/**
 * operator ++
 * @return the pointer element to the next element in the container.
*/  
SideCrossIterator operator++(int);

/**
 * operator --
 * @return the pointer element to the prev element in the container.
*/
SideCrossIterator& operator--();

/**
 * operator --
 * @return the pointer element to the prev element in the container.
*/    
SideCrossIterator operator--(int);

/**
 * operator ==
 * @return true if SideCrossIterator object is equal to other.
*/
bool operator==(const SideCrossIterator other) const;

/**
 * operator !=
 * @return true if SideCrossIterator object is not equal to other.
*/
bool operator!=(const SideCrossIterator other) const ;

/**
 * operator <
 * @return true if SideCrossIterator object is less than other.
*/
bool operator<(const SideCrossIterator other) const;

/**
 * operator >
 * @return true if SideCrossIterator object is greater than other.
*/
bool operator>(const SideCrossIterator other) const ;

/**
 * operator ==
 * @return true if SideCrossIterator object is less or equal to other.
*/
bool operator<=(const SideCrossIterator other) const ;

/**
 * operator >=
 * @return true if SideCrossIterator object is greater or equal to other.
*/
bool operator>=(const SideCrossIterator other) const ;

/**
 * function return the address that hold the smallest element. 
*/
SideCrossIterator  begin();

/**
 * function return the address that hold the end of the container.
*/
SideCrossIterator  end();

/**
 * function add new element to the pointer vector.
*/
void addElement();

/**
 * function remove element from the pointer vector.
*/
void removeElement(int* pdata);
};

/*~~~~~~~PrimeIterator~~~~~~~~~*/
class PrimeIterator
{
private:

/**
 * itPos is iterator of vector<int *> that point on some element in the the primeContainer_.
*/
vector<int *>::iterator  itPos_;

/**
 * primeContainer_- vector that hold all the addresses of the elements that is prime numbers of the container in sort order.
 * to move over the container elemets in prime-sort order.
*/
std::vector<int *>* primeContainer_;

/**
 * container_- reference of MagicalContainer object.
*/
MagicalContainer& container_;

public:

/**
 * PrimeIterator constructor.
 * @param container_- reference of MagicalContainer object.
*/
PrimeIterator(MagicalContainer& container);

/**
 * PrimeIterator operator=.
 * @param other PrimeIterator object.
 * @exception runtime_error if the contaner is diffrent from other.
*/
PrimeIterator& operator=(const PrimeIterator& other);

/**
 * copy constructor.
 * @param other PrimeIterator object.
 * create a copy of other. include other position
*/
PrimeIterator(const PrimeIterator& other);

/**
 * destructor.
*/
~PrimeIterator();

/**
 * operator<<
 * @param os - output stream.
 * @param it - PrimeIterator object.
 * @return the output stream.
*/
friend ostream& operator<<(ostream& os, const PrimeIterator& it) {
    os << **(it.itPos_);
    return os;
}

/**
 * operator * 
 * @return the element pointed by PrimeIterator object.
*/
int operator*() const;

/**
 * operator ++
 * @return the pointer element to the next element in the container that is prime.
*/
PrimeIterator& operator++();

/**
 * operator ++
 * @return the pointer element to the next element in the container that is prime.
*/
PrimeIterator operator++(int);

/**
 * operator -
 * @return the pointer element to the prev element in the container that is prime.
*/
PrimeIterator& operator--();

/**
 * operator --
 * @return the pointer element to the prev element in the container that is prime.
*/
PrimeIterator operator--(int);

/**
 * operator ==
 * @return true if PrimeIterator object is equal to other.
*/
bool operator==(const PrimeIterator other) const ;

/**
 * operator !=
 * @return true if PrimeIterator object is not equal to other.
*/
bool operator!=(const PrimeIterator other) const;

/**
 * operator <
 * @return true if PrimeIterator object is less than other.
*/
bool operator<(const PrimeIterator other) const ;

/**
 * operator >
 * @return true if PrimeIterator object is greater than other.
*/
bool operator>(const PrimeIterator other) const ;

/**
 * operator ==
 * @return true if PrimeIterator object is less or equal to other.
*/
bool operator<=(const PrimeIterator other) const;

/**
 * operator >=
 * @return true if PrimeIterator object is greater or equal to other.
*/
bool operator>=(const PrimeIterator other) const ;

/**
 * function return the address that hold the smallest prime element. 
*/
PrimeIterator begin();

/**
 * function return the address that hold the end of the container.
*/
PrimeIterator end();

/**
 * function add new element to the pointer vector.
*/
void addElement();

/**
 * function remove element from the pointer vector.
*/
void removeElement(int* pdata);

};

/*~~~~~~~MagicalContainer~~~~~~~~~*/
private:


/**
 * container_ is a vector of Magical objects-integer. 
 * in this container
*/
vector<int > container_;

/**
 * vector of pointers to AscendingIterator objects:
 * * is for updating any iterator that exist and hold address pointers of the container.
*/
vector<AscendingIterator *> ascIterators;

/**
 * vector of pointers to SideCrossIterator objects:
 * * is for updating any iterator that exist and hold address pointers of the container.
*/
vector<SideCrossIterator *> sideIterators;

/**
 * vector of pointers to PrimeIterator objects: is for updating any iterator that exist and hold
*/
vector<PrimeIterator *> primeIterators;

public:

/**
 * MagicalContainer constructor.
*/
MagicalContainer();

/**
 * MagicalContainer destructor.
*/
~MagicalContainer();

/**
 * function add new element to the container vector and update all the iterators. 
*/
void addElement(int data);

/**
 * function remove element from the container vector and update all the iterators. 
*/
void removeElement(int data);

/**
 * operator==
 * @return true if MagicalContainer object is equal to other.
*/
bool operator==(const MagicalContainer& other) const;

/**
 * operator!=
 * @return true if MagicalContainer object is not equal to other.
*/
bool operator!=(const MagicalContainer& other) const;

/**
 * the function return the count of elements in the container.
*/
int size() const;

/**
 * the function return iterator to the first    
*/
vector<int>::iterator begin();

/**
 * the function return iterator to the end
*/
vector<int>::iterator end();

/**
 * helper function to update the iterators.
*/
void adding_update();

/**
 * helper function to update the iterators.
*/
void removing_update(int * pdata);

/**
 * getter of vector<AscendingIterator *>
*/
vector<AscendingIterator *>& getAscendingIterators();

/**
 * getter of vector<SideCrossIterator *>
*/
vector<SideCrossIterator *>& getSideCrossIterators();

/**
 * getter of vector<PrimeIterator *>
*/

vector<PrimeIterator *>& getPrimeIterators();

};

}


#endif