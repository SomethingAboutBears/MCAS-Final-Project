#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


void operation() {
    printf("\n --------------------------------------- \n"); 
    printf("Welcome to the MCAS translation\n");
    printf("please choose the following mode: \n");
    printf("0: English to morse\n");
    printf("1: morse to English\n");
    printf("2: Close this program\n");
    printf(" --------------------------------------- \n"); 
    printf("please type the number of mode-> ");
}

void strclear(char *string) {
// clear string array
    int Length = strlen(string);
    memset(string,'\0',Length);
}


char* EtoM(char c,char* morse) {
    if (c == 'A' || c == 'a') {
        strcat(morse,".- ");
    }
    else if (c == 'B' || c == 'b') {
        strcat(morse,"-... ");
    }
    else if (c == 'C' || c == 'c') {
        strcat(morse,"-.-. ");
    }
    else if (c == 'D' || c == 'd') {
        strcat(morse,"-.. ");
    }
    else if (c == 'E' || c == 'e') {
        strcat(morse,". ");
    }
    else if (c == 'F' || c == 'f') {
        strcat(morse,"..-. ");
    }
    else if (c == 'G' || c == 'g') {
        strcat(morse,"--. ");
    }
    else if (c == 'H' || c == 'h') {
        strcat(morse,".... ");
    }
    else if (c == 'I' || c == 'i') {
        strcat(morse,".. ");
    }
    else if (c == 'J' || c == 'j') {
        strcat(morse,".--- ");
    }
    else if (c == 'K' || c == 'k') {
        strcat(morse,"-.- ");
    }
    else if (c == 'L' || c == 'l') {
        strcat(morse,".-.. ");
    }
    else if (c == 'M' || c == 'm') {
        strcat(morse,"-- ");
    }
    else if (c == 'N' || c == 'n') {
        strcat(morse,"-. ");
    }
    else if (c == 'O' || c == 'o') {
        strcat(morse,"--- ");
    }
    else if (c == 'P' || c == 'p') {
        strcat(morse,".--. ");
    }
    else if (c == 'Q' || c == 'q') {
        strcat(morse,"--.- ");
    }
    else if (c == 'R' || c == 'r') {
        strcat(morse,".-. ");
    }
    else if (c == 'S' || c == 's') {
        strcat(morse,"... ");
    }
    else if (c == 'T' || c == 't') {
        strcat(morse,"- ");
    }
    else if (c == 'U' || c == 'u') {
        strcat(morse,"..- ");
    }
    else if (c == 'V' || c == 'v') {
        strcat(morse,"...- ");
    }
    else if (c == 'W' || c == 'w') {
        strcat(morse,".-- ");
    }
    else if (c == 'X' || c == 'x') {
        strcat(morse,"-..- ");
    }
    else if (c == 'Y' || c == 'y') {
        strcat(morse,"-.-- ");
    }
    else if (c == 'Z' || c == 'z') {
        strcat(morse,"--.. ");
    }
    else if (c == '0') {
        strcat(morse,"----- ");
    }
    else if (c == '1') {
        strcat(morse,".---- ");
    }
    else if (c == '2') {
        strcat(morse,"..--- ");
    }
    else if (c == '3') {
        strcat(morse,"...-- ");
    }
    else if (c == '4') {
        strcat(morse,"....- ");
    }
    else if (c == '5') {
        strcat(morse,"..... ");
    }
    else if (c == '6') {
        strcat(morse,"-.... ");
    }
    else if (c == '7') {
        strcat(morse,"--... ");
    }
    else if (c == '8') {
        strcat(morse,"---.. ");
    }
    else if (c == '9') {
        strcat(morse,"----. ");
    }
    else if (c == '.') {
        strcat(morse,".-.-.- ");
    }
    else if (c == ',') {
        strcat(morse,"--..-- ");
    }
    else if (c == ':') {
        strcat(morse,"---... ");
    }
    else if (c == '?') {
        strcat(morse,"..--.. ");
    }
    else if (c == '\'') {
        strcat(morse,".----. ");
    }
    else if (c == '-') {
        strcat(morse,"-....- ");
    }
    else if (c == '/') {
        strcat(morse,"-..-. ");
    }
    else if (c == '(') {
        strcat(morse,"-.--. ");
    }
    else if (c == ')') {
        strcat(morse,"-.--.- ");
    }
    else if (c == '"') {
        strcat(morse,".-..-. ");
    }
    else if (c == '&') {
        strcat(morse,". ... ");
    }
    else if (c= ' ') {
        strcat(morse,"/  ");
    }
    return morse;
}


