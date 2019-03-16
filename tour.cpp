//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include "city.hpp"
#include "tour.hpp"

using namespace std;

/////////why does this have to be here and not in the header???///////////


tour tour::generate_tour(int city_count) {
    for (int i = 0; i < city_count; i++) {
        city new_city{};
        tour_map.insert(make_pair(i, new_city));
        cout << tour_map.size() << endl;
    }
}

tour tour::generate_master_tour() {
    for (int i = 0; i < 20; i++) {
        char letter = '\u0041' + i;
        city new_city{};
        cities_to_visit.insert(make_pair(letter, new_city));
        cout << cities_to_visit.size() << endl; //<< letter << new_city.xlong << new_city.ylat << endl;
    }
}

void tour::print_master_tour() {
    for (auto elem : cities_to_visit) {
        cout << elem.first << " " << elem.second.xlong << " " << elem.second.ylat << "\n";
    }
    cout << endl;
}

ostream &operator<<(ostream &os, const tour &tr) {
//    cout << "d";
//    for (auto elem : tr.tour_map) {
//        cout << "d";
//        os << elem.first << " " << elem.second.xlong << " " << elem.second.ylat << "\n";
//    }
//    os << endl;
    return os;
}

