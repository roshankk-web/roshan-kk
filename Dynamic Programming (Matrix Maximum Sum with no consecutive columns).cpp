#include <iostream>
#include <vector>
using namespace std;
vector<long long> getFSMax(vector<vector<long long>>& dp, int i, int c) {
    long long fmax = max(dp[i][0], dp[i][1]);
    long long smax = min(dp[i][0], dp[i][1]);
    for(int j = 2; j < c; j++) {
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
    vector<vector<long long>> dp(r + 1, vector<long long>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
            if(i == 0) {
                dp[i][j] = mat[i][j];
            }
        }
    }
    for(int i = 1; i < r; i++) {
        vector<long long> fsmax = getFSMax(dp, i - 1, c);
        for(int j = 0; j < c; j++) {
            dp[i][j] = mat[i][j] +
                      (dp[i - 1][j] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }
    cout << getFSMax(dp, r - 1, c)[0];
    return 0;
}
