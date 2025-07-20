// Read/Write to .txt Credit: https://www.programiz.com/c-programming/c-file-input-output
// string concatenation credit: https://www.educative.io/blog/concatenate-string-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	char fileName[30];
	char filePathComplete[90];
	char userFilePathComplete[90];
	char pwFilePathComplete[90];
	char readString[257];
	char writeString[257];
	char randPW;
	char randChar;
	int randNum;
	int action;
	int digitNum;

	// check for desired action
	printf("\n// Enter Desired Action: Read(1), Write(2) or RandPW(3): ");
	scanf("%d", &action);

	if(action == 1 || action == 2){
		// ask for file location
		printf("\n// Enter Name of Site: ");
		scanf("%s", &fileName);
		strcpy(filePathComplete, "/home/masonp/pwman/database/");
		strcat(filePathComplete, fileName);
	}else if(action != 3){
		exit(1);
	}

	if(action == 1){
		// read file
		strcpy(userFilePathComplete, filePathComplete);
		strcat(userFilePathComplete, "-user.txt");
		FILE *userReadFilePtr = fopen(userFilePathComplete, "r");

		if(userReadFilePtr == NULL){
			printf("\n// Error Opening File //\n");
			exit(1);
		}else{
			fscanf(userReadFilePtr, "%s", &readString);
			printf("\n	// User: %s //\n", readString);
			fclose(userReadFilePtr);
		}

		strcpy(pwFilePathComplete, filePathComplete);
		strcat(pwFilePathComplete, "-pw.txt");
		FILE *pwReadFilePtr = fopen(pwFilePathComplete, "r");

		if(pwReadFilePtr == NULL){
			printf("\n// Error Opening File //\n");
			exit(1);
		}else{
			fscanf(pwReadFilePtr, "%s", &readString);
			printf("\n	// PW: %s //\n", readString);
			fclose(pwReadFilePtr);
		}

	}else if(action == 2){
		// write to file
		strcpy(userFilePathComplete, filePathComplete);
		strcat(userFilePathComplete, "-user.txt");
		FILE *userWriteFilePtr = fopen(userFilePathComplete, "w");

		if(userWriteFilePtr == NULL){
			printf("\n// Error Opening File //\n");
			exit(1);
		}else{
			printf("\n// Enter USER String (w/o Spaces): ");
			scanf("%s", &writeString);
			fprintf(userWriteFilePtr, "%s\n", writeString);
			fclose(userWriteFilePtr);
		}

		strcpy(pwFilePathComplete, filePathComplete);
		strcat(pwFilePathComplete, "-pw.txt");
		FILE *pwWriteFilePtr = fopen(pwFilePathComplete, "w");

		if(pwWriteFilePtr == NULL){
			printf("\n// Error Opening File //\n");
			exit(1);
		}else{
			printf("\n// Enter PW String (w/o Spaces): ");
			scanf("%s", &writeString);
			fprintf(pwWriteFilePtr, "%s\n", writeString);
			fclose(pwWriteFilePtr);
		}

	}else if(action == 3){
		char randPW[257];
		printf("\n// Enter Number of Digits for Random PW: ");
		scanf("%d", &digitNum);
		srand(time(NULL));
		printf("\n	// RandPW: ");
		for(int i = 0; i < digitNum; i++){
			randNum = 32;
			while(randNum < 33 || randNum > 126){
				randNum = rand() % 256;
			}
			randChar = randNum;
			printf("%c", randChar);
		}
		printf(" //\n");

	}else{
		// no action entered -> exit
		printf("\n// Error No Action Entered //\n");
		exit(0);
	}

	printf("\n");

	return 0;
}
