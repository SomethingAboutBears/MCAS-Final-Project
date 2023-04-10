#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void tomorse(char c) {
    if (c == 'A' || 'a') {
            printf(".- ");
    }
    else if (c == 'B' || 'b') {
            printf("-... ");
    }
    else if (c == 'C' || 'c') {
        printf("-.-. ");
    }
    else if (c == 'D' || 'd') {
        printf("-.. ");
    }
    else if (c == 'E' || 'e') {
            printf(". ");
    }
    else if (c == 'F' || 'f') {
            printf("..-. ");
    }
    else if (c == 'G' || 'g') {
            printf("--. ");
    }
    else if (c == 'H' || 'H') {
            printf(".... ");
    }
    else if (c == 'I' || 'i') {
            printf(".. ");
    }
    else if (c == 'J' || 'j') {
            printf(".--- ");
    }
    else if (c == 'K' || 'k') {
            printf("-.- ");
    }
    else if (c == 'L' || 'l') {
            printf(".-.. ");
    }
    else if (c == 'M' || 'm') {
            printf("-- ");
    }
    else if (c == 'N' || 'n') {
            printf("-. ");
    }
    else if (c == 'O' || 'o') {
            printf("--- ");
    }
    else if (c == 'P' || 'p') {
            printf(".--. ");
    }
    else if (c == 'Q' || 'q') {
            printf("--.- ")
    }
    else if (c == 'R' || 'r') {
            printf(".-. ");
    }
    else if (c == 'S' || 's') {
            printf("... ");
    }
    else if (c == 'T' || 't') {
            printf("- ");
    }
    else if (c == 'U' || 'u') {
            printf("..- ");
    }
    else if (c == 'V' || 'v') {
            printf("...- ");
    }
    else if (c == 'W' || 'w') {
            printf(".-- ");
    }
    else if (c == 'X' || 'x') {
            printf("-..- ");
    }
    else if (c == 'Y' || 'y') {
            printf("-.-- ");
    }
    else if (c == 'Z' || 'z') {
            printf("--.. ");
    }
        else if (c= ' ') {
            printf("/ ");
        }
    }
