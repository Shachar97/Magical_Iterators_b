#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    :container_(container),sortedContainer_(new std::vector<int *>())
{
    container_.ascIterators.push_back(this);
    if(container.size() != 0){
        for(auto over_container=container_.begin(); over_container != container_.end(); ++over_container){
            sortedContainer_->push_back(&(*over_container));
        }
    }
        /*hold in last position address of container_.end()*/
        sortedContainer_->push_back(&(*container_.end())); 

        /*sort the addresses by value of the elements holds*/
        sort(sortedContainer_->begin(), sortedContainer_->end()-1,compareByValue);

        /*initial itPos to the beginning*/
        itPos_ = sortedContainer_->begin();
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator& other)
    : container_(other.container_),sortedContainer_(new vector<int *>()) 
{        
    container_.ascIterators.push_back(this);

    for(itPos_=other.sortedContainer_->begin(); itPos_!= other.sortedContainer_->end(); ++itPos_){
        sortedContainer_->push_back(*itPos_);
    }
    itPos_ = find(sortedContainer_->begin(), sortedContainer_->end(), *(other.itPos_));
    // it_=other.it_;
}



MagicalContainer::AscendingIterator::~AscendingIterator()
{
    delete sortedContainer_;
    auto pos = find(container_.ascIterators.begin(), container_.ascIterators.end(), this);
    if(pos!= container_.ascIterators.end()){
        container_.ascIterators.erase(pos);
        // cout<<"delete AscendingIterator"<<endl;
    }
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator& other) {
    // cout << "in operator=" << endl;
    if (this != &other) {
        if(container_ !=other.container_){
            throw runtime_error("A operator=: container_ and other.container_ are not the same");    
        }

        delete sortedContainer_;

        sortedContainer_ = new vector<int*>;
        for(itPos_=other.sortedContainer_->begin(); itPos_!= other.sortedContainer_->end(); ++itPos_){
            sortedContainer_->push_back(*itPos_);
        }
        // it_ = find(sortedContainer_->begin(), sortedContainer_->end(), *(other.it_));
        itPos_=other.itPos_;
        
    }

    return *this;
}


int MagicalContainer::AscendingIterator::operator*() const
{
    return **(this->itPos_);
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if( itPos_== sortedContainer_->end()-1 ){
        throw runtime_error("A operator++: out of bound");
    }
    ++itPos_;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int)
{   
    if(itPos_==sortedContainer_->end()-1){
        throw runtime_error("A operator++: out of bound");
    }
    AscendingIterator temp(*this);
    // AscendingIterator(*this, itPos_+1);
    ++(itPos_);
    return temp;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator--()
{
    // cout<<"in operator--"<<endl;
    if(itPos_==sortedContainer_->begin()){
        throw runtime_error("A operator--: out of bound");
    }
    --(itPos_);
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator--(int)
{
    // cout<<"in operator--"<<endl;
    if(itPos_<=sortedContainer_->begin()){
        throw runtime_error("A operator--: out of bound");
    }
    AscendingIterator temp(*this);
    // AscendingIterator(*this, itPos_-1);
    --(itPos_);
    return temp;
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator other) const
{
    // cout << "A in operator==" << endl;
    if(this->container_==other.container_){
        // cout << *(this->itPos_) << " ? " << *(other.itPos_) << endl;
        return *(this->itPos_) == *(other.itPos_);
    }else{
        throw runtime_error("A operator==: not the same container");
    }
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator other) const {
    // cout<<"A in operator!="<<endl;
    if (this->container_ == other.container_) {
        // cout << *(this->itPos_) << " ? " << *(other.itPos_) << endl;
        return *itPos_ != *other.itPos_;
    } else {
        throw runtime_error("A operator!=: not the same container");
    }
}


bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator other) const
{
    if(this->container_==other.container_){
        return *itPos_ < *other.itPos_;
    }else{
        throw runtime_error("A operator<: not the same container");
    }
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator other) const
{
    if(this->container_==other.container_){
        return *itPos_ > *other.itPos_;
    }else{
        throw runtime_error("A operator>: not the same container");
    }
    
}

bool MagicalContainer::AscendingIterator::operator<=(const MagicalContainer::AscendingIterator other) const
{
    if(this->container_==other.container_){
        return *itPos_ <= *other.itPos_;
    }else{
        throw runtime_error("A operator<=: not the same container");
    }
    
}

bool MagicalContainer::AscendingIterator::operator>=(const MagicalContainer::AscendingIterator other) const
{   
    if(this->container_==other.container_){
        return *itPos_ >= *other.itPos_;
    }else{
        throw runtime_error("A operator>=: not the same container");
    }
    
}   

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
    // return AscendingIterator(*this, sortedContainer_->begin());
    AscendingIterator temp(*this);
    temp.itPos_=sortedContainer_->begin();
    return temp;
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
    // return AscendingIterator(*this, sortedContainer_->end()-1);
    AscendingIterator temp(*this);
    temp.itPos_=sortedContainer_->end()-1;
    return temp;
}

void MagicalContainer::AscendingIterator::addElement()
{
    
    int *pos= *itPos_;
    
    int *newElement = &container_.container_.back();
    
    
    auto it = sortedContainer_->begin();
    while(it!= sortedContainer_->end()-1 && **it < *newElement){
        ++it;
    }
    
    sortedContainer_->insert(it, newElement);
    it=sortedContainer_->end()-1;
    *it=&(*container_.end());

    itPos_=find(sortedContainer_->begin(), sortedContainer_->end(), pos);

    
}



void MagicalContainer::AscendingIterator::removeElement(int * pdata){
    auto pos = find(sortedContainer_->begin(), sortedContainer_->end(), pdata);
    if(pos!= sortedContainer_->end()){
        sortedContainer_->erase(pos);
    }else{
        throw runtime_error("A not exist element");
    }
}

}