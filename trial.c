#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello,endworldstophow are you";
    char *token = strtok(str, "endstop");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "endstop");
    }

    return 0;
}
