/*Brute*/
class Solution {
public:
/* Approach 1: Sort the array and keep the element arr[i] if arr[i] == arr[i-1];
TC -> O(NlogN), SC = O(1)
*/
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                ans.emplace_back(nums[i]);
            }
        }
        return ans;
    }
};

// Better:
class Solution {
public:
/* Approach 2: Use a hashmap.
TC -> O(N), SC = O(N)
*/
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            if(mp[nums[i]] > 0){
                ans.emplace_back(nums[i]);
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};


/// Optimal

class Solution {
public:
/* Approach 3: While traversing the array mark index (nums[i]-1) negaive i.e. perform nums[nums[i]-1]*(-1). If nums[i] appears twice, for the first nums[i] we will mark nums[i]-1 negative. Next time if we found that the nums[i]-1 is already marked, we can say nums[i] is duplicate.
Caution: While taking index we have to take abs(nums[i]) as we are marking some indices to keep track of elements. Otherwise we will get runtime error.
TC -> O(N), SC = O(1)
*/
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0) return ans;
        for(int i = 0; i < n; i++){
           if(nums[abs(nums[i])-1] < 0){
               ans.push_back(abs(nums[i]));
           } else nums[abs(nums[i])-1] *= (-1);
        }
        return ans;
    }
};
