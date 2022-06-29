#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TEXT_LENGTH         1000
#define BUFFER_LENGTH       100
#define WORD_AMOUNTS        100
#define WORD_LENGTH         12                

int main(void) {
    char text[TEXT_LENGTH] = "when I makes tea I makes tea, as old mother Grogan said and when I makes water I makes water.";
                                
    char textBuf[BUFFER_LENGTH];
    size_t text_size = sizeof(text);
    size_t textBuf_size = sizeof(textBuf);
    char word[WORD_AMOUNTS][WORD_LENGTH];           //Store words in text[]
    int word_occ[WORD_AMOUNTS] = {0};               //Store occurences of words in text[]
    char delim[] = " .,\n";

    //Enter text from keyboard
    /*printf("Enter text in here \n");
    printf("(Maximum is %d charaters and stop by enter a new line): \n", TEXT_LENGTH);
    while(true) {
        fgets(textBuf, textBuf_size, stdin);        //Enter text from keyborad line by line
        if(textBuf[0] == '\n'){                     //Enter newline to stop entering
            break;
        }

        if(strcat_s(text, text_size, textBuf)) {    //Link text from textBuf[] to text[]
            printf("Exceed text capacity \n");
            return 1;
        }
    }*/
    
    //Token words from text[]
    int i=0;
    bool new_word = true;
    for(char* text_ptr=strtok(text, delim); text_ptr; text_ptr=strtok(NULL, delim)) {

        for(int j=0; j<i; ++j) {                    //Check if this text_ptr is new word or not
            if(strcmp(text_ptr, word[j]) == 0) {
                new_word = false;
                ++word_occ[j];
            }
        }

        if(new_word) {                              //If it is a new word and then assign text_ptr to word[i]
            strcpy(word[i], text_ptr);
            ++word_occ[i++];
        }

        new_word = true;                            //Reset new_word  
    }

    //Output occurences of words in text
    for(int n=0; n<i; ++n) {
        printf("%-10s %d\n", word[n], word_occ[n]);
    }

    return 0;
}