// 解法：スライディングウィンドウ
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long va = *(long long *)a;
    long long vb = *(long long *)b;

    if (va == vb) return 0;
    else if (va < vb) return -1;
    else return 1;
}

int main(void) {
    int N;  long long K;
    scanf("%d %lld", &N, &K);
    long long A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    /* 各要素を K で割った余りに置き換え */
    for (int i = 0; i < N; i++) A[i] = A[i] % K;

    qsort(A, N, sizeof(long long), cmp);

    /*
     * deque を配列で実装する。
     * N 回操作すると head が N-1、tail が 2N-1 まで進むので 2N 要素確保する。
     * 先頭: deque[head], 末尾: deque[tail-1]
     */
    long long deque[2 * N];
    int head = 0, tail = N;
    for (int i = 0; i < N; i++) deque[i] = A[i];

    /* ソート後は deque が昇順なので max = deque[tail-1], min = deque[head] */
    long long ans = deque[tail - 1] - deque[head];

    /*
     * 「先頭を取り出して K 足して末尾に追加」を N-1 回繰り返す。
     * A[i] < K を満たすので A[i] + K >= K > A[N-1] となり、
     * 追加後も deque は昇順を保つ。
     */
    for (int i = 0; i < N - 1; i++) {
        long long front = deque[head];
        head++;
        deque[tail] = front + K;
        tail++;

        long long diff = deque[tail - 1] - deque[head];
        if (diff < ans) ans = diff;
    }

    printf("%lld\n", ans);

    return 0;
}
