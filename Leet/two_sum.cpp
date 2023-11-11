#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        for(auto i=0; i<nums.size()-1;i++) {
            for (auto j=i+1; j<nums.size(); j++){
                if (nums[i]+nums[j] == target) {
                    return {i, j};
                }
            }
        }        
        return result;
    }
};


int main() {
    vector <int> a = {2,3,4, 0, -1, 100};
    Solution s;
    vector<int> result = s.twoSum(a, 7);
    if(result.size() != 0)
        cout << result[0] << " " << result[1] << endl;
    return 0;
}