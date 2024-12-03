#include "./stdc++.h"

using namespace std;

char *numbers = (char *)"0123456789";

int main(void) {
    ios_base::sync_with_stdio(false);
    string input;
    int result = 0;

    while (cin >> input) {
        if (input == "TERMINATOR;") {
            break;
        }

        size_t pos = input.find("mul(", 0);

        while (pos != string::npos) {
            size_t split = input.find(",", pos + 1);
            size_t multEnd = input.find(")", split + 1);
            if (split != string::npos && multEnd != string::npos) {
                string int1 = input.substr(pos + 4, split - pos - 4);
                string int2 = input.substr(split + 1, multEnd - split - 1);

                if (strspn(int1.c_str(), numbers) == int1.size() && strspn(int2.c_str(), numbers) == int2.size()) {
                    cout << int1 << " " << int2 << endl;

                    result += atoi(int1.c_str()) * atoi(int2.c_str());
                }
            }

            pos = input.find("mul(", pos + 1);
        }
    }

    cout << result << " RESULT" << endl;
}
