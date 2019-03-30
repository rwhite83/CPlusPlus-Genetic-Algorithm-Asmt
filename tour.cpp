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

void tour::mutate_the_baby(float mutation_rate) {
    random_device rd;
    mt19937 generator(rd());

    double mutation_rate_percentage = mutation_rate * 100;

    for (int m = 1; m < vector_cities_pointers.size() - 1; m++) {
        uniform_int_distribution<> mutation_distribution(0, 99);
        double mutation_check = mutation_distribution(generator);
        if (mutation_check > mutation_rate_percentage) {
            city *temp_city{};
            temp_city = this->vector_cities_pointers.at(m);
            this->vector_cities_pointers.at(m) = this->vector_cities_pointers.at(m + 1);
            this->vector_cities_pointers.at(m + 1) = temp_city;
        }
    }
    uniform_int_distribution<> mutation_distribution(0, 99);
    double mutation_check = mutation_distribution(generator);
    if (mutation_check > mutation_rate_percentage) {
        city *temp_city{};
        temp_city = this->vector_cities_pointers.at(0);
        this->vector_cities_pointers.at(0) = this->vector_cities_pointers.at(this->vector_cities_pointers.size() - 1);
        this->vector_cities_pointers.at(this->vector_cities_pointers.size() - 1) = temp_city;
    }
}

bool operator!=(tour &lhs_tour, tour &rhs_tour) {
    bool is_not_equal = true;
    for (int i = 0; i < lhs_tour.num_of_cities; i++) {
        if ((lhs_tour.vector_cities_pointers.at(i)->cityName.compare(
                rhs_tour.vector_cities_pointers.at(i)->cityName) == 0)
            || (lhs_tour.vector_cities_pointers.at(i)->ylat == (rhs_tour.vector_cities_pointers.at(i)->ylat)
                || (lhs_tour.vector_cities_pointers.at(i)->xlong == (rhs_tour.vector_cities_pointers.at(i)->xlong)))) {
            bool is_not_equal = false;
        }
        return is_not_equal;
    }
}

bool operator==(tour &lhs_tour, tour &rhs_tour) {
    bool is_equal = true;
    for (int i = 0; i < lhs_tour.num_of_cities; i++) {
        if ((!lhs_tour.vector_cities_pointers.at(i)->cityName.compare(
                rhs_tour.vector_cities_pointers.at(i)->cityName) == 0)
            || (!lhs_tour.vector_cities_pointers.at(i)->ylat == (rhs_tour.vector_cities_pointers.at(i)->ylat)
                || (!lhs_tour.vector_cities_pointers.at(i)->xlong == (rhs_tour.vector_cities_pointers.at(i)->xlong)))) {
            bool is_equal = false;
        }
        return is_equal;
    }
}

tour &tour::operator=(const tour &tr) {
    this->cities_to_visit = tr.cities_to_visit;
    this->num_of_cities = tr.num_of_cities;
    this->fitness_rating = tr.fitness_rating;
    this->vector_cities_pointers = tr.vector_cities_pointers;
    return *this;
}

ostream &operator<<(ostream &os, const tour &tr) {
    for (auto elem : tr.vector_cities_pointers) {
        os << "name: " << elem->cityName << " lattitude: " << elem->ylat << " longitude: " << elem->xlong << endl;
    }
    return os;
}
