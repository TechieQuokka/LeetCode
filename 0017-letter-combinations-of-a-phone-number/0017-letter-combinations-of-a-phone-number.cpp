class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> answer;

        string current = "";
        solution (phoneMap, digits, 0, current, answer);
        return answer;
    }

private:
    void solution (unordered_map<char, string>& phoneMap, string& digits, int index, string& current, vector<string>& outResult) {

        if (index == digits.size()) {

            outResult.push_back (current);
            return;
        }

        string letters = phoneMap[digits[index]];

        for (const char& letter : letters) {

            current.push_back(letter);
            solution (phoneMap, digits, index + 1, current, outResult);
            current.pop_back();
        }
        return;
    }
};