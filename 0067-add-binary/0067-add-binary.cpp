class Solution {
private:
    template<typename T>
    void Swap (T& left, T& right) {

        T temp = left;
        left = right;
        right = temp;
        return;
    }

    void Reverse (char* buffer, int length) {

        for (int left = 0, right = length - 1; left < right; left++, right--) {

            this->Swap (buffer[left], buffer[right]);
        }
        return;
    }

public:
    string addBinary(string first, string second) {
        
        int firstLength = first.length(), secondLength = second.length();
        if (firstLength < secondLength) {

            this->Swap<string> (first, second);
            this->Swap<int> (firstLength, secondLength);
        }

        char result[10001] = { 0, }; int index = 0;
        int temp = 0, firstIndex = firstLength - 1;
        for (int secondIndex = secondLength - 1; secondIndex >= 0; firstIndex--, secondIndex--) {

            int left = first[firstIndex] - '0', right = second[secondIndex] - '0';
            result[index++] = ((left ^ right) ^ temp) + '0';
            temp = (left | right) & temp;
            temp |= left & right;
        }

        for (int pivot = firstIndex; pivot >= 0; pivot--) {

            int value = first[pivot] - '0';
            result[index++] = (value ^ temp) + '0';
            temp = value & temp;
        }
        if (temp == 1) result[index++] = '1';
        result[index] = '\0';

        this->Reverse (result, index);
        return string (result);
    }
};

// 110010
// 010111
// ------
// 001001