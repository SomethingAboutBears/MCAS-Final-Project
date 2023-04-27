#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include "Subfunction.c"


void main() {
    char morseText[3920];
    printf("Input your text (please use Latin characters with no diacritics and numbers only) \n");
    fgets(morseText, 3920, stdin);
    int length = strlen(morseText);
    morseText[length+1] = 0;
    char latinText[280];
    int left = 0;
    for (int i = 0; i < length; i++) {
        if (morseText[i+1] == ' ' && morseText[i+2] == ' ') {
            int right = i;
            char segment[right-left+1];
            printf("%s\n",segment);
            char* segmen = segment;
            MtoE(segmen, latinText);
            left = right + 3;
        }
    }
    printf("The Latin text as written is: %s \n",latinText);
}