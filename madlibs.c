// Authors: Mychaila Palanca, Jaxson McCoy, & Jena Grant
//Assignment: CS Final Project
//Due Date: 12-10-2024

#include <stdio.h>
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

