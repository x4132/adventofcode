#include "./stdc++.h"

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  vector<int> leftArr;
  vector<int> rightArr;

  int in;
  bool left = true;
  while (cin >> in) {
    if (left) {
      leftArr.push_back(in);
    } else {
      rightArr.push_back(in);
    }

    left = !left;
  }

  sort(leftArr.begin(), leftArr.end());
  sort(rightArr.begin(), rightArr.end());

  int output = 0;
  for (int i = 0; i < leftArr.size(); i++) {
    output += abs(leftArr[i] - rightArr[i]);
  }

  cout << output << endl;
}
