#include "./stdc++.h"

using namespace std;

char *numbers = (char *)"0123456789";

int main(void) {
    ios_base::sync_with_stdio(false);
    string input;
    int result = 0;

    bool doing = true;
    while (cin >> input) {
        size_t mulPos = input.find("mul(", 0);
        size_t doPos = input.find("do()", 0);
        size_t dontPos = input.find("don't()", 0);

        if (mulPos == string::npos)
            mulPos = input.max_size();
        if (doPos == string::npos)
            doPos = input.max_size();
        if (dontPos == string::npos)
            dontPos = input.max_size();

        size_t pos = min(mulPos, min(doPos, dontPos));

        while (pos != input.max_size()) {
            if (input.substr(pos, 4) == "do()") {
                cout << "do" << endl;
                doing = true;
            } else if (input.substr(pos, 7) == "don't()") {
                cout << "don't" << endl;
                doing = false;
            } else if (doing && input.substr(pos, 4) == "mul(") {
                size_t split = input.find(",", pos + 1);
                size_t multEnd = input.find(")", split + 1);
                if (split != string::npos && multEnd != string::npos) {
                    string int1 = input.substr(pos + 4, split - pos - 4);
                    string int2 = input.substr(split + 1, multEnd - split - 1);

                    if (strspn(int1.c_str(), numbers) == int1.size() && strspn(int2.c_str(), numbers) == int2.size()) {
                        cout << int1 << " " << int2 << endl;

                        result += stoi(int1) * stoi(int2);
                    }
                }
            }

            size_t mulPos = input.find("mul(", pos + 1);
            size_t doPos = input.find("do()", pos + 1);
            size_t dontPos = input.find("don't()", pos + 1);

            if (mulPos == string::npos)
                mulPos = input.max_size();
            if (doPos == string::npos)
                doPos = input.max_size();
            if (dontPos == string::npos)
                dontPos = input.max_size();

            pos = min(mulPos, min(doPos, dontPos));
        }
    }

    cout << result << " RESULT" << endl;
}
