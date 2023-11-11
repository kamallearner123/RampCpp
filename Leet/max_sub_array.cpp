#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max = nums[0];
        int total;
        int i,j;
        for (i=0; i<nums.size(); i++) {
            if (nums[i] <0) {
                continue;
            }
            total = nums[i];
            if (total > max)
                max = total;
            
            for (j=i+1; j<nums.size(); j++) {
                total += nums[j];
                if(total > max) {
                    max = total;
                }
            }       
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> v = {-2,1};
    cout << s.maxSubArray(v) << endl;;
}