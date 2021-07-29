//============================================================================
// Name        : baseOfRegions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================





bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    if (regions.empty())
        return 0;

    map<Region, int> m;
    for (const auto& item : regions) {
        ++m[item];
    }

    int repeats = 0;

    for (const auto& i : m) {
        if (i.second > repeats) {
            repeats = i.second;
        }
    }
    return repeats;
}



