#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{


MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    : container_(container), primeContainer_(new vector<int *>)
{
    container_.primeIterators.push_back(this);
    if(container_.container_.size() != 0){
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            if (isPrime(*it))
            {
                primeContainer_->push_back(&(*it));
            }
        }    
    }
    primeContainer_->push_back(&(*container_.container_.end()));
    // Sort the primedMagic_ vector
    sort(primeContainer_->begin(), primeContainer_->end()-1,compareByValue);

    // Initialize the iterator
    itPos_ = primeContainer_->begin();
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)
{
    if (this != &other) {

        if(container_ !=other.container_){
            throw runtime_error("A operator=: container_ and other.container_ are not the same");    
        }

        delete this->primeContainer_;
        this->primeContainer_= new vector<int *>;

        for (auto it = other.primeContainer_->begin(); it != other.primeContainer_->end(); ++it){
            this->primeContainer_->push_back(*it);
        }

        itPos_=find(primeContainer_->begin(),primeContainer_->end(),*other.itPos_);
    }
    return *this;
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other)
    :container_(other.container_),primeContainer_(new vector<int *>)
{
    container_.primeIterators.push_back(this);

    for (auto it = other.primeContainer_->begin(); it != other.primeContainer_->end(); ++it){
        this->primeContainer_->push_back(*it);
    }
    itPos_=find(primeContainer_->begin(),primeContainer_->end(),*other.itPos_);
}

MagicalContainer::PrimeIterator::~PrimeIterator(){
    delete primeContainer_;
    auto it = find(container_.primeIterators.begin(),container_.primeIterators.end(),this);
    if(it != container_.primeIterators.end()){
        container_.primeIterators.erase(it);
        // cout<<"delete P"<<endl;
    }
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return *(*itPos_);
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){

    if(itPos_==primeContainer_->end()-1){
        throw runtime_error("operator++: out of bound");
    }
    ++(itPos_);
    return *this;
}
        
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int){

    if(itPos_==primeContainer_->end()-1){
        throw runtime_error("operator++: out of bound");
    }

    PrimeIterator temp(*this);
    ++(itPos_);
    return temp;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator--() {
    if(itPos_==primeContainer_->begin()){
        throw runtime_error("operator--: out of bound");
    }
    --(itPos_);
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator--(int){
    if(itPos_==primeContainer_->begin()){
        throw runtime_error("operator--: out of bound");
    }
    PrimeIterator temp (*this);
    --(itPos_);
    return temp;
}


bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator==: containers are not the same");
    }
    return *itPos_ == *other.itPos_;
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator!=: containers are not the same");
    }
    return *itPos_ != *other.itPos_;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator<: containers are not the same");
    }
    return *itPos_ < *other.itPos_;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator>: containers are not the same");
    }
    return *itPos_ > *other.itPos_;
}

bool MagicalContainer::PrimeIterator::operator<=(const MagicalContainer::PrimeIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator<=: containers are not the same");
    }
    return *itPos_ <= *other.itPos_;
}

bool MagicalContainer::PrimeIterator::operator>=(const MagicalContainer::PrimeIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator>=: containers are not the same");
    }
    return *itPos_ >= *other.itPos_;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
    PrimeIterator temp(*this);
    temp.itPos_=primeContainer_->begin();
    return temp;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
    PrimeIterator temp(*this);
    temp.itPos_=primeContainer_->end()-1;
    return temp;
}

void MagicalContainer::PrimeIterator::addElement(){/*TODO*/
    int *pos= *itPos_;
    
    int *data = &container_.container_.back();
    if(isPrime(*data)){
        auto it = primeContainer_->begin();
        while(it!= primeContainer_->end()-1 && **it < *data){
            ++it;
        }
        
        primeContainer_->insert(it, data);
        it=primeContainer_->end()-1;
        *it=&(*container_.end());

        itPos_=find(primeContainer_->begin(), primeContainer_->end(), pos);
    }
}

void MagicalContainer::PrimeIterator::removeElement(int* pdata){
    if(isPrime(*pdata)){
        // cout<<"P removeElement = "<<*pdata<<endl;
        auto it = find(primeContainer_->begin(),primeContainer_->end(),pdata);
        if(it!=primeContainer_->end()){
            primeContainer_->erase(it);
        }else{
            throw runtime_error("P not exist element");
        }
    }
}

}