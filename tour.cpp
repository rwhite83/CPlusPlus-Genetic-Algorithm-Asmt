//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include "city.hpp"
#include "tour.hpp"

using namespace std;

tour::tour() { }

tour::tour(int city_count) {
    num_of_cities = city_count;
    for (int i = 0; i < city_count; i++) {
        char letter = '\u0041' + i;
        city new_city{};
        cities_to_visit.insert(make_pair(letter, new_city));
    }
}

tour &tour::operator=(const tour &tr) {
    this->cities_to_visit = tr.cities_to_visit;
    this->num_of_cities = tr.num_of_cities;
    this->fitness_rating = tr.fitness_rating;
    return *this;
}

ostream &operator<<(ostream &os, const tour &tr) {
    for (auto elem : tr.cities_to_visit) {
        os << elem.first << " " << elem.second.xlong << " " << elem.second.ylat << "\n";
    }
    os << endl;
    return os;
}

