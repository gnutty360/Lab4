/*
 * Marshall Lindsay
 * 14211662
 * Lab4
 * ECE 3220
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGESTNUMBER 10

int checkCommandLineNumbers(char*);
FILE* openFile(int);
void closeFile(int);
int argumentDecision(char*, int);
int checkArguments(char**, int);

void scale (FILE*, double);
void offset (FILE*, double);
void renameFile (FILE*, char*);
void help();
void statistics(FILE*);
void centerData(FILE*);
void normalize(FILE*);


int main(int argc, char* argv[]){

	int fileNumber;
	int i;
	double numnber;
	FILE* fp = NULL;
	
	//Checks to see if the user inputed enough arguments to open a file
	if(argc <3){
		printf("\nInvalid number of command line arguements!");
		return(1);
	}
	


	//Makes sure all of the command line arguments are properly inputed
	//Returns error messages if they aren't.
	if(checkArguments(argv, argc)){
		return(1);
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
	char file = 0;
	double number;
	for(i = 1; i < argc; i++){
		
		if(!strcmp(argv[i], "-s")){
			i++;
			number = atof(argv[i]);
			if(number == 0){
				printf("\nArgument %d:'%s' is invalid! Use '-h' for options", i, argv[i]);
				return(1);
			}
				
		}else if(!strcmp(argv[i], "-n")){
			i++;
			file++;
			number = atof(argv[i]);
			if(number == 0){
				printf("\nArgument %d:'%s' is invalid! Use '-h' for options", i, argv[i]);
				return(1);
			}
		}else if(!strcmp(argv[i], "-o")){
			i++;
			number = atof(argv[i]);
			if(number == 0){
				printf("\nArgument %d:'%s' is invalid! Use '-h' for options", i, argv[i]);
				return(1);
			}
		}else if(!strcmp(argv[i], "-r")){
			i++;
		}else if(!strcmp(argv[i], "-h")){
		}else if(!strcmp(argv[i], "-S")){
		}else if(!strcmp(argv[i], "-C")){
		}else if(!strcmp(argv[i], "-N")){
		}else{
			printf("\nArgument %d:'%s' is invalid! Use '-h' for options", i, argv[i]);
			return(1);
		}
	}
	
	if(file < 1){
		printf("\nNo data file specified! Use '-h' for options");
		return(1);
	}else if(file > 1){
		printf("\nCannot open more than one data file at a time!\n"
				"Use '-h' for options");
	}
	
	return(0);
}
