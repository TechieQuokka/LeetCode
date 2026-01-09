class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        backtrack(s, 0, parts, result);
        return result;
    }

private:
    void backtrack(string source, int start, vector<string>& parts, vector<string>& outResult) {

        if (parts.size() == 4) {
            if (start == source.length()) {
                outResult.push_back(build(parts));
            }
            return;
        }

        for (int length = 1; length <= 3; length++) {

            if (start + length > source.length()) break;

            string segment = source.substr(start, length);
            if (isValid(segment)) {

                parts.push_back(segment);
                backtrack(source, start + length, parts, outResult);
                parts.pop_back();
            }
        }

        return;
    }

    bool isValid(string segment) {
        if (segment.length() > 1 && segment[0] == '0') {
            return false;
        }

        int value = stoi(segment);
        return value >= 0 && value <= 255;
    }

    string build(vector<string>& parts) {
        string result = parts[0];
        for (int i = 1; i < parts.size(); i++) {
            result += "." + parts[i];
        }
        return result;
    }
};