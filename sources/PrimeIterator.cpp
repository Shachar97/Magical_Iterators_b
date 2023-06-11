#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{


ariel::MagicalContainer::PrimeIterator::PrimeIterator(ariel::MagicalContainer &container): container_(container)
{
    cout<<"the container:"<<endl;
    for (auto over_container=container.begin(); over_container != container.end(); ++over_container)
    {
        cout<<*over_container<<", ";
    }
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        if (isPrime(*it))
        {
            primeContainer_.push_back(*it);
        }
    }
    cout<<"the container:"<<endl;
    for (auto over_container=container.begin(); over_container != container.end(); ++over_container)
    {
        cout<<*over_container<<", ";
    }

    // Sort the primedMagic_ vector
    sort(primeContainer_.begin(), primeContainer_.end());

    // Initialize the iterator
    it_ = primeContainer_.begin();
}


    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator=(const ariel::MagicalContainer::PrimeIterator &other) {
        if (this != &other) {
            this->container_ = other.container_;
            this->primeContainer_ = other.primeContainer_;
            this->it_=other.it_;
        }
        return *this;
    }

    ariel::MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer::PrimeIterator &other):container_(other.container_),primeContainer_(other.primeContainer_),it_(other.it_){
    }

    ariel::MagicalContainer::PrimeIterator::~PrimeIterator(){
    }

    int ariel::MagicalContainer::PrimeIterator::operator*() const
    {
        return *(it_);
    }

    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator++(){

        if(it_>=primeContainer_.end()){
            throw runtime_error("operator++: out of bound");
        }
        ++(it_);
        return *this;
    }
            
    ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::operator++(int){

        if(it_>=primeContainer_.end()){
            throw runtime_error("operator++: out of bound");
        }

        PrimeIterator temp(*this);
        ++(it_);
        return temp;
    }

ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator--() {
    if(it_<=primeContainer_.begin()){
        throw runtime_error("operator--: out of bound");
    }
    --(it_);
    return *this;
}
    
ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::operator--(int){
    if(it_<=primeContainer_.begin()){
        throw runtime_error("operator--: out of bound");
    }
    PrimeIterator temp (*this);
    --(it_);
    return temp;
}
    

    bool ariel::MagicalContainer::PrimeIterator::operator==(const ariel::MagicalContainer::PrimeIterator &other) const {
        return it_ == other.it_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator!=(const ariel::MagicalContainer::PrimeIterator &other) const {
        return !(*this == other);
    }

    bool ariel::MagicalContainer::PrimeIterator::operator<(const ariel::MagicalContainer::PrimeIterator &other) const {
        return it_ < other.it_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator>(const ariel::MagicalContainer::PrimeIterator &other) const {
        return it_ > other.it_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator<=(const ariel::MagicalContainer::PrimeIterator &other) const {
        return it_ <= other.it_;
    }

    bool ariel::MagicalContainer::PrimeIterator::operator>=(const ariel::MagicalContainer::PrimeIterator &other) const {
        return it_ >= other.it_;
    }

    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::begin(){
        it_=primeContainer_.begin();
        return *this;
    }
    ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::end(){
        it_=primeContainer_.end();
        return *this;
    }

    void ariel::MagicalContainer::PrimeIterator::addElement(int data){/*TODO*/
        // if(isPrime(data)){
        //     if(primeIter_->size()==0){
        //         primeIter_->push_back(data);
        //     }else{
        //         auto it = primeIter_->begin();
        //         while(it != primeIter_->end()){
        //             if(data<*it){
        //                 /*INSERT DATA*/
        //                 primeIter_->insert(it,data);
        //                 return;
        //             }
        //             ++it;
        //         }
        //         primeIter_->push_back(data);
        //     }
        // }
    }
}