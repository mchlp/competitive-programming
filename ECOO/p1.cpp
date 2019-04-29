#include <bits/stdc++.h>

using namespace std;

string upper(string line) {
    string newLine = "";
    for (int i = 0; i < line.size(); i++) {
    }
    return newLine;
}

int main() {
    freopen("DATA12.txt", "r", stdin);
    int _ = 10;
    while (_--) {
        int N;
        cin >> N;
        unordered_set<string> emails;
        int eCount = 0;
        for (int i = 0; i < N; i++) {
            string line;
            string newLine = "";
            cin >> line;

            bool pastAt = false;
            bool pastPlus = false;
            for (int j = 0; j < line.size(); j++) {
                if (line.at(j) == '.') {
                    if (pastAt) {
                        newLine += '.';
                    }
                } else if (line.at(j) == '@') {
                    pastAt = true;
                    newLine += '@';
                } else if (line.at(j) == '+') {
                    if (pastAt) {
                        newLine += '+';
                    } else {
                        pastPlus = true;
                    }
                } else {
                    if (pastAt || (!pastPlus)) {
                        newLine += toupper(line.at(j));
                    }
                }
            }
            if (emails.count(newLine) == 0) {
                emails.insert(newLine);
                eCount++;
            }
        }
        cout << eCount << "\n";
    }
}