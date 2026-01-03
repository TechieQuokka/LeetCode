class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";
        return lcpDivideConquer (strs, 0, strs.size() - 1);
    }

private:
    string lcpDivideConquer (vector<string>& strs, int left, int right) {

        if (left >= right) return strs[left];

        int middle = left + (right - left) / 2;
        return commonPrefix(lcpDivideConquer (strs, left, middle), lcpDivideConquer (strs, middle + 1, right));
    }

    string commonPrefix(string string1, string string2) {

        string result = "";
        int minLength = min (string1.size(), string2.size());

        for (int index = 0; index < minLength; index++) {

            if (string1[index] != string2[index]) break;
            result += string1[index];
        }

        return result;
    }
};