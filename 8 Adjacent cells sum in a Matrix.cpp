#include <iostream>
#include <vector>
using namespace std;
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> arr(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    int row, col;
    cin >> row >> col;
    int diff[8][2] = { {-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1} };
    int sum = 0;
    for (int k = 0; k < 8; k++) {
        int adjR = row + diff[k][0];
        int adjC = col + diff[k][1];
        if (adjR >= 0 && adjR < r && adjC >= 0 && adjC < c) {
            sum += arr[adjR][adjC];
        }
    }
    cout << sum;
    return 0;
}
