#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{

MagicalContainer::MagicalContainer(){}

MagicalContainer::~MagicalContainer(){}

void MagicalContainer::addElement(int data)
{

    container_.push_back(data);

    adding_update();

    return;
}

void MagicalContainer::removeElement(int data)
{
    
    //find pdata:
    auto it = std::find(container_.begin(), container_.end(), data);
    int* pdata = &(*it);

    // Check if the element was found
    if (it != container_.end()) {
        
        //update Iterators
        removing_update(pdata);
        
        // Remove the element from the vector
        container_.erase(it);

    }else{
        throw runtime_error("not exist element");
    }
}

bool MagicalContainer::operator==(const MagicalContainer &other) const
{
    return container_ == other.container_;
}

bool MagicalContainer::operator!=(const MagicalContainer &other) const
{
    return container_ != other.container_;
}

int MagicalContainer::size() const{return container_.size();}

std::vector<int>::iterator MagicalContainer::begin(){return container_.begin();}

std::vector<int>::iterator MagicalContainer::end(){return container_.end();}

void MagicalContainer::adding_update()
{
    for(auto it = ascIterators.begin(); it!= ascIterators.end(); ++it){
        (*it)->addElement();
    }
    for(auto it = sideIterators.begin(); it!= sideIterators.end(); ++it){
        (*it)->addElement();
    }
    for(auto it = primeIterators.begin(); it!= primeIterators.end(); ++it){
        (*it)->addElement();
    }
}

void MagicalContainer::removing_update(int *pdata)
{
    // cout<<"M: updates the Removing element "<<*pdata<<endl;
    for(auto it = ascIterators.begin(); it!= ascIterators.end(); ++it){
        (*it)->removeElement(pdata);
    }

    for(auto it = sideIterators.begin(); it!= sideIterators.end(); ++it){
        (*it)->removeElement(pdata);
    }

    for(auto it = primeIterators.begin(); it!= primeIterators.end(); ++it){
        (*it)->removeElement(pdata);
    }
}

std::vector<MagicalContainer::AscendingIterator *> &MagicalContainer::getAscendingIterators(){return ascIterators;}

std::vector<MagicalContainer::SideCrossIterator *> &MagicalContainer::getSideCrossIterators(){return sideIterators;}

std::vector<MagicalContainer::PrimeIterator *> &MagicalContainer::getPrimeIterators(){return primeIterators;}

}