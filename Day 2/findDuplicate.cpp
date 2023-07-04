/* Brute Force */
class Solution {
public:
/*Approach: Sort the array and check if arr[i] == arr[i-1]
TC -> O(NlogN) SC->O(1)
*/
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1])
            return nums[i];
        }
        return -1;
    }
};

/* Better Approach using hashmap*/
class Solution {
public:
/*Approach: Use hashmap to keep track of the frequencies.
TC -> O(N) SC->O(N)
*/
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto &it : nums){
            if(mpp[it]){
                return it;
            }
            mpp[it]++;
        }
        return -1;
    }
};

/*Optimal approach Using Tortoise and Hare method*/
class Solution {
public:
/*Approach:Use tortoise and Hare algorithm or fast and slow pointer.
TC -> O(N) SC->O(1)
*/
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
