class Solution {
public:
    bool canJump(vector<int>& nums) {

        if (nums.size() == 1) return true;
        
        vector<bool> visited (nums.size(), false);
        queue<pair<int, int>> buffer;
        buffer.push ({0, nums[0]});

        while (buffer.empty() == false) {

            auto data = buffer.front(); buffer.pop();
            int current = data.first;
            int jump = data.second;

            for (int index = 1; index <= jump; index++) {

                int pivot = current + index;
                if (pivot >= nums.size() - 1) return true;
                if (visited[pivot]) continue;
                else visited[pivot] = true;

                buffer.push ({pivot, nums[pivot]});
            }
        }

        return false;
    }
};