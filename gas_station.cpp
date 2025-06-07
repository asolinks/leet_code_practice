#include<iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
                int total_tank = 0, current_tank = 0, start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total_tank += diff;
            current_tank += diff;

            if (current_tank < 0) {
                // Reset starting point and current tank
                start_index = i + 1;
                current_tank = 0;
            }
        }

        return total_tank >= 0 ? start_index : -1;
    }
};