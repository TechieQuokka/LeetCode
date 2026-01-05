class Solution {
public:
    int jump(vector<int>& nums) {
        
        int length = nums.size();
        if (length == 1) return 0;

        vector<bool> visited (length, false);
        queue<pair<int, int>> buffer;
        buffer.push ({0, 0}); // index, count
        visited[0] = true;

        while (!buffer.empty()) {

            auto pivot = buffer.front(); buffer.pop();

            for (int position = pivot.first; position <= min(pivot.first + nums[pivot.first], length - 1); position++) {

                if (position == length - 1) return pivot.second + 1;
                if (visited[position]) continue;

                visited[position] = true;
                buffer.push ({position, pivot.second + 1});
            }
        }

        return 0;
    }
};