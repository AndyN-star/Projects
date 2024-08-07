#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

table_t *create_table() {
    // TODO Not yet implemented
    table_t *hash = malloc(sizeof(table_t));
    if (hash == NULL){
        return NULL;
    }
    hash->length = INITIAL_HASH_TABLE_SIZE;
    hash->array = (list_node_t**)malloc(sizeof(list_node_t)*hash->length);
    if (hash->array == NULL){
        return NULL;
    }
    for(int i = 0; i<hash->length; i++){
        hash->array[i] = NULL;
    }
    return hash;

}

dictionary_t *create_dictionary() {
    dictionary_t *dict = malloc(sizeof(dictionary_t));
    if (dict == NULL) {
        return NULL;
    }
    dict->table = create_table();
    if (dict->table == NULL) {
        free(dict);
        return NULL;
    }
    dict->size = 0;
    return dict;
}

int hash_code(const char* word) {
    // TODO Not yet implemented
    int i = 0;
    for(int j = 0; j<strlen(word); j++)
        i = i + (int)(word[j]);
    i = (i * 13) % INITIAL_HASH_TABLE_SIZE;

    return i;
}

int dict_insert(dictionary_t *dict, const char *word) {
    // TODO Not yet implemented
    if(dict == NULL ||dict->table == NULL){
        return -1;
    }
    int index = hash_code(word) % dict->table->length;

    list_node_t *new_node = malloc(sizeof(list_node_t));
    if (new_node == NULL){
        return -1;
    }
    
    strcpy(new_node->word, word); 
    
    new_node->next = NULL;

    list_node_t *current = dict->table->array[index];
    if (current == NULL){
        dict->table->array[index] = new_node;
    } else {
    // Loop until you reach new_node is not null
    // assign the new_node next value
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    }
    dict->size++;

    
    return 0;
}

int dict_find(const dictionary_t *dict, const char *query) {
    if(dict == NULL ||dict->table == NULL){
        return 0;
    }
    int index = hash_code(query) % dict->table->length;
    list_node_t *current = dict->table->array[index];
    while(current!= NULL){
        if(strcmp(current->word, query) == 0){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void dict_print(const dictionary_t *dict) {
    // TODO Not yet implemented
     if(dict == NULL ||dict->table == NULL){
        return;
    }
    for(int i = 0; i<dict->table->length; i++){
        list_node_t *current = dict->table->array[i];
        while(current != NULL){
            printf("%s\n", current->word);
            current = current->next;
        }
        
    }
}    
void dict_free(dictionary_t *dict) {
    // TODO Not yet implemented
if(dict != NULL){
        list_node_t *current;
        for(int i = 0; i< dict->table->length; i++){
            current = dict->table->array[i];
            while(current != NULL){
                list_node_t *tempNode = current;
                list_node_t *nextNode = current->next;
                free(tempNode);
                current = nextNode;

            }
        }
        free(dict->table->array);
        free(dict->table);
        free(dict);
}   

}        

dictionary_t *read_dict_from_text_file(const char *file_name) {
    // TODO Not yet implemented
    FILE *file_handle = fopen(file_name, "r");
    if(file_handle == NULL){
          return NULL; 
    }
    dictionary_t *dict = create_dictionary();
    if (dict == NULL){
        return NULL;
    }
    //fscanf
    char word[MAX_WORD_LEN];
    while(fscanf(file_handle, "%s", word) == 1){
       dict_insert(dict, word);
    }
    //open the dictionary
    //Insert the words into the dictionary
    //

    fclose(file_handle);
    return(dict);
}

int write_dict_to_text_file(const dictionary_t *dict, const char *file_name) {
    // TODO Not yet implemented
    FILE *file_handle = fopen(file_name, "w");
    if(file_handle == NULL){
        return -1;
    }   
    return 0;
    //fprintf
     for(int i = 0; i< dict->table->length; i++){
        list_node_t *current = dict->table->array[i];
        while(current != NULL){
            fprintf(file_handle, "%s\n", current->word);
            current = current->next;
        }
     }
     fclose(file_handle);
     return 0;
}