/*
Zachary Moffatt
zmoffatt
CS12m
5/10/16
Lab 5
Dictionary.c
A dictionary linked list
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"

#define MAX_LEN 500

//Types

//NodeObj structure for the nodes in the linked list
typedef struct NodeObj{
   char* key;
   char* value;
   struct NodeObj* next;
   struct NodeObj* previous;
} NodeObj;

typedef NodeObj* Node;

//Node constructor
//Usage: newNode([Key],[Value])
Node newNode(char* x, char* y) {
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->key = x;
   N->value = y;
   N->next = NULL;
   N->previous = NULL;
   return(N);
}

//Frees nodes
//Usage: newNode([Node])
void freeNode(Node* dN){
   if( dN!=NULL && *dN!=NULL ){
      free(*dN);
      *dN = NULL;
   }
}

typedef struct DictionaryObj{
    int numItems; 
    Node head;
} DictionaryObj;

//Functions

//Creates a new dictionary
//Usage: Dictionary [D] = newDictionary()
Dictionary newDictionary(void){
    Dictionary D = malloc(sizeof(DictionaryObj));
    assert(D!=NULL);
    D->head = NULL;
    D->numItems = 0;
    return D;
}

//Frees a dictionary
//Usage: freeDictionary([Dictionary])
void freeDictionary(Dictionary* pD){
    if(pD!=NULL && *pD!=NULL){
        if(!isEmpty(*pD)){
            makeEmpty(*pD);
        }
        free(*pD);
        *pD = NULL;
    }
}

//Checks if a dictionary is empty
//Usage: isEmpty([Dictionary])
int isEmpty(Dictionary D){
    if(D == NULL){
        fprintf(stderr,"Error: Called isEmpty() on NULL dictionary");
        exit(EXIT_FAILURE);
    }
    return(D->numItems==0);
}

//Returns number of items
//Usage: size([Dictionary])
int size(Dictionary D){
    if(D == NULL){
        fprintf(stderr,"Error: Called isEmpty() on NULL dictionary");
        exit(EXIT_FAILURE);
    }
    return(D->numItems);
}

//Looks for the given char sequence
//Usage: lookup([Dictionary], [String])
//Returns NULL if string is not found
char* lookup(Dictionary D, char* k){
    if(D == NULL){
        fprintf(stderr,"Error: Called lookup() on NULL dictionary");
        exit(EXIT_FAILURE);
    }
    if(D->numItems==0){
        fprintf(stderr,"Error: Called lookup() on empty dictionary");
        exit(EXIT_FAILURE);
    }
    Node N = D->head;
    for( ; N!=NULL; N=N->next){
        if(strcmp(N->key, k)==0){
            return N->value;
        }
    }
    return NULL;
}

//Inserts a new node
//Usage: insert([Dictionary], [Key String], [Value String])
void insert(Dictionary D, char* k, char* v){
    if(D == NULL){
        fprintf(stderr,"Error: Called insert() on NULL dictionary");
        exit(EXIT_FAILURE);
    }
    Node P = newNode(k,v);
    if(D->numItems==0){
        D->head=P;
    }
    else{
        Node N = D->head;
        for( ; N->next!=NULL; N=N->next){}
        P->previous=N;
        P->previous->next=P;
    }
    D->numItems++;
}

//Deletes a node with the given string
//Usage: delete([Dictionary], [Key String])
void delete(Dictionary D, char* k){
    if(D == NULL){
        fprintf(stderr,"Error: Called delete() on NULL dictionary");
        exit(EXIT_FAILURE);
    }
    if(D->numItems==0){
        fprintf(stderr,"Error: Called delete() on empty dictionary");
        exit(EXIT_FAILURE);
    }
    else{
        Node R = D->head;
        for( ; R!=NULL; R=R->next){
            if(strcmp(R->key, k)==0){
                if(R->previous==NULL&&R->next==NULL){
                    makeEmpty(D);
                }
                else{
                    if(R->previous==NULL){
                        Node N = R->next;
                        N->previous = NULL;
                        D->head = N;
                        D->numItems--;
                    }
                    else{
                        if(R->next==NULL){
                            Node P = R->previous;
                            P->next = NULL;
                            D->numItems--;
                        }
                        else{
                            Node N = R->next;
                            Node P = R->previous;
                            P->next = N;
                            N->previous = P;
                            D->numItems--;
                        }
                    }
                    free(R);
                }
            }
        }
    }
}

//Clears all nodes from the given dictionary
//Usage: makeEmpty([Dictionary])
void makeEmpty(Dictionary D){
    if(D == NULL){
        fprintf(stderr,"Error: Called makeEmpty() on NULL dictionary");
        exit(EXIT_FAILURE);
    }
    if(D->numItems==0){
        fprintf(stderr,"Error: Called makeEmpty() on empty dictionary");
        exit(EXIT_FAILURE);
    }
    else{
        Node N = D->head;
        while(N!=NULL){
            Node A = N;
            N = N->next;
            free(A);
        }
        D->numItems=0;
    }
}

//Prints out the given dictionary
//Usage: printDictionary([Output File ],[Dictionary])
void printDictionary(FILE* out, Dictionary D){
    if(D->numItems==0){
        fprintf(stderr,"Error: Called printDictionary() on empty dictionary");
        exit(EXIT_FAILURE);
    }
    else{
        Node N = D->head;
        for( ; N!=NULL; N=N->next){
            fprintf(out,"%s %s \n",N->key, N->value);
        }
    }
}
