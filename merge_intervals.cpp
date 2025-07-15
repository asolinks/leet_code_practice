#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        // Sort intervals by the starting time
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);

        for (std::size_t i = 1; i < intervals.size(); ++i) {
            std::vector<int>& last = merged.back();

            if (intervals[i][0] <= last[1]) {
                last[1] = std::max(last[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
