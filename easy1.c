#include <stdio.h>
#include <string.h>

int lengthOfLastWord(const char *s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Calculate length of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    printf("%d\n", lengthOfLastWord(s));

    return 0;
}

