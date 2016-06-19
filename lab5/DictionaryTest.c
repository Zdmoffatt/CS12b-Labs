/*
Zachary Moffatt
zmoffatt
CS12m
5/10/16
Lab 5
DictionaryTest.c
Tester for Dictionary.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
    Dictionary A = newDictionary();
    insert(A, "one", "a");
    insert(A, "two", "b");
    insert(A, "thr", "c");
    insert(A, "fou", "d");
    insert(A, "fiv", "e");

    printDictionary(stdout, A);

    delete(A, "one");
    delete(A, "thr");
    delete(A, "fiv");

    printf("%d\n", size(A));
    printf("%s\n", (isEmpty(A)?"true":"false"));

    makeEmpty(A);
    printf("%d\n", size(A));
    printf("%s\n", (isEmpty(A)?"true":"false"));

    insert(A, "one", "a");
    printf("%d\n", size(A));
    printf("%s\n", (isEmpty(A)?"true":"false"));

    delete(A, "one");
    printf("%d\n", size(A));
    printf("%s\n", (isEmpty(A)?"true":"false"));

    insert(A, "fiv", "e");
    printf("%d\n", size(A));
    printf("%s\n", (isEmpty(A)?"true":"false"));
    printDictionary(stdout, A);
    makeEmpty(A);
    printf("End of Dictionary A tests\n");
    freeDictionary(&A);

    Dictionary B = newDictionary();
    insert(B, "a", "q");
    insert(B, "b", "w");
    insert(B, "c", "e");
    insert(B, "d", "r");
    insert(B, "e", "t");
    printDictionary(stdout, B);

    char* v = lookup(B, "a");
    if(v!=NULL){printf("Exists\n");}
    else{printf("Does not exist");}

    char* b = lookup(B, "z");
    if(b!=NULL){printf("Exists\n");}
    else{printf("Does not exist\n");}

    delete(B,"a");
    char* n = lookup(B, "a");
    if(n!=NULL){printf("Exists\n");}
    else{printf("Does not exist\n");}
    printf("End of Dictionary B tests\n");
    freeDictionary(&B);

}