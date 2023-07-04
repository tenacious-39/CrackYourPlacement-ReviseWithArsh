// Solution link: https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/
/* Brute Force*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto it : nums){
            st.insert(it);
        }
        int i = 0;
        for(auto it : st){
            nums[i++] = it;
        }
        return st.size();
    }
};
// Optimal Approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        while(j < n){
            if(nums[j] != nums[i]){
                i++;
                swap(nums[j], nums[i]);
            }
            j++;
        }
        return i+1;
    }
};
