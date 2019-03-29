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

    travelogue();
    travelogue(city[], int, int, int);
    tour* move_elite_to_front();
    travelogue get_parent(int);
    static tour make_a_mutant_baby(travelogue*, travelogue*, int, double);
    travelogue master_function(travelogue, int, float);

    travelogue &operator=(const travelogue&);
    friend ostream& operator<<(ostream&, const travelogue&);

    // do i have to kill the pointers in the pointers?
    //void kill_me();

};

