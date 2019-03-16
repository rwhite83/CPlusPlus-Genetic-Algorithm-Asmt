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
    map<int, city> tour_map;

    double fitness_rating;

    tour generate_tour(int);

    tour generate_master_tour();

    void print_master_tour();

    friend ostream& operator<<(ostream&, const tour&);

};

