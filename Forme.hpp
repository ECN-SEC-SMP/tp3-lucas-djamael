//  Forme.hpp

#ifndef Forme_hpp
#define Forme_hpp

#include <iostream>
#include <stdexcept>
#include "Point.hpp"

using namespace std;
template <typename T, typename R>
class Rectangle;

template <typename T, typename R>
class Forme
{
protected:
    Point<T> centre;
public:

    Forme(T abs, T ord) : centre(abs, ord) {}
    Forme(const Point<T>& c) : centre(c) {}

    friend ostream& operator<<(ostream& os, const Forme<T, R>& forme) {
        os << "Centre: " << forme.centre;
        return os;
    }

    virtual R perimetre() const = 0;
    virtual R surface() const = 0;
    virtual Rectangle<T,R> boiteEnglobante() const = 0;
};


#endif