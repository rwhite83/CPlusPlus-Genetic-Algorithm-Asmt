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

    int num_of_cities;

    map<char, city> cities_to_visit;

    double fitness_rating;

    tour();

    tour(int);

    tour &operator=(const tour &tr);

    friend ostream& operator<<(ostream&, const tour&);

};

