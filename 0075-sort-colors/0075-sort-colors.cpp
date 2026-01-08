class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int buffer[3] = { 0, };
        int length = nums.size();
        for (int index = 0; index < length; index++) {

            buffer[nums[index]]++;
        }

        int index = 0;
        for (int pivot = 0; pivot < 3; pivot++) {
            for (int loop = 0; loop < buffer[pivot]; loop++) {

                nums[index++] = pivot;
            }
        }

        return;
    }
};