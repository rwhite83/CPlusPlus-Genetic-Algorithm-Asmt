//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include <algorithm>
#include "travelogue.hpp"
#include <random>


using namespace std;

/////////why does this have to be here and not in the header???///////////
vector<tour> travelogue_vector;

vector<city> city_randomizer;

int my_random {5};

travelogue::travelogue(int num_of_shuffles, tour master_tour) {

    for (int i = 0; i < num_of_shuffles; i++) {
        for(auto i : master_tour.cities_to_visit) {
            city_randomizer.push_back(i.second);
        }
        using std::swap;
        std::random_shuffle(city_randomizer.begin(), city_randomizer.end());
        tour randomized_tour_to_add;
        char letter = '\u0041';
        for (auto j : city_randomizer) {
            randomized_tour_to_add.cities_to_visit.insert(make_pair(letter, j));
            letter ++;
        }
        double temp_tour = randomized_tour_to_add.determine_fitness();
        if (temp_tour > fittest_tour) {
            fittest_tour = temp_tour;
        }
        city_randomizer.clear();
        cout << endl;
    }
}