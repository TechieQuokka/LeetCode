class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> answer;
        vector<int> buffer (nums.size());
        bool table[8] = { false, };
        permutation (nums, buffer, table, 0, 0, nums.size(), answer);

        return answer;
    }

private:
    void permutation (const vector<int>& nums, vector<int>& buffer, bool check[], int current, int depth, int size, vector<vector<int>>& outResult) {

        if (depth == size) {

            outResult.push_back (buffer);
            return;
        }

        for (int index = 0; index < size; index++) {
            if (check[index]) continue;

            buffer[current] = nums[index];
            check[index] = true;
            permutation (nums, buffer, check, current + 1, depth + 1, size, outResult);
            check[index] = false;
        }
        return;
    }
};