class Solution {
public:
    bool isValid(string source) {
        
        stack<char> buffer;
        for (const auto& element : source) {

            if (element == '(' || element == '{' || element == '[') {

                buffer.push (element);
                continue;
            }
            else if (buffer.empty()) return false;

            char target = buffer.top();
            if (element == ')') {
                if (target != '(') return false;
                
                buffer.pop();
            }
            else if (element == '}') {
                if (target != '{') return false;

                buffer.pop();
            }
            else if (target != '[') return false;
            else buffer.pop();
        }

        return buffer.empty();
    }
};