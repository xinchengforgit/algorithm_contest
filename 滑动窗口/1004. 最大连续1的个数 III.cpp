#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
            int l = 0, r = 0;
        int cur = 0;
        int ans = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r] == 0) {
                cur++;
            }
            while (cur > k) {
                if (nums[l] == 0) {
                    cur--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};