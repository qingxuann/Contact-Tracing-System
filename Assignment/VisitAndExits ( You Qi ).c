#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6067)
#pragma warning(disable:4477)


struct Condition {
	char symptom[50], maskCond[40], sanitizeCond[40];
};


typedef struct {
	char date[20], timeIn[10], ic[20], venueID[20];
	float temp;
	struct Condition cond;
	char scanIn[40], timeOut[10];
}VaeData;

typedef struct {
	char visitorIC[20];
}VisitorDetails;




void displayData() {
	VaeData workers;
	struct Condition cond;
	FILE* ftoread;
	system("cls");
	ftoread = fopen("visitandexit1.bin", "rb");
	if (!ftoread) {
		printf("Unable to open the file!");
		exit(-1);
	}



	printf("\n");
	printf("-----RECORD-----\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%s %10s %s %10s %s %11s %3s %8s %s%10s%s%10s%s %11s %s %10s %s %s %s %s %s\n", "|", "Login Date", "|", "Login Time", "|", "IC Number", "|", "Venue ID", "|", "Temperature", "|", "Signs of symtomp", "|", "Mask Condition", "|", "Sanitize Condition", "|", "Scan Condition", "|", "Logout Time", "|");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while (fread(&workers, sizeof(VaeData), 1, ftoread) != 0) {


		printf("|%-12s|%-12s|%-15s|%-10s|%-11.1f|%-16s|%-16s|%-20s|%-16s|%-13s|\n", workers.date, workers.timeIn, workers.ic,
			workers.venueID, workers.temp, workers.cond.symptom,
			workers.cond.maskCond, workers.cond.sanitizeCond,
			workers.scanIn, workers.timeOut);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}





	fclose(ftoread);
}


void searchData() {
	VaeData workers;
	VaeData work[50];
	int datafound = 0;
	struct Condition cond;
	int continueSearch = 0;
	char searchIc[20];
	int data = 0;
	FILE* fp;
	fp = fopen("visitandexit1.bin", "rb");

	if (!fp) {
		printf("Unable to open the file!");
		exit(-1);
	}
	system("cls");


	while (fread(&work[data], sizeof(VaeData), 1, fp) != 0) {
		data++;
		datafound++;
	}
	do {
		rewind(stdin);
		printf("\nEnter worker's IC number to check: ");
		scanf("%s", &searchIc);
		rewind(stdin);
		printf("--------SEARCH RECORD-------\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("%s %10s %s %10s %s %11s %3s %8s %s%10s%s%10s%s %11s %s %10s %s %s %s %s %s\n", "|", "Login Date", "|", "Login Time", "|", "IC Number", "|", "Venue ID", "|", "Temperature", "|", "Signs of symtomp", "|", "Mask Condition", "|", "Sanitize Condition", "|", "Scan Condition", "|", "Logout Time", "|");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		for (int data = 0; data < datafound; data++) {
			if (strcmp(searchIc, work[data].ic) == 0) {

				printf("|%-12s|%-12s|%-15s|%-10s|%-11.1f|%-16s|%-16s|%-20s|%-16s|%-13s|\n", &work[data].date, &work[data].timeIn, &work[data].ic,
					&work[data].venueID, work[data].temp, &work[data].cond.symptom,
					&work[data].cond.maskCond, &work[data].cond.sanitizeCond,
					&work[data].scanIn, work[data].timeOut);
				printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("Do you want to continue searching?(-1 to stop): ");
				scanf("%d", &continueSearch);
				rewind(stdin);
			}
		}

		for (int data = 0; data < 1; data++) {
			if (strcmp(searchIc, work[data].ic) == 1)
			{
				printf("\nNo data found, please re-enter !\n");
			}
		}


	} while (continueSearch != -1);

	return continueSearch;



	fclose(fp);
}

