#include "MagicalContainer.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel{

        ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(ariel::MagicalContainer &container): container_(container)
        {
            if(container_.size()!=0){

                for(auto over_container=container_.begin(); over_container != container_.end(); ++over_container){
                    sidedContainer_.push_back(&(*over_container));
                }   
                    
                sort(sidedContainer_.begin(),sidedContainer_.end(),compareByValue);

                    
                // Initialize the iterators
                it_ = sidedContainer_.begin();

                auto temp =sidedContainer_;
                    
                auto st = temp.begin();
                auto en = temp.end() - 1;
                while (st < en) {

                    /*add min val*/
                    *it_=*st;
                    ++it_;

                    /*add max val*/
                    *it_=*en;
                    ++it_;

                    /*promote st & en*/
                    ++st;
                    --en;
                }

                // Handle the middle element for odd-sized containers
                if (st == en) {
                    *it_=*st;
                    ++it_;
                }
        
                // Reset the iterator position to the beginning
                it_ = sidedContainer_.begin();
            }
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator=(const ariel::MagicalContainer::SideCrossIterator &other) {
            if (this != &other) {
                this->container_=other.container_;
                this->sidedContainer_=other.sidedContainer_;
                this->it_=other.it_;
            }
            return *this;
        }

        ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer::SideCrossIterator &other):container_(other.container_),sidedContainer_(other.sidedContainer_),it_(other.it_){
        }


        ariel::MagicalContainer::SideCrossIterator::~SideCrossIterator(){
        }

        int ariel::MagicalContainer::SideCrossIterator::operator*() const {
            return *(*it_);
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator++(){
            if(it_==sidedContainer_.end()){
                throw runtime_error("S operator++: out of bound");
            }
            ++(it_);
            return *this;
        }
            
        ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::operator++(int){
            if(it_==sidedContainer_.end()){
                throw runtime_error("S operator++: out of bound");
            }
            SideCrossIterator temp(*this);
            ++(it_);
            return temp;
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator--(){
            
            if(it_==sidedContainer_.begin()){
                throw runtime_error("S operator--: out of bound");
            }

            --(it_);
            return *this;
        }
            
        ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::operator--(int)
        {

            if(it_==sidedContainer_.begin()){
                throw runtime_error("S operator--: out of bound");
            }

            SideCrossIterator temp (*this);
            --(it_);
            return temp;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator==(const ariel::MagicalContainer::SideCrossIterator &other) const
        {
            cout<<"S operator=="<<endl;
            return it_ == other.it_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator!=(const ariel::MagicalContainer::SideCrossIterator &other) const
        {
            cout<<"S operator!="<<endl;
            cout<<*it_<<" "<<*other.it_<<endl;
            return !(it_ == other.it_);
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator<(const ariel::MagicalContainer::SideCrossIterator &other) const{
            return it_ < other.it_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator>(const ariel::MagicalContainer::SideCrossIterator &other) const{
            return it_ > other.it_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator<=(const ariel::MagicalContainer::SideCrossIterator &other) const{
            return it_ <= other.it_;
        }

        bool ariel::MagicalContainer::SideCrossIterator::operator>=(const ariel::MagicalContainer::SideCrossIterator &other) const {
            return it_ >= other.it_;
        }

        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::begin(){
            it_=sidedContainer_.begin();
            return *this;
        }
        ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::end(){
            cout<<"S in end"<<endl;
            it_=sidedContainer_.end();
            return *this;
        }

        void ariel::MagicalContainer::SideCrossIterator::addElement(int data){/*TODO*/
            // if(sideIter_->size()==0){
            //     sideIter_->push_back(data);
            // }else{
            //     bool flag = true;
            //     auto it = sideIter_->begin();
            //     while(it != sideIter_->end()){
            //         if(flag){
            //             if(data<*it){
            //                 /*INSERT DATA*/
            //                 sideIter_->insert(it,data);
            //                 return;
            //             }
            //             flag = false;
            //             ++it;
            //         }else{
            //             if(data>*it){
            //                 /*INSERT DATA*/
            //                 sideIter_->insert(it,data);
            //                 return;
            //             }
            //             flag = true;
            //             ++it;
            //         }
            //     }
            //     sideIter_->push_back(data);
            // }
        }
}