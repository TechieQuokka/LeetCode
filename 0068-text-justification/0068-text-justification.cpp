class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> answer;
        vector<pair<int, string>> buffer;
        for (const auto& element : words) {
            if (buffer.empty()) {
                buffer.push_back ({element.length() + 1, element});
                continue;
            }
            
            auto data = buffer.back();
            if (data.first + element.length() <= maxWidth) buffer.push_back ({data.first + element.length() + 1, element});
            else {
                answer.push_back (justifyLine (buffer, buffer.back().first - 1, maxWidth));
                buffer.clear();
                buffer.push_back ({element.length() + 1, element});
            }
        }

        answer.push_back (leftAlignLine(buffer, maxWidth));
        return answer;
    }

private:
    string justifyLine (vector<pair<int, string>> buffer, int length, int maxWidth) {

        int wordCount = buffer.size();
        int gaps = wordCount - 1;
        
        if (gaps == 0) return buffer[0].second + string(maxWidth - buffer[0].second.length(), ' ');
        
        int pureWordLength = length - gaps;
        int totalSpaces = maxWidth - pureWordLength;
        int spacesPerGap = totalSpaces / gaps;
        int extraSpaces = totalSpaces % gaps;

        string result = "";
        for (int index = 0; index < wordCount; index++) {
            result += buffer[index].second;
            if (index < gaps) {
                int spaces = spacesPerGap;
                if (index < extraSpaces) spaces++;
                result += string(spaces, ' ');
            }
        }
        return result;
    }

    string leftAlignLine(vector<pair<int, string>> buffer, int maxWidth) {
    
        string result = "";
        int wordCount = buffer.size();
        
        for (int index = 0; index < wordCount; index++) {
            result += buffer[index].second;
            if (index < wordCount - 1) result += ' ';
        }
        
        if (maxWidth > result.length()) result += string(maxWidth - result.length(), ' ');
        
        return result;
    }
};