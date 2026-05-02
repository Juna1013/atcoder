#include <stdio.h>

int N, Q;
int below_card[300001];
int count_arr[300001];

int find_pile(int c) {
    if (below_card[c] == -1) return c;
    below_card[c] = find_pile(below_card[c]);
    return below_card[c];
}

int main(void) {
    int i, C, P;

    scanf("%d %d", &N, &Q);

    for (i = 1; i <= N; i++) {
        below_card[i] = -1;
    }

    for (i = 0; i < Q; i++) {
        scanf("%d %d", &C, &P);
        below_card[C] = P;
    }

    for (i = 1; i <= N; i++) {
        count_arr[find_pile(i)]++;
    }

    for (i = 1; i <= N; i++) {
        if (i > 1) printf(" ");
        printf("%d", count_arr[i]);
    }
    printf("\n");

    return 0;
}
