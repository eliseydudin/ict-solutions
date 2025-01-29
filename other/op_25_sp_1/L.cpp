/*
 * 60/100 points
 */

#include <stdio.h>

int N, M, K, dor[5000][5000], j, u, result, min[5000];

int solve(int uk, int sum) {
  int i;

  if (result == 0) return 0;
  if (uk == u - 1) {
    if (result > sum) result = sum;
    return 1;
  };

  if (sum >= result) return 0;

  if (sum < min[uk]) min[uk] = sum;
  for (i = 0; i < N; i++) {
    if (dor[uk][i] >= 0 && sum + dor[uk][i] < min[i])
      solve(i, sum + dor[uk][i]);
  }
  return 0;
}

int main() {
  int i;
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  scanf("%d %d", &N, &M);

  for (i = 0; i < 5000; i++)
    for (j = 0; j < 5000; j++) dor[i][j] = -1;
  for (i = 0; i < M; i++) {
    scanf("%d %d", &j, &u);
    if (dor[j - 1][u - 1] == -1) {
      dor[j - 1][u - 1] = 0;
      dor[u - 1][j - 1] = 1;
    } else {
      dor[j - 1][u - 1] = 0;
    };
  };

  scanf("%d", &K);
  for (i = 0; i < K; i++) {
    result = 20000;
    for (j = 0; j < N; j++) {
      min[j] = 20000;
    }
    scanf("%d %d", &j, &u);

    solve(j - 1, 0);

    if (result == 20000) {
      printf("-1\n");
    } else {
      printf("%d\n", result);
    }
  }
  return 0;
}
