//  listeFormes.hpp

#ifndef listeFormes_hpp
#define listeFormes_hpp

#include <stdexcept>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Forme.hpp"
#include "Rectangle.hpp"


using namespace std;
template <typename T, typename R>

class ListeFormes
{
protected:
    std::vector<std::shared_ptr<Forme<T,R>>> formes;
    
public:

    void ajouter(std::shared_ptr<Forme<T,R>> forme) {
        formes.push_back(forme);
    }

    const std::vector<std::shared_ptr<Forme<T,R>>>& getFormes() const {
        return formes;
    }

    R surfaceTotale() const {
        R total = 0;
        for (const auto& f : formes)
            total += f->surface();
        return total;
    }

    Rectangle<T,R> boiteEnglobante() const {

        if (formes.empty())
            throw std::runtime_error("Liste vide");

        // Initialisation au premier élément
        Rectangle<T,R> box = formes[0]->boiteEnglobante();

        T minX = box.getMinX();
        T maxX = box.getMaxX();
        T minY = box.getMinY();
        T maxY = box.getMaxY();

        // On fusionne les autres
        for (size_t i = 1; i < formes.size(); ++i) {

            Rectangle<T,R> b = formes[i]->boiteEnglobante();

            minX = std::min(minX, b.getMinX());
            maxX = std::max(maxX, b.getMaxX());
            minY = std::min(minY, b.getMinY());
            maxY = std::max(maxY, b.getMaxY());
        }

        T centreX = (minX + maxX) / 2.0;
        T centreY = (minY + maxY) / 2.0;
        T largeur = maxX - minX;
        T hauteur = maxY - minY;

        return Rectangle<T,R>( Point<T>(centreX, centreY), largeur, hauteur );
    }


};


#endif