#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Add all intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the merged interval
        result.push_back(newInterval);

        // Add all intervals after newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main() {
    Solution sol;

    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> newInterval = {2, 5};

    std::vector<std::vector<int>> result = sol.insert(intervals, newInterval);

    std::cout << "Resulting intervals:\n";
    for (const auto& interval : result) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
