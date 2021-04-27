#include <string>
#include <vector>
#include <fstream>
#include <iostream>



class Line {
    public:
     int index;
     std::string osm_id;
     std::string type;
     int oneway;
     int bridge;
     std::string geometry;


    Line& operator<<(const std::string& line);
};


std::string SubstrFromPosToDel(const std::string& str, size_t* idx_ptr);
std::vector<Line> LinesFromCsvFile(const std::string& file_name);
