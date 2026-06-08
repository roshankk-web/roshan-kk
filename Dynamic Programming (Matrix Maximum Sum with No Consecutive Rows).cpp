#include <iostream>
#include <vector>
using namespace std;
vector<long long> getFSMax(vector<vector<long long>>& dp, int j, int r) {
    long long fmax = max(dp[0][j], dp[1][j]);
    long long smax = min(dp[0][j], dp[1][j]);
    for(int i = 2; i < r; i++) {
        if(dp[i][j] > fmax) {
            smax = fmax;
            fmax = dp[i][j];
        }
        else if(dp[i][j] > smax) {
            smax = dp[i][j];
        }
    }
    return {fmax, smax};
}
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    vector<vector<long long>> dp(r, vector<long long>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
            if(j == 0) {
                dp[i][j] = mat[i][j];
            }
        }
    }
    for(int j = 1; j < c; j++) {
        vector<long long> fsmax = getFSMax(dp, j - 1, r);
        for(int i = 0; i < r; i++) {
            dp[i][j] = mat[i][j] +
                      (dp[i][j - 1] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }
    cout << getFSMax(dp, c - 1, r)[0];
    return 0;
}
