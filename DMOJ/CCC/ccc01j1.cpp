#include<bits/stdc++.h>

using namespace std;

int H;

int main() {
    scanf("%d", &H);
    for (int i=1; i<H; i+=2) {
        for (int _=0; _<i; _++) {
            printf("*");
        }
        for (int _=0; _<H-i; _++) {
            printf(" ");
        }
        for (int _=0; _<H-i; _++) {
            printf(" ");
        }
        for (int _=0; _<i; _++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i=H; i>=0; i-=2) {
        for (int _=0; _<i; _++) {
            printf("*");
        }
        for (int _=0; _<H-i; _++) {
            printf(" ");
        }
        for (int _=0; _<H-i; _++) {
            printf(" ");
        }
        for (int _=0; _<i; _++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}