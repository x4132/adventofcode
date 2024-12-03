#include "./stdc++.h"

using namespace std;

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
        bool isIncreasing = (report[1] > report[0]);

        bool flag = true;
        for (int i = 0; i < report.size() - 1; i++) {
            if (isIncreasing && report[i + 1] < report[i]) {
                flag = false;
                break;
            } else if (!isIncreasing && report[i + 1] > report[i]) {
                flag = false;
                break;
            }

            int diff = abs(report[i + 1] - report[i]);

            if (diff < 1 || diff > 3) {
                flag = false;
                break;
           }
        }

        if (flag) {
            output++;
        }
    }

    cout << output << endl;
}
