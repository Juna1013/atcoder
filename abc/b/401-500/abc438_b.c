#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void) {
    int N, M;
    char S[101], T[101];
    scanf("%d %d", &N, &M);
    scanf("%s", S);
    scanf("%s", T);
    
    int min_ops = INT_MAX;
    
    for (int i = 0; i <= N - M; i++) {
        int ops = 0;
        for (int j = 0; j < M; j++) {
            int from = T[j] - '0';
            int to = S[i + j] - '0';
            int cost = (to - from + 10) % 10;
            ops += cost;
        }
        if (ops < min_ops) {
            min_ops = ops;
        }
    }
    
    printf("%d\n", min_ops);
    
    return 0;
}