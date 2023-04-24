#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char* EtoM(char c,char* morse);

int main() {
    char latinText[2000];
    fgets(latinText, 2000, stdin);
    int length = strlen(latinText);
    latinText[length-1] = 0;
    char morse[15000] = "";
    for (int i = 0; i < length; i++) {
        tomorse(latinText[i],morse);
    }
    printf("The AMC as written is: \n %s",morse);
    return 0;
}

char* EtoM(char c,char* morse) {
    if (c == 'A' || c == 'a') {
        strcat(morse,".-   ");
    }
    else if (c == 'B' || c == 'b') {
        strcat(morse,"-...   ");
    }
    else if (c == 'C' || c == 'c') {
        strcat(morse,".. .   ");
    }
    else if (c == 'D' || c == 'd') {
        strcat(morse,"-..   ");
    }
    else if (c == 'E' || c == 'e') {
        strcat(morse,".   ");
    }
    else if (c == 'F' || c == 'f') {
        strcat(morse,".-.   ");
    }
    else if (c == 'G' || c == 'g') {
        strcat(morse,"--.   ");
    }
    else if (c == 'H' || c == 'h') {
        strcat(morse,"....   ");
    }
    else if (c == 'I' || c == 'i') {
        strcat(morse,"..   ");
    }
    else if (c == 'J' || c == 'j') {
        strcat(morse,"-.-.   ");
    }
    else if (c == 'K' || c == 'k') {
        strcat(morse,"-.-   ");
    }
    else if (c == 'L' || c == 'l') {
        strcat(morse,"⸺   ");
    }
    else if (c == 'M' || c == 'm') {
        strcat(morse,"--   ");
    }
    else if (c == 'N' || c == 'n') {
        strcat(morse,"-.   ");
    }
    else if (c == 'O' || c == 'o') {
        strcat(morse,". .   ");
    }
    else if (c == 'P' || c == 'p') {
        strcat(morse,".....   ");
    }
    else if (c == 'Q' || c == 'q') {
        strcat(morse,"..-.   ");
    }
    else if (c == 'R' || c == 'r') {
        strcat(morse,". ..   ");
    }
    else if (c == 'S' || c == 's') {
        strcat(morse,"...   ");
    }
    else if (c == 'T' || c == 't') {
        strcat(morse,"-   ");
    }
    else if (c == 'U' || c == 'u') {
        strcat(morse,"..-   ");
    }
    else if (c == 'V' || c == 'v') {
        strcat(morse,"...-   ");
    }
    else if (c == 'W' || c == 'w') {
        strcat(morse,".--   ");
    }
    else if (c == 'X' || c == 'x') {
        strcat(morse,".-..   ");
    }
    else if (c == 'Y' || c == 'y') {
        strcat(morse,".. ..   ");
    }
    else if (c == 'Z' || c == 'z') {
        strcat(morse,"... .   ");
    }
    else if (c == '0') {
        strcat(morse,"⸻   ");
    }
    else if (c == '1') {
        strcat(morse,".--.   ");
    }
    else if (c == '2') {
        strcat(morse,"..-..   ");
    }
    else if (c == '3') {
        strcat(morse,"...-.   ");
    }
    else if (c == '4') {
        strcat(morse,"....-   ");
    }
    else if (c == '5') {
        strcat(morse,"---   ");
    }
    else if (c == '6') {
        strcat(morse,"......   ");
    }
    else if (c == '7') {
        strcat(morse,"--..   ");
    }
    else if (c == '8') {
        strcat(morse,"-....   ");
    }
    else if (c == '9') {
        strcat(morse,"-..-   ");
    }
    else if (c == '.') {
        strcat(morse,"..--..   ");
    }
    else if (c == ',') {
        strcat(morse,".-.-   ");
    }
    else if (c == ':') {
        strcat(morse,"-.- . .   ");
    }
    else if (c == '?') {
        strcat(morse,"-..-.   ");
    }
    else if (c == '\'') {
        strcat(morse,"..-. .-..   ");
    }
    else if (c == '-') {
        strcat(morse,"... .-..   ");
    }
    else if (c == '/') {
        strcat(morse,"..- -   ");
    }
    else if (c == '(') {
        strcat(morse,"..... -.   ");
    }
    else if (c == ')') {
        strcat(morse,"..... .. ..   ");
    }
    else if (c == '"') {
        strcat(morse,"..-. -.   ");
    }
    else if (c == '&') {
        strcat(morse,". ...   ");
    }
    else if (c == '!') {
        strcat(morse,"---.   ");
    }
    else if (c == ';') {
        strcat(morse,"... ..   ");
    }
    else if (c= ' ') {
        strcat(morse,"/   ");
    }
    return morse;
    }
