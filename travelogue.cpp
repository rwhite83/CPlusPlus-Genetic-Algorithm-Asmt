//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include <algorithm>
#include "travelogue.hpp"
#include <random>
#include "tour.hpp"


using namespace std;

travelogue::travelogue(city base_city_list[], int num_of_cities, int population_size, int num_of_shuffles) {
    
    tour::tour(city base_city_list[], int city_count) {
        city *city_pointer;


    // sets a base distance
    fittest_tour_distance = master_tour.get_tour_distance();



    // populates a vector with randomized versions of master tour
    for (int i = 0; i < num_of_shuffles; i++) {

        // create a new tour and re-adds randomized elements into it
        tour randomized_tour_to_add = master_tour;
        randomized_tour_to_add.shuffle_cities();

        // sets calculates distance travelled and inverted ratio
        double temp_tour_ratio = randomized_tour_to_add.determine_fitness();
        double temp_tour_distance = randomized_tour_to_add.get_tour_distance();

        // checks if they beat the existing value, and updates if they do
        if (temp_tour_ratio > fittest_tour_ratio) {
            fittest_tour_ratio = temp_tour_ratio;
        }
        if (temp_tour_distance < fittest_tour_distance) {
            fittest_tour_distance = temp_tour_distance;
        }
        travelogue_vector.push_back(new tour(randomized_tour_to_add));
    }
    cout << travelogue_vector.size() << endl;
}

// deletes all of the pointers in the vector and clears the vector
void travelogue::kill_me() {
    for (auto elem : travelogue_vector) {
        delete(elem);
    }
    travelogue_vector.clear();
}