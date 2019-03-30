


#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "travelogue.hpp"

int main() {

    srand(time(NULL));

    int cities_in_tour = 32;
    int population_size = 32;
    float mutation_rate = 0.15;
    int number_of_shuffles = 1;
    int number_of_iterations = 1000;

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

    city master_list [cities_in_tour];

    travelogue new_travelogue{master_list, cities_in_tour, population_size, number_of_shuffles};

    travelogue hip_new_travelogue = new_travelogue.master_function(new_travelogue, population_size, mutation_rate, number_of_iterations, number_of_shuffles);

    cout << "minimum distance for given tour is: " << hip_new_travelogue.fittest_tour_distance << endl;

    return 0;
}