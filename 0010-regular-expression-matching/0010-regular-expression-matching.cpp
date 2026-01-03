class Solution {
public:
    bool isMatch(string s, string p) { return isMatchRecursive(s, p, 0, 0); }

    bool isMatchRecursive(string source, string pattern, int s_index,
                          int p_index) {

        if (s_index == source.size() && p_index == pattern.size())
            return true;
        if (p_index == pattern.size())
            return false;

        bool firstMatch =
            (s_index < source.size()) &&
            (pattern[p_index] == source[s_index] || pattern[p_index] == '.');

        if (p_index + 1 < pattern.size() && pattern[p_index + 1] == '*') {

            bool result =
                isMatchRecursive(source, pattern, s_index, p_index + 2);
            result |= firstMatch &&
                      isMatchRecursive(source, pattern, s_index + 1, p_index);
            return result;
        } else
            return firstMatch &&
                   isMatchRecursive(source, pattern, s_index + 1, p_index + 1);
    }
};