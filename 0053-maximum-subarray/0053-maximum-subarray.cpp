class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int current = nums[0];
        int maxSum = nums[0];

        for (int index = 1; index < nums.size(); index++) {

            int element = nums[index];
            current = max (element, current + element);
            maxSum = max (maxSum, current);
        }

        return maxSum;
    }
};