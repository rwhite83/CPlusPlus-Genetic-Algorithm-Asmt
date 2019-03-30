//
// Created by rwhit on 3/16/2019.
//

#pragma once
#include "tour.hpp"
#include <map>
#include <random>

using namespace std;


class tour {

public:

    int num_of_cities;
    string city_desig = "";
    double fitness_rating;
    double travel_distance;

    vector<city*> vector_cities_pointers;

    map<string, city> cities_to_visit;

    vector<city> vector_cities_to_visit;
    vector<pair<double,double>> coordinate_vector;
    vector<string> city_vector;

    tour();
    tour(city[], int);

    double determine_fitness();
    double get_tour_distance();
    void shuffle_cities();
    double get_distance_between_cities(city, city);
    bool contains_city(city);
    void mutate_the_baby(float, int);

    bool operator!=(tour);
    bool operator==(tour);
    tour &operator=(const tour&);
    friend ostream& operator<<(ostream&, const tour&);
};

