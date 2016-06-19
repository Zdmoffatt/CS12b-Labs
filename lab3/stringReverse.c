/*
Zachary Moffatt
zmoffatt
4/14/16
CS12M
Lab3
stringReverse
Takes in two files, tokenizes the first file, reverses the tokens and outputs them to the second file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Takes in a string pointer and reverses it by swapping characters and moving inwards, returns nothing
   Usage stringReverse([string]);
*/
void stringReverse(char* s){
    int a=0;
    int b=strlen(s)-1;
    char temp = a;
    while(a<(b+1)/2){
        temp = s[a];
        s[a]=s[b-a];
        s[b-a]=temp;
        a++;
    }
}

int main(int argc, char* argv[]){
    FILE* input;
    FILE* output;
    char word[256];
    //Input checking
    if(argc!=3){
        printf("Usage: FileReverse <Input File> <Output file>");
        exit(EXIT_FAILURE);
    }
    input = fopen(argv[1], "r");
    if( input==NULL ){
        printf("Unable to read from file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    output = fopen(argv[2], "w");
    if( output==NULL ){
        printf("Unable to write to file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    //Takes in tokens from files and reverses them before outputting them to the next file
    while( fscanf(input, " %s", word) != EOF ){
        stringReverse(word);
        fprintf(output, "%s\n", word);
    }
    fclose(input);
    fclose(output);
    return(EXIT_SUCCESS);
}