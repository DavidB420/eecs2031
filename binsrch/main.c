/* Binary search */
/* David Badiei, Mar. 2024 */

#define _CRT_SECURE_NO_WARNINGS //remove if not using msvc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <BaseTsd.h>

#include "getline.h"
#include "binsrch.h"

int main(int argc, char* argv[]) {
    int c;

    SSIZE_T nread;                
    size_t len = 0;               
    char* line = NULL;            
    int value;
    binptr DBp = NULL;


    while ((nread = getline(&line, &len, stdin)) != -1) {
        value = atoi(line);

        if (value == 0)
            break;
    
        bininsert(&DBp, value);
    }
   
    while ((nread = getline(&line, &len, stdin)) != -1) {
        value = atoi(line);

        if (value == 0)
            break;

        if (binsearch(&DBp, value) == 0)
            printf("Found value %d\n", value);
        else
            printf("Could not find %d\n", value);
    }

    return 0;
}
