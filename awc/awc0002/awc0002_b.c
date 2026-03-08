#include <stdio.h>

int main(void) {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int A[N], B[M];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);
    
    int number_cnt = 0;
    long long suger_content = 0;
    for (int i = 0; i < M; i++) {
        if (A[B[i] - 1] < K) {
            number_cnt++;
            suger_content += A[B[i] - 1];
        }
    }

    printf("%d ", number_cnt);
    printf("%lld\n", suger_content);

    return 0;
}
