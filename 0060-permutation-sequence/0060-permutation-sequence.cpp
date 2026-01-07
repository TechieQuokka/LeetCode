class Solution {
public:
    string getPermutation(int n, int k) {
        
        k--;
        vector<char> available (n);
        for (int index = 0; index < n; index++) available[index] = (index + 1) + '0';

        string answer = "";

        for (int pivot = n; pivot > 0; pivot--) {

            int value = factorial (pivot - 1);
            int index = k / value;

            answer += available[index];
            available.erase (available.begin() + index);

            k %= value;
        }

        return answer;
    }

private:
    int factorial (int number) {

        static int table[32] = { 0, };
        if (table[number] > 0) return table[number];
        if (number == 0) return 1;
        return table[number] = number * factorial (number - 1);
    }
};