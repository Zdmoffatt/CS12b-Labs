/*
Zachary Moffatt
zmoffatt
4/29/16
CS12M
Lab4
charType.c
Takes in a file scans each line and prints a report of the characters on the lines to the output file
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 500

//Takes in a string, catagorizes its characters and saves them to the array for their type
//Usage: extract_chars([input string],[alphabetic array],[digit array],[punctuation array],[whitespace array])
void extract_chars(char* s, char* a, char* d, char* p, char* w){
    int i=0, a_count=0, d_count=0, p_count=0, w_count=0;
    while(s[i]!='\0' && i<MAX_STRING_LENGTH){
        if(isalpha(s[i])){
            a[a_count]=s[i];
            a_count++;
        }
        else{
            if(isdigit(s[i])){
                d[d_count]=s[i];
                d_count++;
            }
            else{
                if(ispunct(s[i])){
                    p[p_count]=s[i];
                    p_count++;
                }
                else{
                    if(isspace(s[i])){
                        w[w_count]=s[i];
                        w_count++;
                    }
                    else{
                        //Should never be reached but good for bug checking
                        printf("Cannot parse a character");
                    }
                }
            }
        }
        i++;
    }
    a[a_count]='\0';
    d[d_count]='\0';
    p[p_count]='\0';
    w[w_count]='\0';
}


int main(int argc, char* argv[]){

    FILE* in;
    FILE* out;
    
    char* line;
    char* alpha;
    char* digit;
    char* punct;
    char* white;
    int currentLine = 1;

    //Check for correct number of arguments
    if(argc!=3){
        printf("Usage: charType [input file] [output file]");
        exit(EXIT_FAILURE);
    }
    //Check if first arg is a file that exists
    if(access(argv[0],F_OK )==-1){
        printf("Usage: charType [input file] [output file]");
        exit(EXIT_FAILURE);
    }

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    //Create an array each type of character to be scanned for
    //They will hold those characters when they are catagorized
    line  = calloc(MAX_STRING_LENGTH+1, sizeof(char));
    assert( line!=NULL);
    alpha = calloc(MAX_STRING_LENGTH+1, sizeof(char));
    assert( alpha!=NULL);
    digit = calloc(MAX_STRING_LENGTH+1, sizeof(char));
    assert( digit!=NULL);
    punct = calloc(MAX_STRING_LENGTH+1, sizeof(char));
    assert( punct!=NULL);
    white = calloc(MAX_STRING_LENGTH+1, sizeof(char));
    assert( white!=NULL);

    while(fgets(line, MAX_STRING_LENGTH, in)!= NULL){
        extract_chars(line, alpha, digit, punct, white);

        fprintf(out,"line %d contains: \n",currentLine);
        fprintf(out,"%d alphabetic characters: ", (int)strlen(alpha));
        fprintf(out,"%s \n", alpha);
        fprintf(out,"%d numeric characters: ", (int)strlen(digit));
        fprintf(out,"%s \n", digit);
        fprintf(out,"%d punctuation characters: ", (int)strlen(punct));
        fprintf(out,"%s \n", punct);
        fprintf(out,"%d whitespace characters: ", (int)strlen(white));
        fprintf(out,"%s", white);
        fprintf(out,"\n");
        currentLine++;
    }

    //Free all memory
    free(line);
    free(alpha);
    free(digit);
    free(punct);
    free(white);
    fclose(in);
    fclose(out);
    return(EXIT_SUCCESS);
}