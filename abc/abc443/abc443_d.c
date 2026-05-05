#include <stdio.h>

#define MAXN 300001

int R[MAXN], dp_left[MAXN], dp_right[MAXN];

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &R[i]);

        // 左から右へ
        dp_left[0] = R[0];
        for (int i = 1; i < N; i++) {
            dp_left[i] = min(R[i], dp_left[i-1]+1);
        }

        // 右から左へ
        dp_right[N-1] = R[N-1];
        for (int i = N-2; i >= 0; i--) {
            dp_right[i] = min(R[i], dp_right[i+1]+1);
        }

        // 答えを計算
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int t = min(dp_left[i], dp_right[i]);
            ans += R[i] - t;
        }
        printf("%lld\n", ans);
    }

    return 0;
}