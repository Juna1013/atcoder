#include <stdio.h>

#define MAXN 200001

int A[MAXN];
int L[MAXN];
int start[MAXN + 1];
long long C[MAXN];

int main(void) {
    int N;
    long long K;
    scanf("%d %lld", &N, &K);

    start[1] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d",&L[i]);
        for (int j = 1; j <= L[i]; j++) {
            scanf("%d", &A[start[i] + j - 1]);
        }
        start[i + 1] = start[i] + L[i];
    }

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &C[i]);
    }

    for (int i = 1; i <= N; i++) {
        long long block = C[i] * L[i];
        if (K <= block) {
            int pos = K % L[i];
            if (pos == 0) pos = L[i];
            printf("%d\n", A[start[i] + pos - 1]);
            return 0;
        } else {
            K -= C[i] * L[i];
        }
    }

    return 0;
}
