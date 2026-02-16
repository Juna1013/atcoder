#include <stdio.h>
#include <string.h>

int main(void) {
    int N; scanf("%d", &N);
    char S[N][101];

    int len_max = 0;
    int S_len[N];
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
        S_len[i] = strlen(S[i]);
        if (len_max < strlen(S[i])) len_max = strlen(S[i]);
    }

    for (int i = 0; i < N; i++) {
        S_len[i] = (len_max - S_len[i]) / 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S_len[i]; j++) printf(".");
        printf("%s", S[i]);
        for (int j = 0; j < S_len[i]; j++) printf(".");
        printf("\n");
    }

    return 0;
}
