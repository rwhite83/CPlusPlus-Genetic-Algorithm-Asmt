//
// Created by rwhit on 3/16/2019.
//

#pragma once

#include "city.hpp"
#include "tour.hpp"

using namespace std;

class travelogue {

public:

    vector<tour *> travelogue_vector;

    double fittest_tour_ratio = 0;
    double fittest_tour_distance = 0;

    travelogue(city[], int, int, int);

    void kill_me();

};

