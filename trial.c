#include <stdio.h>
#include <string.h>

int main() {
     // type the index number
    int num = 12;
    char myChar[100] = "my greeting \\";
    printf("%s\n",myChar);
    printf("The slash is %c\n",myChar[num]);
    if (myChar[num] == "\'") {
        printf("work correctly!\n");
    }
    else printf("it failed, your pointed string is %c\n",myChar[num]);


    return 0;
}
