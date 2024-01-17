
//-----------------------------------------
  // Time Complexity: O(n)
  //  Space Complexity: O(1)


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first_max = nums[0], index_x = 0;
        for(int i = 1; i <= nums.size() - 1; i++){
            if(first_max < nums[i]){
                first_max = nums[i];
                index_x = i;
            }
        }

        int second_max = INT_MIN, index_y;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(index_x != i && second_max < nums[i]){
                second_max = nums[i];
            }
        }

        return (first_max - 1)*(second_max - 1);
    }
};

//-------------------------------------------------


// ------------------------------------------------

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] - 1)*(nums[nums.size() - 2] - 1);
    }
};

// Question Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2023-12-12 
