class Solution {
public:
    int lengthOfLastWord(string source) {
        
        bool flag = false;
        int last = source.length() - 1, count = 0;
        for (int index = last; index >= 0; index--) {

            if (isAlphabet (source[index])) {

                flag = true;
                count++;
            }
            else if (flag) break;
        }

        return count;
    }

private:
    bool isAlphabet(char character) {

        return character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z';
    }
};