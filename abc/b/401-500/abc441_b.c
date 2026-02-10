#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    char S[27], T[27];
    scanf("%s %s", S, T);

    int Q;
    scanf("%d", &Q);

    bool in_s[26] = {0};
    bool in_t[26] = {0};
    for (int i = 0; i < N; i++) in_s[S[i] - 'a'] = true;
    for (int i = 0; i < M; i++) in_t[T[i] - 'a'] = true;

    for (int i = 0; i < Q; i++) {
        char w[101];
        scanf("%s", w);
        size_t len = strlen(w);

        bool all_s = true;
        bool all_t = true;
        for (size_t j = 0; j < len; j++) {
            int idx = w[j] - 'a';
            if (!in_s[idx]) all_s = false;
            if (!in_t[idx]) all_t = false;
        }

        if (all_s && !all_t) {
            puts("Takahashi");
        } else if (!all_s && all_t) {
            puts("Aoki");
        } else {
            puts("Unknown");
        }
    }

    return 0;
}
