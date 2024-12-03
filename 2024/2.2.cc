#include "./stdc++.h"

using namespace std;

bool isSafe(const vector<int>& nums) {
    if (nums.size() <= 1) return true;

    // Try both increasing and decreasing
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < nums.size() - 1; i++) {
        int diff = nums[i+1] - nums[i];
        if (diff <= 0) increasing = false;
        if (diff >= 0) decreasing = false;
        if (abs(diff) < 1 || abs(diff) > 3) {
            increasing = false;
            decreasing = false;
        }
    }

    return increasing || decreasing;
}

bool isSafeWithDampener(const vector<int>& report) {
    if (isSafe(report)) return true;

    // Try removing each number
    for (int i = 0; i < report.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < report.size(); j++) {
            if (j != i) temp.push_back(report[j]);
        }
        if (isSafe(temp)) return true;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);

    vector<vector<int>> reports;

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> report;
        int num;
        while (ss >> num) {
            report.push_back(num);
        }

        reports.push_back(report);
    }

    int output = 0;
    for (vector<int> report : reports) {
        if(isSafeWithDampener(report)) {
            output++;
        }
    }

    cout << output << endl;
}
