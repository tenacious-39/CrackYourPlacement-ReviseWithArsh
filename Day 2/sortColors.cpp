/*Brute force*/
class Solution {
public:
/* Approach: Sort the array using sort() function.
TC -> O(NlogN), SC -> O(1)
*/
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

/* Better Approach sorting by counting 0's, 1's and 2's*/
class Solution {
public:
/* Approach: Sort by counting the 0's, 1's, 2's.
TC -> O(2*N), SC -> O(1)
*/
    void sortColors(vector<int>& nums) {
        int z = 0, o = 0, t = 0;
        for(auto it : nums){
            if(it == 0) z++;
            else if(it == 1) o++;
            else t++;
        }
        int i = 0;
        while(z--) nums[i++] = 0;
        while(o--) nums[i++] = 1;
        while(t--) nums[i++] = 2;
    }
};

/* Optimal Approach Dutch national flag algorithm*/

class Solution {
public:
/* Approach: Dutch national flag algorithm low, mid, high.
TC -> O(2*N), SC -> O(1)
*/
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            switch(nums[mid]){
            case 0: swap(nums[low], nums[mid]);
            low++, mid++;
             break;
            case 1: mid++; break;
            case 2: swap(nums[mid], nums[high]);
            high--;
             break;
        }
        }
    }
};
