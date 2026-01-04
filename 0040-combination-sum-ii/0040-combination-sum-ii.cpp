class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> answer;
        vector<int> list;

        sort (candidates.begin(), candidates.end());
        solution (candidates, target, list, 0, answer);
        return answer;
    }

private:
    void solution (vector<int>& candidates, int remaining, vector<int>& list, int startIndex, vector<vector<int>>& outResult) {

        if (remaining == 0) {

            outResult.push_back (list);
            return;
        }
        if (remaining < 0) return;

        for (int index = startIndex; index < candidates.size(); index++) {
            if (index > startIndex && candidates[index] == candidates[index - 1]) continue;
            
            list.push_back (candidates[index]);
            solution (candidates, remaining - candidates[index], list, index + 1, outResult);
            list.pop_back();
        }
        return;
    }
};