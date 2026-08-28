#include <stdio.h>

int main() {
    int min, max;
    printf("Enter min: ");
    scanf("%d", &min);
    printf("Enter max: ");
    scanf("%d", &max);
    for (int i = min; i <= max; i++) {
        printf("%d ", i);
    }
    return 0;
}
