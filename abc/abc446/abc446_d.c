// 解法：DP貪欲法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_int(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);
}

static int lower_bound(int *arr, int n, int v) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] < v) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // 座標圧縮：a[i] と a[i]-1 を両方圧縮
    int *vals = malloc(2 * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vals[2*i] = a[i];
        vals[2*i+1] = a[i]-1;
    }
    qsort(vals, 2*n, sizeof(int), cmp_int);
    int m = 0;
    for (int i = 0; i < 2*n; i++) {
        if (i == 0 || vals[i] != vals[i-1]) {
            vals[m++] = vals[i];
        }
    }

    int *dp = calloc(m, sizeof(int));
    int ans = 1;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vals, m, a[i]);
        int pred_idx = lower_bound(vals, m, a[i]-1);
        dp[idx] = dp[pred_idx] + 1;
        if (dp[idx] > ans) ans = dp[idx];
    }

    printf("%d\n", ans);

    free(a); free(vals); free(dp);
    return 0;
}
