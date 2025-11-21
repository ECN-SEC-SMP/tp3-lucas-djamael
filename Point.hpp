//  Point.hpp

#ifndef Point_hpp
#define Point_hpp

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>


using namespace std;
template <typename T>

class Point
{
protected:
    T x;
    T y;
public:

    Point(T abs, T ord) : x(abs), y(ord) {}

    T getX() const {return x;}
    T getY() const {return y;}

    void setX(T abs) {x = abs;}
    void setY(T ord) {y = ord;}

    void translater(T dx, T dy){
        x += dx;
        y += dy;
    }


    Point(const Point<T>& p) : x(p.x), y(p.y) {}

    friend ostream& operator<<(ostream& os, const Point<T>& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

// Définition de la spécialisation
template <>
inline void Point<std::string>::translater(std::string dx, std::string dy)
{
    (void)dx; // pour supprimer le warning
    (void)dy; // pour supprimer le warning
    std::swap(x, y);
}

#endif