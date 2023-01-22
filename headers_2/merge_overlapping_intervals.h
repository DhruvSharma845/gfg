#pragma once

#include <utility>
#include <vector>
#include <algorithm>

class MergeOverlappingIntervals {
public:
    using Interval = std::pair<int, int>;
    using IntervalArray = std::vector<Interval>;
    IntervalArray mergeIntervals(const IntervalArray& intervals);
};

MergeOverlappingIntervals::IntervalArray MergeOverlappingIntervals::mergeIntervals(const MergeOverlappingIntervals::IntervalArray& intervals) {
    IntervalArray clonedIntervals(intervals.begin(), intervals.end());

    std::sort(clonedIntervals.begin(), clonedIntervals.end(), [](const Interval& f, const Interval& s) {
        return f.first < s.first;
    });

    std::stack<Interval> intervalSt;
    intervalSt.push(clonedIntervals[0]);

    for(int i = 1; i < clonedIntervals.size(); ++i) {
        if(clonedIntervals[i].first < intervalSt.top().second) {
            intervalSt.top().second = std::max(intervalSt.top().second, clonedIntervals[i].second);
        }
        else {
            intervalSt.push(clonedIntervals[i]);
        }
    } 
    IntervalArray res;
    res.reserve(intervalSt.size());
    while(!intervalSt.empty()) {
        res.push_back(intervalSt.top());
        intervalSt.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
}