#include "data.h"
#include <iostream>
using namespace std;


int main() {
    
    // demo
    std::vector<Line> data = LinesFromCsvFile("shape.csv");
    cout 
    << "index:     " << data[0].index << '\n'
    << "osm_id:    " << data[0].osm_id << '\n'
    << "type:      " << data[0].type << '\n'
    << "oneway:    " << data[0].oneway << '\n'
    << "bridge:    " << data[0].bridge << '\n'
    << "geometry:  " << data[0].geometry << '\n'
    << "size:      " << data.size() << endl;
    
    
};