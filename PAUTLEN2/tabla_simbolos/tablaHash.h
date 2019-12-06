#ifndef TABLAHASH_H
#define TABLAHASH_H

#define TABLE_SIZE 262144

/*Categoria del elemento*/
typedef enum {
    VARIABLE=0,
    PARAMETRO,
    FUNCION
}CATEGORIA;

/*Tipo variable que almacena un unico valor o un vector que almacena una serie de elementos */
typedef enum {
    BOOLEAN=0,
    INT
}TIPO;

/*Tipo del elemento si es una variable o paramentro, si es un vector es el tipo que se alamcena en este, si es una funcion se refiere al tipo de retorno*/
typedef enum {
    ESCALAR=0,
    VECTOR
}CLASE;

/*ESTADO CORRECTO Y ERRONEO*/
typedef enum {
    ERROR=0,
    OK
} STATUS;


typedef struct entry_t {
    char *key;
    CATEGORIA category;
    TIPO type;
    CLASE escalar_vector;
    int adicional1; /*valor si es escalar, longitud si es vector y numero de parametro si es funcion*/
    int adicional2; /*posicion en llamada a funcion si es parametro, posicion de declaracion si variable es local, numero de variables locales si es funcion*/
} entry_t;/*Categoria del elemento*/

typedef struct {
    entry_t **entries;
} ht_t;


entry_t *ht_pair(const char *key, int c, int t, int e_v, int a1, int a2);
ht_t *ht_create(void);
STATUS ht_set(ht_t *hashtable, const char *key, int c, int t, int e_v, int a1, int a2);
entry_t * ht_get(ht_t *hashtable, const char *key) ;
STATUS ht_destroy(ht_t *hashtable);
void ht_dump(ht_t *hashtable);

#endif