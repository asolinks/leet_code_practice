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

int main() {
    RandomizedSet randomizedSet;

    std::cout << boolalpha; // Print bools as true/false

    std::cout << "Insert 1: " << randomizedSet.insert(1) << std::endl;     // true
    std::cout << "Remove 2: " << randomizedSet.remove(2) << std::endl;     // false
    std::cout << "Insert 2: " << randomizedSet.insert(2) << std::endl;     // true
    std::cout << "Get Random: " << randomizedSet.getRandom() << endl; // 1 or 2
    std::cout << "Remove 1: " << randomizedSet.remove(1) << std::endl;     // true
    std::cout << "Insert 2: " << randomizedSet.insert(2) << std::endl;     // false
    std::cout << "Get Random: " << randomizedSet.getRandom() << std::endl; // 2

    return 0;
}