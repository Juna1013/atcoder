#include <stdio.h>

int main(void) {
    int H, W;
    scanf("%d %d", &H, &W);

    for (int i = 0; i < H; i++) {
        if (i == 0 || i == H-1) {
            for (int j = 0; j < W; j++) printf("#");
        } else {
            printf("#");
            for (int j = 0; j < W-2; j++) printf(".");
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
