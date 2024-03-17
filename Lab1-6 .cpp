#include <stdio.h>

int GetMatrix(int *row, int *col);

int main() {
    int m, n;
    int i, j;
    
    GetMatrix(&m, &n);

    int data[m][n];
    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
        	printf("Data[%d][%d]: ", i, j);
            scanf("%d", &data[i][j]);
        }
    }
    printf("Matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int GetMatrix(int *row, int *col) {
    printf("Enter the number of rows: ");
    scanf("%d", row);

    printf("Enter the number of columns: ");
    scanf("%d", col);

    return 0;
}
