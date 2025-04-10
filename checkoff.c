#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 50

int get_word(char word[]);
void copy(char to[], const char from[]);
void reverse(char word[], int length);

int main() {
    char word[MAXLENGTH];
    char longest[MAXLENGTH];

    int max_length = 0;
    int len;

    while ((len = get_word(word)) > 0) {
        if (len > max_length) {
            max_length = len;
            copy(longest, word);
        }
    }

    if (max_length > 0) {
        printf("Longest word: %s (Length: %d)\n", longest, max_length);
        reverse(longest, max_length);
        printf("Longest word reversed: %s\n", longest);
    } else {
        printf("No words entered.\n");
    }

    return EXIT_SUCCESS;
}

/**
 * Reads a single word from input, ignoring punctuation and spaces.
 * Stops reading at EOF, newline, or space.
 * Returns the length of the word read.
 */
int get_word(char s[]) {
    int i = 0;
    int c = getchar();

    // Skip leading spaces and non-alphanumeric characters
    while (c != EOF && !isalnum(c)) {
        c = getchar();
    }

    while (c != EOF && isalnum(c)) {
        if (i < MAXLENGTH - 1) {
            s[i++] = c;
        }
        c = getchar();
    }

    s[i] = '\0';
    return i;
}

/**
 * Copies a string from `from` to `to`.
 */
void copy(char to[], const char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

/**
 * Reverses the contents of the string in place.
 */
void reverse(char word[], int length) {
    int temp;
    for (int i = 0; i < (length / 2); i++) {
        temp = word[i];
        word[i] = word[length - i - 1];
        word[length - i - 1] = temp;
    }
}
