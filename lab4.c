/*
 * Marshall Lindsay
 * 14211662
 * Lab4
 * ECE 3220
 */

#include <stdio.h>
#include <stdlib.h>


int checkCommandLineNumbers(char*);
FILE* openFile(int);
void closeFile(int);



int main(int argc, char* argv[]){

	int fileNumber;
	FILE* fp = NULL;
	

	if(argc <3){
		printf("\nInvalid number of command line arguements!");
		return(1);
	}

	
	
	if((argv[1][0] == '-') && (argv[1][1] == 'n')){
		
		fileNumber = atoi(argv[2]);
		if(!fileNumber){
			printf("\nIvalid file number");
			return(1);
		}

	}else{
		printf("\nFirst command line argument is invalid!\n"
			"Please specify the file number by -n [file number]");
		return(1);
	}

	fp = openFile(fileNumber);
	if(fp == NULL){
		printf("\nProblem opening file #%d. Terminating program", fileNumber);
		return(1);
	}

	return(EXIT_SUCCESS);


}

FILE* openFile(int fileNumber){

	switch(fileNumber){
	case 1:
	case 2:
	case 3:
	
	}
}

