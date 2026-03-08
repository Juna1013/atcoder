#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *ia = (Interval *)a;
    Interval *ib = (Interval *)b;
    if (ia->l != ib->l) return ia->l - ib->l;
    return ib->r - ia->r;
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    Interval seg[M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &seg[i].l, &seg[i].r);
    }

    qsort(seg, M, sizeof(Interval), cmp);

    int cnt = 0;
    int pos = 1;  // 次にカバーすべき区画
    int i = 0;

    while (pos <= N) {
        int best = -1;
        // pos以下から始まる区間のうち、右端が最大のものを選ぶ
        while (i < M && seg[i].l <= pos) {
            if (seg[i].r > best) best = seg[i].r;
            i++;
        }
        if (best == -1) {
            // posをカバーできる区間がない
            printf("-1\n");
            return 0;
        }
        cnt++;
        pos = best + 1;  // bestまでカバーされたので、次はbest+1から
    }

    printf("%d\n", cnt);
    return 0;
}
