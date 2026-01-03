class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int answer = nums[0] + nums[1] + nums[2];

        int length = nums.size();
        for (int index = 0; index < length - 2; index++) {

            if (index > 0 && nums[index] == nums[index - 1]) continue;

            int left = index + 1, right = length - 1;
            while (left < right) {

                int sum = nums[index] + nums[left] + nums[right];

                if (abs(sum - target) < abs(answer - target)) answer = sum;

                if (sum == target) return sum;
                else if (sum < target) left++;
                else right--;
            }
        }

        return answer;
    }
};