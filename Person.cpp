/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Person.cpp
 * Author: stefa_000
 * 
 * Created on den 8 mars 2017, 17:16
 */

#include "Person.h"

Person::Person():name(""),height(0.0){
    
}

Person::Person(std::string name, double height):name(name), height(height) {
}

Person::Person(const Person& person):name(person.name), height(person.height) {
}

Person::~Person() {
}


bool operator== (const Person &lhs, const Person &rhs){
    return (lhs.name == rhs.name);
}

