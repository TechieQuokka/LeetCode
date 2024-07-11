class Solution {
public:
    int findKthLargest(vector<int>& numbers, int target) {
        
        priority_queue<int> heap;

        for (const auto& element : numbers) {

            heap.push (element);
        }

        for (int repeat = 1; repeat < target; repeat++) {

            heap.pop();
        }

        return heap.top();
    }
};