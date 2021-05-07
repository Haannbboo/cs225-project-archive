#include "dataLoader.h"


std::string SubstrFromPosToDel(const std::string& str, size_t* idx_ptr) {
    
    size_t& idx = *idx_ptr;
    std::string substr;
    for (; idx < str.size(); ++idx) {
        if (str.at(idx) == '"'){
            substr.push_back(str.at(idx));
            idx++;
            while(true) {
                substr.push_back(str.at(idx));
                if (str.at(idx) == '"') {
                    return substr;
                }
                idx++;
            }
        }
        if (str.at(idx) == ',' || str.at(idx) == '\n') break;
        substr.push_back(str.at(idx));
    }
    idx += 1;
    return substr;
}


Line& Line::operator<<(const std::string& line) {

    size_t idx = 0;
    index = std::stoi(SubstrFromPosToDel(line, &idx));
    osm_id = SubstrFromPosToDel(line, &idx);
    type = SubstrFromPosToDel(line, &idx);
    oneway = std::stoi(SubstrFromPosToDel(line, &idx));
    bridge = std::stoi(SubstrFromPosToDel(line, &idx));
    geometry = SubstrFromPosToDel(line, &idx);
    return *this;
}


std::vector<Line> LinesFromCsvFile(const std::string& file_name) {

    std::ifstream ifs(file_name);
    std::vector<Line> lines;
    std::string line;
    std::getline(ifs, line);
    while (std::getline(ifs, line)) {
        Line m;
        m << line;
        lines.push_back(m);
    }
    ifs.close();
    return lines;
}






