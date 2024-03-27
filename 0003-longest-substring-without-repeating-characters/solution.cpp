#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 1;

        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;

        auto start = s.begin();
        auto end = s.begin() + 1;

        do
        {
            auto aux = start;

            bool skip = false;

            while (aux < end)
            {
                skip = *aux == *end;

                if(skip) break;

                aux++;
            }

            
            
            if (skip)
            {
                start++;
                end = start + 1;
            }
            else
            {
                int size = end - start + 1;

                if (end - start + 1 > max)
                    max = end - start + 1;

                end++;
            }

        } while (end != s.end());

        return max;
    }
};

int main()
{
    Solution *solution = new Solution();

    string s = "";
    auto result = solution->lengthOfLongestSubstring(s);

    printf("[%d]", result);
}