void addInfo() {
	VaeData workers;
	struct Condition cond;
	int addCount = 0;
	int stopAdd;

	FILE* fpfp;
	fpfp = fopen("visitandexit1.bin", "ab");
	if (!fpfp) {
		printf("Unable to open file!");
		exit(-1);
	}
	system("cls");
	do {
		rewind(stdin);
		printf("----Add information----");
		printf("\nEnter current date e.g 1/1/2021: ");
		scanf("%s", &workers.date);
		rewind(stdin);
		printf("\nEnter check in time e.g 12:00am: ");
		scanf("%s", &workers.timeIn);
		rewind(stdin);
		printf("\nEnter your ic number e.g 010234-23-2343: ");
		scanf("%s", &workers.ic);
		rewind(stdin);
		printf("\nEnter venue ID: ");
		scanf("%s", &workers.venueID);
		rewind(stdin);
		printf("\nEnter your temperature e.g 36.5: ");
		scanf("%f", &workers.temp);
		rewind(stdin);
		printf("\nDo you have any signs of symptom: ");
		scanf("%s", &workers.cond.symptom);
		rewind(stdin);
		printf("\nAre you wearing mask: ");
		scanf("%s", &workers.cond.maskCond);
		rewind(stdin);
		printf("\nIs your hand sanitized: ");
		scanf("%s", &workers.cond.sanitizeCond);
		rewind(stdin);
		printf("\nHave you scan the QR code: ");
		scanf("%s", &workers.scanIn);
		rewind(stdin);
		printf("\nEnter check out time e.g 12:00am: ");
		scanf("%s", &workers.timeOut);
		addCount++;

		fwrite(&workers, sizeof(VaeData), 1, fpfp);
		rewind(stdin);
		printf("\nContinue to add?(-1 to stop): ");
		scanf("%d", &stopAdd);
	} while (stopAdd != -1);
	printf("\n");
	printf("%d new record added !\n", addCount);
	fclose(fpfp);

	FILE* readUpdate;
	readUpdate = fopen("visitandexit1.bin", "rb");
	if (!readUpdate) {
		printf("Unable to open the file !");
		exit(-1);
	}
	system("cls");
	printf("-----UPDATED RECORDS-----\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("%s %10s %s %10s %s %11s %3s %8s %s%10s%s%10s%s %11s %s %10s %s %s %s %s %s\n", "|", "Login Date", "|", "Login Time", "|", "IC Number", "|", "Venue ID", "|", "Temperature", "|", "Signs of symtomp", "|", "Mask Condition", "|", "Sanitize Condition", "|", "Scan Condition", "|", "Logout Time", "|");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	while (fread(&workers, sizeof(VaeData), 1, readUpdate) != 0) {

		printf("|%-12s|%-12s|%-15s|%-10s|%-11.1f|%-16s|%-16s|%-20s|%-16s|%-13s|\n", workers.date, workers.timeIn, workers.ic,
			workers.venueID, workers.temp, workers.cond.symptom,
			workers.cond.maskCond, workers.cond.sanitizeCond,
			workers.scanIn, workers.timeOut);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	}

	fclose(readUpdate);


}

void dataReport() {
	VaeData workers;
	struct Condition cond;

	FILE* reportData;
	reportData = fopen("visitandexit1.bin", "rb");
	if (!reportData) {
		printf("Unable to open the file !");
		exit(-1);
	}
	system("cls");
	int dataCollected = 1;
	float temp;
	int tempCount1 = 1;
	int tempCount2 = 1;

	while (fread(&workers, sizeof(VaeData), 1, reportData) != 0) {
		dataCollected++;
		temp = workers.temp;
		if (temp < 37.5) {
			tempCount1++;
		}
		else if (temp >= 37.5) {
			tempCount2++;
		}

	}
	printf("\n-------------------------------------------------------------------------\n");
	printf("|                     SUMARRY REPORT OF WORKERS INFO                    |\n");
	printf("-------------------------------------------------------------------------\n");
	printf("|                        TITLE                        |  TOTAL NUMBERS  |\n");
	printf("-------------------------------------------------------------------------\n");
	printf("| Total data recorded                                 |       %-9d |\n", dataCollected - 1);
	printf("| Workers with temperature LESS than 37.5             |       %-9d |\n", tempCount1 - 1);
	printf("| Workers with temperature MORE than or equal to 37.5 |       %-9d |\n", tempCount2 - 1);
	printf("-------------------------------------------------------------------------\n");
	fclose(reportData);
}

