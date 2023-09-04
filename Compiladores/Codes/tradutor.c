#include <stdio.h>
#include <ctype.h>

int lookAhead;

void reconhecer(int t) {
    if (lookAhead == t) {
        lookAhead = getchar();
    } else {
        printf("ERRO\n");
    }
}

void termo() {
    if (isdigit(lookAhead)) {
        putchar(lookAhead);
        reconhecer(lookAhead);
    }
}

void expr() {
    termo();
    while (1) {
        if (lookAhead == '-') {
            //printf("entrei aquii");
            reconhecer('-');
            termo();
            putchar('-');
        } else if (isdigit(lookAhead)) {
            printf("ERRO\n");
            break;
        } else {
            break; // Não é nem subtração nem dígito, então saia do loop
        }
    }
}

int main() {
    lookAhead = getchar();
    expr();
    putchar('\n');
    return 0;
}
