class Solution {
private:
    vector<int> KMP_Substring_Search (string& source, string& pattern, vector<int>& table) {
	
        vector<int> result;
        
        int length = source.length(), patternLength = pattern.length();
        for (int index = 0, pivot = 0; index < length; index++) {
            if (source[index] == pattern[pivot]) {
                if (pivot == (patternLength - 1)) { // find
                    
                    result.push_back(index - patternLength + 1);
                    pivot = table[pivot];
                }
                else pivot++;
                continue;
            }
            
            while (pivot > 0)
            {
                pivot = table[pivot - 1];
                if (source[index] == pattern[pivot]) {
                    
                    pivot++;
                    break;
                }
            }
        }
        
        return result;
    }

    vector<int> PrefixArrayLogic (string& pattern) {
        
        int length = pattern.length();
        vector<int> table (length, 0);
        
        for (int index = 1, pivot = 0; index < length; index++) {
            
            if (pattern[index] == pattern[pivot]) {
                
                table[index] = ++pivot;
                continue;
            }
            
            while (pivot > 0 && pattern[index] != pattern[pivot]) {
                
                pivot = table[pivot - 1];
            }
            
            table[index] = pivot == 0 && pattern[index] != pattern[pivot] ? pivot : ++pivot;
        }
        return table;
    }
public:
    int strStr(string haystack, string needle) {
        
        vector<int> table = PrefixArrayLogic (needle);
	    vector<int> result = KMP_Substring_Search (haystack, needle, table);

        if (result.size() == 0) return -1;
        return result[0];
    }
};