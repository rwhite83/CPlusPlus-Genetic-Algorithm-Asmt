//
// Created by rwhit on 3/16/2019.
//

#pragma once

#include "city.hpp"
#include "tour.hpp"

using namespace std;

class travelogue {

public:

    travelogue(int, tour);;

    friend ostream& operator<<(ostream&, const travelogue&);

};

