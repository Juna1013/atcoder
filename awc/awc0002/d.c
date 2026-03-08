// 提出したところタイムアウト
#include <stdio.h>

int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    int C[N], R[M];
    for (int i = 0; i < N; i++) scanf("%d", &C[i]);
    for (int j = 0; j < M; j++) scanf("%d", &R[j]);

    // 各宝箱を強度が低い順にソートする
    int tmp = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (C[j] > C[j+1]) {
                tmp = C[j];
                C[j] = C[j+1];
                C[j+1] = tmp;
            }
        }
    }

    // 鍵の開錠能力が低い順にソートする
    tmp = 0;
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - i - 1; j++) {
            if (R[j] > R[j+1]) {
                tmp = R[j];
                R[j] = R[j+1];
                R[j+1] = tmp;
            }
        }
    }

    // 宝箱と開錠能力をそれぞれ高い順から照らし合わせて、開けられる宝箱の個数をカウントする
    int cnt = 0;
    int j = 0; // 鍵のインデックス

    for (int i = 0; i < N; i++) {
        // C[i]を開けられる鍵を探す
        while (j < M && R[j] < C[i]) j++; // この鍵では開けられないので、次の鍵へ

        if (j < M) { // 開けられる鍵が見つかった（R[j] >= C[i]）
            cnt++;
            j++; // この鍵を使ったので次の鍵へ
        } else break; // もう鍵がない
    }

    // cnt（開けることのできる宝箱の個数）を出力する
    printf("%d\n", cnt);
    return 0;
}
