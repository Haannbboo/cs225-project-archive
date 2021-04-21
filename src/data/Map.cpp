#include "Map.h"

#include <DataFrame>


void Map::readFile() {
    df.read(fpath);
}