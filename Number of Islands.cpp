#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>>& grid, int i, int j) {
    int r = grid.size();
    int c = grid[0].size();
    if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    dfs(grid, i - 1, j); 
    dfs(grid, i + 1, j); 
    dfs(grid, i, j - 1); 
    dfs(grid, i, j + 1); 
}
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    int islandCount = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                islandCount++;
                dfs(grid, i, j);
            }
        }
    }
    cout << islandCount << endl;
    return 0;
}
