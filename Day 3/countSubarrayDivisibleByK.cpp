/*Brute force*/
class Solution {
/* Generate all possible subarrays with their sum and count the number of them divisible by k.
TC->O(N^2), SC -> O(1)
*/
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum % k == 0) ans++;
            }
        }
        return ans;
    }
};

/* Optimal */
class Solution {
/* Same as count subarray sum with XOR k.
TC->O(N), SC -> O(1)
*/
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for(auto it : nums){
            sum += it;
            int r = sum % k;
            if(r < 0) r += k;
            if(sum%k == 0) ans++;
            ans += mp[r];
            mp[r]++;
        }
        return ans;
    }
};
