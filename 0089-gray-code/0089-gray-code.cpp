class Solution {
public:
    vector<int> grayCode(int n) {
        
        int number = 2;
        vector<int> answer = { 0, 1 };
        for (int loop = 1; loop < n; loop++) {

            auto temp = reverse (answer, number);
            answer.insert (answer.end(), temp.begin(), temp.end());
            number <<= 0x1;
        }

        return answer;
    }

private:
    vector<int> reverse (vector<int> source, int number) {

        vector<int> result;
        for (int index = source.size() - 1; index >= 0; index--) {

            int value = source[index] | number;
            result.push_back(value);
        }

        return result;
    }
};