#include <iostream>
#include "prime.hpp"
using namespace std;


namespace ariel{
    // return 1 if given unsign int is a prime number else return 0.
    bool isPrime( int number) {
        if (number < 2) return false;
        if (number == 2) return true;
        if (number % 2 == 0) return false;

        for ( int i = 3; (i * i) <= number; i += 2){
            if (number % i == 0) return false;
        }
        return true;
    }

    bool compareByValue(const int* a, const int* b) {
    return *a < *b;
}

}
