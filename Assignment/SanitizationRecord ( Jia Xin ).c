#include<stdio.h>
#include<windows.h>
#include "main.h"
#pragma warning(disable:4996)
#pragma warning (disable:6031)

typedef struct {
	char name[40];
	char ph[13];
	char IC[20];
	char ID[10];
	char symptoms;
	double temp;
}Employee;

typedef struct {
	Employee record;
	char venue[30];
	int day, month, year, time;
}Details;

void addRecord();
void displayRecord();
void modifyRecord();
void deleteRecord();
void searchRecord();
void cert();
void report();

void red() {
	printf("\033[1;31m");
}
void green() {
	printf("\033[0;32m");
}
void reset() {
	printf("\033[0m");
}

void menu() {
	printf("\t\t\t\t\t\======================================\n");
	printf("\t\t\t\t\t|\t\t\t\t      |\n");
	printf("\t\t\t\t\t|           :-WELCOME TO-:            |\n");
	printf("\t\t\t\t\t|   :-SANITIZATION RECORDS MODULE-:   |\n");
	printf("\t\t\t\t\t|\t\t\t\t      |\n");
	printf("\t\t\t\t\t======================================\n");

}

void addRecord() {
	int record = 0, test, i;
	Details rcd;
	char comfirm;


	FILE* fptr;
	fptr = fopen("records.txt", "a");
	if (fptr == NULL)
	{
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	SYSTEMTIME t;
	GetLocalTime(&t);

	printf("\nLogin time - as at %02d - %02d - %d  %02d:%02d\n\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);

	do {
		record++;
		rewind(stdin);

		printf("\nPlease enter your details >");
		printf("\n\nID                   :");
		scanf("%[^\n]", &rcd.record.ID);
		rewind(stdin);

		do {
			printf("Name                 :");
			scanf("%[^\n]", &rcd.record.name);
			rewind(stdin);
			test = 2;
			for (int i = 0; i < strlen(rcd.record.name); i++) {
				if (((rcd.record.name[i] < 65 || rcd.record.name[i] > 90) && (rcd.record.name[i] < 97 || rcd.record.name[i] > 122)) && rcd.record.name[i] != 32) {
					test = 1;
				}
			}
			if (test == 1) {
				red();
				printf("\tPlease enter again! only character.\n");
				reset();
			}

		} while (test == 1);

		do {
			printf("\nI/C number");
			printf("\n(eg:030602-11-xxxx / 03060211xxxx)\n");
			printf("--> ");
			scanf("%[^\n]", &rcd.record.IC);
			rewind(stdin);
			test = 2;

			for (i = 0; i < strlen(rcd.record.IC); i++) {
				if ((rcd.record.IC[i] < 48 || rcd.record.IC[i]  >57) && rcd.record.IC[i] != 45) {
					test = 1;
				}
			}
			if (test == 1) {
				red();
				printf("\tPlease enter again! only numbers and you may included '-'\n");
				reset();
			}
		} while (test == 1);

		do {
			printf("\nContact number       ");
			printf("\n(eg:010-5032289 / 0105032289)\n");
			printf("--> ");
			scanf("%[^\n]", &rcd.record.ph);
			rewind(stdin);
			test = 2;

			for (int i = 0; i < strlen(rcd.record.ph); i++) {
				if ((rcd.record.ph[i] < 48 || rcd.record.ph[i]  >57) && rcd.record.ph[i] != 45) {
					test = 1;
				}
			}
			if (test == 1) {
				red();
				printf("\tPlease enter again! only numbers and you may included '-'\n");
				reset();
			}
		} while (test == 1);

		do {
			printf("\nBody temperature     :");
			scanf("%lf", &rcd.record.temp);
			rewind(stdin);

			if (rcd.record.temp > 37.6) {
				red();
				printf("\tHigh Temperature. Please go hospital for a check!\n");
				reset();
			}
			if (rcd.record.temp < 35.4) {
				red();
				printf("\tLow Temperature. Please check again!\n");
				reset();
			}
			if (rcd.record.temp > 35.5 && rcd.record.temp < 37.5) {
				green();
				printf("\tNormal Temperature. Welcome and take care!\n");
				reset();
			}
		} while (rcd.record.temp < 35.4);

		do {
			printf("Any symptoms?(Y/N)   :");
			scanf("%c", &rcd.record.symptoms);
			rewind(stdin);

			if (rcd.record.symptoms != 78 && rcd.record.symptoms != 89 && rcd.record.symptoms != 110 && rcd.record.symptoms != 121) {
				red();
				printf("\tPlease enter again! only 'y' / 'n'\n");
				reset();
			}
		} while (rcd.record.symptoms != 78 && rcd.record.symptoms != 89 && rcd.record.symptoms != 110 && rcd.record.symptoms != 121);

		do {
			printf("\n");
			printf("Please enter Sanitization Records details >");
			printf("\nEnter Today's >");
			printf("\ndate  :");
			scanf("%02d", &rcd.day);
			printf("month :");
			scanf("%02d", &rcd.month);
			printf("year  :");
			scanf("%d", &rcd.year);
			rewind(stdin);
			printf("%02d - %02d - %d\n", rcd.day, rcd.month, rcd.year);

			if (rcd.day != t.wDay) {
				red();
				printf("Please enter today date!\n");
				reset();
			}
			if (rcd.month != t.wMonth) {
				red();
				printf("Please enter current month!\n");
				reset();
			}
			if (rcd.year != t.wYear) {
				red();
				printf("Please enter curent year!\n");
				reset();
			}
		} while (rcd.day != t.wDay || rcd.month != t.wMonth || rcd.year != t.wYear);


		printf("\n");
		printf("Enter Sanitization Venue :");
		scanf("%[^\n]", &rcd.venue);
		rewind(stdin);

		do {
			printf("\nPlease convert to 24hours-clock (eg: 7pm --> 1900)");
			printf("\nEnter current time >");
			printf("\nTime  :");
			scanf("%d", &rcd.time);
			rewind(stdin);
			if (rcd.time < 0000 || rcd.time > 2359) {
				red();
				printf("\tPlease enter again!\n");
				reset();
			}
		} while (rcd.time < 0000 || rcd.time > 2359);

		do {
			printf("\n\nWant to add person incharge? (Y/N) :");
			scanf("%c", &comfirm);
			rewind(stdin);

			if (comfirm != 78 && comfirm != 89 && comfirm != 110 && comfirm != 121) {
				red();
				printf("\tPlease enter again! only 'y' / 'n'\n");
				reset();
			}
		} while (comfirm != 78 && comfirm != 89 && comfirm != 110 && comfirm != 121);

		fprintf(fptr, "%s|%s|%s|%s|%lf|%c|%d-%d-%d|%s|%d|", rcd.record.ID, rcd.record.name, rcd.record.IC, rcd.record.ph,
			rcd.record.temp, rcd.record.symptoms, rcd.day, rcd.month, rcd.year, rcd.venue, rcd.time);

	} while (toupper(comfirm) != 'N');
	printf("%d Record sucessfully added.\n\n", record);
	fclose(fptr);
}


void displayRecord() {
	Details disply;
	int record = 0;

	FILE* fptr2;
	fptr2 = fopen("records.txt", "r");

	if (fptr2 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	printf("\t\t\t\n---------- Sanitization Records Module ---------\n");
	printf(" ______________________________________________________________________________________________________________________________________________\n");
	printf(" | %-10s | %-15s  | %-14s  | %-15s | %-s | %-14s | %-14s | %-15s | %-5s |\n", "ID", "Name", "IC", "Phone.no ", "Temperature", "Any", "Date", "Venue", "Login");
	printf(" | %-10s | %15s  | %-15s | %-15s | %11s | %-s | %-14s | %-15s | %-5s | \n", " ", " ", " ", " ", " ", "symptoms (Y/N)", "   ", "   ", "Time");
	printf(" |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");

	while (fscanf(fptr2, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d|\n", disply.record.ID, disply.record.name, disply.record.IC, disply.record.ph, &disply.record.temp,
		&disply.record.symptoms, &disply.day, &disply.month, &disply.year, disply.venue, &disply.time) != EOF)
	{
		printf(" |%-10s  |%-17s | %-15s | %-15s | %-11.2lf | %-14c | %02d - %02d - %d | %-15s | %6d|", disply.record.ID, disply.record.name, disply.record.IC, disply.record.ph,
			disply.record.temp, disply.record.symptoms, disply.day, disply.month, disply.year, disply.venue, disply.time);
		printf(" \n |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
		record++;
	}


	printf("\n");
	printf("\n< %d records listed >\n", record);
	fclose(fptr2);
	system("pause");
}



void modifyRecord() {
	Details update;
	Details mod[50];
	char edit[10];
	int modRecord = 0;
	int i = 0, modifyNum, test;
	char comfirm, sure;

	FILE* fptr3;
	fptr3 = fopen("records.txt", "r");

	if (fptr3 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	while (fscanf(fptr3, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d|\n", mod[i].record.ID, mod[i].record.name, mod[i].record.IC, mod[i].record.ph, &mod[i].record.temp,
		&mod[i].record.symptoms, &mod[i].day, &mod[i].month, &mod[i].year, mod[i].venue, &mod[i].time) != EOF) {
		modRecord++;
		i++;
	}
	fclose(fptr3);

	do {
		printf("\nEnter ID to modify :");
		scanf("%s", &edit);
		rewind(stdin);

		for (int i = 0; i < modRecord; i++) {
			if (strcmp(mod[i].record.ID, edit) == 0) {
				printf("\n Record Before Editing > \n");
				printf(" ______________________________________________________________________________________________________________________________________________\n");
				printf(" | %-10s | %-15s  | %-14s  | %-15s | %-s | %-14s | %-14s | %-15s | %-5s |\n", "ID", "Name", "IC", "Phone.no ", "Temperature", "Any", "Date", "Venue", "Login");
				printf(" | %-10s | %15s  | %-15s | %-15s | %11s | %-s | %-14s | %-15s | %-5s | \n", " ", " ", " ", " ", " ", "symptoms (Y/N)", "   ", "   ", "Time");
				printf(" |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
				printf(" |%-10s  |%-17s | %-15s | %-15s | %-11.2lf | %-14c | %02d - %02d - %d | %-15s | %6d|", mod[i].record.ID, mod[i].record.name, mod[i].record.IC, mod[i].record.ph,
					mod[i].record.temp, mod[i].record.symptoms, mod[i].day, mod[i].month, mod[i].year, mod[i].venue, mod[i].time);
				printf(" \n |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");

				printf("\n");
				printf("Choose to modify :\n");
				printf("==================\n");
				printf("1. Name\n");
				printf("2. I/C number\n");
				printf("3. Contact number\n");
				printf("4. Temperature\n");
				printf("5. Symptoms (Y/N)\n");
				printf("6. Venue\n");
				printf("7. Exit\n");

				printf("Enter a number to modify :");
				scanf("%d", &modifyNum);
				rewind(stdin);

				switch (modifyNum) {
				case 1:
					do {
						printf("\n\nEnter New Name :");
						scanf("%[^\n]", &update.record.name);
						rewind(stdin);
						test = 2;
						for (int i = 0; i < strlen(update.record.name); i++) {
							if (((update.record.name[i] < 65 || update.record.name[i] > 90) && (update.record.name[i] < 97 || update.record.name[i] > 122)) && update.record.name[i] != 32) {
								test = 1;
							}
						}
						if (test == 1) {
							red();
							printf("\tPlease enter again! only character.\n");
							reset();
						}

					} while (test == 1);

					strcpy(mod[i].record.name, update.record.name);
					break;

				case 2:
					do {
						printf("\n\nEnter New I/C number :");
						scanf("%[^\n]", &update.record.IC);
						rewind(stdin);
						test = 2;

						for (i = 0; i < strlen(update.record.IC); i++) {
							if ((update.record.IC[i] < 48 || update.record.IC[i]  >57) && update.record.IC[i] != 45) {
								test = 1;
							}
						}
						if (test == 1) {
							red();
							printf("\tPlease enter again! only numbers and you may included '-'\n");
							reset();
						}
					} while (test == 1);

					strcpy(mod[i].record.IC, update.record.IC);
					break;

				case 3:
					do {
						printf("\n\nEnter New contact number :");
						scanf("%[^\n]", &update.record.ph);
						rewind(stdin);
						test = 2;

						for (int i = 0; i < strlen(update.record.ph); i++) {
							if ((update.record.ph[i] < 48 || update.record.ph[i]  >57) && update.record.ph[i] != 45) {
								test = 1;
							}
						}
						if (test == 1) {
							red();
							printf("\tPlease enter again! only numbers and you may included '-'\n");
							reset();
						}
					} while (test == 1);

					strcpy(mod[i].record.ph, update.record.ph);
					break;

				case 4:
					do {
						printf("\n\nEnter New Temperature :");
						scanf("%lf", &update.record.temp);
						rewind(stdin);

						if (update.record.temp > 37.6) {
							red();
							printf("\tHigh Temperature. Please go hospital for a check!\n");
							reset();
						}
						if (update.record.temp < 35.4) {
							red();
							printf("\tLow Temperature. Please check again!\n");
							reset();
						}
						else if (update.record.temp > 35.5 && update.record.temp < 37.5) {
							green();
							printf("\tNormal Temperature.\n");
							reset();
						}

					} while (update.record.temp < 35.4);
					mod[i].record.temp = update.record.temp;
					break;

				case 5:
					do {
						printf("\n\nEnter New Symptoms info(Y/N) :");
						scanf("%c", &update.record.symptoms);
						rewind(stdin);

						if (update.record.symptoms != 78 && update.record.symptoms != 89 && update.record.symptoms != 110 && update.record.symptoms != 121) {
							red();
							printf("\tPlease enter again! only 'y' / 'n'\n");
							reset();
						}
					} while (update.record.symptoms != 78 && update.record.symptoms != 89 && update.record.symptoms != 110 && update.record.symptoms != 121);


					mod[i].record.symptoms = update.record.symptoms;
					break;

				case 6:
					printf("\n\nEnter New Venue :");
					scanf("%[^\n]", &update.venue);
					rewind(stdin);
					strcpy(mod[i].venue, update.venue);
					break;

				case 7:
					printf("\n\nPress 'Enter' back to main menu\n");
					return 0;
					break;

				default:
					break;
				}
				do {
					printf("\nSure to modify (Y/N)? : ");
					scanf("%c", &comfirm);
					rewind(stdin);
					if (comfirm != 78 && comfirm != 89 && comfirm != 110 && comfirm != 121) {
						red();
						printf("\tPlease enter again! only 'y' / 'n'\n");
						reset();
					}
				} while (comfirm != 78 && comfirm != 89 && comfirm != 110 && comfirm != 121);

				if (toupper(comfirm) == 'Y') {
					printf("\nCurrent Record (After editing) :-\n");
					printf(" ______________________________________________________________________________________________________________________________________________\n");
					printf(" | %-10s | %-15s  | %-14s  | %-15s | %-s | %-14s | %-14s | %-15s | %-5s |\n", "ID", "Name", "IC", "Phone.no ", "Temperature", "Any", "Date", "Venue", "Login");
					printf(" | %-10s | %15s  | %-15s | %-15s | %11s | %-s | %-14s | %-15s | %-5s | \n", " ", " ", " ", " ", " ", "symptoms (Y/N)", "   ", "   ", "Time");
					printf(" |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
					printf(" |%-10s  |%-17s | %-15s | %-15s | %-11.2lf | %-14c | %02d - %02d - %d | %-15s | %6d|", mod[i].record.ID, mod[i].record.name, mod[i].record.IC, mod[i].record.ph,
						mod[i].record.temp, mod[i].record.symptoms, mod[i].day, mod[i].month, mod[i].year, mod[i].venue, mod[i].time);
					printf(" \n |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
					i++;
				}
				else {
					printf("\n\nPress 'Enter' back to main menu\n");
					return 0;
				}
			}
		}
		for (int i = 0; i < 1; i++) {
			if (strcmp(mod[i].record.ID, edit) == 1) {
				red();
				printf("Record Not Found! Please enter again!\n");
				reset();
			}
		}
		do {
			printf("\nContinue to modify another (Y/N)? :");
			scanf("%c", &sure);
			rewind(stdin);

			if (sure != 78 && sure != 89 && sure != 110 && sure != 121) {
				red();
				printf("\tPlease enter again! only 'y' / 'n'\n");
				reset();
			}
		} while (sure != 78 && sure != 89 && sure != 110 && sure != 121);

	} while (toupper(sure) == 'Y');

	FILE* fptr4;
	fptr4 = fopen("records.txt", "w");

	if (fptr4 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	for (i = 0; i < modRecord; i++) {
		fprintf(fptr3, "%s|%s|%s|%s|%lf|%c|%d-%d-%d|%s|%d|\n", mod[i].record.ID, mod[i].record.name, mod[i].record.IC, mod[i].record.ph,
			mod[i].record.temp, mod[i].record.symptoms, mod[i].day, mod[i].month, mod[i].year, mod[i].venue, mod[i].time);
	}

	fclose(fptr4);
}

void deleteRecord() {
	Details dlt[50];
	char delete[40];
	int dltRecord = 0, i = 0, test;
	char comfDlt, continueDlt;

	FILE* fptr5;
	fptr5 = fopen("records.txt", "r");
	if (fptr5 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	while (fscanf(fptr5, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d|\n", dlt[i].record.ID, dlt[i].record.name, dlt[i].record.IC, dlt[i].record.ph, &dlt[i].record.temp,
		&dlt[i].record.symptoms, &dlt[i].day, &dlt[i].month, &dlt[i].year, dlt[i].venue, &dlt[i].time) != EOF) {
		dltRecord++;
		i++;
	}
	fclose(fptr5);

	do {
		printf("\nEnter ID to delete :");
		scanf("%s", &delete);
		rewind(stdin);

		for (int i = 0; i < dltRecord; i++) {
			if (strcmp(dlt[i].record.ID, delete) == 0) {

				printf("\n Record Before Delete > \n");
				printf(" ______________________________________________________________________________________________________________________________________________\n");
				printf(" | %-10s | %-15s  | %-14s  | %-15s | %-s | %-14s | %-14s | %-15s | %-5s |\n", "ID", "Name", "IC", "Phone.no ", "Temperature", "Any", "Date", "Venue", "Login");
				printf(" | %-10s | %15s  | %-15s | %-15s | %11s | %-s | %-14s | %-15s | %-5s | \n", " ", " ", " ", " ", " ", "symptoms (Y/N)", "   ", "   ", "Time");
				printf(" |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
				printf(" |%-10s  |%-17s | %-15s | %-15s | %-11.2lf | %-14c | %02d - %02d - %d | %-15s | %6d|", dlt[i].record.ID, dlt[i].record.name, dlt[i].record.IC, dlt[i].record.ph,
					dlt[i].record.temp, dlt[i].record.symptoms, dlt[i].day, dlt[i].month, dlt[i].year, dlt[i].venue, dlt[i].time);
				printf(" \n |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
				do {
					printf("\nSure want to delete this record? (Y/N) :");
					scanf("%c", &comfDlt);
					rewind(stdin);

					if (toupper(comfDlt) == 'Y') {
						printf("\n Delete successfully.\n");
						dltRecord--;

						for (i; i < dltRecord; i++) {
							dlt[i] = dlt[i + 1];
						}
					}
					else if (toupper(comfDlt) == 'N') {
						printf("\nUnsucessful delete record!\n");
						printf("Press 'Enter' back to main menu\n");
						return 0;
					}

					if (comfDlt != 78 && comfDlt != 89 && comfDlt != 110 && comfDlt != 121) {
						red();
						printf("\tPlease enter again! only 'y' / 'n'\n");
						reset();
					}
				} while (comfDlt != 78 && comfDlt != 89 && comfDlt != 110 && comfDlt != 121);
			}
		}

		for (int i = 0; i < 1; i++) {
			if (strcmp(dlt[i].record.ID, delete) == 1) {
				red();
				printf("Record Not Found! Please enter again!\n");
				reset();
			}
		}

		do {
			printf("\nContinue to delete another (Y/N)? : ");
			scanf("%c", &continueDlt);
			rewind(stdin);

			if (continueDlt != 78 && continueDlt != 89 && continueDlt != 110 && continueDlt != 121) {
				red();
				printf("\tPlease enter again! only 'y' / 'n'\n");
				reset();
			}
		} while (continueDlt != 78 && continueDlt != 89 && continueDlt != 110 && continueDlt != 121);

	} while (toupper(continueDlt) == 'Y');

	FILE* fptr6;
	fptr6 = fopen("records.txt", "w");

	if (fptr6 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	for (i = 0; i < dltRecord; i++) {
		fprintf(fptr6, "%s|%s|%s|%s|%lf|%c|%d-%d-%d|%s|%d|\n", dlt[i].record.ID, dlt[i].record.name, dlt[i].record.IC, dlt[i].record.ph,
			dlt[i].record.temp, dlt[i].record.symptoms, dlt[i].day, dlt[i].month, dlt[i].year, dlt[i].venue, dlt[i].time);
	}

	fclose(fptr6);
}

void searchRecord() {
	Details search[50];
	char searchID[20];
	int searchRec = 0, i = 0;
	char comfirmSrch;

	FILE* fptr7;
	fptr7 = fopen("records.txt", "r");

	if (fptr7 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	while (fscanf(fptr7, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d|\n", search[i].record.ID, search[i].record.name, search[i].record.IC, search[i].record.ph, &search[i].record.temp,
		&search[i].record.symptoms, &search[i].day, &search[i].month, &search[i].year, search[i].venue, &search[i].time) != EOF) {
		searchRec++;
		i++;
	}
	fclose(fptr7);

	do {

		printf("\nEnter ID to search record :");
		scanf("%s", &searchID);
		rewind(stdin);
		printf("\n");

		for (int i = 0; i < searchRec; i++) {
			if (strcmp(search[i].record.ID, searchID) == 0) {
				printf(" ______________________________________________________________________________________________________________________________________________\n");
				printf(" | %-10s | %-15s  | %-14s  | %-15s | %-s | %-14s | %-14s | %-15s | %-5s |\n", "ID", "Name", "IC", "Phone.no ", "Temperature", "Any", "Date", "Venue", "Login");
				printf(" | %-10s | %15s  | %-15s | %-15s | %11s | %-s | %-14s | %-15s | %-5s | \n", " ", " ", " ", " ", " ", "symptoms (Y/N)", "   ", "   ", "Time");
				printf(" |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");
				printf(" |%-10s  |%-17s | %-15s | %-15s | %-11.2lf | %-14c | %02d - %02d - %d | %-15s | %6d|", search[i].record.ID, search[i].record.name, search[i].record.IC, search[i].record.ph,
					search[i].record.temp, search[i].record.symptoms, search[i].day, search[i].month, search[i].year, search[i].venue, search[i].time);
				printf(" \n |____________|__________________|_________________|_________________|_____________|________________|________________|_________________|_______|\n");

			}
		}
		for (int i = 0; i < 1; i++) {
			if (strcmp(search[i].record.ID, searchID) == 1) {
				red();
				printf("Record Not Found! Please enter again!\n");
				reset();
			}
		}
		do {
			printf("\nContinue to search another (Y/N)? : ");
			scanf("%c", &comfirmSrch);
			rewind(stdin);

			if (comfirmSrch != 78 && comfirmSrch != 89 && comfirmSrch != 110 && comfirmSrch != 121) {
				red();
				printf("\tPlease enter again! only 'y' / 'n'\n");
				reset();
			}
		} while (comfirmSrch != 78 && comfirmSrch != 89 && comfirmSrch != 110 && comfirmSrch != 121);


	} while (toupper(comfirmSrch) == 'Y');


}

void cert() {
	Details cert[50];
	char staffCert[20];
	int certRecord = 0, i = 0;
	char comfirmRep;

	FILE* fptr7;
	fptr7 = fopen("records.txt", "r");

	if (fptr7 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	while (fscanf(fptr7, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d|\n", cert[i].record.ID, cert[i].record.name, cert[i].record.IC, cert[i].record.ph, &cert[i].record.temp,
		&cert[i].record.symptoms, &cert[i].day, &cert[i].month, &cert[i].year, cert[i].venue, &cert[i].time) != EOF) {
		certRecord++;
		i++;
	}
	fclose(fptr7);

	do {
		printf("\nEnter ID to search :");
		scanf("%s", &staffCert);
		rewind(stdin);
		printf("\n");

		for (int i = 0; i < certRecord; i++) {
			if (strcmp(cert[i].record.ID, staffCert) == 0) {

				printf("======================================================\n\n");
				printf("Name                 : %s\n", cert[i].record.name);
				printf("IC Number            : %s\n", cert[i].record.IC);
				printf("Phone Number         : %s\n", cert[i].record.ph);
				printf("Temperature          : %.lf\n", cert[i].record.temp);
				printf("Any Symptoms         : %c\n", cert[i].record.symptoms);
				printf("Date                 : %02d/%02d/%d\n", cert[i].day, cert[i].month, cert[i].year);
				printf("Time (24hours-clock) : %d\n", cert[i].time);
				printf("Visited Venue        : %s\n", cert[i].venue);
				printf("\n======================================================\n");

				printf("\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t CERTIFICATE OF COMPLETION \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t            NAME           \t\t|\n");
				printf("\t|%23s %-20s  %10s          \n", " ", cert[i].record.name, "|");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t          IC Number        \t\t|\n");
				printf("\t|%20s %15s %19s             \n", " ", cert[i].record.IC, "|");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t Has succeddfully completed\t\t|\n");
				printf("\t|\t\t Cleaning and Sanitization \t\t|\n");
				printf("\t|\t\t at %-30s %6s                     \n", cert[i].venue, "|");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|%-17s Completed on %02d/%02d/%d %14s\n", " ", cert[i].day, cert[i].month, cert[i].year, "|");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t|\t       Certificate Provide By:\t\t\t|\n");
				printf("\t|\t    Tunku Abdul Rahman University Collage  \t|\n");
				printf("\t|\t\t                           \t\t|\n");
				printf("\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n\n");
			}
		}

		for (int i = 0; i < 1; i++) {
			if (strcmp(cert[i].record.ID, staffCert) == 1) {
				red();
				printf("Record Not Found! Please enter again!\n");
				reset();
			}
		}
		do {
			printf("\nContinue to search another (Y/N)? : ");
			scanf("%c", &comfirmRep);
			rewind(stdin);

			if (comfirmRep != 78 && comfirmRep != 89 && comfirmRep != 110 && comfirmRep != 121) {
				red();
				printf("\tPlease enter again! only 'y' / 'n'\n");
				reset();
			}
		} while (comfirmRep != 78 && comfirmRep != 89 && comfirmRep != 110 && comfirmRep != 121);
	} while (toupper(comfirmRep) == 'Y');
}

void report() {
	Details report[50];
	char staffReport[20];
	int i = 0, repRecord = 0;
	int jan = 0, feb = 0, mac = 0, april = 0, may = 0, june = 0, july = 0, aug = 0, sep = 0, oct = 0, nov = 0, dec = 0;

	FILE* fptr7;
	fptr7 = fopen("records.txt", "r");

	if (fptr7 == NULL) {
		printf("Unable to open the records.txt file!");
		exit(-1);
	}

	while (fscanf(fptr7, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d|\n", report[i].record.ID, report[i].record.name, report[i].record.IC, report[i].record.ph, &report[i].record.temp,
		&report[i].record.symptoms, &report[i].day, &report[i].month, &report[i].year, report[i].venue, &report[i].time) != EOF) {
		i++;
		repRecord++;
	}
	fclose(fptr7);

	for (int i = 0; i < repRecord; i++) {
		if (report[i].month == 1) {
			jan++;
		}
		else if (report[i].month == 2) {
			feb++;
		}
		else if (report[i].month == 3) {
			mac++;
		}
		else if (report[i].month == 4) {
			april++;
		}
		else if (report[i].month == 5) {
			may++;
		}
		else if (report[i].month == 6) {
			june++;
		}
		else if (report[i].month == 7) {
			july++;
		}
		else if (report[i].month == 8) {
			aug++;
		}
		else if (report[i].month == 9) {
			sep++;
		}
		else if (report[i].month == 10) {
			oct++;
		}
		else if (report[i].month == 11) {
			nov++;
		}
		else if (report[i].month == 12) {
			dec++;
		}
	}

	printf("\t\t\n----------Sanitization Report---------\n\n");

	printf("Total of person enter to Sanization on\n");
	printf("====================================\n");
	printf("January   : %d\n", jan);
	printf("February  : %d\n", feb);
	printf("March     : %d\n", mac);
	printf("April     : %d\n", april);
	printf("May       : %d\n", may);
	printf("June      : %d\n", june);
	printf("July      : %d\n", july);
	printf("Ausgust   : %d\n", aug);
	printf("September : %d\n", sep);
	printf("October   : %d\n", oct);
	printf("November  : %d\n", nov);
	printf("December  : %d\n\n", dec);
	system("pause");
}

void sanitizationRecord() {
	int selection;

	do {
		system("cls");
		menu();
		printf("\n===============");
		printf("\n  MAIN MENU");
		printf("\n===============\n");
		printf("1. Add Record\n2. Display Record\n");
		printf("3. Modify Record\n4. Delete Record\n");
		printf("5. Search Record\n6. Certification\n7. Report\n8. Exit\n");
		printf("\nYour selection :");
		scanf("%d", &selection);

		switch (selection) {
		case 1:
			addRecord();
			break;
		case 2:
			displayRecord();
			break;
		case 3:
			modifyRecord();
			break;
		case 4:
			deleteRecord();
			break;
		case 5:
			searchRecord();
			break;
		case 6:
			cert();
			break;
		case 7:
			report();
			break;
		}
	} while (selection != 8);
}



