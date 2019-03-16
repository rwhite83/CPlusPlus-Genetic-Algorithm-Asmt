#include <iostream>
#include "city.hpp"
#include "tour.hpp"
#include "travelogue.hpp"

int main() {

    //tour master_tour{};

    tour sample_tour{};

    sample_tour.generate_tour(5);

    //master_tour.generate_master_tour();

    //master_tour.print_master_tour();
    cout << sample_tour;

    return 0;
}