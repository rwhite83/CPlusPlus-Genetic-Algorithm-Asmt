//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include <algorithm>
#include "travelogue.hpp"
#include <random>
#include <set>
#include "tour.hpp"


using namespace std;

travelogue::travelogue() {}

travelogue::travelogue(city base_city_list[], int num_of_cities, int population_size, int num_of_shuffles) {

    tour base_tour{base_city_list, num_of_cities};

    // sets a base distance
    fittest_tour_distance = base_tour.get_tour_distance();

    // populates a vector with randomized versions of master tour
    for (int i = 0; i < population_size; i++) {

        // create a new tour and re-adds randomized elements into it
        tour randomized_tour_to_add = tour{base_city_list, num_of_cities};
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
}

tour *travelogue::move_elite_to_front() {
    tour *temp_tour;
    for (int i = 0; i < travelogue_vector.size(); i++) {
        if (travelogue_vector.at(0)->get_tour_distance() > travelogue_vector.at(i)->get_tour_distance()) {
            temp_tour = travelogue_vector.at(0);
            travelogue_vector.at(0) = travelogue_vector.at(i);
            travelogue_vector.at(i) = temp_tour;
        }
    }
    return travelogue_vector.at(0);
}

travelogue travelogue::get_parent(int pop_size) {

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution_start(1, pop_size);
    uniform_int_distribution<> distribution_size(1, pop_size - 1);
    int parent_start = distribution_start(generator) + 1;
    int parent_size = distribution_size(generator);

    travelogue parent_travelogue{};

    int values_to_add = parent_size;
    int index_to_increment = parent_start;
    while (values_to_add != 0) {
        if (index_to_increment == 0 || index_to_increment >= pop_size - 1) {
            index_to_increment = 1;
        }
        index_to_increment++;
        parent_travelogue.travelogue_vector.push_back(travelogue_vector.at(index_to_increment));
        values_to_add--;
    }
    return parent_travelogue;
}

tour travelogue::make_a_mutant_baby(travelogue *mommy, travelogue *daddy, int city_count, double mutation_rate) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution_start(0, city_count - 1);
    int baby_mommy_start = distribution_start(generator);

    tour *elite_mommy = mommy->travelogue_vector.at(0);
    tour *elite_daddy = daddy->travelogue_vector.at(0);

    tour baby_tour;

    for (int k = baby_mommy_start; k < city_count; k++) {
        baby_tour.vector_cities_pointers.push_back(elite_mommy->vector_cities_pointers.at(k));
    }
    for (int h = 0; baby_tour.vector_cities_pointers.size() < city_count; h++) {
        bool matching = false;
        for (int m = 0; m < baby_tour.vector_cities_pointers.size(); m++) {
            if (*elite_daddy->vector_cities_pointers.at(h) != *baby_tour.vector_cities_pointers.at(m)) {

                matching = true;
            }
        }
        if (matching) {
            baby_tour.vector_cities_pointers.push_back(elite_daddy->vector_cities_pointers.at(h));

        }
    }

    cout << baby_tour << endl;

    double mutation_rate_percentage = mutation_rate * 100;

    for (int m = 0; m < city_count - 1; m++) {
        uniform_int_distribution<> mutation_distribution(0, 99);
        double mutation_check = mutation_distribution(generator);
        if (mutation_check > mutation_rate_percentage) {
            cout << "mutation_check: " << mutation_check << " " << "mutation_rate_percentage: "
                 << mutation_rate_percentage << endl;
            city temp_city{};
            temp_city = *baby_tour.vector_cities_pointers.at(m);
            *baby_tour.vector_cities_pointers.at(m) = *baby_tour.vector_cities_pointers.at(m + 1);
            *baby_tour.vector_cities_pointers.at(m + 1) = temp_city;
        }
    }
    uniform_int_distribution<> mutation_distribution(0, 99);
    double mutation_check = mutation_distribution(generator);
    city temp_city{};
    temp_city = *baby_tour.vector_cities_pointers.at(city_count - 1);
    *baby_tour.vector_cities_pointers.at(city_count - 1) = *baby_tour.vector_cities_pointers.at(0);
    *baby_tour.vector_cities_pointers.at(0) = temp_city;
    return baby_tour;
}


travelogue travelogue::master_function(travelogue travelogue_to_master_all_over, int cities_in_tour, float mutation_rate){
    travelogue_to_master_all_over.move_elite_to_front();
    for(int i = 1; i < cities_in_tour; i++) {
        travelogue mommy_travelogue = travelogue_to_master_all_over.get_parent(cities_in_tour);
        travelogue daddy_travelogue = travelogue_to_master_all_over.get_parent(cities_in_tour);
        mommy_travelogue.move_elite_to_front();
        daddy_travelogue.move_elite_to_front();
        tour mutant_baby_tour = make_a_mutant_baby(&mommy_travelogue, &daddy_travelogue, cities_in_tour, mutation_rate);
        this->travelogue_vector.at(i) = &mutant_baby_tour;
    }
    return travelogue_to_master_all_over;
}

travelogue &travelogue::operator=(const travelogue &trvlg) {
    this->travelogue_vector = trvlg.travelogue_vector;
    return *this;
}

ostream &operator<<(ostream &os, const travelogue &trvlg) {
    for (auto elem : trvlg.travelogue_vector) {
        os << *elem;
        os << elem->get_tour_distance() << endl;
        os << elem->determine_fitness() << "\n" << endl;
    }
    return os;
}