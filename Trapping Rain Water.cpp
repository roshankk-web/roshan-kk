#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    vector<int> lMax(n);
    vector<int> rMax(n);
    lMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        lMax[i] = max(lMax[i - 1], height[i]);
    }
    rMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rMax[i] = max(rMax[i + 1], height[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += min(lMax[i], rMax[i]) - height[i];
    }
    cout << count;
    return 0;
}
