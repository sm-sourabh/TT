#include <iostream>
#include <vector>
using namespace std;

int max_profit(int m, vector<int>& w, vector<int>& p) {
    int n = w.size();
    vector<vector<int>> table(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i-1] > j) {
                table[i][j] = table[i-1][j];
            } else {
                table[i][j] = max(table[i-1][j], p[i-1] + table[i-1][j-w[i-1]]);
            }
        }
    }
    return table[n][m];
}

int main() {
    int m = 50; // maximum capacity of the sack
    vector<int> w = {10, 20, 30}; // weights of objects
    vector<int> p = {60, 100, 120}; // profits of objects
    cout << "Maximum profit: " << max_profit(m, w, p) << endl;
    return 0;
}
