#include <bits/stdc++.h>

using namespace std;

int main() {

    string name;
    getline(cin, name);
    cout << name << endl;
    cout << "====================\n";

    int tab = 0;
    int tr = 0;
    int th = 0;
    int ttwoh = 0;
    int tthreeh = 0;
    int thome = 0;

    for (int i = 0; i < 10; i++) {
        string team;
        int gp, ab, r, h, twoh, threeh, home;
        cin >> team >> gp >> ab >> r >> h >> twoh >> threeh >> home;
        int bat = round(h * 1000 / (double) ab);
        int slug = round(1000 *((h - twoh - threeh - home) + (2 * twoh) + (3 * threeh) + (4 * home)) / (double) ab);
        cout << team << ": ." << bat << " ." << slug << endl;

        tab += ab;
        tr += r;
        th += h;
        ttwoh += twoh;
        tthreeh += threeh;
        thome += home;
    }

    cout << "====================\n";
    int bat = round(th * 1000 / (double) tab);
    int slug = round(1000 *((th - ttwoh - tthreeh - thome) + (2 * ttwoh) + (3 * tthreeh) + (4 * thome)) / (double) tab);
    cout << "Big 10 Av: ." << bat << " ." << slug << endl;


    return 0;
}