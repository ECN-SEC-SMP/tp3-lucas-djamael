//  Carre.hpp

#ifndef Carre_hpp
#define Carre_hpp

#include <stdexcept>
#include <iostream>


using namespace std;
template <typename T, typename R>

class Carre : public Rectangle<T, R>
{
protected:
    T cote;
    
public:

    Carre(const Point<T>& c, T cote) : Rectangle<T, R>(c, cote, cote), cote(cote) {}

    friend ostream& operator<<(ostream& os, const Carre<T, R>& carre) {
        os << "Carre(Centre: " << carre.centre << ", Côté: " << carre.cote << ")";
        return os;
    }

    R perimetre() const override {
        return (4 * cote);
    }

    R surface() const override {
        return (cote * cote);
    }

    Rectangle<T,R> boiteEnglobante() const override {
        return Rectangle<T,R>(this->centre, cote, cote);
    }


};


#endif