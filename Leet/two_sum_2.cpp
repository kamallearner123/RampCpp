#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        vector <int> actual(nums.size());
        copy(nums.begin(), nums.end(), actual.begin());

        sort(nums.begin(), nums.end());
        for (auto x: nums) {
            cout << x << " " << endl;
        }
        for (auto y: actual) {
            cout << y << " " << endl;
        }
        int len = nums.size();
        int i=0, j=len-1;
        while(i!=j) {
            cout << i << " " << j << endl;      
            auto sum = nums[i]+nums[j];
            if (sum < target) {
                i++;
            } else if (sum> target) {
                j--;
            } else {
                return {(int)distance(actual.begin(), find(actual.begin(), actual.end(), nums[i])),
                len-1-(int)distance(actual.rbegin(), find(actual.rbegin(), actual.rend(), nums[j]))};
            }
            cout << i << " " << j << endl;      
        }  
        return result;
    }
};


int main() {
    vector <int> a = {3,2,4, 0, -1, 100};
    Solution s;
    vector<int> result = s.twoSum(a, 6);
    if(result.size() != 0)
        cout << result[0] << " " << result[1] << endl;
    return 0;
}