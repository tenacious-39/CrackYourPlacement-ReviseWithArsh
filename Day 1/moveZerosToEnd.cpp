/* Brute Force*/
class Solution {
public:
/*
Naive approach: Use a temporary array and store all the non-zero elements in order.
Now, fill the first places of the original array with the elements from the temp
array and fill the last cells with 0.
TC -> O(2*N), SC -> O(non-negative elements)
*/
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(auto it : nums){
            if(it){
                temp.emplace_back(it);
            }
        }

        int nonNeg = temp.size(), n = nums.size();
        for(int i = 0; i < nonNeg; i++){
            nums[i] = temp[i];
        }

        for(int i = nonNeg; i < n; i++)
        nums[i] = 0;

    }
};


/* Optimal Approach*/
class Solution {
public:
/*
Naive approach: Use 2 pointer method. Place j ointer on the first 0. Place i next
to it. Now, if nums[i] != 0, swap(nums[i], nums[j]) and increment both i and j.
If nums[i] == 0, just increment i nothing else.
TC -> O(N), SC -> O(1)
*/
    void moveZeroes(vector<int>& nums) {
        int i = -1, j = -1;
        for(auto it : nums){
            j++;
            if(!it) break;
        }
        i = j+1;
        int n = nums.size();
        while(i < n){
            if(nums[i]){
                swap(nums[i], nums[j]);
                i++, j++;
            } else{
                i++;
            }
        }
    }
};
