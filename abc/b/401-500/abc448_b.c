// 解法：貪欲法
#include <stdio.h>
#include <stdlib.h>

// qsortに渡す比較関数
int cmp_desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    long long C[M+1];
    for (int j = 1; j <= M; j++) {
        scanf("%lld", &C[j]);
    }

    // 各コショウ種類ごとにB_iを集める
    int *B[M+1];
    int cnt[M+1];
    for (int j = 1; j <= M; j++) {
        B[j] = NULL;
        cnt[j] = 0;
    }

    int A[N], Bv[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i], &Bv[i]);
        cnt[A[i]]++;
    }
    for (int j = 1; j <= M; j++) B[j] = malloc(cnt[j] * sizeof(int));
    int idx[M+1];
    for (int j = 1; j <= M; j++) idx[j] = 0;
    for (int i = 0; i < N; i++) {
        B[A[i]][idx[A[i]]++] = Bv[i];
    }

    long long ans = 0;
    for (int j = 1; j <= M; j++) {
        qsort(B[j], cnt[j], sizeof(int), cmp_desc);
        long long rem = C[j];
        for (int k = 0; k < cnt[j] && rem > 0; k++) {
            long long take = B[j][k] < rem ? B[j][k] : rem;
            ans += take;
            rem -= take;
        }
        free(B[j]);
    }

    printf("%lld\n", ans);
    return 0;
}
