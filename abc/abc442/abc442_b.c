#include <stdio.h>

int main(void) {
    int Q, A;
    scanf("%d", &Q);

    int volume = 0;
    int playback = 0;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &A);

        if (A == 1) volume++;
        else if (A == 2) {
            if (volume >= 1) volume--;
        } else {
            playback ^= 1;
        }

        if (volume >= 3 && playback == 1) puts("Yes");
        else puts("No");
    }

    return 0;
}
