#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int right;
int left;
int i;
char* MtoE(char* segment,char* output);

void main() {
    char morseText[3920];
    printf("Input your text (please use Latin characters with no diacritics and numbers only) \n");
    fgets(morseText, 3920, stdin);
    int length = strlen(morseText);
    morseText[length+1] = 0;
    char latinText[280];
    left = 0;
    for (i = 0; i < length; i++) {
        if (morseText[i+1] == ' ' && morseText[i+2] == ' ') {
        //if (morseText[i+1] == '\0') {
            right = i;
            char segment[right-left+1];
            printf("left = %d, right = %d, length of morseText = %d\n", left, right, length);
            strncpy(segment, morseText + left, right - left);
            segment[strlen(segment)] = '\0';
            printf("%s\n",segment);
            char* segmen = segment;
            MtoE(segmen, latinText);
            left = right + 3;
        }
    }
    printf("The Latin text as written is: %s \n",latinText);
}

char* MtoE(char* segment,char* output) {
    printf("hello\n");
    if (strcmp(segment,".-") == 1) {
        strcat(output,"a");
        printf("DBG: 1\n");
    }
    else if (segment = "-...") {
        printf("DBG: 2\n");
        strcat(output,"b");
    }
    /*
    else if (c == 'C' || c == 'c') {
        strcat(output,".. .   ");
    }
    else if (c == 'D' || c == 'd') {
        strcat(output,"-..   ");
    }
    else if (c == 'E' || c == 'e') {
        strcat(output,".   ");
    }
    else if (c == 'F' || c == 'f') {
        strcat(output,".-.   ");
    }
    else if (c == 'G' || c == 'g') {
        strcat(output,"--.   ");
    }
    else if (c == 'H' || c == 'h') {
        strcat(output,"....   ");
    }
    else if (c == 'I' || c == 'i') {
        strcat(output,"..   ");
    }
    else if (c == 'J' || c == 'j') {
        strcat(output,"-.-.   ");
    }
    else if (c == 'K' || c == 'k') {
        strcat(output,"-.-   ");
    }
    else if (c == 'L' || c == 'l') {
        strcat(output,"⸺   ");
    }
    else if (c == 'M' || c == 'm') {
        strcat(output,"--   ");
    }
    else if (c == 'N' || c == 'n') {
        strcat(output,"-.   ");
    }
    else if (c == 'O' || c == 'o') {
        strcat(output,". .   ");
    }
    else if (c == 'P' || c == 'p') {
        strcat(output,".....   ");
    }
    else if (c == 'Q' || c == 'q') {
        strcat(output,"..-.   ");
    }
    else if (c == 'R' || c == 'r') {
        strcat(output,". ..   ");
    }
    else if (c == 'S' || c == 's') {
        strcat(output,"...   ");
    }
    else if (c == 'T' || c == 't') {
        strcat(output,"-   ");
    }
    else if (c == 'U' || c == 'u') {
        strcat(output,"..-   ");
    }
    else if (c == 'V' || c == 'v') {
        strcat(output,"...-   ");
    }
    else if (c == 'W' || c == 'w') {
        strcat(output,".--   ");
    }
    else if (c == 'X' || c == 'x') {
        strcat(output,".-..   ");
    }
    else if (c == 'Y' || c == 'y') {
        strcat(output,".. ..   ");
    }
    else if (c == 'Z' || c == 'z') {
        strcat(output,"... .   ");
    }
    else if (c == '0') {
        strcat(output,"⸻   ");
    }
    else if (c == '1') {
        strcat(output,".--.   ");
    }
    else if (c == '2') {
        strcat(output,"..-..   ");
    }
    else if (c == '3') {
        strcat(output,"...-.   ");
    }
    else if (c == '4') {
        strcat(output,"....-   ");
    }
    else if (c == '5') {
        strcat(output,"---   ");
    }
    else if (c == '6') {
        strcat(output,"......   ");
    }
    else if (c == '7') {
        strcat(output,"--..   ");
    }
    else if (c == '8') {
        strcat(output,"-....   ");
    }
    else if (c == '9') {
        strcat(output,"-..-   ");
    }
    else if (c == '.') {
        strcat(output,"..--..   ");
    }
    else if (c == ',') {
        strcat(output,".-.-   ");
    }
    else if (c == ':') {
        strcat(output,"-.- . .   ");
    }
    else if (c == '?') {
        strcat(output,"-..-.   ");
    }
    else if (c == '\'') {
        strcat(output,"..-. .-..   ");
    }
    else if (c == '-') {
        strcat(output,"... .-..   ");
    }
    else if (c == '/') {
        strcat(output,"..- -   ");
    }
    else if (c == '(') {
        strcat(output,"..... -.   ");
    }
    else if (c == ')') {
        strcat(output,"..... .. ..   ");
    }
    else if (c == '"') {
        strcat(output,"..-. -.   ");
    }
    else if (c == '&') {
        strcat(output,". ...   ");
    }
    else if (c == '!') {
        strcat(output,"---.   ");
    }
    else if (c == ';') {
        strcat(output,"... ..   ");
    }
    else if (c= ' ') {
        strcat(output,"/   ");
    }
    */
    return output;
    }

