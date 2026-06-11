#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int diff[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp,
        int r, int c, int i, int j) {
    if (dp[i][j] != 0)
        return dp[i][j];
    int aMax = 0;
    for (int k = 0; k < 4; k++) {
        int adjR = i + diff[k][0];
        int adjC = j + diff[k][1];
        if (adjR >= 0 && adjR < r &&
            adjC >= 0 && adjC < c &&
            matrix[adjR][adjC] > matrix[i][j]) {
            aMax = max(aMax, dfs(matrix, dp, r, c, adjR, adjC));
        }
    }
    dp[i][j] = 1 + aMax;
    return dp[i][j];
}
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(r, vector<int>(c, 0));
    int maxLen = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dp[i][j] == 0) {
                maxLen = max(maxLen, dfs(matrix, dp, r, c, i, j));
            }
        }
    }
    cout << maxLen << endl;
    return 0;
}
