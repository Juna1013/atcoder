#include <stdio.h>

int main(void) {
  // 入力
  int N;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // 各人について判定
  for (int i = 0; i < N; i++) {
    int result = -1;
    // 左側から順に探す（最も近い人を見つけるため逆順）
    for (int j = i - 1; j >= 0; j--) {
      if (A[j] > A[i]) {
        result = j + 1; // 1-indexed
        break;
      }
    }
    printf("%d\n", result);
  }

  return 0;
}
