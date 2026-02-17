#include <stdio.h>

int main(void) {
    int N, K; scanf("%d %d", &N, &K);
    int A[N]; for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int max_power = -1, max_address = 0;
    for (int i = 0; i < N; i++) {
        if (max_power < A[i]) {
            max_power = A[i];
            max_address = i;
        }
    }

    printf("%d\n", max_address+1);
    return 0;
}
