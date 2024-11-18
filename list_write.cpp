// Melissa Mandyck ASU ID: 1230934824
#include "list_read.h"
#include "list_write.h"
#include <stdio.h>
#include <stdlib.h>

void listRelease(LIST *pLIST){
    NODE* pNODE, * pTemp;

    if (!pLIST) {
        fprintf(stderr, "Error in listRelease: NULL list\n");
        exit(0);
    }
    pNODE = pLIST->head;
    while (pNODE) {
        pTemp = pNODE->next;
        free(pNODE);
        pNODE = pTemp;
    }

    pLIST->head = NULL;
    pLIST->tail = NULL;
    pLIST->length = 0;
}


NODE * listInsert(LIST *pLIST, double key){
    NODE* pNODE;

    if (!pLIST) {
        fprintf(stderr, "Error in listInsert: NULL list\n");
        exit(0);
    }

    pNODE = (NODE*)malloc(sizeof(NODE));
    if (!pNODE) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(0);
    }

    pNODE->key = key;
    pNODE->next = pLIST->head;
    pLIST->head = pNODE;

    if (pLIST->tail == NULL) {
        pLIST->tail = pNODE;
    }

    pLIST->length++;
    return pNODE;
}


NODE * listAppend(LIST *pLIST, double key){
    NODE *pNODE;
    if (!pLIST) {
        fprintf(stderr, "Error in listAppend: NULL list\n");
        exit(0);
    }

    pNODE = (NODE*)malloc(sizeof(NODE));
    if (!pNODE) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(0);
    }

    pNODE->key = key;
    pNODE->next = NULL;

    if (pLIST->tail) {
        pLIST->tail->next = pNODE;
    }
    else {
        pLIST->head = pNODE;
    }

    pLIST->tail = pNODE;
    pLIST->length++;
    return pNODE;
}


NODE * listDelete(LIST *pLIST, double key){
    NODE* pNODE, * pPrev;

    if (!pLIST) {
        fprintf(stderr, "Error in listDelete: NULL list\n");
        exit(0);
    }

    pNODE = pLIST->head;
    pPrev = NULL;

    while (pNODE) {
        if (pNODE->key == key) {
            if (pPrev) {
                pPrev->next = pNODE->next;
            }
            else {
                pLIST->head = pNODE->next;
            }

            if (pNODE == pLIST->tail) {
                pLIST->tail = pPrev;
            }

            pLIST->length--;
            return pNODE;
        }
        pPrev = pNODE;
        pNODE = pPrev->next;
    }
    fprintf(stdout, "Warning in listDelete: Key %lf not in list\n", key);
    return NULL;
}