char* MtoE(char* segment,char* output) {
    if (strcmp(segment,".-") == 0) {
        strcat(output,"a");
    }
    else if (strcmp(segment,"-...") == 0) {
        strcat(output,"b");
    }
    else if (strcmp(segment,"-.-.") == 0) {
        strcat(output,"c");
    }
    else if (strcmp(segment,"-..") == 0) {
        strcat(output,"d");
    }
    else if (strcmp(segment,".") == 0 && strlen(segment) == 1) {
        strcat(output,"e");
    }
    else if (strcmp(segment,"..-.") == 0) {
        strcat(output,"f");
    }
    else if (strcmp(segment,"--.") == 0) {
        strcat(output,"g");
    }
    else if (strcmp(segment,"....") == 0) {
        strcat(output,"h");
    }
    else if (strcmp(segment,"..") == 0 && strlen(segment) == 2) {
        strcat(output,"i");
    }
    else if (strcmp(segment,".---") == 0) {
        strcat(output,"j");
    }
    else if (strcmp(segment,"-.-") == 0) {
        strcat(output,"k");
    }
    else if (strcmp(segment,".-..") == 0) {
        strcat(output,"l");
    }
    else if (strcmp(segment,"--") == 0) {
        strcat(output,"m");
    }
    else if (strcmp(segment,"-.") == 0) {
        strcat(output,"n");
    }
    else if (strcmp(segment,"---") == 0) {
        strcat(output,"o");
    }
    else if (strcmp(segment,".--.") == 0) {
        strcat(output,"p");
    }
    else if (strcmp(segment,"--.-") == 0) {
        strcat(output,"q");
    }
    else if (strcmp(segment,".-.") == 0) {
        strcat(output,"r");
    }
    else if (strcmp(segment,"...") == 0) {
        strcat(output,"s");
    }
    else if (strcmp(segment,"-") == 0) {
        strcat(output,"t");
    }
    else if (strcmp(segment,"..-") == 0) {
        strcat(output,"u");
    }
    else if (strcmp(segment,"...-") == 0) {
        strcat(output,"v");
    }
    else if (strcmp(segment,".--") == 0) {
        strcat(output,"w");
    }
    else if (strcmp(segment,"-..-") == 0) {
        strcat(output,"x");
    }
    else if (strcmp(segment,"-.--") == 0) {
        strcat(output,"y");
    }
    else if (strcmp(segment,"--..") == 0) {
        strcat(output,"z");
    }
    else if (strcmp(segment,"-----") == 0) {
        strcat(output,"0");
    }
    else if (strcmp(segment,".----") == 0) {
        strcat(output,"1");
    }
    else if (strcmp(segment,"..---") == 0) {
        strcat(output,"2");
    }
    else if (strcmp(segment,"...--") == 0) {
        strcat(output,"3");
    }
    else if (strcmp(segment,"....-") == 0) {
        strcat(output,"4");
    }
    else if (strcmp(segment,".....") == 0) {
        strcat(output,"5");
    }
    else if (strcmp(segment,"-....") == 0) {
        strcat(output,"6");
    }
    else if (strcmp(segment,"--...") == 0) {
        strcat(output,"7");
    }
    else if (strcmp(segment,"---..") == 0) {
        strcat(output,"8");
    }
    else if (strcmp(segment,"----.") == 0) {
        strcat(output,"9");
    }
    else if (strcmp(segment,".-.-.-") == 0) {
        strcat(output,".");
    }
    else if (strcmp(segment,"--..--") == 0) {
        strcat(output,",");
    }
    else if (strcmp(segment,"---...") == 0) {
        strcat(output,":");
    }
    else if (strcmp(segment,"..--..") == 0) {
        strcat(output,"?");
    }
    else if (strcmp(segment,".----.") == 0) {
        strcat(output,"\'");
    }
    else if (strcmp(segment,"-....-") == 0) {
        strcat(output,"-");
    }
    else if (strcmp(segment,"-..-.") == 0) {
        strcat(output,"/");
    }
    else if (strcmp(segment,"-.--.") == 0) {
        strcat(output,"(");
    }
    else if (strcmp(segment,"-.--.-") == 0) {
        strcat(output,")");
    }
    else if (strcmp(segment,".-..-.") == 0) {
        strcat(output,"\"");
    }
    else if (strcmp(segment,".-...") == 0) {
        strcat(output,"&");
    }
    else if (strcmp(segment,"/") == 0) {
        strcat(output," ");
    }
    return output;
}


