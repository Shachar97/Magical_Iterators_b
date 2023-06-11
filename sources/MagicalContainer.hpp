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
        vector<int *>::iterator  it_;
        std::vector<int *> * sortedContainer_;
        MagicalContainer& container_;

    public:
        AscendingIterator(MagicalContainer& container);

        AscendingIterator& operator=(const AscendingIterator& other);

        AscendingIterator(const AscendingIterator& other);

        ~AscendingIterator();

        friend ostream& operator<<(ostream& os, const AscendingIterator& it)
        {
            os << **(it.it_);
            return os;
        }

        int operator*() const;

    AscendingIterator& operator++();

    AscendingIterator operator++(int);

    AscendingIterator& operator--();

    AscendingIterator operator--(int);

    bool operator==(const AscendingIterator& other) const;

    bool operator!=(const AscendingIterator& other) const;

    bool operator<(const AscendingIterator& other) const;

    bool operator>(const AscendingIterator& other) const;
    
    bool operator<=(const AscendingIterator& other) const;

    bool operator>=(const AscendingIterator& other) const;



    AscendingIterator& begin();

    AscendingIterator& end();

    void addElement(int data);

    };

    /*~~~~~~~SideCrossIterator~~~~~~~~~*/
    class SideCrossIterator
    {
    private:

    vector<int *>::iterator  it_;
    std::vector<int *> sidedContainer_;
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
            os << it;  
            return os;
        }

        int operator*() const;

        SideCrossIterator& operator++();
            
        SideCrossIterator operator++(int);

        SideCrossIterator& operator--();
            
        SideCrossIterator operator--(int);

        bool operator==(const SideCrossIterator& other) const;

        bool operator!=(const SideCrossIterator& other) const ;

        bool operator<(const SideCrossIterator &other) const;

        bool operator>(const SideCrossIterator &other) const ;

        bool operator<=(const SideCrossIterator &other) const ;

        bool operator>=(const SideCrossIterator &other) const ;

        SideCrossIterator & begin();

        SideCrossIterator & end();

        void addElement(int data);
    };

    /*~~~~~~~PrimeIterator~~~~~~~~~*/
    class PrimeIterator
    {
    private:
        vector<int >::iterator  it_;
        std::vector<int > primeContainer_;
        MagicalContainer& container_;
        
    public:
        PrimeIterator(MagicalContainer& container);

        PrimeIterator& operator=(const PrimeIterator& other);

        PrimeIterator(const PrimeIterator& other);

        ~PrimeIterator();

        friend ostream& operator<<(ostream& os, const PrimeIterator& it) {
            os << *it.it_;  
            return os;
        }

        int operator*() const;

        PrimeIterator& operator++();
            
        PrimeIterator operator++(int);

        PrimeIterator& operator--();

        PrimeIterator operator--(int);

        /*EQ*/
        bool operator==(const PrimeIterator& other) const ;

        /*NE*/
        bool operator!=(const PrimeIterator& other) const;

        bool operator<(const PrimeIterator &other) const ;

        bool operator>(const PrimeIterator &other) const ;


        bool operator<=(const PrimeIterator &other) const;


        bool operator>=(const PrimeIterator &other) const ;


        PrimeIterator& begin();

        PrimeIterator& end();


        void addElement(int data);
    };
    
    /*~~~~~~~MagicalContainer~~~~~~~~~*/
    private:
        
        AscendingIterator* ascendIter_;
        SideCrossIterator* sideIter_;
        PrimeIterator* primeIter_;

    public:
        MagicalContainer():ascendIter_(nullptr),sideIter_(nullptr),primeIter_(nullptr){}
        ~MagicalContainer(){}
        void addElement(int data){/*TODO*/

            container_.push_back(data);

            /*AscendingIterator*/
            if(ascendIter_){/*TODO*/
                ascendIter_->addElement(data);
            }

            /*SideCrossIterator*/
            if(sideIter_){/*TODO*/
                sideIter_->addElement(data);
            }

            /*PrimeIterator*/
            if(primeIter_){/*TODO*/
                primeIter_->addElement(data);
            }

            return;
        }
        void removeElement(int data){/*TODO*/
            auto it = std::find(container_.begin(), container_.end(), data);

            // Check if the element was found
            if (it != container_.end()) {
                // Remove the element from the vector
                container_.erase(it);
            }else{
                throw runtime_error("not exist element");
            }
        }
        bool operator==(const MagicalContainer& other) const{
            return container_ == other.container_;
        }

        int size() const {/*TODO*/return container_.size();}
        vector<int>::iterator begin(){
            return container_.begin();
        }
        vector<int>::iterator end(){
            return container_.end();
        }
    };

}


#endif