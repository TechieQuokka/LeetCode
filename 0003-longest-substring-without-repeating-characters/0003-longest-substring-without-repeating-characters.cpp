class Solution {
public:
    int lengthOfLongestSubstring(string source) {
  
        bool table[128] = { false, };
        
        int maxCount = 0, count = 0;  
        int left = 0, right = 0;
        int length = source.size();
        while (right < length) {
            
            char character = source[right];
            if (table[(int)character] == 0) {
            
                table[(int)character] = true;
                right++;
                count++;
                maxCount = max (maxCount, count);
                continue;
            }
            while (source[left++] != character) {
                
                table[(int)source[left - 1]] = false;
                count--;
            }
            
            right++;
            table[(int)character] = true;
            maxCount = max (maxCount, count);
        }
        return maxCount;
    }
};