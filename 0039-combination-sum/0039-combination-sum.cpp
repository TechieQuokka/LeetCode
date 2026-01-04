class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> answer;
        vector<int> list;
        solution (candidates, target, list, 0, answer);
        return answer;
    }

private:
    void solution (vector<int>& candidates, int target, vector<int>& list, int startIndex, vector<vector<int>>& outResult) {

        int calculate = sum (list);
        if (calculate == target) {

            outResult.push_back (list);
            return;
        }
        if (calculate > target) return;

        for (int index = startIndex; index < candidates.size(); index++) {

            int element = candidates[index];
            list.push_back (element);
            solution (candidates, target, list, index, outResult);
            list.pop_back();
        }
        return;
    }

    int sum (vector<int>& list) {

        int result = 0;
        for (const int& element : list) {

            result += element;
        }

        return result;
    }
};