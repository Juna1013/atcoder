#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = N; i > 0; i--) {
        printf("%d", i);
        if (i != 1) printf(",");
    }
    printf("\n");

    return 0;
}
