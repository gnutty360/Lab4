/*
 * Marshall Lindsay
 * 14211662
 * Lab4
 * ECE 3220
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkCommandLineNumbers(char*);
FILE* openFile(int);
void closeFile(int);
int argumentDecision(char*, int);
int checkArguments(char**, int);


int main(int argc, char* argv[]){

	int fileNumber;
	int i;
	FILE* fp = NULL;
	
	//Checks to see if the user inputed enough arguments to open a file
	if(argc <3){
		printf("\nInvalid number of command line arguements!");
		return(1);
	}

	
	//Checks to make sure the second argument is '-n' followed by an appropriate
	//number. If not the program will terminate with an error message.
	if((argv[1][0] == '-') && (argv[1][1] == 'n')){
		
		fileNumber = atoi(argv[2]);
		if(!fileNumber || fileNumber < 1 || fileNumber > 11 ){
			printf("\nIvalid file number");
			return(1);
		}

	}else{
		printf("\nFirst command line argument is invalid!\n"
			"Please specify the file number by -n [file number]");
		return(1);
	}

	
	
	//File number should be valid at this point. 
	//Going to open the specified data file and error check the opening of 
	//said file. 
	

	fp = openFile(fileNumber);
	if(fp == NULL){
		printf("\nProblem opening file #%d. Terminating program", fileNumber);
		fclose(fp);
		return(1);
	}else{
		printf("\nThe file is open");
	}

	


	if(checkArguments(argv, argc)){
	}
	
	
	//while(argumentDecision(argv, argc));
	
		
	

	//Close the file and exit.
	if(fclose(fp)){
		printf("\nFile was not closed correctly");
	}else{
		printf("\nThe file has closed correctly");
	}


	return(EXIT_SUCCESS);


}

FILE* openFile(int fileNumber){
	char fileName[15];


	//I really do not like this switch statement.
	//I could probably split the string and then cacatenate to make
	//more pleasent to look at. I will use this for now because I know
	//that It will work. 
	switch(fileNumber){
	case 1:
		strcpy(fileName, "Raw_data_01.txt");
		break;
	case 2: 
		strcpy(fileName, "Raw_data_02.txt");
		break;
	case 3:
		strcpy(fileName, "Raw_data_03.txt");
		break;
	case 4:
		strcpy(fileName, "Raw_data_04.txt");
		break;
	case 5:
		strcpy(fileName, "Raw_data_05.txt");
		break;
	case 6:
		strcpy(fileName, "Raw_data_06.txt");
		break;
	case 7:
		strcpy(fileName, "Raw_data_07.txt");
		break;
	case 8:
		strcpy(fileName, "Raw_data_08.txt");
		break;
	case 9:
		strcpy(fileName, "Raw_data_09.txt");
		break;
	case 10:
		strcpy(fileName, "Raw_data_10.txt");
		break;
	case 11:
		strcpy(fileName, "Raw_data_11.txt");
		break;
	default:
		printf("\nUmm.. yeah... You should not be here");
		return(NULL);

	}

	
	FILE* fp = fopen(fileName, "r");

	return(fp);
}

int checkArguments(char** argv, int argc){
	int i;
	for(i = 3; i < argc; i++){
		
		if(!strcmp(argv[i], "-s")){
			printf("\nWe have liftoff");

		}else{
			printf("\nArgument %d:%s is invalid! Please try again!", i, argv[i]);
			return(1);
		}

	}
		
	return(0);
}



/*
int argumentDecision(char* argv, int argc){
	int i;

	for(i = 4; i < argc; i++){
		switch(argv[i]){

			default:
				printf("\nArgument %d: %s is invalid!", i, argv[i]);
				return(0);


		}

}
*/
