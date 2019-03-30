//
// Created by rwhit on 3/16/2019.
//

#include "city.hpp"
#include "tour.hpp"
#include <random>
#include <iostream>
#include <sstream>


city::city() {
    this->xlong = make_random();
    this->ylat = make_random();
    this->cityName = gen_random();
}

double city::make_random() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, 1000);
    double my_double = distribution(generator);
}

string city::gen_random() {
    char s[9];
    stringstream ss;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 9; ++i) {
        ss << alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return ss.str();
}

bool operator!=(const city &lhs_city, const city &rhs_city) {
//    bool is_not_equal = true;
//    if ((lhs_city.ylat != rhs_city.ylat)
//        && (lhs_city.xlong != rhs_city.xlong)
//        && (lhs_city.cityName.compare(rhs_city.cityName) != 0)) {
//        is_not_equal = false;
//    }
    return !operator==(lhs_city,rhs_city);
}

bool operator==(const city &lhs_city, const city &rhs_city) {
    bool is_equal = false;
    if ((lhs_city.ylat == rhs_city.ylat)
        && (lhs_city.xlong == rhs_city.xlong)
        && (lhs_city.cityName.compare(rhs_city.cityName) == 0)) {
        is_equal = true;
    }
    return is_equal;
}

city &city::operator=(const city &cty) {
    this->cityName = cty.cityName;
    this->ylat = cty.ylat;
    this->xlong = cty.xlong;
    return *this;
}

ostream &operator<<(ostream &os, const city &cty) {
    os << "name: " << cty.cityName << " lattitude: " << cty.ylat << " longitude: " << cty.xlong;
    return os;
}




