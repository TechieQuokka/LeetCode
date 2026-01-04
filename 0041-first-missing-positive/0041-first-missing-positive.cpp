class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int length = nums.size();
        for (int& element : nums) {
            if (element <= 0 || element > length) 
                element = length + 1;
        }

        for (int index = 0; index < length; index++) {

            int data = abs(nums[index]);
            if (data > length) continue;

            nums[data - 1] = nums[data - 1] < 0 ? nums[data - 1] : -nums[data - 1];
        }

        for (int index = 0; index < length; index++) {

            if (nums[index] > 0) return index + 1;
        }

        return length + 1;
    }
};