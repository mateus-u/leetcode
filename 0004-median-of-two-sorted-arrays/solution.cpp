#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged(nums1.size() + nums2.size());

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        if (merged.size() % 2 == 1)
        {
            return merged[merged.size() / 2];
        }
        else
        {
            int a = merged[merged.size() / 2 -1];
            int b = merged[merged.size() / 2];

            return double(a + b) / 2;
        }
    }
};

int main()
{
    auto solution = new Solution();

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double response = solution->findMedianSortedArrays(nums1, nums2);

    cout << response << endl;
}