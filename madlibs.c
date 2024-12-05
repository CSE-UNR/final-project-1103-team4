// Authors: Mychaila Palanca, Jaxson McCoy, & Jena Grant
//Assignment: CS Final Project
//Due Date: 12-10-2024

//working code (missing: extra credit portion, still working on copy function) 
#include <stdio.h>
#include <stdbool.h>

#define MAX_LINES 150
#define MAX_LENGTH 120

//function prototypes
void readFileContent(char *filename, char content[MAX_LINES][MAX_LENGTH], int *lineCount);
void userInput(char *message, char *inputStorage);
void createMadlib(char content[MAX_LINES][MAX_LENGTH], int lineCount, char result[MAX_LINES][MAX_LENGTH]);
void displayResult(char result[MAX_LINES][MAX_LENGTH], int lineCount);
void copy(char *goal, char *source);

int main() {
    char filename[MAX_LENGTH];
    char content[MAX_LINES][MAX_LENGTH];
    char finishedMadlib[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;

    printf("Enter the filename: ");
    fgets(filename, MAX_LENGTH, stdin);

    for (int i = 0; filename[i]; i++) {
        if (filename[i] == '\n') {
            filename[i] = '\0';
            break;
        }
    }

    readFileContent(filename, content, &lineCount);

    if (lineCount == 0) {
        printf("Try Again.\n");
        return 1;
    }

    createMadlib(content, lineCount, finishedMadlib);
    displayResult(finishedMadlib, lineCount);

    return 0;
}

// 5 functions 
void readFileContent(char *filename, char content[MAX_LINES][MAX_LENGTH], int *lineCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file '%s'.\n", filename);
        return;
    }

    while (fgets(content[*lineCount], MAX_LENGTH, file)) {
        for (int i = 0; content[*lineCount][i]; i++) {
            if (content[*lineCount][i] == '\n') {
                content[*lineCount][i] = '\0';
                break;
            }
        }
        (*lineCount)++;
    }
    fclose(file);
}

void userInput(char *message, char *inputStorage) {
    printf("Please enter %s: ", message);
    fgets(inputStorage, MAX_LENGTH, stdin);

    for (int i = 0; inputStorage[i]; i++) {
        if (inputStorage[i] == '\n') {
            inputStorage[i] = '\0';
            break;
        }
    }
}

void createMadlib(char content[MAX_LINES][MAX_LENGTH], int lineCount, char result[MAX_LINES][MAX_LENGTH]) {
    for (int i = 0; i < lineCount; i++) {
        char input[MAX_LENGTH];

        switch (content[i][0]) {
            case 'A':
                userInput("an adjective", input);
                copy(result[i], input);
                break;
            case 'N':
                userInput("a noun", input);
                copy(result[i], input);
                break;
            case 'V': 
                userInput("a verb", input);
                copy(result[i], input);
                break;
            default:    
                copy(result[i], content[i]);
                break;
        }
    }
}

void displayResult(char result[MAX_LINES][MAX_LENGTH], int lineCount) {
    printf(" ");
    for (int i = 0; i < lineCount; i++) {
        printf("%s", result[i]);
        if (i < lineCount - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void copy(char *goal, char *source) {
    while (*source) {
        *goal++ = *source++;
    }
    *goal = '\0';
}

/*#include <stdio.h>
#define FILENAME "madlib1.txt"
#define STRARRLEN 200

int main(){
	FILE* fpt;
	//word type pointers
	
	
	//Creating file Pointer and checking if it opened
	fpt = fopen(FILENAME, "r");
	if (fpt = NULL){
		printf("File did not open\n");
		return 0;
	}
	
	//function call
	//2d Array creation (these can be passed through to other functions)
	
	//after array creation we then need to then recheck for all single letters.
	//Each time we get one, an if statement will take that info, prompts user for input, gets					 					
	//input, and puts it in its corresponding array (if we need extra functions im sure
	//there is a workaround we could do).
	
	//second function call
		
	fclose(fpt);
	return 0;
}

//function to count however many of each word type there are in the mad lib.
//add to a counter which will be used to create the amount of columns for three 2D arrays
//2d arrays will be created in main. counter variables will be pointers

*/
