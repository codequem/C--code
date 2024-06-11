#pragma once 
#include <string>

class Person{
private:
    std::string name = "unknown";
public:
    Person() = default;
    Person(const std::string& name) : name(name) {}
    virtual ~Person() = default;
    virtual void show() const;
};