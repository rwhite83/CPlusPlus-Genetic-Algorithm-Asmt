//
// Created by rwhit on 3/16/2019.
//

#include <iostream>
#include "travelogue.hpp"
#include "city.hpp"
#include "tour.hpp"

using namespace std;

/////////why does this have to be here and not in the header???///////////
vector<tour> travelogue_vector;

//travelogue travelogue::generate_travelogue(double travelogue_count) {
//    travelogue_vector.clear();
//    for (int i = 0; i < travelogue_count; i++) {
//        //tour new_tour{};
//        new_tour.generate_tour(travelogue_count);
//        cout << new_tour;
//        travelogue_vector.push_back(new_tour);
//    }
//}
//
//ostream &operator<<(ostream &os, const travelogue &tr) {
////    for (auto elem : travelogue_vector) {
////        //cout << elem;
////        //os << elem << "d" << "\n";
////    }
////    os << endl;
//    return os;
//}