#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

char* MtoE(char* segment,char* output);

void main() {

    char morseText[3920];
    printf("Input your text (please use Latin characters with no diacritics and numbers only ->) \n");
    fgets(morseText, 3920, stdin);

    // define output and its pointer
    char latinText[280];
    char *ptr;
        // first split
    ptr = strtok(morseText,",");
    //printf("the length of morse code is %lu\n",strlen(ptr));
    MtoE(ptr,latinText);
        
        // second and following split
    while(ptr != NULL) {
        ptr = strtok(NULL,",");
        //printf("the length of morse code is %lu\n",strlen(ptr));
        if(ptr != NULL) {
            MtoE(ptr,latinText);
        }    
    }

    printf("The Latin text as written is: %s \n",latinText);

}

char* MtoE(char* segment,char* output) {
    if (strcmp(segment,".-") == 0) {
        strcat(output,"a");
    }
    else if (strcmp(segment,"-...") == 0) {
        strcat(output,"b");
    }
    else if (strcmp(segment,".. .") == 0) {
        strcat(output,"c");
    }
    else if (strcmp(segment,"-..") == 0) {
        strcat(output,"d");
    }
    else if (strcmp(segment,".") == 0 && strlen(segment) == 1) {
        strcat(output,"e");
    }
    else if (strcmp(segment,".-.") == 0) {
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
    else if (strcmp(segment,"-.-.") == 0) {
        strcat(output,"j");
    }
    else if (strcmp(segment,"-.-") == 0) {
        strcat(output,"k");
    }
    else if (strcmp(segment,"----") == 0) {
        strcat(output,"l");
    }
    else if (strcmp(segment,"--") == 0) {
        strcat(output,"m");
    }
    else if (strcmp(segment,"-.") == 0) {
        strcat(output,"n");
    }
    else if (strcmp(segment,". .") == 0) {
        strcat(output,"o");
    }
    else if (strcmp(segment,".....") == 0) {
        strcat(output,"p");
    }
    else if (strcmp(segment,"..-.") == 0) {
        strcat(output,"q");
    }
    else if (strcmp(segment,". ..") == 0) {
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
    else if (strcmp(segment,".-..") == 0) {
        strcat(output,"x");
    }
    else if (strcmp(segment,".. ..") == 0) {
        strcat(output,"y");
    }
    else if (strcmp(segment,"... .") == 0) {
        strcat(output,"z");
    }
    else if (strcmp(segment,"-----") == 0) {
        strcat(output,"0");
    }
    else if (strcmp(segment,".--.") == 0) {
        strcat(output,"1");
    }
    else if (strcmp(segment,"..-..") == 0) {
        strcat(output,"2");
    }
    else if (strcmp(segment,"-") == 0) {
        strcat(output,"3");
    }
    else if (strcmp(segment,"....-") == 0) {
        strcat(output,"4");
    }
    else if (strcmp(segment,"---") == 0) {
        strcat(output,"5");
    }
    else if (strcmp(segment,"......") == 0) {
        strcat(output,"6");
    }
    else if (strcmp(segment,"--..") == 0) {
        strcat(output,"7");
    }
    else if (strcmp(segment,"-....") == 0) {
        strcat(output,"8");
    }
    else if (strcmp(segment,"-..-") == 0) {
        strcat(output,"9");
    }
    else if (strcmp(segment,"..--..") == 0) {
        strcat(output,".");
    }
    else if (strcmp(segment,".-.-") == 0) {
        strcat(output,",");
    }
    else if (strcmp(segment,"-.- . .") == 0) {
        strcat(output,":");
    }
    else if (strcmp(segment,"-..-.") == 0) {
        strcat(output,"?");
    }
    else if (strcmp(segment,"..-. .-..") == 0) {
        strcat(output,"\'");
    }
    else if (strcmp(segment,"... .-..") == 0) {
        strcat(output,"-");
    }
    else if (strcmp(segment,"..- -") == 0) {
        strcat(output,"/");
    }
    else if (strcmp(segment,"..... -.") == 0) {
        strcat(output,"(");
    }
    else if (strcmp(segment,"..... .. ..") == 0) {
        strcat(output,")");
    }
    else if (strcmp(segment,"..-. -.") == 0) {
        strcat(output,"\"");
    }
    else if (strcmp(segment,". ...") == 0) {
        strcat(output,"&");
    }
    else if (strcmp(segment,"---.") == 0) {
        strcat(output,"!");
    }
    else if (strcmp(segment,"... ..") == 0) {
        strcat(output,";");
    }
    else if (strcmp(segment,"/") == 0) {
        strcat(output," ");
    }
    return output;
}


