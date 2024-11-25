//Jaxson McCoy, 
//November 25, 2024

#include <sdio.h>
#define FILENAME "madlib1.txt"
#define STRARRLEN 200

int main(){
	FILE* fpt;
	
	
	//Creating file Pointer and checking if it opened
	fpt = fopen(FILENAME, "r");
	if (fpt = NULL){
		printf("File did not open\n");
		return 0;
	}
	
	
	
	fclose(fpt);
	return 0;
}
