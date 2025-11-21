//  Rectangle.hpp

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <iostream>
#include <stdexcept>
#include "Forme.hpp"

using namespace std;
template <typename T, typename R>

class Rectangle : public Forme<T, R>
{
protected:
    T largeur;
    T hauteur;
    
public:

    Rectangle(const Point<T>& c, T l, T h) : Forme<T, R>(c), largeur(l), hauteur(h) {}

    friend ostream& operator<<(ostream& os, const Rectangle<T, R>& rect) {
        os << "Rectangle(Centre: " << rect.centre << ", Largeur: " << rect.largeur << ", Hauteur: " << rect.hauteur << ")";
        return os;
    }

    R perimetre() const override {
        return (2 * (largeur + hauteur)); //static_cast<R>
    }

    R surface() const override {
        return (largeur * hauteur); //static_cast<R>
    }

    T getLargeur() const { return largeur; }
    T getHauteur() const { return hauteur; }

    T getMinX() const { return this->centre.getX() - largeur / 2; }
    T getMaxX() const { return this->centre.getX() + largeur / 2; }
    T getMinY() const { return this->centre.getY() - hauteur / 2; }
    T getMaxY() const { return this->centre.getY() + hauteur / 2; }

    Rectangle<T,R> boiteEnglobante() const override {
        return *this;
    }


};


#endif