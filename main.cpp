


#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "travelogue.hpp"

int main() {

    srand(time(NULL));

    int cities_in_tour = 32;
    int population_size = 32;
    int mutation_rate = 0.15;
    int number_of_shuffles = 64;
    int number_of_iterations = 1000;
    int number_of_parents;
    int number_of_elites = 1;

    /*
    cout << "please enter the number of cities, enter 0 for default: " << endl;
        cin >> cities_in_tour;
    cout << "please enter the number of candidate tours, enter 0 for default: " << endl;
        cin >> population_size;
    cout << "please enter the required mutation rate, enter 0 for default: " << endl;
        int raw_percentage;
        cin >> raw_percentage;
        mutation_rate = raw_percentage/100;
    cout << "please enter the number of shuffles required, enter 0 for default: " << endl;
        cin >> number_of_shuffles;
    cout << "please enter the number of iterations required, enter 0 for default: " << endl;
        cin >> number_of_iterations;

    if (cities_in_tour == 0) {
        cities_in_tour = 32;
    }
    if (population_size == 0) {
        population_size = 32;
    }
    if (number_of_shuffles == 0) {
        number_of_shuffles = 64;
    }
    if (number_of_iterations == 0) {
        number_of_iterations = 1000;
    }
     */

    //const tour master_tour{cities_in_tour};

    //cout << master_tour << endl;

//    tour tour_test(cities_in_tour);
//
//    cout << tour_test << endl;
//
//    tour_test.shuffle_cities();
//
//    cout << tour_test << endl;
//
//    travelogue wonder_trip {population_size, master_tour};
//
//    cout << wonder_trip.fittest_tour_distance << "\n" << wonder_trip.fittest_tour_ratio << endl;
//
//    wonder_trip.kill_me();


    city master_list [cities_in_tour];

    for (auto elem : master_list) {
        cout << elem << endl;
    }

    tour new_tour  = tour(master_list, cities_in_tour);

    cout << new_tour.get_tour_distance() << endl;
    cout << new_tour.determine_fitness() << endl;

    new_tour.shuffle_cities();

    cout << new_tour << endl;

    cout << new_tour.get_tour_distance() << endl;
    cout << new_tour.determine_fitness() << endl;

    city newCity;

    //cout << newCity.gen_random();

    return 0;
}