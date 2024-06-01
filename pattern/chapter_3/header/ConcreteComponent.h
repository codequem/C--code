#pragma once

class ConcreteComponent: public Component
{
public:
    ConcreteComponent();
    ~ConcreteComponent();
    void operation() override;
};