class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> answer;
        
        sort (nums.begin(), nums.end());

        int length = nums.size();
        for (int index = 0; index < length - 2; index++) {

            if (index > 0 && nums[index] == nums[index - 1]) continue;

            int left = index + 1, right = length - 1;
            while (left < right) {

                int sum = nums[index] + nums[left] + nums[right];
                if (sum == 0) {

                    answer.push_back ({nums[index], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }

        return answer;
    }
};