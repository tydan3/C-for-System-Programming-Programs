#include <stdio.h>

int main(int argc, char* argv[]) {
    int i = 1;
    
    printf("HI\n");
    
    if (3 < 5) {
        printf("A\n");    
    } else {
        printf("B\n");
    }
    
    printf("C\n");
    
    while (i < 4) {
        printf("D\n");
        i++;
    }
    
    printf("E\n");
    
    switch(3) {
       case 2:
           printf("F\n");
           break;
       case 3:
           printf("G\n");
       case 4:
           printf("H\n");
           break;
       case 5:
           printf("K\n");
           break;
    }
    
    printf("L\n");
    
    for (i = 0; i < 4; i++) {
        printf("M\n");
    }
    
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0)
            continue;
        printf("N\n");
    }
    
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0)
             break;
        printf("O\n");
    }        
    
    return 0;
}
