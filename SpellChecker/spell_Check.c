#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

#define MAX_CMD_LEN 128

// A helper function to spell check a specific file
// 'file_name': Name of the file to spell check
// 'dict': A dictionary containing correct words
int spell_check_file(const char *file_name, const dictionary_t *dict) {
    // TODO Not yet implemented
    //Open the file 
    //check if the file is open correctly
    //use a while loop. open the fil and get each word one by one until you reach the end of the file
    //Once you check for spaces new line and word length
    //Call the dict find function
    //found in the diction
    //End of new_file checking
    FILE *file_handle = fopen(file_name, "r");
    if (file_handle == NULL){
        return -1;
    } 
    char c; 
    //Space, newline, character
    char word[MAX_CMD_LEN];
    int count = 0;
    
    while ((c = fgetc(file_handle)) != EOF) {
        if (c == '\n' || c == ' ') {
            word[count] = '\0'; 
            if (count > 0) {
                if (dict_find(dict, word)) {
                    printf("%s ", word);
                } else {
                    printf("%s[X] ", word);
                }
                count = 0; 
            }
            if (c == '\n') {
                printf("\n");
            }
        } else {
            word[count] = c;
            count++;
        }
    }
    
    fclose(file_handle);
    return 0;
}
/*
 * This is in general *very* similar to the list_main file seen in lab
 */
int main(int argc, char **argv) {
    dictionary_t *dict = NULL;
    if (argc == 1) {
        dict = create_dictionary();
        if (dict == NULL) {
            printf("Failed to create dictionary\n");
            return 1;
        }
    } else if(argc == 2) {
        dict = read_dict_from_text_file(argv[1]);
        if (dict == NULL) {
            printf("Failed to read dictionary from text file\n");
            // dict_free(dict);
            return 0;
        } else {
            printf("Dictionary successfully read from text file\n");
        }
    } else if (argc >= 3) {
        dict = read_dict_from_text_file(argv[1]);
        if (dict == NULL) {
            printf("Failed to read dictionary from text file\n");
            return 0;
        }

        int success = spell_check_file(argv[2], dict);
        if (success) {
            printf("Dictionary successfully read from text file\n");
        }

        if (success != 0) {
            printf("Spell check failed\n");
            dict_free(dict);
            return 0;
        }

    if (dict != NULL){
        dict_free(dict);
    
       }
         return 0;
}
   

    char cmd[MAX_CMD_LEN];
    printf("CSCI 2021 Spell Check System\n");
    printf("Commands:\n");
    printf("  add <word>:              adds a new word to dictionary\n");
    printf("  lookup <word>:           searches for a word\n");
    printf("  print:                   shows all words currently in the dictionary\n");
    printf("  load <file_name>:        reads in dictionary from a file\n");
    printf("  save <file_name>:        writes dictionary to a file\n");
    printf("  check <file_name>: spell checks the specified file\n");
    printf("  exit:                    exits the program\n");


    while (1) {
        printf("spell_check> ");
        if (scanf("%s", cmd) == EOF) {
            printf("\n");
            break;
        }

        if (strcmp("exit", cmd) == 0) {
            break;
        }

        // TODO Add cases for the other commands
        // Read in the command and any additional arguments (where needed)
    
        else if(strcmp("add",cmd) == 0){
            scanf("%s", cmd);
            dict_insert(dict, cmd);
    
        }else if(strcmp("lookup", cmd) == 0){
            scanf("%s",cmd);
            int success = dict_find(dict, cmd);
            if (success){
                printf("'%s' present in dictionary\n", cmd);
            } else {
                printf("'%s' not found\n",cmd);
            }
        }else if(strcmp("print",cmd) == 0){
            dict_print(dict);
    
        } else if (strcmp("load", cmd) == 0) {
        scanf("%s", cmd);
        dictionary_t *new_dictionary = read_dict_from_text_file(cmd);
        if (new_dictionary != NULL) {
           printf("Dictionary successfully read from text file\n");

        if (dict != NULL) {
            dict_free(dict);
        }
            dict = new_dictionary;
        } else {
            printf("Failed to read dictionary from text file\n");
        }
    } else if (strcmp("save", cmd) == 0) {
        scanf("%s", cmd);
        int success = write_dict_to_text_file(dict, cmd);
        
        if (!success) {   
            printf("Dictionary successfully written to text file\n");
        } else {
            printf("Failed to write dictionary to text file\n");
        }

        }else if(strcmp("check",cmd) == 0){
            scanf("%s",cmd);
        int success = spell_check_file(cmd, dict);
        if (success == -1){
            printf("Spell check failed\n");
        }       
            
        }else {
            printf("Unknown command %s\n", cmd);
        }
    
     }
    dict_free(dict);
    return 0;
}
