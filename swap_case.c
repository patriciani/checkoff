#include <stdio.h>

int swap_case(int b);

int main() {
    int my_char;
    while ((my_char = getchar()) != EOF) {
        my_char = swap_case(my_char);
        putchar(my_char);
        fflush(stdout);
    }
}

int swap_case(int my_char) {
    if (my_char >= 'a' && my_char <= 'z') {
        return my_char - 'a' + 'A';
    } else if (my_char >= 'A' && my_char <= 'Z') {
        return my_char - 'A' + 'a';
    } else {
        return my_char;
    }
}