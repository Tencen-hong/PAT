
#include <stdio.h>
#include <string.h>

//编译器gcc
int main() {
    char s1[10010];
    char s2[10010];
    gets(s1);
    gets(s2);
    char asc[130];
    for (int i = 0; s2[i] != '\0'; ++i) {
        asc[s2[i]]++;
    }
    for (int i = 0; i < strlen(s1); ++i) {
        if (!asc[s1[i]]) {
            printf("%c", s1[i]);
        }
    }


    return 0;
}
