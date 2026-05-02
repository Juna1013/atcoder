#include <stdio.h>
#include <stdlib.h>

int N, K;
long long A[300001];
long long group_sum[300001];
int M;

int cmp_asc (const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int cmp_desc(const void *a, const void *b) {
    return cmp_asc(b, a);
}

int main(void) {
    int i;
    long long total = 0;
    long long current_sum;
    long long ans;

    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        total += A[i];
    }

    qsort(A, N, sizeof(long long), cmp_asc);

    M = 0;
    current_sum = A[0];
    for (i = 1; i < N; i++) {
        if (A[i] != A[i-1]) {
            group_sum[M++] = current_sum;
            current_sum = A[i];
        } else {
            current_sum += A[i];
        }
    }
    group_sum[M++] = current_sum;

    qsort(group_sum, M, sizeof(long long), cmp_desc);

    if (K >= M) {
        printf("0\n");
        return 0;
    }

    ans = total;
    for (i = 0; i < K; i++) {
        ans -= group_sum[i];
    }

    printf("%lld\n", ans);
    return 0;
}
