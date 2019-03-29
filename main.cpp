


#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "travelogue.hpp"

int main() {

    srand(time(NULL));

    int cities_in_tour = 6;
    int population_size = 6;
    float mutation_rate = 0.15;
    int number_of_shuffles = 64;
    int parent_pool_size = 6;
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

//    for (auto elem : master_list) {
//        cout << elem << endl;
//    }

//    tour new_tour  = tour(master_list, cities_in_tour);
//
//    cout << new_tour.get_tour_distance() << endl;
//    cout << new_tour.determine_fitness() << endl;

    travelogue new_travelogue{master_list, cities_in_tour, population_size, number_of_shuffles};

    cout << new_travelogue;
//
//    cout << new_travelogue.fittest_tour_distance << endl;
//
//    cout << "elite tour: \n" << *new_travelogue.move_elite_to_front() << endl;
//
//    cout << new_travelogue << endl;
//
//    cout << endl;
//
////    cout << "a parent tour: \n" << *new_travelogue.move_elite_to_front();
////
//    cout << endl;
//
//    //cout << new_travelogue;
//
//    travelogue mommy = new_travelogue.get_parent(population_size);
//
//    travelogue daddy = new_travelogue.get_parent(population_size);

    //cout << "mommy: \n" << mommy << endl;

    //cout << "daddy: \n" << daddy << endl;

    //cout << "elite tour momomy: \n" <<

//    *mommy.move_elite_to_front();

    //cout << "elite tour daddy: \n" <<
    //
    // *daddy.move_elite_to_front();

//    tour baby_tour = travelogue::make_a_mutant_baby(&mommy, &daddy, cities_in_tour, mutation_rate);

//    cout << "baby tour: \n" << baby_tour;

    cout << "this happened" << mutation_rate;

    return 0;
}