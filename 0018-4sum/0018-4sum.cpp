class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> answer;

        int length = nums.size();
        for (int row = 0; row < length - 3; row++) {
            if (row > 0 && nums[row] == nums[row - 1]) continue;

            for (int column = row + 1; column < length - 2; column++) {
                if (column > row + 1 && nums[column] == nums[column - 1]) continue;

                int left = column + 1, right = length - 1;
                while (left < right) {

                    long long sum = (long long)nums[row] + nums[column] + nums[left] + nums[right];
                    if (sum == target) {

                        answer.push_back ({nums[row], nums[column], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }

        return answer;
    }
};