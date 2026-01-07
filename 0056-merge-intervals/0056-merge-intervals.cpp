class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort (intervals.begin(), intervals.end());

        vector<vector<int>> answer;
        answer.push_back (intervals[0]);

        for (int index = 1, pivot = 0; index < intervals.size(); index++) {

            auto& interval = intervals[index];
            if (interval[0] <= answer[pivot][1]) {

                answer[pivot][1] = max (answer[pivot][1], interval[1]);
                continue;
            }

            answer.push_back (interval);
            pivot++;
        }

        return answer;
    }
};