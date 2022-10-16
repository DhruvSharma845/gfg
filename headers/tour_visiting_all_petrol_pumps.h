#pragma once

#include <utility>
#include <vector>

class PetrolPumpsTour {
public:
    int getIndexOfPetrolPumpThatCoverAllPetrolPumps(const std::vector<std::pair<int, int>>& petrolPumpInfo);
};

auto PetrolPumpsTour::getIndexOfPetrolPumpThatCoverAllPetrolPumps(const std::vector<std::pair<int, int>>& petrolPumpInfo) -> int {
    int start = 0;
    int end = 1;

    int currentCapacity = petrolPumpInfo[start].second - petrolPumpInfo[start].first;

    while(end != start || currentCapacity < 0) {
        while(currentCapacity < 0 && end != start) {
            currentCapacity -= (petrolPumpInfo[start].second - petrolPumpInfo[start].first);
            start = (start + 1) % petrolPumpInfo.size();
            if(start == 0) {
                return -1;
            }
        }
        currentCapacity += (petrolPumpInfo[end].second - petrolPumpInfo[end].first);
        end = (end + 1) % petrolPumpInfo.size();
    }
    return start;
}