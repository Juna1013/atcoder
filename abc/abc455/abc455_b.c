#include <stdio.h>

int H, W;
char S[11][11];

int is_symmetric(int h1, int h2, int w1, int w2) {
    int i, j;
    for (i = h1; i <= h2; i++) {
        for (j = w1; j <= w2; j++) {
            if (S[i][j] != S[h1+h2-i][w1+w2-j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int h1, h2, w1, w2;
    int count = 0;

    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", S[i]);
    }

    for (h1 = 0; h1 <= H-1; h1++) {
        for (h2 = h1; h2 <= H-1; h2++) {
            for (w1 = 0; w1 <= W-1; w1++) {
                for (w2 = w1; w2 <= W-1; w2++) {
                    if (is_symmetric(h1, h2, w1, w2)) {
                        count++;
                    }
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
