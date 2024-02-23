#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, short> map;
        vector<int> response;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                response = {i, map[target - nums[i]]};
                break;
            }

            map.insert(pair<int, short>{nums[i], i});
        }

        return response;
    }
};

int main()
{
    auto solution = new Solution();

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto result = solution->twoSum(nums, target);

    printf("[%d,%d]", result[0], result[1]);
}