void editInfo() {
	VaeData workers;
	VaeData w[20];
	int wCount = 0;
	struct Condition cond;
	FILE* editFile;
	editFile = fopen("visitandexit1.bin", "rb");
	if (!editFile) {
		printf("Unable to find the file !");
		exit(-1);
	}
	system("cls");
	while (fread(&w[wCount], sizeof(VaeData), 1, editFile) != 0) {
		wCount++;
	}
	int editInfo[20];
	int editStructure;
	char update;
	char edit;
	int editCount = 0;

	do {
		editStructure = -1;
		printf("\nPlease enter the worker's IC to edit:");
		scanf("%s", &editInfo);
		printf("\n");
		rewind(stdin);

		int i = 0;
		while (i < wCount && editStructure == -1) {
			if (strcmp(&editInfo, w[i].ic) == 0) {
				editStructure = i;
			}
			i++; //check next index
		}

		if (editStructure == -1) {
			printf("No data found !\n\n");
		}
		else {
			printf("-----RECORDS BEFORE UPDATING-----");
			printf("\n%s %10s %s %10s %s %11s %3s %8s %s%10s%s%10s%s %11s %s %10s %s %s %s %s %s\n", "|", "Login Date", "|", "Login Time", "|", "IC Number", "|", "Venue ID", "|", "Temperature", "|", "Signs of symtomp", "|", "Mask Condition", "|", "Sanitize Condition", "|", "Scan Condition", "|", "Logout Time", "|");
			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("|%-12s|%-12s|%-15s|%-10s|%-11.1f|%-16s|%-16s|%-20s|%-16s|%-13s|\n", w[editStructure].date, w[editStructure].timeIn, w[editStructure].ic,
				w[editStructure].venueID, w[editStructure].temp, w[editStructure].cond.symptom,
				w[editStructure].cond.maskCond, w[editStructure].cond.sanitizeCond,
				w[editStructure].scanIn, w[editStructure].timeOut);

			printf("\n\n----Enter updated details----\n");
			printf("Enter current date e.g 1/1/2021: ");
			scanf("%s", &w[editStructure].date);
			rewind(stdin);
			printf("\nEnter check in time e.g 12:00am: ");
			scanf("%s", &w[editStructure].timeIn);
			rewind(stdin);
			printf("\nEnter your ic number e.g 010234-23-2343: ");
			scanf("%s", &w[editStructure].ic);
			rewind(stdin);
			printf("\nEnter venue ID: ");
			scanf("%s", &w[editStructure].venueID);
			rewind(stdin);
			printf("\nEnter your temperature e.g 36.5: ");
			scanf("%f", &w[editStructure].temp);
			rewind(stdin);
			printf("\nDo you have any signs of symptom: ");
			scanf("%s", &w[editStructure].cond.symptom);
			rewind(stdin);
			printf("\nAre you wearing mask: ");
			scanf("%s", &w[editStructure].cond.maskCond);
			rewind(stdin);
			printf("\nIs your hand sanitized: ");
			scanf("%s", &w[editStructure].cond.sanitizeCond);
			rewind(stdin);
			printf("\nHave you scan the QR code: ");
			scanf("%s", &w[editStructure].scanIn);
			rewind(stdin);
			printf("\nEnter check out time e.g 12:00am: ");
			scanf("%s", &w[editStructure].timeOut);
			rewind(stdin);
			printf("\nAre you sure to modify?(Y/N)");
			scanf("%c", &update);
			rewind(stdin);
			if (toupper(update) == 'Y') {
				printf("-----RECORDS AFTER UPDATING-----");
				printf("\n%s %10s %s %10s %s %11s %3s %8s %s%10s%s%10s%s %11s %s %10s %s %s %s %s %s\n", "|", "Login Date", "|", "Login Time", "|", "IC Number", "|", "Venue ID", "|", "Temperature", "|", "Signs of symtomp", "|", "Mask Condition", "|", "Sanitize Condition", "|", "Scan Condition", "|", "Logout Time", "|");
				printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("|%-12s|%-12s|%-15s|%-10s|%-11.1f|%-16s|%-16s|%-20s|%-16s|%-13s|\n", w[editStructure].date, w[editStructure].timeIn, w[editStructure].ic,
					w[editStructure].venueID, w[editStructure].temp, w[editStructure].cond.symptom,
					w[editStructure].cond.maskCond, w[editStructure].cond.sanitizeCond,
					w[editStructure].scanIn, w[editStructure].timeOut);
				editCount++;
			}
		}
		printf("Edit another record?(Y/N): ");
		rewind(stdin);
		scanf("%c", &edit);
		rewind(stdin);
	} while (toupper(edit) == 'Y');
	printf("%d modification recorded.\n\n", editCount);

	FILE* editWrite;
	editWrite = fopen("visitandexit1.bin", "wb");
	fwrite(&w, sizeof(VaeData), wCount, editWrite);
	fclose(editWrite);
	fclose(editFile);
}

