class Solution {
public:
    bool isMatch(string s, string p) {

        vector<vector<optional<bool>>> memo (s.size()+1, vector<optional<bool>>(p.size()+1));
        return isMatchRecursive(memo, s, p, 0, 0);
    }

    bool isMatchRecursive(vector<vector<optional<bool>>>& memo, const string& source, const string& pattern, int s_index, int p_index) {

        if (s_index == source.size() && p_index == pattern.size())
            return true;
        if (p_index == pattern.size())
            return false;

        if (memo[s_index][p_index].has_value()) return memo[s_index][p_index].value();

        bool firstMatch = (s_index < source.size()) && (pattern[p_index] == source[s_index] || pattern[p_index] == '.');

        if (p_index + 1 < pattern.size() && pattern[p_index + 1] == '*') {

            bool result = isMatchRecursive(memo, source, pattern, s_index, p_index + 2);
            result |= firstMatch && isMatchRecursive(memo, source, pattern, s_index + 1, p_index);
            memo[s_index][p_index] = result;
            return result;
        } 
        memo[s_index][p_index] = firstMatch && isMatchRecursive(memo, source, pattern, s_index + 1, p_index + 1);
        return memo[s_index][p_index].value();
    }
};