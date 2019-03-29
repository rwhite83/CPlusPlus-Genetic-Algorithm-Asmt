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

    city &operator=(const city&);
    friend bool operator!=(const city&, const city&);
    friend bool operator==(const city&, const city&);
    friend ostream& operator<<(ostream&, const city&);

};

