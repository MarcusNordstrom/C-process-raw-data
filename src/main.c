/* 
The MIT License (MIT)

Copyright (c) 2020 Anna Brondin and Marcus Nordström

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitatioceiln the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define PATH "INSERT PATH HERE"

static int16_t swap_int16( int16_t val ) 
{
    return (val << 8) | ((val >> 8) & 0xFF);
}

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    size_t read;
    FILE *fp = fopen(PATH, "r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    static char val[40];
    while ((read = getline(&line, &len, fp)) != -1) {
        long time1 = strtol(strtok(line, "-"), NULL, 16);
        time1 |= strtol(strtok(NULL, "-"), NULL, 16) << 8;
        time1 |= strtol(strtok(NULL, "-"), NULL, 16) << 16;
        time1 |= strtol(strtok(NULL, "-"), NULL, 16) << 24;
        strcpy(val, strtok(NULL, "-"));
        strcpy(&(val[2]), strtok(NULL, "-"));
        long x_val1 = strtol(val, NULL, 16);
        int16_t x1 = (int16_t)x_val1;
        strcpy(val, strtok(NULL, "-"));
        strcpy(&(val[2]), strtok(NULL, "-"));
        long y_val1 = strtol(val, NULL, 16);
        int16_t y1 = (int16_t)y_val1;
        strcpy(val, strtok(NULL, "-"));
        strcpy(&(val[2]), strtok(NULL, "-"));
        long z_val1 = strtol(val, NULL, 16);
        int16_t z1 = swap_int16(z_val1);

        long time2 = strtol(strtok(NULL, "-"), NULL, 16);
        time2 |= strtol(strtok(NULL, "-"), NULL, 16) << 8;
        time2 |= strtol(strtok(NULL, "-"), NULL, 16) << 16;
        time2 |= strtol(strtok(NULL, "-"), NULL, 16) << 24;
        strcpy(val, strtok(NULL, "-"));
        strcpy(&(val[2]), strtok(NULL, "-"));
        long x_val2 = strtol(val, NULL, 16);
        int16_t x2 = (int16_t)x_val2;
        strcpy(val, strtok(NULL, "-"));
        strcpy(&(val[2]), strtok(NULL, "-"));
        long y_val2 = strtol(val, NULL, 16);
        int16_t y2 = (int16_t)y_val2;
        strcpy(val, strtok(NULL, "-"));
        strcpy(&(val[2]), strtok(NULL, "-"));
        long z_val2 = strtol(val, NULL, 16);
        int16_t z2 = swap_int16(z_val2);
        printf("%ld,%d,%d,%d\n%ld,%d,%d,%d\n",time1, x1, y1, z1, time2, x2, y2, z2);
    }
    fclose(fp);
    if (line)
        free(line);
}