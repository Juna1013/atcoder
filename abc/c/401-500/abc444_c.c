#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int is_valid(long long L, int *vals, int *cnt, int U) {
    int left = 0;
    int right = U - 1;

    if (right >= 0 && (long long)vals[right] > L) return 0;

    if (right >= 0 && (long long)vals[right] == L) right--;

    while (left <= right) {
        long long sum = (long long)vals[left] + vals[right];
        if (sum != L) return 0;

        if (left == right) {
            if (cnt[left] % 2 != 0) return 0;
        } else {
            if (cnt[left] != cnt[right]) return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int *A = (int *)malloc(sizeof(int) * N);
    if (!A) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int), cmp_int);

    int minA = A[0];
    int maxA = A[N - 1];

    int *vals = (int *)malloc(sizeof(int) * N);
    int *cnt = (int *)malloc(sizeof(int) * N);
    if (!vals || !cnt) {
        free(A);
        free(vals);
        free(cnt);
        return 0;
    }

    int U = 0;
    for (int i = 0; i < N; ) {
        int v = A[i];
        int c = 0;
        while (i < N && A[i] == v) {
            c++;
            i++;
        }
        vals[U] = v;
        cnt[U] = c;
        U++;
    }

    long long ans[2];
    int ans_n = 0;

    long long L1 = maxA;
    if (is_valid(L1, vals, cnt, U)) {
        ans[ans_n++] = L1;
    }

    long long L2 = (long long)maxA + minA;
    if (L2 != L1 && is_valid(L2, vals, cnt, U)) {
        ans[ans_n++] = L2;
    }

    if (ans_n == 2 && ans[0] > ans[1]) {
        long long tmp = ans[0];
        ans[0] = ans[1];
        ans[1] = tmp;
    }

    for (int i = 0; i < ans_n; i++) {
        if (i) printf(" ");
        printf("%lld", ans[i]);
    }
    printf("\n");

    free(A);
    free(vals);
    free(cnt);
    return 0;
}
