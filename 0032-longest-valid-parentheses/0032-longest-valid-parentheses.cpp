class Solution {
public:
    int longestValidParentheses(string source) {
        
        int answer = 0;
        stack<int> buffer;
        buffer.push(-1);

        for (int index = 0; index < source.length(); index++) {

            if (source[index] == '(') buffer.push(index);
            else {

                buffer.pop();
                if (buffer.empty()) buffer.push(index);
                else answer = max (answer, index - buffer.top());
            }
        }

        return answer;
    }
};