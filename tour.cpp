//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include <algorithm>
#include "city.hpp"
#include "tour.hpp"

using namespace std;

tour::tour() {
}

tour::tour(city base_city_list[], int city_count) {
    city *city_pointer;
    for (int i = 0; i < city_count; i++) {
        city *city_pointer = &base_city_list[i];
        vector_cities_pointers.push_back(city_pointer);
    }
}

double tour::get_tour_distance() {
    fitness_rating = 0;
    for (int i = 1; i < vector_cities_pointers.size(); i++) {
        fitness_rating += get_distance_between_cities(*vector_cities_pointers[i], *vector_cities_pointers[i-1]);
    }
    return fitness_rating;
}

double tour::determine_fitness() {
    for (auto elem : vector_cities_pointers) {
        fitness_rating += get_distance_between_cities(*elem, *elem);
    }
    double fitness_rating_ratio = 10000 * (1 / fitness_rating);
    return fitness_rating_ratio;
}

void tour::shuffle_cities() {
    random_shuffle(vector_cities_pointers.begin(), vector_cities_pointers.end());
}


double tour::get_distance_between_cities(city city_origin, city city_destination) {
    return sqrt(pow(city_origin.xlong, 2) + pow(city_destination.ylat, 2));
}

bool tour::contains_city(city city_to_check) {
    for (auto elem : vector_cities_pointers) {
        return (elem->xlong == city_to_check.xlong && elem->ylat == city_to_check.ylat);
    }
}

tour &tour::operator=(const tour &tr) {
    this->cities_to_visit = tr.cities_to_visit;
    this->num_of_cities = tr.num_of_cities;
    this->fitness_rating = tr.fitness_rating;
    return *this;
}

ostream &operator<<(ostream &os, const tour &tr) {
    for (auto elem : tr.vector_cities_pointers) {
        os << "name: " << elem->cityName << " lattitude: " << elem->ylat << " longitude: " << elem->xlong << endl;
    }
    os << endl;
    return os;
}













//tour::tour(int city_count) {
//    num_of_cities = city_count;
//    for (int i = 0; i < city_count; i++) {
//        city_desig = string("city: ") + to_string(i) + string(": ");
//        city new_city{};
//        cities_to_visit.insert(make_pair(city_desig, new_city));
//    }
//}

//tour::tour(city base_city_list[], int city_count) {
//    city *city_pointer;
//    for (int i = 0; i < city_count; i++) {
//        city *city_pointer = &base_city_list[i];
//        vector_cities_pointers.push_back(city_pointer);
//        coordinate_vector.push_back(make_pair(base_city_list[i].ylat, base_city_list.xlong));
//        city_vector.push_back(base_city_list[i].cityName);
//    }
//    random_shuffle(coordinate_vector.begin(), coordinate_vector.end());
//    random_shuffle(city_vector.begin(), city_vector.end());
//    random_shuffle(vector_cities_pointers.begin(), vector_cities_pointers.end());
//}

//double tour::get_tour_distance() {
//    for (auto elem : cities_to_visit) {
//        fitness_rating += get_distance_between_cities(elem.second, elem.second);
//    }
//    return fitness_rating;
//}


//double tour::determine_fitness() {
//    for (auto elem : cities_to_visit) {
//        fitness_rating += get_distance_between_cities(elem.second, elem.second);
//    }
//    double fitness_rating_ratio = 10000 * (1 / fitness_rating);
//    return fitness_rating_ratio;
//}


//void tour::shuffle_cities() {
//
//    vector<city> city_randomizer;
//
//    for (auto i : cities_to_visit) {
//        city_randomizer.push_back(i.second);
//    }
//
//    random_shuffle(city_randomizer.begin(), city_randomizer.end());
//
//    cities_to_visit.clear();
//
//    for (int i = 0; i < city_randomizer.size(); i++) {
//        city_desig = string("city: ") + to_string(i) + string(": ");
//        cities_to_visit.insert(make_pair(city_desig, city_randomizer.at(i)));
//    }
//}