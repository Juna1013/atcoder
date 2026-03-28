#include <stdio.h>

#define MAX 300005

int heights[MAX]; // 追加した木の高さ
int size = 0;     // heights の要素数

// ソート済み配列に h を挿入する
void insert(int h) {
    int i = size - 1;
    while (i >= 0 && heights[i] > h) {
        heights[i+1] = heights[i];
        i--;
    }
    heights[i+1] = h;
    size++;
}

// heights の中で値が low < x <= high の個数を返す
int count_range(int low, int high) {
    // left: heights[i] > low が初めて真になるインデックス
    int lo = 0, hi = size;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (heights[mid] > low) hi = mid;
        else lo = mid + 1;
    }
    int left = lo;

    // right: heights[i] > high が初めて真になるインデックス
    lo = 0; hi = size;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (heights[mid] > high) hi = mid;
        else lo = mid + 1;
    }
    int right = lo;

    return right - left;
}

int main(void) {
    int Q, n, h;
    scanf("%d", &Q);

    int threshold = 0;
    int count = 0;

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &n, &h);
        if (n == 1) {
            if (h > threshold) {
                insert(h);
                count++;
            }
        } else {
            if (h > threshold) {
                count -= count_range(threshold, h);
                threshold = h;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
