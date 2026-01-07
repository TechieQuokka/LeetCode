class Solution {
public:
    bool isMatch(string s, string p) {
        
        this->table.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return isMatchRecursive (s, 0, p, 0);
    }

private:
    bool isMatchRecursive (string& source, int s_index, string& pattern, int p_index) {

        if (table[s_index][p_index] != -1) return table[s_index][p_index];

        if (p_index == pattern.length()) return table[s_index][p_index] = s_index == source.length();
        if (s_index == source.length()) {
            for (int index = p_index; index < pattern.length(); index++) {
                if (pattern[index] != '*') return table[s_index][p_index] = false;
            }
            return table[s_index][p_index] = true;
        }

        if (pattern[p_index] == '*') {

            if (table[s_index][p_index] = isMatchRecursive (source, s_index, pattern, p_index + 1)) return true;
            if (table[s_index][p_index] = isMatchRecursive (source, s_index + 1, pattern, p_index)) return true;
            return table[s_index][p_index] = false;
        }

        if (pattern[p_index] == '?' || source[s_index] == pattern[p_index]) 
            return table[s_index][p_index] = isMatchRecursive (source, s_index + 1, pattern, p_index + 1);
        return table[s_index][p_index] = false;
    }

private:
    vector<vector<int>> table;
};