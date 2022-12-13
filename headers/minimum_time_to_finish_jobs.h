#pragma once

#include <vector>
#include <algorithm>
#include <limits>

class MinimumTimeToFinishAllJobs {
private:
    bool isPossibleTime(int numOfAssignees, int timeTakenByAssignee, const std::vector<int>& jobs, int mid);
public:
    int getMinTIme(int numOfAssignees, int timeTakenByAssignee, const std::vector<int>& jobs);
};

int MinimumTimeToFinishAllJobs::getMinTIme(int numOfAssignees, int timeTakenByAssignee, const std::vector<int>& jobs) {
    int low = 0; 
    int high = std::accumulate(jobs.begin(), jobs.end(), 0);

    int res = std::numeric_limits<int>::max();
    int maxElem = *std::max_element(jobs.begin(), jobs.end());
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid >= maxElem && isPossibleTime(numOfAssignees, timeTakenByAssignee, jobs, mid)) {
            if(mid < res) {
                res = mid;
            }
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return res * timeTakenByAssignee;
}

bool MinimumTimeToFinishAllJobs::isPossibleTime(int numOfAssignees, int timeTakenByAssignee, const std::vector<int>& jobs, int mid) {
    int currentAssignees = 0;
    int currentWork = 0;
    for(const auto& elem: jobs) {
        if(currentWork + elem  > mid) {
            ++currentAssignees;
            currentWork = 0;
        }
        currentWork += elem;
    }
    if(currentWork > 0 && currentWork <= mid) {
        ++currentAssignees;
    }
    return (currentAssignees <= numOfAssignees);
}