class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> answer;
        vector<int> buffer;

        backtrack (nums, buffer, 0, answer);
        return answer;
    }

private:
    void backtrack (vector<int>& nums, vector<int>& buffer, int current, vector<vector<int>>& outResult) {

        outResult.push_back (buffer);

        for (int index = current; index < nums.size(); index++) {

            buffer.push_back (nums[index]);
            backtrack (nums, buffer, index + 1, outResult);
            buffer.pop_back();
        }

        return;
    }
};