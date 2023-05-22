#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int m, vector<int>& w, vector<int>& p) {
    // dp[i][j] stores the maximum profit that can be obtained using the first i items and a capacity of j
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(w[i-1] <= j) { // if the current item can fit in the remaining capacity
                dp[i][j] = max(dp[i-1][j], p[i-1] + dp[i-1][j-w[i-1]]); // take the maximum of including and not including the item
            }
            else { // if the current item cannot fit in the remaining capacity
                dp[i][j] = dp[i-1][j]; // don't include the item
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    int m =50;
    vector<int> w = {10, 20, 30}; // weights of objects
    vector<int> p = {60, 100, 120}; // profits of objects
    int n = w.size();
    
    
    int ans = knapsack(n, m, w, p);
    cout << ans << endl;
    
    return 0;
}
