#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> valToIndex;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end())
            return false;
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end())
            return false;

        int index = valToIndex[val];
        int lastElement = nums.back();

        // Move the last element to the index of the element to be removed
        nums[index] = lastElement;
        valToIndex[lastElement] = index;

        // Remove last element
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};