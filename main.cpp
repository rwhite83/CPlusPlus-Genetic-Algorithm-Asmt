


#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "travelogue.hpp"

int main() {

    const tour master_tour{20};

    tour master_test{20};

//    double wubbs = master_test.determine_fitness();
//
//    cout << wubbs;

//    cout << master_tour;
//
//    cout << master_test;
//
//    cout << master_test.fitness_rating;

    travelogue wonder_trip {5, master_tour};

    cout << wonder_trip.fittest_tour << endl;

    return 0;
}