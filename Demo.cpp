#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;


    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    cout<<endl;

    ++ascIter;//3
    container.addElement(1);
    container.addElement(29);
    container.addElement(4);
    

    cout<< "begin=" << ascIter.begin() << endl;
    cout<< "end=" << ascIter.end() << endl;
    
    
    std::cout << "Elements in ascending order:\n";
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {

        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

    std::cout << "Elements in cross order:\n";
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;
    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    cout<<endl;
    ++crossIter;
    
    ++primeIter;

    cout << std::endl;
    MagicalContainer::AscendingIterator ascIter_1(container);
    MagicalContainer::AscendingIterator ascIter_2(container);
    MagicalContainer::AscendingIterator ascIter_3(container);
    MagicalContainer::AscendingIterator ascIter_4(ascIter);
    MagicalContainer::SideCrossIterator crossIter_1(container);
    MagicalContainer::SideCrossIterator crossIter_2(container);
    MagicalContainer::SideCrossIterator crossIter_3(container);
    MagicalContainer::SideCrossIterator crossIter_4(crossIter);
    MagicalContainer::PrimeIterator primeIter_1(container);
    MagicalContainer::PrimeIterator primeIter_2(container);
    MagicalContainer::PrimeIterator primeIter_3(container);
    MagicalContainer::PrimeIterator primeIter_4(primeIter);

    cout<<"test"<<endl;
    for(auto it = container.getAscendingIterators().begin(); it!= container.getAscendingIterators().end(); ++it) {
        cout << **it << ' ';
    }
    cout<<endl;
    for(auto it = container.getSideCrossIterators().begin(); it!= container.getSideCrossIterators().end(); ++it) {
        cout << **it << ' ';
    }
    cout<<endl;
    for(auto it = container.getPrimeIterators().begin(); it!= container.getPrimeIterators().end(); ++it) {
        cout << **it << ' ';
    }
    cout << endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}
