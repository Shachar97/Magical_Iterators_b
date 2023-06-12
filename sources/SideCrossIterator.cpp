#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    : container_(container),sidedContainer_(new vector<int *> )
{
    container_.sideIterators.push_back(this);
    if(container_.size()!=0){

        for(auto over_container=container_.begin(); over_container != container_.end(); ++over_container){
            sidedContainer_->push_back(&(*over_container));
        }   

        sidedContainer_->push_back(&(*container_.end()));
        sort(sidedContainer_->begin(),sidedContainer_->end()-1,compareByValue);

            
        // Initialize the iterators
        itPos_ = sidedContainer_->begin();

        auto temp =*sidedContainer_;
            
        auto st = temp.begin();
        auto en = temp.end() - 2;
        while (st < en) {

            /*add min val*/
            *itPos_=*st;
            ++itPos_;

            /*add max val*/
            *itPos_=*en;
            ++itPos_;

            /*promote st & en*/
            ++st;
            --en;
        }

        // Handle the middle element for odd-sized containers
        if (st == en) {
            *itPos_=*st;
        }

        // Reset the iterator position to the beginning
        itPos_ = sidedContainer_->begin();

    }else{//no elements in the container
        sidedContainer_->push_back(&(*container_.end()));
        itPos_ = sidedContainer_->begin();
    }
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)
{
    if (this != &other) {

        if(container_ !=other.container_){
            throw runtime_error("A operator=: container_ and other.container_ are not the same");    
        }

        delete sidedContainer_;

        sidedContainer_ = new vector<int *>;

        for( itPos_ =other.sidedContainer_->begin(); itPos_ != other.sidedContainer_->end(); ++itPos_){
            sidedContainer_->push_back(*itPos_);
        }

        // itPos_=other.itPos_;
        itPos_ =find(sidedContainer_->begin(),sidedContainer_->end(),*(other.itPos_));
    }
    return *this;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)
    :container_(other.container_),sidedContainer_(new vector<int *> )
{
    container_.sideIterators.push_back(this);
    for( itPos_ =other.sidedContainer_->begin(); itPos_ != other.sidedContainer_->end(); ++itPos_){
            sidedContainer_->push_back(*itPos_);
    }
    // itPos_=other.itPos_;
    itPos_ =find(sidedContainer_->begin(),sidedContainer_->end(),*(other.itPos_));
}


MagicalContainer::SideCrossIterator::~SideCrossIterator(){
    delete sidedContainer_;
    
    auto it = find(container_.sideIterators.begin(),container_.sideIterators.end(),this);

    if(it!=container_.sideIterators.end()){
        container_.sideIterators.erase(it);
        // cout<<"delete S"<<endl;
    }
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return *(*itPos_);
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
    if(itPos_==sidedContainer_->end()-1){
        throw runtime_error("S operator++: out of bound");
    }
    ++(itPos_);
    return *this;
}
    
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int){
    if(itPos_==sidedContainer_->end()-1){
        throw runtime_error("S operator++: out of bound");
    }
    SideCrossIterator temp(*this);
    ++(itPos_);
    return temp;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator--(){
    
    if(itPos_==sidedContainer_->begin()){
        throw runtime_error("S operator--: out of bound");
    }

    --(itPos_);
    return *this;
}
    
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator--(int)
{

    if(itPos_==sidedContainer_->begin()){
        throw runtime_error("S operator--: out of bound");
    }

    SideCrossIterator temp (*this);
    --(itPos_);
    return temp;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator other) const
{
    if(this->container_ != other.container_){
        throw runtime_error("S operator==: containers are not the same");
    }
    // cout<<"S operator=="<<endl;
    return *itPos_ == *other.itPos_;
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator other) const
{
    // cout<<"S operator!="<<endl;
    // cout<<*itPos_<<" "<<*other.itPos_<<endl;
    if(this->container_ != other.container_){
        throw runtime_error("S operator!=: containers are not the same");
    }
    return *itPos_ != *other.itPos_;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator other) const{
    if(this->container_ != other.container_){
        throw runtime_error("S operator<: containers are not the same");
    }
    return *itPos_ < *other.itPos_;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator other) const{
    if(this->container_ != other.container_){
        throw runtime_error("S operator>: containers are not the same");
    }
    return *itPos_ > *other.itPos_;
}

bool MagicalContainer::SideCrossIterator::operator<=(const MagicalContainer::SideCrossIterator other) const{
    if(this->container_ != other.container_){
        throw runtime_error("S operator<=: containers are not the same");
    }
    return *itPos_ <= *other.itPos_;
}

bool MagicalContainer::SideCrossIterator::operator>=(const MagicalContainer::SideCrossIterator other) const {
    if(this->container_ != other.container_){
        throw runtime_error("S operator>=: containers are not the same");
    }
    return *itPos_ >= *other.itPos_;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
    SideCrossIterator temp(*this);
    temp.itPos_=sidedContainer_->begin();
    return temp;
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
    SideCrossIterator temp(*this);
    temp.itPos_=sidedContainer_->end()-1;
    return temp;
}

void MagicalContainer::SideCrossIterator::addElement(){

    int *data= &container_.container_.back();
    int *p_end= sidedContainer_->back();
    int *pos=*itPos_;
    sidedContainer_->pop_back();
    sidedContainer_->push_back(data);
    sidedContainer_->push_back(p_end);
    sort(sidedContainer_->begin(),sidedContainer_->end()-1,compareByValue);

    itPos_ = sidedContainer_->begin();

        auto temp =*sidedContainer_;
            
        auto st = temp.begin();
        auto en = temp.end() - 2;
        while (st < en) {

            /*add min val*/
            *itPos_=*st;
            ++itPos_;

            /*add max val*/
            *itPos_=*en;
            ++itPos_;

            /*promote st & en*/
            ++st;
            --en;
        }

        // Handle the middle element for odd-sized containers
        if (st == en) {
            *itPos_=*st;
        }

        auto it=sidedContainer_->end()-1;
        *it=&(*container_.end());

        itPos_=find(sidedContainer_->begin(),sidedContainer_->end(),pos);
}

void MagicalContainer::SideCrossIterator::removeElement(int* pdata){
    // cout<<"S removeElement = "<<*pdata<<endl;
    auto it = find(sidedContainer_->begin(),sidedContainer_->end(),pdata);
    if(it!=sidedContainer_->end()){
        sidedContainer_->erase(it);
    }else{
        throw runtime_error("S not exist element");
    }
}



}