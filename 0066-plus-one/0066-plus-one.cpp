class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int temp = 1;
        int last = digits.size() - 1;
        for (int index = last; index >= 0; index--) {

            int sum = digits[index] + temp;
            if (sum < 10) {

                digits[index] = sum;
                temp = 0;
                break;
            }
            digits[index] = sum % 10;
        }
        if (temp == 1) digits.insert (digits.begin(), 1);

        return digits;
    }
};