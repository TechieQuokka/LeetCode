class Solution {
public:
    string minWindow(string source, string target) {
        
        unordered_map<char, int> targetCount;
        for (const auto& element : target) {

            if (targetCount.contains (element) == false) targetCount[element] = 1;
            else targetCount[element]++;
        }

        unordered_map<char, int> windowCount;

        int required = targetCount.size();
        int formed = 0;

        int left = 0, right = 0;
        int minLength = INT_MAX;
        int minLeft = 0;

        while (right < source.length()) {

            char character = source[right];
            windowCount[character]++;

            if (targetCount.contains(character) && windowCount[character] == targetCount[character]) formed++;

            while (left <= right && formed == required) {
                if (right - left + 1 < minLength) {

                    minLength = right - left + 1;
                    minLeft = left;
                }

                character = source[left];
                windowCount[character]--;

                if (targetCount.contains(character) && windowCount[character] < targetCount[character]) formed--;

                left++;
            }
            right++;
        }

        return minLength == INT_MAX ? "" : source.substr(minLeft, minLength);
    }
};