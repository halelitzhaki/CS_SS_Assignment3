#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define TRUE 1
#define FALSE 0
#define A 'a'
#define B 'b'
#define FILE_LEN 250

int getLine(char s[]);
int getWord(char w[]);
int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

int main (int argc, char *argv[]) {
    char line[LINE], word[WORD], *str = malloc(WORD), *choice = malloc(WORD);
    getWord(str);
    getWord(choice);
    if(choice[0] == A) {
        getLine(line);
        print_lines(str);
    }
    else if(choice[0] == B) {
        getLine(line);
        print_similar_words(str);
    }
    free(choice);
    free(str);
    return 0;
}

int getLine(char s[]) {
    int i = 0;
    for(i = 0; i < LINE; i++) {
        scanf("%c", &s[i]);
        if(s[i] == '\n' || s[i] == '\0') {
            s[i] = '\0';
            break;
        }
    }
    return i;
}

int getWord(char w[]) {
    int i = 0;
    for(i = 0; i < WORD; i++) {
        scanf("%c", &w[i]);
        if(w[i] == '\n' || w[i] == '\t' || w[i] == ' ' || w[i] == '\0') {
            w[i] = '\0';
            break;
        }
    }
    return i;
}

int substring( char * str1, char * str2) {
    int start = FALSE, result = FALSE;
    for(int i = 0; i<strlen(str1); i++) {
        int j = 0;
        if(start == TRUE) {
            result = TRUE;
            for(j = 1; j<strlen(str2); j++) {
                if(str1[i] != str2[j]) {
                    result = FALSE;
                    start = FALSE;
                    break;
                }
                else if(j == strlen(str2) - 1) return result;
                i++;
            }
        }
        else {
            if(str1[i] == str2[j]) {
                if(strlen(str2) == 1) return TRUE;
                start = TRUE;
            }
        }
    }
    return result;
}

int similar (char *s, char *t, int n) {
    if(n == 0) {
        if(strcmp(s, t) == 0) return TRUE;
        else return FALSE; 
    }
    int *tShow = malloc(strlen(t)), nCount = 0, result = TRUE, j = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == t[j]) {
            tShow[j] = 1;
            j++;
        }
        else {
            nCount++;
        }
    }
    for(j = 0; j<strlen(t); j++) {
        if(tShow[j] == 0){
            free(tShow);
            return FALSE;
        }
    }
    if(nCount != n) {
        free(tShow);
        return FALSE;
    }
    free(tShow);
    return result;
}

void print_lines(char * str) {
    char line[LINE];
    while(getLine(line) != 0) {
        if(substring(line, str) == TRUE) printf("%s\n", line);
        bzero(line, LINE);
    }
}

void print_similar_words(char * str) {
    char word[WORD];
    while(getWord(word) != 0) {
        if(similar(word, str, 1) == TRUE || similar(word, str, 0) == TRUE) {
            printf("%s\n", word);
        }
        bzero(word, WORD);
    }
}
