#pragma once
#include "Component.h"

class Decorator : public Component
{
protected:
    Component *component;
};