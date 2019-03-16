


#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "travelogue.hpp"

int main() {

    const tour master_tour{20};

    tour master_test{20};

    cout << master_tour;

    cout << master_test;

    travelogue{5, master_tour};

    return 0;
}