#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 0;
    char runagain;
    char mode;
    char shot;
    int i = 0;

    printf("User input max number : ");
    scanf("%d", &n);

    printf("----| Normal Series : ");
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    } 
    printf("\n");

    bool checkExit = false;
    do {
        printf("Display Odd/Even/Normal? (o/e/n): ");
        scanf(" %c", &mode); 

        if (mode == 'e') {
            printf("----| Even Series : ");
            for (i = 2; i <= n; i += 2) {
                printf("%d ", i);
            }
            break;

        } else if (mode == 'o') {
            printf("----| Odd Series : ");
            for (i = 1; i <= n; i += 2) {
                printf("%d ", i);
            }
            break;

        } else if (mode == 'n') {
            printf("----| Normal Series : ");
            for (i = 1; i <= n; i++) {
                printf("%d ", i);
            }
            break;
        } 
        printf("\n");

    } while (true);

    do {
        printf("Display a-z / z-a? (a/z) : ");
        scanf(" %c", &shot);

        switch (shot) {
            case 'a':
                printf("This is a \n");
                break;

            case 'z':
                printf("This is z \n");
                break;
        }
        printf("\n");
    } while (shot != 'a' && shot != 'z');
    printf("END");

    return 0;
}
