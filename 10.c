#include <stdio.h>
int main(){
    FILE *fs;
    FILE *fd;
    char ch;
    fs = fopen("intput.txt", "r");
    fd = fopen("output.txt", "w");
    while(1) {
        ch = fgetc(fs);
        if (ch == EOF) {
            break;
        }
        else {
            fputc(ch, fd);
        }
    }
    fclose(fs);
    printf("Copied successfully!");
    fclose(fd);