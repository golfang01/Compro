#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = KnapsackDP(w, v, n, wx);
    for (int i = 0; i < n; i++)
        printf("%d", x[i]);
    free(x);
    return 0;
}

int *KnapsackDP(int *w, int *v, int n, int wx) {
    int *x = (int *)malloc(n * sizeof(int));
    int i, j;
    int dp[n + 1][wx + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= wx; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i - 1] <= j)
                dp[i][j] = (v[i - 1] + dp[i - 1][j - w[i - 1]]) > dp[i - 1][j] ? v[i - 1] + dp[i - 1][j - w[i - 1]] : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (i = n, j = wx; i > 0 && j > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            x[i - 1] = 1;
            j -= w[i - 1];
        } else {
            x[i - 1] = 0;
        }
    }

    return x;
}
