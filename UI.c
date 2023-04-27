#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include "Subfunction.c"


// main function

void main() {
    char Double[2]  = " ";
    char single[]  = " ";
    strcat(Double,single);
    int OpeNum;
    while(OpeNum != 2) {
        operation();
        scanf("%d", &OpeNum);
        getchar();
    // mode 0 EtoM
    if (OpeNum == 0) {
            char latinText[2000];
            printf("type sentense you wanna translate:\n");
            fgets(latinText, 2000, stdin);
            int length = strlen(latinText);
            latinText[length-1] = 0;
            char morse[15000] = "";
            for (int i = 0; i < length; i++) {
                EtoM(latinText[i],morse);
            }
            printf("The AMC as written is: \n %s \n",morse);
            printf("clearing the result\n");
            strclear(morse);
            strclear(latinText);
    }
    // mode 1 MtoE
    else if (OpeNum == 1) {

        // define morse signals. Plsease make three spaces between each signals
        char morseText[3920];
        printf("Input your text (please use Latin characters with no diacritics and numbers only ->) \n");
        fgets(morseText, 3920, stdin);

        // define output and its pointer
        char latinText[280];
        char *ptr;
            // first split
        ptr = strtok(morseText,Double);
        MtoE(ptr,latinText);
            
            // second and following split
        while(ptr != NULL) {
            ptr = strtok(NULL,Double);
            if(ptr != NULL) {
                MtoE(ptr,latinText);
            }    
        }

        printf("The Latin text as written is: %s \n",latinText);
        printf("clearing your typed morse code\n");
        
        // clear string array
        strclear(latinText); // define inside Subfunction.c
        strclear(morseText);
        
    }
    
    // mode 2 close program
    else if (OpeNum == 2) {
        printf("close this program\n"); // delete this after embeded into Adafruit
        break;
    }

        // error message
    else {
        printf("Wrong number. try it again\n");
        printf("\n");
    }

    // end of the while loop
    printf("\n\n\n");
    }
}
