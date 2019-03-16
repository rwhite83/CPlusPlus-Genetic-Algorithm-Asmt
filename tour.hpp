//
// Created by rwhit on 3/16/2019.
//

#pragma once
#include "tour.hpp"
#include <map>
#include <random>

using namespace std;


class tour {

public:

    map<char, city> cities_to_visit;

    double fitness_rating;

    tour(int);

    friend ostream& operator<<(ostream&, const tour&);

};

