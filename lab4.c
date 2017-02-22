/*
 * Marshall Lindsay
 * 14211662
 * Lab4
 * ECE 3220
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* openFile(char**, int, int*);
void argumentDecision(char**, int, FILE*, int*);
int checkArguments(char**, int);

void scale (FILE*, double, int*);
void offset (FILE*, double, int*);
void renameFile (FILE*, char*);
void help();
void statistics(FILE*, int*);
void centerData(FILE*, int*);
void normalize(FILE*, int*);


int main(int argc, char* argv[]){

	int number;
	int fileNumber;
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
	//Attempts to open the file. If the file does not open, or if the file number
	//isn't valid, returns NULL.
	fp = openFile(argv, argc, &fileNumber);
	
	if(fp == NULL){
		printf("\nFile could not be opened!");
		return(1);
	}
	printf("\nfileNumber in main: %d", fileNumber);
	argumentDecision(argv, argc, fp, &fileNumber);
	
	
	if(fclose(fp) != 0){
		printf("\nFile was not close successfully!");
	}
	return(EXIT_SUCCESS);


}

FILE* openFile(char** argv, int argc, int* fileNumPtr){
	char fileName[15];
	int fileNumber;
	int i;
	
	for(i = 1; i < argc; i++){
		
		if(!strcmp(argv[i], "-n")){
			i++;
			fileNumber = atoi(argv[i]);
			fileNumPtr = &fileNumber;
		}
	}
	
	printf("\nfileName assigned value: %d", *fileNumPtr);
	
	//I really do not like this switch statement.
	//I could probably split the string and then concatenate to make
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
		printf("\nInvalid file number!");
		return(NULL);

	}
		
	printf("\nOpening %s...", fileName);
	FILE* fp = fopen(fileName, "r");
	
	if(fp == NULL){
		printf("\nError opening %s\nTerminating", fileName);
	}
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

void argumentDecision(char** argv, int argc, FILE* fp, int* fileNumber){
		
		int i;
		double value;
		char* newName;
		
		for(i = 1; i < argc; i++){
			if(!strcmp(argv[i],"-n")){
				i++;
			}else if(!strcmp(argv[i],"-s")){
				i++;
				value = atof(argv[i]);
				printf("\nBegin Scale...");
				scale(fp, value, fileNumber);
			}else if(!strcmp(argv[i],"-o")){
				i++;
				value = atof(argv[i]);
				printf("\nBegin Offset...");
				offset(fp, value, fileNumber);
			}else if(!strcmp(argv[i],"-r")){
				i++;
				newName = argv[i];
				printf("\nBegin Rename...");
				renameFile(fp, newName);
			}else if(!strcmp(argv[i],"-h")){
				printf("\nBegin Help...");
				help();
			}else if(!strcmp(argv[i],"-S")){
				printf("\nBegin Statistics...");
				statistics(fp, fileNumber);
			}else if(!strcmp(argv[i],"-C")){
				printf("\nBegin CenterData...");
				centerData(fp, fileNumber);
			}else if(!strcmp(argv[i],"-N")){
				printf("\nBegin Normalize...");
				normalize(fp, fileNumber);
			}
		}
		
		return;
}

void scale(FILE* fp, double value, int* fileNumber){
	
	FILE* newFP;
	int numberOfData;
	int largestData;
	double* dataArray;
	char newFileName[20];
	int i;
	
	sprintf(newFileName, "Scaled_Data_%.2d.txt", *fileNumber);
	printf("\nfileNumber: %d", *fileNumber);
	printf("\n%s", newFileName);
	newFP = fopen(newFileName, "w");
	if(newFP == NULL){
		printf("\nUnable create file %s. Scaling terminated!", newFileName);
		return;
	}
	
	fscanf(fp, "%d %d", &numberOfData, &largestData);
	
	dataArray = malloc(numberOfData* sizeof(double));

	for(i = 0; i < numberOfData; i++){
		fscanf(fp, "%d", &dataArray[i]);
	}
	
	fprintf(newFP, "%d %d\t %d %d", numberOfData, largestData, numberOfData, (int)(value)*largestData);
	
	fclose(newFP);
	free(dataArray);
	
	return;
}

void offset (FILE* fp, double value, int* fileNumber){
	
}
void renameFile (FILE* fp, char* newName){
	
}
void help(){
	
}
void statistics (FILE* fp, int* fileNumber){
	
}
void centerData (FILE* fp, int* fileNumber){
	
}
void normalize (FILE* fp, int* fileNumber){
	
}