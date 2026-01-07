class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> answer;
        this->buffer.resize (nums.size());
        fill (begin(check), end(check), false);

        sort (nums.begin(), nums.end());

        permutation (nums, this->buffer, this->check, 0, nums.size(), answer);

        return answer;
    }

private:
    void permutation (const vector<int>& nums, vector<int>& buffer, bool check[], int current, int size, vector<vector<int>>& outResult) {

        if (current == size) {

            outResult.push_back (buffer);
            return;
        }

        for (int index = 0; index < size; index++) {

            if (check[index]) continue;
            if (index > 0 && nums[index] == nums[index - 1] && check[index - 1] == false) continue;

            buffer[current] = nums[index];
            check[index] = true;
            permutation (nums, buffer, check, current + 1, size, outResult);
            check[index] = false;
        }
        return;
    }

private:
    vector<int> buffer;
    bool check[16];
};