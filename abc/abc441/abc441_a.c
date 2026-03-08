#include <stdio.h>

int main(void) {
    int P, Q, X, Y;
    scanf("%d %d", &P, &Q);
    scanf("%d %d", &X, &Y);

    if ((P <= X && X <= P + 99) && (Q<= Y && Y <= Q + 99)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
