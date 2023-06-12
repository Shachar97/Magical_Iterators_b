#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "prime.hpp"

using namespace std;

namespace ariel{

class MagicalContainer
{
private:
vector<int > container_;
    
public:

/*~~~~~~~AscendingIterator~~~~~~~~~*/
class AscendingIterator
{
private:
vector<int *>::iterator  itPos_;
std::vector<int *> * sortedContainer_;
MagicalContainer& container_;

public:
AscendingIterator(MagicalContainer& container);

AscendingIterator& operator=(const AscendingIterator& other);

AscendingIterator(const AscendingIterator& other);

~AscendingIterator();

friend ostream& operator<<(ostream& os, const AscendingIterator& it)
{
    os << **(it.itPos_);
    return os;
}

int operator*() const;

AscendingIterator& operator++();

AscendingIterator operator++(int);

AscendingIterator& operator--();

AscendingIterator operator--(int);

bool operator==(const AscendingIterator other) const;

bool operator!=(const AscendingIterator other) const;

bool operator<(const AscendingIterator other) const;

bool operator>(const AscendingIterator other) const;

bool operator<=(const AscendingIterator other) const;

bool operator>=(const AscendingIterator other) const;



AscendingIterator begin();

AscendingIterator end();

void addElement();
void removeElement(int* pdata);

};

/*~~~~~~~SideCrossIterator~~~~~~~~~*/
class SideCrossIterator
{
private:

vector<int *>::iterator  itPos_;
std::vector<int *> * sidedContainer_;
MagicalContainer& container_;
            
public:
SideCrossIterator(MagicalContainer& container);

SideCrossIterator& operator=(const SideCrossIterator& other);

SideCrossIterator(const SideCrossIterator& other);

~SideCrossIterator();

/*
TODO OPERATORS
*/
friend ostream& operator<<(ostream& os, const SideCrossIterator& it) {
    os << **(it.itPos_);
    return os;
}

int operator*() const;

SideCrossIterator& operator++();
    
SideCrossIterator operator++(int);

SideCrossIterator& operator--();
    
SideCrossIterator operator--(int);

bool operator==(const SideCrossIterator other) const;

bool operator!=(const SideCrossIterator other) const ;

bool operator<(const SideCrossIterator other) const;

bool operator>(const SideCrossIterator other) const ;

bool operator<=(const SideCrossIterator other) const ;

bool operator>=(const SideCrossIterator other) const ;

SideCrossIterator  begin();

SideCrossIterator  end();

void addElement();
void removeElement(int* pdata);
};

/*~~~~~~~PrimeIterator~~~~~~~~~*/
class PrimeIterator
{
private:
vector<int *>::iterator  itPos_;
std::vector<int *>* primeContainer_;
MagicalContainer& container_;

public:
PrimeIterator(MagicalContainer& container);

PrimeIterator& operator=(const PrimeIterator& other);

PrimeIterator(const PrimeIterator& other);

~PrimeIterator();

friend ostream& operator<<(ostream& os, const PrimeIterator& it) {
    os << **(it.itPos_);
    return os;
}

int operator*() const;

PrimeIterator& operator++();
    
PrimeIterator operator++(int);

PrimeIterator& operator--();

PrimeIterator operator--(int);


bool operator==(const PrimeIterator other) const ;


bool operator!=(const PrimeIterator other) const;

bool operator<(const PrimeIterator other) const ;

bool operator>(const PrimeIterator other) const ;


bool operator<=(const PrimeIterator other) const;


bool operator>=(const PrimeIterator other) const ;


PrimeIterator begin();

PrimeIterator end();


void addElement();
void removeElement(int* pdata);
};

/*~~~~~~~MagicalContainer~~~~~~~~~*/
private:

vector<AscendingIterator *> ascIterators;
vector<SideCrossIterator *> sideIterators;
vector<PrimeIterator *> primeIterators;

public:

MagicalContainer();

~MagicalContainer();

void addElement(int data);

void removeElement(int data);

bool operator==(const MagicalContainer& other) const;

bool operator!=(const MagicalContainer& other) const;

int size() const;

vector<int>::iterator begin();

vector<int>::iterator end();

void adding_update();

void removing_update(int * pdata);

vector<AscendingIterator *>& getAscendingIterators();

vector<SideCrossIterator *>& getSideCrossIterators();

vector<PrimeIterator *>& getPrimeIterators();

};

}


#endif