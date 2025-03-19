class Solution {
public:
    bool IsPalindrome (string source, int start, int end) {

        for (int left = start, right = end; left < right; left++, right--) {

            if (source[left] != source[right]) return false;
        }
        return true;
    }

    string SubString (string source, int start, int end) {

        char result[1024] = { 0, };

        int position = 0;
        for (int index = start; index <= end; index++) {

            result[position++] = source[index];
        }

        return string(result);
    }

    string longestPalindrome(string source) {
        
        int start = 0, end = 0;

        int max_count = -1;
        int count = 1;

        int length = source.size();
        for (int pivot = 0; pivot < length; pivot++) {
            for (int index = pivot; index < length; index++) {
                if (source[pivot] == source[index] && IsPalindrome(source, pivot, index) && max_count < count) {

                    start = pivot;
                    end = index;
                    max_count = count;
                }
                count++;
            }
            count = 1;
        }
        return SubString (source, start, end);
    }
};