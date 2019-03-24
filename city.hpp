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

    string cityName;
    double xlong;
    double ylat;

    city();

    void swap(const city &, const city &);

    string gen_random();

    friend ostream& operator<<(ostream&, const city&);

};

