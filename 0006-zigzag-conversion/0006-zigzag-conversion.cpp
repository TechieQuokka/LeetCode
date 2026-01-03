class Solution {
public:
    string convert(string source, int numRows) {

        if (numRows < 2)  return source;
        
        vector<vector<char>> destination (numRows);

        int index = 0, direction = 1;
        for (const auto& character : source) {

            destination[index].push_back (character);

            if (index == 0) direction = 1;
            else if (index == numRows - 1) direction = -1;

            index += direction;
        }

        int position = 0;
        int length = source.size();
        char* result = new char[length + 1];
        for (int row = 0; row < numRows; row++) {
            for (const auto& element : destination[row]) {

                result[position++] = element;
            }
        }
        result[position++] = '\0';

        string answer(result);
        delete[] result;

        return answer;
    }
};