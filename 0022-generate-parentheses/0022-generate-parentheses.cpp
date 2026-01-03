class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> answer;
        solution ("", 0, 0, 0, n, answer);

        return answer;
    }

private:
    void solution (string current, int open, int close, int depth, int size, vector<string>& outResult) {

        if (depth == size * 2) {

            outResult.push_back (current);
            return;
        }

        if (open < size) solution (current + '(', open + 1, close, depth + 1, size, outResult);
        if (close < open) solution (current + ')', open, close + 1, depth + 1, size, outResult);
        return;
    }

    bool isParentheses (string data) {

        stack<bool> buffer;
        for (const auto& element : data) {

            if (element == '(') buffer.push (true);
            else if (element == ')' && buffer.empty() == false) buffer.pop();
            else return false;
        }
        return buffer.empty();
    }
};