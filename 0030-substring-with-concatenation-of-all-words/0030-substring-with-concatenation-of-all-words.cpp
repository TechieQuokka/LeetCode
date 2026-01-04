class Solution {
public:
    vector<int> findSubstring(string source, vector<string>& words) {
        
        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        unordered_map<string, int> hash;
        for (const string& word : words) {

            if (!hash.contains(word)) hash[word] = 1;
            else hash[word]++;
        }

        vector<int> result;
        int length = source.length();

        for (int start = 0; start < wordLength; start++) {

            int left = start, right = start;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + wordLength <= length) {

                string word = slice (source, right, right + wordLength);
                right += wordLength;

                if (!hash.contains(word)) {

                    seen.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > hash[word]) {

                    string leftWord = slice (source, left, left + wordLength);
                    seen[leftWord]--;
                    count--;
                    left += wordLength;
                }

                if (count == wordCount) {

                    result.push_back (left);
                }
            }
        }

        return result;
    }

private:
    string slice (string& source, int start, int end) {

        return source.substr(start, end - start);
    }
};