#include <stdio.h>

int main(void) {
    int N, M; scanf("%d %d", &N, &M);

    int answer = (N + 1) / 2;
    if (M <= answer) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}