void deleteRec() {
	VaeData workers;
	VaeData w[20];
	int wCount = 0;
	char answer;
	char deleteTheIC[20];

	FILE* deleteFile;
	deleteFile = fopen("visitandexit1.bin", "rb");
	if (!deleteFile) {
		printf("Unable to open the file !");
		exit(-1);
	}
	system("cls");
	printf("\nPlease enter any worker's IC number in the file to reset all(The last data will be remained):");
	scanf("%s", deleteTheIC);
	printf("\n");
	rewind(stdin);

	while (fread(&w[wCount], sizeof(VaeData), 1, deleteFile) != 0) {

		if (strcmp(deleteTheIC, workers.ic) == 0) {
			int deleteStructure = wCount;
			printf("\n%s %10s %s %10s %s %11s %3s %8s %s%10s%s%10s%s %11s %s %10s %s %s %s %s %s\n", "|", "Login Date", "|", "Login Time", "|", "IC Number", "|", "Venue ID", "|", "Temperature", "|", "Signs of symtomp", "|", "Mask Condition", "|", "Sanitize Condition", "|", "Scan Condition", "|", "Logout Time", "|");
			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("|%-12s|%-12s|%-15s|%-10s|%-11.1f|%-16s|%-16s|%-20s|%-16s|%-13s|\n", w[deleteStructure].date, w[deleteStructure].timeIn, w[deleteStructure].ic,
				w[deleteStructure].venueID, w[deleteStructure].temp, w[deleteStructure].cond.symptom,
				w[deleteStructure].cond.maskCond, w[deleteStructure].cond.sanitizeCond,
				w[deleteStructure].scanIn, w[deleteStructure].timeOut);

		}

	}


	printf("IC detected, reset all accomplished, redirected to MENU.\n");

	fclose(deleteFile);

	FILE* saveDelete;
	saveDelete = fopen("visitandexit1.bin", "wb");
	if (!saveDelete) {
		printf("Unable to open the file !");
		exit(-1);
	}
	fwrite(&w, sizeof(VaeData), 1, saveDelete);

	fclose(saveDelete);
}
void visitAndExit() {

	int select;
	do {

		printf("\n\n-------- VISIT AND EXIT MENU --------\n\n");
		printf(" 1. Display Workers Info\n");
		printf(" 2. Add Workers Info\n");
		printf(" 3. Modify Workers Info\n");
		printf(" 4. Search Workers Info\n");
		printf(" 5. Summary Workers Report\n");
		printf(" 6. Reset and Remain Workers Info\n");
		printf(" 7. Exit\n");
		printf("------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &select);
		rewind(stdin);

		switch (select) {
		case 1: displayData();
			break;
		case 2: addInfo();
			break;
		case 3: editInfo();
			break;
		case 4: searchData();
			break;
		case 5: dataReport();
			break;
		case 6: deleteRec();
			break;
		case 7:printf("\nThank you for using Visit and Exit program !\n");
			break;
		default: printf("Invalid ! Please re-enter...\n");
		}
	} while (select != 7);

}




