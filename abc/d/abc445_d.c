#include <stdio.h>
#include <stdlib.h>

#define MAXN 200001

int ph[MAXN], pw[MAXN];
int bw[MAXN], bh[MAXN];
int used[MAXN];
int ar[MAXN], ac[MAXN];

typedef struct { int val, lo, hi, ptr; } Grp;
Grp wg[MAXN], hg[MAXN];
int nwg, nhg;

int cmpw(const void *a, const void *b) { return pw[*(int*)a] - pw[*(int*)b]; }
int cmph(const void *a, const void *b) { return ph[*(int*)a] - ph[*(int*)b]; }

void build(int *s, int n, int *v, Grp *g, int *ng) {
    *ng = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && v[s[j]] == v[s[i]]) j++;
        g[(*ng)++] = (Grp){v[s[i]], i, j, i};
        i = j;
    }
}

int findg(Grp *g, int ng, int v) {
    int lo = 0, hi = ng - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (g[m].val == v) return m;
        if (g[m].val < v) lo = m + 1;
        else hi = m - 1;
    }
    return -1;
}

int findp(Grp *g, int *s) {
    while (g->ptr < g->hi) {
        if (!used[s[g->ptr]]) return s[g->ptr];
        g->ptr++;
    }
    return -1;
}

int main(void) {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &ph[i], &pw[i]);
        bw[i] = bh[i] = i;
    }
    qsort(bw, N, sizeof(int), cmpw);
    qsort(bh, N, sizeof(int), cmph);
    build(bw, N, pw, wg, &nwg);
    build(bh, N, ph, hg, &nhg);

    int h = H, w = W, r = 1, c = 1;
    for (int step = 0; step < N - 1; step++) {
        int f = -1, gi;
        gi = findg(wg, nwg, w);
        if (gi >= 0) f = findp(&wg[gi], bw);
        if (f >= 0) {
            used[f] = 1;
            ar[f] = r; ac[f] = c;
            r += ph[f]; h -= ph[f];
        } else {
            gi = findg(hg, nhg, h);
            f = findp(&hg[gi], bh);
            used[f] = 1;
            ar[f] = r; ac[f] = c;
            c += pw[f]; w -= pw[f];
        }
    }
    for (int i = 0; i < N; i++)
        if (!used[i]) { ar[i] = r; ac[i] = c; break; }

    for (int i = 0; i < N; i++)
        printf("%d %d\n", ar[i], ac[i]);
    return 0;
}