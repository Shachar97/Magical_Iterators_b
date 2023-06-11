#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{


ariel::MagicalContainer::AscendingIterator::AscendingIterator(ariel::MagicalContainer &container): container_(container) {
    sortedContainer_= new std::vector<int *>();
    if(container.size() != 0){
        for(auto over_container=container_.begin(); over_container != container_.end(); ++over_container){
            sortedContainer_->push_back(&(*over_container));
        }
        
        sort(sortedContainer_->begin(), sortedContainer_->end(),compareByValue);
        // for(auto over_container=sortedContainer_->begin(); over_container!= sortedContainer_->end(); ++over_container){
        //     cout << **over_container << endl;
        // }
    }
    it_ = sortedContainer_->begin();
    // cout<<**it_;
    cout << "@@@@@@@@@@@"<<endl;
}

ariel::MagicalContainer::AscendingIterator::AscendingIterator(const ariel::MagicalContainer::AscendingIterator& other)
    : container_(other.container_) {
        cout <<"in copy constructor"<<endl;
    // sortedContainer_ = new std::vector<int*>(*other.sortedContainer_);
    sortedContainer_ = new std::vector<int*>;
    for(it_=other.sortedContainer_->begin(); it_!= other.sortedContainer_->end(); ++it_){
        sortedContainer_->push_back(*it_);
    }
    it_ = std::find(sortedContainer_->begin(), sortedContainer_->end(), *(other.it_));
    cout<<*sortedContainer_->end()<<" , "<<*other.sortedContainer_->end()<<endl;
    cout << "@@@@@@@@@@@"<<endl;
}



ariel::MagicalContainer::AscendingIterator::~AscendingIterator()
{
    delete sortedContainer_;
}

ariel::MagicalContainer::AscendingIterator& ariel::MagicalContainer::AscendingIterator::operator=(const ariel::MagicalContainer::AscendingIterator& other) {
    cout << "in operator=" << endl;
    if (this != &other) {
        container_ = other.container_;

        delete sortedContainer_;

        sortedContainer_ = new std::vector<int*>(*other.sortedContainer_);

        it_ = std::find(sortedContainer_->begin(), sortedContainer_->end(), *(other.it_));
    }

    return *this;
}


int ariel::MagicalContainer::AscendingIterator::operator*() const
{
    cout << "in operator*" << endl;
    return **(this->it_);
}

ariel::MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::operator++()
{
    cout << "in operator++" << endl;
    if( it_== sortedContainer_->end() ){
        throw runtime_error("A operator++: out of bound");
    }
    ++it_;
    return *this;
}

ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::operator++(int)
{   
    cout<<"in operator++"<<endl;
    if(it_==sortedContainer_->end()){
        throw runtime_error("A operator++: out of bound");
    }
    AscendingIterator temp(*this);
    ++(it_);
    return temp;
}

ariel::MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::operator--()
{
    cout<<"in operator--"<<endl;
    if(it_<=sortedContainer_->begin()){
        throw runtime_error("A operator--: out of bound");
    }
    --(it_);
    return *this;
}

ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::operator--(int)
{
    cout<<"in operator--"<<endl;
    if(it_<=sortedContainer_->begin()){
        throw runtime_error("A operator--: out of bound");
    }
    AscendingIterator temp(*this);
    --(it_);
    return temp;
}

bool ariel::MagicalContainer::AscendingIterator::operator==(const ariel::MagicalContainer::AscendingIterator &other) const
{
    cout << "A in operator==" << endl;
    if(this->container_==other.container_){
        cout << *(this->it_) << " ? " << *(other.it_) << endl;
        return *(this->it_) == *(other.it_);
    }else{
        throw runtime_error("A operator==: not the same container");
    }
}

bool ariel::MagicalContainer::AscendingIterator::operator!=(const ariel::MagicalContainer::AscendingIterator& other) const {
    cout<<"A in operator!="<<endl;
    if (this->container_ == other.container_) {
        cout << *(this->it_) << " ? " << *(other.it_) << endl;
        return *it_ != *other.it_;
    } else {
        throw runtime_error("A operator!=: not the same container");
    }
}


bool ariel::MagicalContainer::AscendingIterator::operator<(const ariel::MagicalContainer::AscendingIterator &other) const
{
    if(this->container_==other.container_){
        return it_ < other.it_;
    }else{
        throw runtime_error("A operator<: not the same container");
    }
}

bool ariel::MagicalContainer::AscendingIterator::operator>(const ariel::MagicalContainer::AscendingIterator &other) const
{
    if(this->container_==other.container_){
        return it_ > other.it_;
    }else{
        throw runtime_error("A operator>: not the same container");
    }
    
}

bool ariel::MagicalContainer::AscendingIterator::operator<=(const ariel::MagicalContainer::AscendingIterator &other) const
{
    if(this->container_==other.container_){
        return it_ <= other.it_;
    }else{
        throw runtime_error("A operator<=: not the same container");
    }
    
}

bool ariel::MagicalContainer::AscendingIterator::operator>=(const ariel::MagicalContainer::AscendingIterator &other) const
{   
    if(this->container_==other.container_){
        return it_ >= other.it_;
    }else{
        throw runtime_error("A operator>=: not the same container");
    }
    
}   

ariel::MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::begin(){
    it_=sortedContainer_->begin();
    return *this;
}

ariel::MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::end(){
    // cout << "in end func:" << **(sortedContainer_->end()-1)<< endl;
    it_=sortedContainer_->end();
    return *this;
}

void ariel::MagicalContainer::AscendingIterator::addElement(int data)
{
    // if(it_==nullptr){
    //     it_ = new vector<int>::iterator;
    //     **it_=data;
    //     begin_=*it_;
    //     ++(*it_);
    //     end_=*it_;
    //     *it_=begin_;
    //     return;
    // }
    // if(data < *begin_){
    //     --begin_;
    //     *begin_=data;
    // }else if(data > *(end_-1)){
    //     *end_=data;
    //     ++end_;
    // }else{
    //     vector<int>::iterator temp_1;
    //     temp_1=begin_;
    //     while(data>*temp_1){
    //         ++temp_1;
    //     }
        
    //     int temp_2;
    //     while(temp_1 != end_){
    //         temp_2=*temp_1;
    //         *temp_1=data;
    //         data=temp_2;
    //         ++temp_1;
    //     }
    //     *end_=data;
    //     ++end_;

    // }
}

}