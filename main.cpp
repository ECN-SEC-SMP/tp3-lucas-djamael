/*
 * LUCAS OROS 
 * TP3 - SEC - 17/11/2025
 * CPP - TP3 - main.cpp
 *
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>  
#include <ctime>    
#include "Point.hpp"
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "listeFormes.hpp"

using namespace std;

int main()
{
    cout << "---------------------------------" << endl;
    cout << "TP 3 - Test de la classe Point" << endl;
    cout << "---------------------------------" << endl;

    Point<double> p1(2.5, 3.5);
    cout << "Point p1: " << p1 << endl;
    p1.translater(1.0, -1.0);
    cout << "Après translation de (1.0, -1.0), p1: " << p1 << endl;
    Point<double> p2 = p1;
    cout << "Point p2 (copie de p1): " << p2 << endl;

    cout << "---------------------------------" << endl;
    cout << "TP 3 - Test de la classe Rectangle" << endl;
    cout << "---------------------------------" << endl;

    Point<double> centre(5.2, 4.3);
    Rectangle<double, double> rect(centre, 10.0, 5.0);
    cout << rect << endl;
    cout << "Périmètre du rectangle: " << rect.perimetre() << endl;
    cout << "Surface du rectangle: " << rect.surface() << endl;

    cout << "---------------------------------" << endl;
    cout << "TP 3 - Test de la classe Carre" << endl;
    cout << "---------------------------------" << endl;
    Carre<double, double> carre(centre, 4.0);
    cout << carre << endl;
    cout << "Périmètre du carré: " << carre.perimetre() << endl;
    cout << "Surface du carré: " << carre.surface() << endl;

    cout << "---------------------------------" << endl;
    cout << "TP 3 - Test de la spécialisation de Point pour std::string" << endl;
    cout << "---------------------------------" << endl;
    Point<string> p("Hello", "World");
    cout << p << endl;
    p.translater("AA", "BB");   // va swapper
    cout << p << endl;

    cout << "---------------------------------" << endl;
    cout << "TP 3 - Test de la classe ListeFormes" << endl;
    cout << "---------------------------------" << endl;
    ListeFormes<double, double> liste;
    Point<double> centreCarre1(5.2, 4.3);
    Point<double> centreRect1(7.9, 1.7);
    Point<double> centreRect2(-5.0, -5.0);
    liste.ajouter(make_shared<Rectangle<double, double>>(centreRect1, 4.0, 6.0));
    liste.ajouter(make_shared<Carre<double, double>>(centreCarre1, 3.0));
    liste.ajouter(make_shared<Rectangle<double, double>>(centreRect2, 2.0, 8.0));
    
    cout << "Surface totale des formes: " << liste.surfaceTotale() << endl;
    Rectangle<double, double> boite = liste.boiteEnglobante();
    cout << "Boîte englobante: " << boite << endl;

    
    return 0;
}