class Solution {
public:
    int numTrees(int n) {
        
        vector<int> table (n + 1);

        table[0] = table[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {
            for (int root = 1; root <= nodes; root++) {

                int leftNodes = root - 1;
                int rightNodes = nodes - root;

                table[nodes] += table[leftNodes] * table[rightNodes];
            }
        }

        return table[n];
    }
};