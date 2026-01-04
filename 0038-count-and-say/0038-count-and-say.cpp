class Solution {
public:
    string countAndSay(int n) {

        string answer = "1";
        for (int loop = 1; loop < n; loop++) {

            answer = solution (answer);
        }

        return answer;
    }

private:
    string solution (string source) {

        string result = "";
        int count = 0; char previous = source[0];
        for (const char& element : source) {
            if (previous != element) {

                result += (char)((int)'0' + count);
                result += previous;
                count = 0;
            }

            count++;
            previous = element;
        }

        result += (char)((int)'0' + count);
        result += previous;
        return result;
    }
};