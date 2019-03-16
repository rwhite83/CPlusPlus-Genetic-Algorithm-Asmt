//
// Created by rwhit on 3/16/2019.
//

#include "city.hpp"
#include "tour.hpp"
#include <random>
#include <iostream>

//////////why does this have to be here and not in header???/////////////
random_device rd;

double city::make_random() {
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, 1000);
    double my_double = distribution(generator);
}

city::city() {
    this->xlong = make_random();
    this->ylat = make_random();
}



