//
// Created by rwhit on 3/16/2019.
//

#pragma once
#include <map>
#include <random>

using namespace std;


struct city {

private:

    double make_random();

public:

    double xlong;
    double ylat;

    city();

    void swap(const city&, const city&);

};

