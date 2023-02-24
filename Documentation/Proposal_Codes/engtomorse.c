#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char* tomorse(char c,char* output);

int main() {
    char input[2000];
    printf("Input your text (please use Latin characters with no diacritics and numbers only) \n");
    fgets(input, 2000, stdin);
    int length = strlen(input);
    input[length-1] = 0;
    char output[15000] = "";
    for (int i = 0; i < length; i++) {
        tomorse(input[i],output);
    }
    printf("The AMC as written is: \n %s",output);
    return 0;
}

char* tomorse(char c,char* output) {
    if (c == 'A' || c == 'a') {
        strcat(output,".-   ");
    }
    else if (c == 'B' || c == 'b') {
        strcat(output,"-...   ");
    }
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
    return output;
    }
