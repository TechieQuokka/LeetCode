class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort (nums.begin(), nums.end());
        
        set<vector<int>> result;
        vector<int> buffer;
        backtrack (nums, buffer, 0, result);

        vector<vector<int>> answer;
        for (const auto& element : result) {

            answer.push_back (element);
        }

        return answer;
    }

private:
    void backtrack (vector<int>& nums, vector<int>& buffer, int current, set<vector<int>>& outResult) {

        outResult.insert (buffer);

        for (int index = current; index < nums.size(); index++) {

            buffer.push_back (nums[index]);
            backtrack (nums, buffer, index + 1, outResult);
            buffer.pop_back();
        }

        return;
    }
};