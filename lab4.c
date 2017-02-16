/*
 * Marshall Lindsay
 * 14211662
 * Lab4
 * ECE 3220
 */

#include <stdio.h>
#include <stdlib.h>


int checkCommandLineNumbers(char*);
void openFile(int);
void closeFile(int);



int main(int argc, char* argv[]){

	int fileNumber;
	fileNumber = atoi(argv[2]);
	printf("\nThe first argument is %s", argv[0]);
	printf("\nThe second argument is %s", argv[1]);
	printf("\nThe third argument value is %d", fileNumber);
	/*

	if(argc <3){
		printf("\nInvalid number of command line arguements!");
		return(1);
	}
	if((argv[1][0] != '-') && (argv[1][1] != 'n')){
		printf("\nFirst command line argument is invalid!\n"
				"Please specify the file number by -n [file number]");
		return(1);
	}
	
	fileNumber = atoi(argv[2]);
	if(fileNumber){
		printf("\nInvalid file number");
		return(1);
	}else{
		printf("\n%d",fileNumber);
	}
*/
	return(EXIT_SUCCESS);

}

