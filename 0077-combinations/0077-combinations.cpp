class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> answer;
        vector<int> buffer (k);
        combination (buffer, 0, 0, k, n, answer);

        return answer;
    }

private:
    void combination (vector<int>& buffer, int current, int depth, int span, int size, vector<vector<int>>& outResult) {

        if (span == 0) {

            outResult.push_back (buffer);
            return;
        }
        if (depth == size) return;

        buffer[current] = depth + 1;

        combination (buffer, current + 1, depth + 1, span - 1, size, outResult);
        combination (buffer, current, depth + 1, span, size, outResult);
    }
};