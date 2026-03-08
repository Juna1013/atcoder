#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int h = N / 100;
    int t = (N / 10) % 10;
    int o = N % 10;

    if (h == t && t == o) printf("Yes\n");
    else printf("No\n");

    return 0;
}
