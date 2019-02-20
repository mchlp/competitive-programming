#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        if (x < 1000) {
            printf("Newbie\n");
        } else if (x < 1200) {
            printf("Amateur\n");
        } else if (x < 1500) {
            printf("Expert\n");
        } else if (x < 1800) {
            printf("Candidate Master\n");
        } else if (x < 2200) {
            printf("Master\n");
        } else if (x < 3000) {
            printf("Grandmaster\n");
        } else if (x < 4000) {
            printf("Target\n");
        } else {
            printf("Rainbow Master\n");
        }
    }
}