#pragma once

#include "Person.h"

class Finery : public Person{
protected:
    Person* component;
public:
    void decorate(Person* component);
    
    void show() const override;
};

class TShirt : public Finery{
public:
    void show() const override;
};

class BigTrouser : public Finery{
public:
    void show() const override;
};

class Sneakers : public Finery{
public:
    void show() const override;
};

class Suit : public Finery{
public:
    void show() const override;
};