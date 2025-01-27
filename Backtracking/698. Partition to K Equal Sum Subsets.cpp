/*------------------------
  Time Complexity: O(n!)
  Space Complexity: O(n!)
---------------------------*/

class Solution {
public:
    bool partition(vector<int> &nums, int i, vector<int> &buckets, int &target){
        if(i == nums.size()){
            for(int num : buckets){
                if(num != target) return false;
            }
            return true;
        }

        for(int bucket = 0; bucket <= buckets.size() - 1; bucket++){
            if(buckets[bucket] + nums[i] > target) continue;

            buckets[bucket] += nums[i];
            if(partition(nums, i + 1, buckets, target)) return true;
            buckets[bucket] -= nums[i];

            if(buckets[bucket] == 0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size()) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(k > sum || sum % k) return false;

        sort(nums.begin(), nums.end(), greater<int>());
        int target = (sum / k);
        vector<int> buckets(k, 0);
        return partition(nums, 0, buckets, target);
    }
};

/*
Question Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
Author: M.R.Naganathan
*/
