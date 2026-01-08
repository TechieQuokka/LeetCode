class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> buffer;
        int maxArea = 0;

        int length = heights.size();
        for (int index = 0; index < length; index++) {
            while (buffer.empty() == false && heights[buffer.top()] > heights[index]) {

                int height = heights[buffer.top()]; buffer.pop();
                int width = 0;

                if (buffer.empty()) width = index;
                else width = index - buffer.top() - 1;

                int area = height * width;
                maxArea = max (maxArea, area);
            }

            buffer.push (index);
        }

        while (buffer.empty() == false) {

            int height = heights[buffer.top()];
            buffer.pop();

            int width = buffer.empty() ? length : length - buffer.top() - 1;
            int area = height * width;
            maxArea = max (maxArea, area);
        }

        return maxArea;
    }
};