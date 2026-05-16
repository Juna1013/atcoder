#include <stdio.h>

#define MAXN 400005

int lo[MAXN], lo_size = 0;
int hi[MAXN], hi_size = 0;

void push_lo(int v) {
    lo[lo_size] = v;
    int i = lo_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (lo[p] < lo[i]) {
            int tmp = lo[p]; lo[p] = lo[i]; lo[i] = tmp;
            i = p;
        } else break;
    }
}

int pop_lo(void) {
    int ret = lo[0];
    lo[0] = lo[--lo_size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, m = i;
        if (l < lo_size && lo[l] > lo[m]) m = l;
        if (r < lo_size && lo[r] > lo[m]) m = r;
        if (m == i) break;
        int tmp = lo[i]; lo[i] = lo[m]; lo[m] = tmp;
        i = m;
    }
    return ret;
}

void push_hi(int v) {
    hi[hi_size] = v;
    int i = hi_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (hi[p] > hi[i]) {
            int tmp = hi[p]; hi[p] = hi[i]; hi[i] = tmp;
            i = p;
        } else break;
    }
}

int pop_hi(void) {
    int ret = hi[0];
    hi[0] = hi[--hi_size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, m = i;
        if (l < hi_size && hi[l] < hi[m]) m = l;
        if (r < hi_size && hi[r] < hi[m]) m = r;
        if (m == i) break;
        int tmp = hi[i]; hi[i] = hi[m]; hi[m] = tmp;
        i = m;
    }
    return ret;
}

void insert(int v) {
    if (lo_size == 0 || v <= lo[0]) push_lo(v);
    else push_hi(v);

    if (lo_size == hi_size + 2) push_hi(pop_lo());
    else if (hi_size > lo_size) push_lo(pop_hi());
}

int main(void) {
    int X, Q;
    scanf("%d %d", &X, &Q);
    insert(X);
    for (int i = 0; i < Q; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        insert(A);
        insert(B);
        printf("%d\n", lo[0]);
    }
    return 0;
}
