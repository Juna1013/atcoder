#include <stdio.h>

int main(void) {
    int H, W;
    scanf("%d %d", &H, &W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int adj = (i > 0) + (i < H-1) + (j > 0) + (j < W-1);
            if (j > 0) printf(" ");
            printf("%d", adj);
        }
        printf("\n");
    }

    return 0;
}
