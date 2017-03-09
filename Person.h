
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <vector>

class Person {
public:
    struct MyPrint {
        const bool operator()(const Person &person) {
            std::cout << person.name << ", " << person.height << "m" << std::endl;
        };
    };
    
    struct MyBinOp {
        const double operator()(const double& number, const Person &person) {
            return number + person.height;
        };
    };
    
    struct MyUnOp{
         const Person operator()(const Person &person) {
            return Person(person.name, (person.height / 2));
        };
    };
    
    struct MyFunc{
        double mean;
        const Person& operator()(Person& lhs, Person &rhs) {
            lhs.height = rhs.height - mean;
            return lhs;
        };
    };
    
    struct TallerThanAMeter{
        const bool operator()(const Person &person) {
            return (person.height > 1);
        };
    };
    
    struct ComparePerson {
        const bool operator()(const Person &lhs, const Person &rhs) {
            return lhs.height < rhs.height;
        };
    };
    Person();
    Person(std::string name, double height);
    Person(const Person& person);
    friend bool operator== (const Person &lhs, const Person &rhs);
    std::string getName() const { return name; };
    double getHeight() const { return height; };
    virtual ~Person();
private:
    std::string name;
    double height;
};

#endif /* PERSON_H */

