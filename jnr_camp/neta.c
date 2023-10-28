#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        alice += x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        bob += x;
    }
    if (alice > bob)
        printf("Alice\n");
    else if (alice < bob)
        printf("Bob\n");
    else
        printf("Re-election\n");
    return 0;
}