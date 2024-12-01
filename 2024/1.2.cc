#include "./stdc++.h"

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    vector<int> leftArr;
    map<int, int> rightMap;

    int in;
    bool left = true;
    while (cin >> in) {
        if (left) {
            leftArr.push_back(in);
            if (!rightMap.contains(in)) {
                rightMap[in] = 0;
            }
        } else {
            if (rightMap.contains(in)) {
                rightMap[in]++;
            } else {
                rightMap[in] = 1;
            }
        }

        left = !left;
    }

    int output = 0;
    for (int i : leftArr) {
        output += i * rightMap[i];
    }

    cout << output << endl;
}
