#include <stdio.h>
#include<string.h>
int main() {
    char M[100]; // Allocate enough space for input
    scanf("%99s", M); // Prevent buffer overflow
    printf("%d", strlen(M));
    return 0;
}