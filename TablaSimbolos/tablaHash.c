#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaHash.h"

unsigned int hash(const char *key) {
    
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // hash method (multiplication)
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }
    value = value % TABLE_SIZE;

    return value;
}

entry_t *ht_pair(const char *key, int c, int t, int e_v, int a1, int a2) {
    
    entry_t *entry = malloc(sizeof(struct entry_t));
    entry->key = malloc(strlen(key) + 1);

    strcpy(entry->key, key);
    entry->category = c;
    entry->type = t;
    entry->escalar_vector = e_v;
    entry->adicional1 = a1;
    entry->adicional2 = a2;

    return entry;
}

ht_t *ht_create(void) {
    
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

    int i = 0;
    for (; i < TABLE_SIZE; ++i) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

STATUS ht_set(ht_t *hashtable, const char *key, int c, int t, int e_v, int a1, int a2) {
    
    unsigned int bucket = hash(key);

    entry_t *entry = hashtable->entries[bucket];

    if (entry == NULL) {
        hashtable->entries[bucket] = ht_pair(key, c, t, e_v, a1, a2);
        return OK;
    }else{
        return ERROR;
    }
}

entry_t * ht_get(ht_t *hashtable, const char *key) {
    
    unsigned int bucket = hash(key);

    entry_t *entry = hashtable->entries[bucket];

    if (entry == NULL) {
        return NULL;
    }

    return entry;
}

STATUS ht_destroy(ht_t *hashtable) {
    
    if(hashtable == NULL){
        return ERROR;
    }

    for (int i = 0; i < TABLE_SIZE; ++i) {
     
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue;
        }

        free(entry->key);
        free(entry);
    }

    free(hashtable->entries);
    free(hashtable);

    return OK;
}

void ht_dump(ht_t *hashtable) {
    
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue;
        }

        printf("\nbucket[%d]: ", i);


        printf("%s adicional1= %d adicional2= %d", entry->key, entry->adicional1, entry->adicional2);
        if(entry->category == VARIABLE){
            printf(" category=VARIABLE");
        }else if(entry->category == PARAMETRO){
            printf(" category=PARAMETRO");
        }else if(entry->category == FUNCION){
            printf(" category=FUNCION");
        }

        if(entry->type == INT){
            printf(" type=INT");
        }else if(entry->type == BOOLEAN){
            printf(" type=BOOLEAN");
        }

        if(entry->escalar_vector == ESCALAR){
            printf(" escalar_vector=ESCALAR");
        }else if(entry->escalar_vector == VECTOR){
            printf(" escalar_vector=VECTOR");
        }

         
        printf("\n");
    }
}