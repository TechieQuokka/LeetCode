class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> sorted_nums;
        for (int index = 0; index < nums.size(); index++) {
            sorted_nums.push_back ({nums[index], index});
        }

        sort (sorted_nums.begin(), sorted_nums.end());

        int left = 0, right = nums.size() - 1;

        while (left < right) {

            int sum = sorted_nums[left].first + sorted_nums[right].first;

            if (sum == target) {

                return {sorted_nums[left].second, sorted_nums[right].second};
            }
            else if (sum < target) left++;
            else right--;
        }

        return {};
    }
};