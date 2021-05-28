/**
 * C program to append data to a file
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

int writeData(char dataToAppend[BUFFER_SIZE])
{
    /* File pointer to hold reference of input file */
    FILE *fPtr;

    char filePath[] = "./data.dat";

    /*  Open all file in append mode. */
    fPtr = fopen(filePath, "a");


    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open '%s' file.\n", filePath);
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }

    /* Append data to file */
    fputs(dataToAppend, fPtr);
    fclose(fPtr);
    return 0;
}
