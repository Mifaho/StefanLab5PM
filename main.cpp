
#include "Person.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
/*
struct MyPrint {
    const bool operator()(const Person &person) {
        std::cout << person.getName() << " är " << person.getHeight() << "m lång" << std::endl;
    };
};*/




int main(int argc, char** argv) {
    srand(time(NULL));
    Person persons[] = {
        Person("Kalle", (double) rand() / (RAND_MAX + 1)+(rand() % 2)),
        Person("Erik", (double) rand() / (RAND_MAX + 1)+(rand() % 2)),             
        Person("Erik", (double) rand() / (RAND_MAX + 1)+(rand() % 2)),
        Person("Olle", (double) rand() / (RAND_MAX + 1)+(rand() % 2)),
        Person("Pelle", (double) rand() / (RAND_MAX + 1)+(rand() % 2))
        //Person("Fredrik", (double) rand() / (RAND_MAX + 1)+(rand() % 2))
    };
    Person::MyPrint myPrint;
    Person::MyBinOp myBinOp;
    Person::MyUnOp myUnOp;
    Person::MyFunc myFunc;
    Person::TallerThanAMeter taller;
    Person::ComparePerson comparePerson;
    std::vector<Person> vecPersons = {persons[0], persons[1], persons[2], persons[3], persons[4]};
    std::for_each(vecPersons.begin(), vecPersons.end(), myPrint);
    std::cout << std::endl << "Första person som är längre än 1 meter (find_if)" << std::endl;
    myPrint(*(std::find_if(vecPersons.begin(), vecPersons.end(), taller)));
    std::cout << std::endl << "(adjacent_find)" << std::endl;
    myPrint(*(std::adjacent_find(vecPersons.begin(), vecPersons.end())));
    std::cout << std::endl << "(equal) " << std::equal(vecPersons.begin(), vecPersons.end(), vecPersons.begin()) << std::endl;
    std::cout << std::endl << "(search)" << std::endl;
    myPrint(*(std::search(vecPersons.begin(), vecPersons.end(), vecPersons.begin() + 2, vecPersons.begin() + 3)));
    std::cout << std::endl << "mean (accumulate)" << std::endl;
    double mean = std::accumulate(vecPersons.begin(), vecPersons.end(), 0.0, myBinOp) / vecPersons.size();
    myFunc.mean = mean;
    std::cout << mean << std::endl;
    std::vector<Person> v2(5);
    std::cout << std::endl << "half the height for all (transform)" << std::endl;
    std::transform(vecPersons.begin(), vecPersons.end(), v2.begin(), myUnOp);
    std::for_each(v2.begin(), v2.end(), myPrint);
    std::transform(v2.begin(), v2.end(), vecPersons.begin(), v2.begin(), myFunc);
    std::cout << std::endl << "height with the mean removed (transform)" << std::endl;
    std::for_each(v2.begin(), v2.end(), myPrint);
    std::cout << std::endl << "(sort)" << std::endl;
    std::sort(v2.begin(), v2.end(), comparePerson);
    std::for_each(v2.begin(), v2.end(), myPrint);
    return 0;
}

