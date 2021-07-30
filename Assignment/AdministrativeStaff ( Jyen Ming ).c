#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "main.h"
#pragma warning (disable:4996)
#pragma warning (disable:6031)

void BoldRed()
{
	printf("\033[1;91m");
}
void BoldGreen()
{
	printf("\033[1;92m");
}
void Reset()
{
	printf("\033[0m");
}

struct Date {
	int year;
	int month;
	int day;
};

struct Date2 {
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;
};

struct StaffInfo {
	char id[10];
	char name[40];
	char position[20];
	char department[20];
	char password[20];
	char contactNo[15];
	struct Date joinedDate;
};

void menu2();
void addStaff();
void searchStaff();
void modifyStaff();
void displayStaff();
void login();

void addStaff() {
	char option, ans;
	int count = 0, i, check, yy, mm, dd, select = 0, a;
	FILE* fp;
	fp = fopen("staff.dat", "rb");
	FILE* fp1;
	fp1 = fopen("staff.dat", "ab");
	struct StaffInfo staff;

	if (fp == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}
	if (fp1 == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}
	printf("\n\n");
	printf("%52s _______     __     __      _______ __          ___   ___ \n", "");
	printf("%52s|   _   |.--|  |.--|  |    |     __|  |_.---.-.'  _|.'  _|\n", "");
	printf("%52s|       ||  _  ||  _  |    |__     |   _|  _  |   _||   _|\n", "");
	printf("%52s|___|___||_____||_____|    |_______|____|___._|__|  |__|  \n", "");
	printf("\n\n\n");
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	printf("\t%c Staff Details %c\n", 186, 186);
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	printf("\n");

	struct StaffInfo cmpDetails[1000];
	fread(&cmpDetails[count], sizeof(struct StaffInfo), 1, fp);
	do {
		do
		{



			if (select == -1)
			{
				printf("%8c%s", 32, "+==========================================+\n");
				printf("%8c%s", 32, "|");
				BoldRed();
				printf("%s", " This ID has been used ! Please try again ");
				Reset();
				printf("%s", "|\n");
				printf("%8c%s", 32, "+==========================================+\n");

			}
			select = 0;
			printf("\tEnter Staff ID               : ");
			scanf("%s", &staff.id);
			rewind(stdin);
			for (i = 0; i <= count; i++)
			{
				if (strcmp(staff.id, cmpDetails[i].id) == 0)
				{
					select = -1;
				}
			}
		} while (select == -1);
		do {
			printf("\tEnter Staff Name             : ");
			scanf("%[^\n]", &staff.name);
			rewind(stdin);
			check = 2;
			for (i = 0; i < strlen(staff.name); i++) {
				if (((staff.name[i] < 65 || staff.name[i] > 90) && (staff.name[i] < 97 || staff.name[i] > 122)) && staff.name[i] != 32) {
					check = 1;
				}
			}
			if (check == 1) {
				printf("%57s", "+==============================================+\n");
				printf("%9s", "|");
				BoldRed();
				printf("   Input error! Please input only character.  ");
				Reset();
				printf("|\n");
				printf("%57s", "+==============================================+\n");

			}
		} while (check == 1);
		do {
			printf("\tEnter Position               : ");
			scanf("%[^\n]", &staff.position);
			rewind(stdin);
			check = 2;
			for (i = 0; i < strlen(staff.position); i++) {
				if (((staff.position[i] < 65 || staff.position[i] > 90) && (staff.position[i] < 97 || staff.position[i] > 122)) && staff.position[i] != 32) {
					check = 1;
				}
			}
			if (check == 1) {
				printf("%57s", "+==============================================+\n");
				printf("%9s", "|");
				BoldRed();
				printf("   Input error! Please input only character.  ");
				Reset();
				printf("|\n");
				printf("%57s", "+==============================================+\n");
			}
		} while (check == 1);
		do {
			printf("\tEnter Department             : ");
			scanf("%[^\n]", &staff.department);
			rewind(stdin);
			check = 2;
			for (i = 0; i < strlen(staff.department); i++) {
				if (((staff.department[i] < 65 || staff.department[i] > 90) && (staff.department[i] < 97 || staff.department[i] > 122)) && staff.department[i] != 32) {
					check = 1;
				}
			}
			if (check == 1) {
				printf("%57s", "+==============================================+\n");
				printf("%9s", "|");
				BoldRed();
				printf("   Input error! Please input only character.  ");
				Reset();
				printf("|\n");
				printf("%57s", "+==============================================+\n");
			}
		} while (check == 1);
		do {
			printf("\tEnter Password (max 10 char) : ");
			scanf("%[^\n]", &staff.password);
			rewind(stdin);
			check = 2;
			if (strlen(staff.password) > 10)
			{
				check = 1;
				printf("%60s", "+=================================================+\n");
				printf("%9s", "|");
				BoldRed();
				printf("   Input error! Please input only 10 character.  ");
				Reset();
				printf("|\n");
				printf("%60s", "+=================================================+\n");
			}
		} while (check == 1);
		do {
			printf("\tEnter Contact Number         : ");
			scanf("%s", &staff.contactNo);
			rewind(stdin);
			check = 2;
			for (i = 0; i < strlen(staff.contactNo); i++) {
				if (staff.contactNo[i] < 48 || staff.contactNo[i]  >57) {
					check = 1;
				}
			}
			if (check == 1) {
				printf("%57s", "+==============================================+\n");
				printf("%9s", "|");
				BoldRed();
				printf("    Input error! Please input only integer.   ");
				Reset();
				printf("|\n");
				printf("%57s", "+==============================================+\n");
			}
		} while (check == 1);
		do {
			printf("\tEnter the joined date        :\n");
			printf("\t                   Day   : ");
			scanf("%d", &staff.joinedDate.day);
			rewind(stdin);
			printf("\t                   Month : ");
			scanf("%d", &staff.joinedDate.month);
			rewind(stdin);
			printf("\t                   Year  : ");
			scanf("%d", &staff.joinedDate.year);
			rewind(stdin);
			yy = staff.joinedDate.year;
			mm = staff.joinedDate.month;
			dd = staff.joinedDate.day;
			if (yy >= 1900 && yy <= 9999)
			{
				//check month
				if (mm >= 1 && mm <= 12)
				{
					//check days
					if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
					{
						check = 2;
					}
					else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
					{
						check = 2;
					}
					else if ((dd >= 1 && dd <= 28) && (mm == 2))
					{
						check = 2;
					}
					else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
					{
						check = 2;
					}
					else
					{
						printf("%58s", "+==========================================+\n");
						printf("%14s", "|");
						BoldRed();
						printf("    Day is invalid in the current month   ");
						Reset();
						printf("|\n");
						printf("%58s", "+==========================================+\n");
						check = 1;
					}
				}
				else
				{
					printf("%41s", "+=========================+\n");
					printf("%14s", "|");
					BoldRed();
					printf("    Month is not valid   ");
					Reset();
					printf("|\n");
					printf("%41s", "+=========================+\n");
					check = 1;
				}
			}
			else
			{
				printf("%40s", "+========================+\n");
				printf("%14s", "|");
				BoldRed();
				printf("    Year is not valid   ");
				Reset();
				printf("|\n");
				printf("%40s", "+========================+\n");
				check = 1;
			}
		} while (check == 1);
		fwrite(&staff, sizeof(struct StaffInfo), 1, fp1);
		printf("\tDo you want to continue to add more staff (Y = yes) ? ");
		scanf("%c", &option);
		rewind(stdin);
		printf("\n");
		count++;
	} while (toupper(option) == 'Y');

	printf("\n");
	printf("%17c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	printf("%16c%c", 32, 179);
	BoldGreen();
	printf("   %d Record added successfully    ", count);
	Reset();
	printf("%c\n", 179);
	printf("%17c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	fclose(fp1);
	fclose(fp);

	printf("\n\tBack to main Page (M) or Exit Program (E) : ");
	rewind(stdin);
	scanf("%c", &ans);

	if (toupper(ans) == 'M') {
		system("CLS");
		menu2();
	}
	else if (toupper(ans) == 'E') {
		exit(-1);
	}
}

void searchStaff() {
	int pCount = 0, i, select;
	char search[6] = "", option, ans;

	FILE* fp;
	fp = fopen("staff.dat", "rb");

	if (fp == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}





	struct StaffInfo staff[1000];
	fread(&staff[pCount], sizeof(struct StaffInfo), 1, fp);
	while (!feof(fp))
	{
		pCount++;
		fread(&staff[pCount], sizeof(struct StaffInfo), 1, fp);
	}
	do {
		select = -1;
		printf("%30s _______                         __         _______ __          ___   ___ \n", "");
		printf("%30s|     __|.-----.---.-.----.----.|  |--.    |     __|  |_.---.-.'  _|.'  _|\n", "");
		printf("%30s|__     ||  -__|  _  |   _|  __||     |    |__     |   _|  _  |   _||   _|\n", "");
		printf("%30s|_______||_____|___._|__| |____||__|__|    |_______|____|___._|__|  |__|  \n", "");
		printf("\n\n\n\n\n\tEnter the Staff ID you want to search > ");
		scanf("%s", &search);
		rewind(stdin);
		printf("\n");
		for (i = 0; i <= pCount; i++) {
			if (strcmp(search, staff[i].id) == 0) {
				printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
				printf("\t%c Staff Details %c\n", 186, 186);
				printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
				printf("\n\n");
				printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 213, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 184);
				printf("\t%c   Staff ID       : %-20s   %c\n", 179, staff[i].id, 179);
				printf("\t%c   Staff Name     : %-20s   %c\n", 179, staff[i].name, 179);
				printf("\t%c   Position       : %-20s   %c\n", 179, staff[i].position, 179);
				printf("\t%c   Department     : %-20s   %c\n", 179, staff[i].department, 179);
				printf("\t%c   Password       : %-20s   %c\n", 179, staff[i].password, 179);
				printf("\t%c   Contact Number : %-20s   %c\n", 179, staff[i].contactNo, 179);
				printf("\t%c   Joined date    : %02d/%02d/%-14d   %c\n", 179, staff[i].joinedDate.day, staff[i].joinedDate.month, staff[i].joinedDate.year, 179);
				printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 212, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 190);
				select = i;
				option = 'N';
			}
		}
		if (select == -1) {

			printf("%36s", "+========================+\n");
			printf("%10s", "|");
			BoldRed();
			printf("   No Record Found!!!   ");
			Reset();
			printf("|\n");
			printf("%36s", "+========================+\n");
			printf("\n\tEnter ID again ? ( Y = yes ) > ");
			scanf("%c", &option);
			if (toupper(option) == 'Y') {
				system("CLS");
			}
			rewind(stdin);

		}
		else if (select = i) {
			printf("\n\n\tDo you want to search more staff ?? ( Y = yes ) > ");
			scanf("%c", &option);
			rewind(stdin);
			if (toupper(option) == 'Y') {
				system("CLS");
			}
		}
	} while (toupper(option) == 'Y');
	fclose(fp);
	printf("\n\tBack to main Page (M) or Exit Program (E) : ");
	rewind(stdin);
	scanf("%c", &ans);

	if (toupper(ans) == 'M') {
		system("CLS");
		menu2();
	}
	else if (toupper(ans) == 'E') {
		exit(-1);
	}
}

void modifyStaff() {
	char modifyID[6], ans;
	int pCount = 0, i, select = -1, check;
	int modifiedCount = 0, option = 0, choice, choice2 = 0;
	char yesNo, contactNo[15], option2;
	char name[40], position[20], department[20], password[20];
	int  day, month, year, mm, yy, dd;

	FILE* fp;
	fp = fopen("staff.dat", "rb");

	if (fp == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}


	printf("%30s _______           __ __   ___             _______ __          ___   ___ \n", "");
	printf("%30s|   |   |.-----.--|  |__|.'  _|.--.--.    |     __|  |_.---.-.'  _|.'  _|\n", "");
	printf("%30s|       ||  _  |  _  |  ||   _||  |  |    |__     |   _|  _  |   _||   _|\n", "");
	printf("%30s|__|_|__||_____|_____|__||__|  |___  |    |_______|____|___._|__|  |__|  \n", "");
	printf("%30s                               |_____|                                   \n", "");


	struct StaffInfo staff[1000];
	fread(&staff[pCount], sizeof(struct StaffInfo), 1, fp);
	while (!feof(fp))
	{
		pCount++;
		fread(&staff[pCount], sizeof(struct StaffInfo), 1, fp);
	}

	fclose(fp);
	do {
		select = -1;
		printf("\n\n\tEnter modify Staff Id:");
		scanf("%s", &modifyID);
		rewind(stdin);
		printf("\n");
		for (i = 0; i < pCount; i++)
		{
			if (strcmp(staff[i].id, modifyID) == 0)
			{
				select = i;
			}
		}
		if (select == -1)
		{
			printf("%36s", "+========================+\n");
			printf("%10s", "|");
			BoldRed();
			printf("   No Record Found!!!   ");
			Reset();
			printf("|\n");
			printf("%36s", "+========================+\n");
		}
		else {
			do
			{
				printf("\t +===============================+                  \n");
				printf("\t ||    Choose 1 modify option   ||                  \n");
				printf("\t +===============================+                  \n");
				printf("\t ||                                                 \n");
				printf("\t ||     +--------------------------------------+    \n");
				printf("\t ||===> | Press 1 : Modify all details         |    \n");
				printf("\t ||     +--------------------------------------+    \n");
				printf("\t ||     +--------------------------------------+    \n");
				printf("\t ||===> | Press 2 : Select 1 details to modify |    \n");
				printf("\t        +--------------------------------------+    \n");
				printf("\n");
				printf("\tYour option : ");
				rewind(stdin);
				scanf("%d", &option);
				rewind(stdin);
				printf("\n");
				if (option == 1)
				{
					printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
					printf("\t%c Staff Details %c\n", 186, 186);
					printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
					printf("\n");
					printf("\tStaff ID                      : %s\n", modifyID);
					do {
						printf("\tEnter Staff Name              : ");
						scanf("%[^\n]", name);
						rewind(stdin);
						check = 2;
						for (i = 0; i < strlen(name); i++) {
							if (((name[i] < 65 || name[i] > 90) && (name[i] < 97 || name[i] > 122)) && name[i] != 32) {
								check = 1;
							}
						}
						if (check == 1) {
							printf("%57s", "+==============================================+\n");
							printf("%9s", "|");
							BoldRed();
							printf("   Input error! Please input only character.  ");
							Reset();
							printf("|\n");
							printf("%57s", "+==============================================+\n");
						}
					} while (check == 1);
					do {
						printf("\tEnter Position                : ");
						scanf("%[^\n]", &position);
						rewind(stdin);
						check = 2;
						for (i = 0; i < strlen(position); i++) {
							if (((position[i] < 65 || position[i] > 90) && (position[i] < 97 || position[i] > 122)) && position[i] != 32) {
								check = 1;
							}
						}
						if (check == 1) {
							printf("%57s", "+==============================================+\n");
							printf("%9s", "|");
							BoldRed();
							printf("   Input error! Please input only character.  ");
							Reset();
							printf("|\n");
							printf("%57s", "+==============================================+\n");
						}
					} while (check == 1);
					do {
						printf("\tEnter Department              : ");
						scanf("%[^\n]", &department);
						rewind(stdin);
						check = 2;
						for (i = 0; i < strlen(department); i++) {
							if (((department[i] < 65 || department[i] > 90) && (department[i] < 97 || department[i] > 122)) && department[i] != 32) {
								check = 1;
							}
						}
						if (check == 1) {
							printf("%57s", "+==============================================+\n");
							printf("%9s", "|");
							BoldRed();
							printf("   Input error! Please input only character.  ");
							Reset();
							printf("|\n");
							printf("%57s", "+==============================================+\n");
						}
					} while (check == 1);

					do {
						printf("\tEnter Password (max 10 char)  : ");
						scanf("%[^\n]", &password);
						rewind(stdin);
						check = 2;
						if (strlen(password) > 10)
						{
							check = 1;
							printf("%61s", "+=================================================+\n");
							printf("%9s", "|");
							BoldRed();
							printf("   Input error! Please input only 10 character.  ");
							Reset();
							printf("|\n");
							printf("%61s", "+=================================================+\n");
						}
					} while (check == 1);
					do {
						printf("\tEnter Contact Number          : ");
						scanf("%s", &contactNo);
						rewind(stdin);
						check = 2;
						for (i = 0; i < strlen(contactNo); i++) {
							if (contactNo[i] < 48 || contactNo[i]  >57) {
								check = 1;
							}
						}
						if (check == 1) {
							printf("%57s", "+==============================================+\n");
							printf("%9s", "|");
							BoldRed();
							printf("    Input error! Please input only integer.   ");
							Reset();
							printf("|\n");
							printf("%57s", "+==============================================+\n");
						}
					} while (check == 1);
					do {
						printf("\tEnter the joined date         :\n");
						printf("\t                   Day   : ");
						scanf("%d", &day);
						rewind(stdin);
						printf("\t                   Month : ");
						scanf("%d", &month);
						rewind(stdin);
						printf("\t                   Year  : ");
						scanf("%d", &year);
						rewind(stdin);

						mm = month;
						yy = year;
						dd = day;
						if (yy >= 1900 && yy <= 9999)
						{
							//check month
							if (mm >= 1 && mm <= 12)
							{
								//check days
								if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
								{
									check = 2;
								}
								else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
								{
									check = 2;
								}
								else if ((dd >= 1 && dd <= 28) && (mm == 2))
								{
									check = 2;
								}
								else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
								{
									check = 2;
								}
								else
								{
									printf("%53s", "+==========================================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("    Day is invalid in the current month   ");
									Reset();
									printf("|\n");
									printf("%53s", "+==========================================+\n");
									check = 1;
								}
							}
							else
							{
								printf("%36s", "+=========================+\n");
								printf("%9s", "|");
								BoldRed();
								printf("    Month is not valid   ");
								Reset();
								printf("|\n");
								printf("%36s", "+=========================+\n");
								check = 1;
							}
						}
						else
						{
							printf("%35s", "+========================+\n");
							printf("%9s", "|");
							BoldRed();
							printf("    Year is not valid   ");
							Reset();
							printf("|\n");
							printf("%35s", "+========================+\n");
							check = 1;
						}
					} while (check == 1);
					printf("\tSure to Modify (Y = yes)?: ");
					scanf("%c", &yesNo);
					rewind(stdin);
					if (toupper(yesNo) == 'Y')
					{
						printf("\n\t+===========================================+\n");
						printf("\t|");
						BoldGreen();
						printf(" The record has been changed sucessfully ! ");
						Reset();
						printf("|\n");
						printf("\t+===========================================+\n");
						strcpy(staff[select].name, name);
						strcpy(staff[select].position, position);
						strcpy(staff[select].department, department);
						strcpy(staff[select].password, password);
						strcpy(staff[select].contactNo, contactNo);
						staff[select].joinedDate.day = day;
						staff[select].joinedDate.month = month;
						staff[select].joinedDate.year = year;
						modifiedCount++;
					}
				}
				else if (option == 2)
				{
					do {
						printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
						printf("\t%c   Choose the option :%14c\n", 186, 186);
						printf("\t%c   1. Modify name%19c\n", 186, 186);
						printf("\t%c   2. Modify position%15c\n", 186, 186);
						printf("\t%c   3. Modify department%13c\n", 186, 186);
						printf("\t%c   4. Modify password%15c\n", 186, 186);
						printf("\t%c   5. Modify contact number%9c\n", 186, 186);
						printf("\t%c   6. Modify Joined date%12c\n", 186, 186);
						printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
						printf("\n\tYour choice : ");
						rewind(stdin);
						scanf("%d", &choice);

						switch (choice) {
						case 1:
						{
							do {
								printf("\tEnter new name : ");
								rewind(stdin);
								scanf("%[^\n]", name);
								printf("\n");
								check = 2;
								for (i = 0; i < strlen(name); i++) {
									if (((name[i] < 65 || name[i] > 90) && (name[i] < 97 || name[i] > 122)) && name[i] != 32) {
										check = 1;
									}
								}
								if (check == 1) {
									printf("%57s", "+==============================================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("   Input error! Please input only character.  ");
									Reset();
									printf("|\n");
									printf("%57s", "+==============================================+\n");
								}
							} while (check == 1);
							printf("\tSure to Modify (Y = yes)?:");
							rewind(stdin);
							scanf("%c", &yesNo);
							if (toupper(yesNo) == 'Y')
							{
								printf("\n\t+=====================================+\n");
								printf("\t|");
								BoldGreen();
								printf(" Name has been changed sucessfully ! ");
								Reset();
								printf("|\n");
								printf("\t+=====================================+\n\n");
								strcpy(staff[select].name, name);
								modifiedCount++;
							}
							break;
						}
						case 2:
						{
							do {
								printf("\tEnter new position :");
								rewind(stdin);
								scanf("%[^\n]", position);
								printf("\n");
								check = 2;
								for (i = 0; i < strlen(position); i++) {
									if (((position[i] < 65 || position[i] > 90) && (position[i] < 97 || position[i] > 122)) && position[i] != 32) {
										check = 1;
									}
								}
								if (check == 1) {
									printf("%57s", "+==============================================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("   Input error! Please input only character.  ");
									Reset();
									printf("|\n");
									printf("%57s", "+==============================================+\n");
								}
							} while (check == 1);
							printf("\tSure to Modify (Y = yes)?:");
							rewind(stdin);
							scanf("%c", &yesNo);
							if (toupper(yesNo) == 'Y')
							{
								printf("\n\t+=========================================+\n");
								printf("\t|");
								BoldGreen();
								printf(" Position has been changed sucessfully ! ");
								Reset();
								printf("|\n");
								printf("\t+=========================================+\n\n");

								strcpy(staff[select].position, position);
								modifiedCount++;

							}
							break;
						}
						case 3:
						{
							do {
								printf("\tEnter new department :");
								rewind(stdin);
								scanf("%[^\n]", department);
								printf("\n");
								check = 2;
								for (i = 0; i < strlen(department); i++) {
									if (((department[i] < 65 || department[i] > 90) && (department[i] < 97 || department[i] > 122)) && department[i] != 32) {
										check = 1;
									}
								}
								if (check == 1) {
									printf("%57s", "+==============================================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("   Input error! Please input only character.  ");
									Reset();
									printf("|\n");
									printf("%57s", "+==============================================+\n");
								}
							} while (check == 1);
							printf("\tSure to Modify (Y = yes)?:");
							rewind(stdin);
							scanf("%c", &yesNo);
							if (toupper(yesNo) == 'Y')
							{
								printf("\n\t+===========================================+\n");
								printf("\t|");
								BoldGreen();
								printf(" Department has been changed sucessfully ! ");
								Reset();
								printf("|\n");
								printf("\t+===========================================+\n\n");

								strcpy(staff[select].department, department);
								modifiedCount++;

							}
							break;
						}
						case 4:
						{
							do {
								printf("\tEnter Password (max 10 char) : ");
								rewind(stdin);
								scanf("%[^\n]", &password);
								check = 2;
								if (strlen(password) > 10)
								{
									check = 1;
									printf("%61s", "+=================================================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("   Input error! Please input only 10 character.  ");
									Reset();
									printf("|\n");
									printf("%61s", "+=================================================+\n");
								}
							} while (check == 1);
							printf("\n");
							printf("\tSure to Modify (Y = yes)?:");
							rewind(stdin);
							scanf("%c", &yesNo);
							if (toupper(yesNo) == 'Y')
							{
								printf("\n\t+=========================================+\n");
								printf("\t|");
								BoldGreen();
								printf(" Password has been changed sucessfully ! ");
								Reset();
								printf("|\n");
								printf("\t+=========================================+\n\n");

								strcpy(staff[select].password, password);
								modifiedCount++;

							}
							break;
						}
						case 5:
						{
							do {
								printf("\tEnter new contact number :");
								rewind(stdin);
								scanf("%s", &contactNo);
								printf("\n");
								check = 2;
								for (i = 0; i < strlen(contactNo); i++) {
									if (contactNo[i] < 48 || contactNo[i]  >57) {
										check = 1;
									}
								}
								if (check == 1) {
									printf("%57s", "+==============================================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("    Input error! Please input only integer.   ");
									Reset();
									printf("|\n");
									printf("%57s", "+==============================================+\n");
								}
							} while (check == 1);
							printf("\tSure to Modify (Y = yes)?:");
							rewind(stdin);
							scanf("%c", &yesNo);
							if (toupper(yesNo) == 'Y')
							{
								printf("\n\t+===============================================+\n");
								printf("\t|");
								BoldGreen();
								printf("  Contact Number has been changed sucessfully ! ");
								Reset();
								printf("|\n");
								printf("\t+===============================================+\n\n");

								strcpy(staff[select].contactNo, contactNo);
								modifiedCount++;
							}
							break;
						}
						case 6:
						{
							do {
								printf("\tEnter new joined date\n");
								printf("\t             Day   : ");
								scanf("%d", &day);
								printf("\t             Month : ");
								scanf("%d", &month);
								printf("\t             Year  : ");
								scanf("%d", &year);
								rewind(stdin);
								printf("\n");
								mm = month;
								yy = year;
								dd = day;
								if (yy >= 1900 && yy <= 9999)
								{
									//check month
									if (mm >= 1 && mm <= 12)
									{
										//check days
										if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
										{
											check = 2;
										}
										else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
										{
											check = 2;
										}
										else if ((dd >= 1 && dd <= 28) && (mm == 2))
										{
											check = 2;
										}
										else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
										{
											check = 2;
										}
										else
										{
											printf("%53s", "+==========================================+\n");
											printf("%9s", "|");
											BoldRed();
											printf("    Day is invalid in the current month   ");
											Reset();
											printf("|\n");
											printf("%53s", "+==========================================+\n");
											check = 1;
										}
									}
									else
									{
										printf("%36s", "+=========================+\n");
										printf("%9s", "|");
										BoldRed();
										printf("    Month is not valid   ");
										Reset();
										printf("|\n");
										printf("%36s", "+=========================+\n");
										check = 1;
									}
								}
								else
								{
									printf("%35s", "+========================+\n");
									printf("%9s", "|");
									BoldRed();
									printf("    Year is not valid   ");
									Reset();
									printf("|\n");
									printf("%35s", "+========================+\n");
									check = 1;
								}
							} while (check == 1);
							printf("\tSure to Modify (Y = yes)?:");
							rewind(stdin);
							scanf("%c", &yesNo);
							if (toupper(yesNo) == 'Y')
							{
								printf("\n\t+============================================+\n");
								printf("\t|");
								BoldGreen();
								printf(" Joined Date has been changed sucessfully ! ");
								Reset();
								printf("|\n");
								printf("\t+============================================+\n\n");
								staff[select].joinedDate.day = day;
								staff[select].joinedDate.month = month;
								staff[select].joinedDate.year = year;
								modifiedCount++;
							}
							break;
						}
						default:
						{
							printf("%84s", "+==================================+\n");
							printf("%48s", "|");
							BoldRed();
							printf("   Invalid Number ! Type Again.   ");
							Reset();
							printf("|\n");
							printf("%84s", "+==================================+\n");
							choice2 = 2;
						}
						}
					} while (choice2 == 2);

				}
				else {
					printf("%84s", "+==================================+\n");
					printf("%48s", "|");
					BoldRed();
					printf("   Invalid Number ! Type Again.   ");
					Reset();
					printf("|\n");
					printf("%84s", "+==================================+\n");
				}
			} while (option != 1 && option != 2);
		}
		option = 1;
		printf("\n\tDo you want to modify more staff ?? ( Y = yes ) > ");
		rewind(stdin);
		scanf("%c", &option2);
		if (toupper(option2) == 'Y') {
			option = 3;
			system("CLS");
			printf("%30s _______           __ __   ___             _______ __          ___   ___ \n", "");
			printf("%30s|   |   |.-----.--|  |__|.'  _|.--.--.    |     __|  |_.---.-.'  _|.'  _|\n", "");
			printf("%30s|       ||  _  |  _  |  ||   _||  |  |    |__     |   _|  _  |   _||   _|\n", "");
			printf("%30s|__|_|__||_____|_____|__||__|  |___  |    |_______|____|___._|__|  |__|  \n", "");
			printf("%30s                               |_____|                                   \n", "");
		}
	} while (option == 3);
	printf("\t%d records modified\n", modifiedCount);
	fp = fopen("staff.dat", "wb");

	if (fp == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}

	fwrite(&staff, sizeof(struct StaffInfo), pCount, fp);
	fclose(fp);

	printf("\n\tBack to main Page (M) or Exit Program (E) : ");
	rewind(stdin);
	scanf("%c", &ans);

	if (toupper(ans) == 'M') {
		system("CLS");
		menu2();
	}
	else if (toupper(ans) == 'E') {
		exit(-1);
	}
}

void displayStaff() {
	char ans;
	int option;
	FILE* fp;
	FILE* fp1;
	fp = fopen("staff.dat", "rb");
	fp1 = fopen("loginDate.dat", "rb");
	struct StaffInfo staff;
	struct Date2 loginDate;

	if (fp == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}
	if (fp1 == NULL)
	{
		printf("\tError opening file\n");
		exit(-1);
	}


	printf("%30s _____  __               __                   _______                    \n", "");
	printf("%30s|     \\|__|.-----.-----.|  |.---.-.--.--.    |   |   |.-----.-----.--.--.\n", "");
	printf("%30s|  --  |  ||__ --|  _  ||  ||  _  |  |  |    |       ||  -__|     |  |  |\n", "");
	printf("%30s|_____/|__||_____|   __||__||___._|___  |    |__|_|__||_____|__|__|_____|\n", "");
	printf("%30s                 |__|             |_____|                                \n", "");

	printf("\n\n");


	printf("\t         +===============================+                  \n");
	printf("\t         ||    Choose 1 display option  ||                  \n");
	printf("\t         +===============================+                  \n");
	printf("\t         ||                                                 \n");
	printf("\t         ||     +--------------------------------------+    \n");
	printf("\t         ||===> | Press 1 : display staff details      |    \n");
	printf("\t         ||     +--------------------------------------+    \n");
	printf("\t         ||     +--------------------------------------+    \n");
	printf("\t         ||===> | Press 2 : display admin login date   |    \n");
	printf("\t                +--------------------------------------+    \n");
	printf("\n");
	printf("\t         Your option : ");
	rewind(stdin);
	scanf("%d", &option);
	rewind(stdin);
	system("CLS");
	if (option == 1) {
		printf("%28s _____  __               __                   _______ __          ___   ___ \n", "");
		printf("%28s|     \\|__|.-----.-----.|  |.---.-.--.--.    |     __|  |_.---.-.'  _|.'  _|\n", "");
		printf("%28s|  --  |  ||__ --|  _  ||  ||  _  |  |  |    |__     |   _|  _  |   _||   _|\n", "");
		printf("%28s|_____/|__||_____|   __||__||___._|___  |    |_______|____|___._|__|  |__|  \n", "");
		printf("%28s                 |__|             |_____|                                   \n\n\n", "");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("\t%c%3s%-12s%c%5s%-15s%c%6s%-14s%c%5s%-20s%c%6s%-14s%c%3s%-17s%c%4s%-16s%c\n", 186, "", "STAFF ID", 186, "", "STAFF NAME", 186, "", "POSITION", 186, "", "DEPARTMENT", 186, "", "PASSWORD", 186, "", "CONTACT NUMBER", 186, "", "JOINED DATE", 186);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
		fread(&staff, sizeof(struct StaffInfo), 1, fp);
		while (!feof(fp))
		{
			printf("\t%c%5s%-10s%c%5s%-15s%c%5s%-15s%c%3s%-22s%c%5s%-15s%c%5s%-15s%c%5s%02d-%02d-%-0d%6c\n", 186, "", staff.id, 186, "", staff.name, 186, "", staff.position, 186, "", staff.department, 186, "", staff.password, 186, "", staff.contactNo, 186, "", staff.joinedDate.day, staff.joinedDate.month, staff.joinedDate.year, 186);
			printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

			fread(&staff, sizeof(struct StaffInfo), 1, fp);
		}


		printf("\n\tBack to main Page (M) or Exit Program (E) : ");
		rewind(stdin);
		scanf("%c", &ans);

		if (toupper(ans) == 'M') {
			system("CLS");
			menu2();
		}
		else if (toupper(ans) == 'E') {
			exit(-1);
		}
	}
	else if (option == 2) {


		printf("%10s _____  __               __                   _______     __            __             _____                __             _____         __         \n", "");
		printf("%10s|     \\|__|.-----.-----.|  |.---.-.--.--.    |   _   |.--|  |.--------.|__|.-----.    |     |_.-----.-----.|__|.-----.    |     \\.---.-.|  |_.-----.\n", "");
		printf("%10s|  --  |  ||__ --|  _  ||  ||  _  |  |  |    |       ||  _  ||        ||  ||     |    |       |  _  |  _  ||  ||     |    |  --  |  _  ||   _|  -__|\n", "");
		printf("%10s|_____/|__||_____|   __||__||___._|___  |    |___|___||_____||__|__|__||__||__|__|    |_______|_____|___  ||__||__|__|    |_____/|___._||____|_____|\n", "");
		printf("%10s                 |__|             |_____|                                                           |_____|                                         \n", "");


		printf("\n\n\t%35s\n", "ADMIN LOGIN DATE");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("\t%-12c%-15s%-11c%-14s%5c\n", 186, "Date", 186, "Time", 186);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

		fread(&loginDate, sizeof(struct Date2), 1, fp1);
		while (!feof(fp1))
		{
			printf("\t%-7c%0d - %02d - %02d%6s%c%8s%02d:%02d:%02d%13c\n", 186, loginDate.year, loginDate.month, loginDate.day, "", 186, "", loginDate.hour, loginDate.minute, loginDate.second, 186);
			printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

			fread(&loginDate, sizeof(struct Date2), 1, fp1);
		}


		printf("\n\tBack to main Page (M) or Exit Program (E) : ");
		rewind(stdin);
		scanf("%c", &ans);

		if (toupper(ans) == 'M') {
			system("CLS");
			menu2();
		}
		else if (toupper(ans) == 'E') {
			exit(-1);
		}



	}

	fclose(fp1);
	fclose(fp);
}

void menu2() {
	int choice;

	printf("\n\n");
	printf("%13s ________         __                                 _______             _______ _______ ______ _______ ______      _______ __          ___   ___ \n", "");
	printf("%13s|  |  |  |.-----.|  |.----.-----.--------.-----.    |_     _|.-----.    |_     _|   _   |   __ \\   |   |      |    |     __|  |_.---.-.'  _|.'  _|\n", "");
	printf("%13s|  |  |  ||  -__||  ||  __|  _  |        |  -__|      |   |  |  _  |      |   | |       |      <   |   |   ---|    |__     |   _|  _  |   _||   _|\n", "");
	printf("%13s|________||_____||__||____|_____|__|__|__|_____|      |___|  |_____|      |___| |___|___|___|__|_______|______|    |_______|____|___._|__|  |__|  \n", "");
	printf("\n\n\n");

	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 183);
	printf("\t\t\t%c   1. Add Staff%16c\n", 186, 186);
	printf("\t\t\t%c   2. Search Staff%13c\n", 186, 186);
	printf("\t\t\t%c   3. Modify Staff Details%5c\n", 186, 186);
	printf("\t\t\t%c   4. Display Record%11c\n", 186, 186);
	printf("\t\t\t%c   5. Exit Programme%11c\n", 186, 186);
	printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 211, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 189);
	do {
		printf("\t\t\tEnter your choice > ");
		scanf("%d", &choice);
		rewind(stdin);

		printf("\n");
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
			printf("%56s", "+=========================+\n");
			printf("%29s", "|");
			BoldRed();
			printf("    Input is not valid   ");
			Reset();
			printf("|\n");
			printf("%56s", "+=========================+\n");
			printf("\n");
		}

	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
	system("CLS");
	switch (choice)
	{
	case 1:
		addStaff();
		break;
	case 2:
		searchStaff();
		break;
	case 3:
		modifyStaff();
		break;
	case 4:
		displayStaff();
		break;
	case 5:
		exit(0);
		break;
	}
}

void login() {
	char username[20] = { 0 }, option1 = "", choice = "";
	char password[20] = { 0 };

	printf("\n");

	printf("%11s _______    __          __       __       __              __   __                  _______ __          ___  ___      _______          __       __       \n", "");
	printf("%11s|   _   .--|  .--------|__.-----|__.-----|  |_.----.---.-|  |_|__.--.--.-----.    |     __|  |_.---.-.'  _.'  _|    |   |   .-----.--|  .--.--|  .-----.\n", "");
	printf("%11s|       |  _  |        |  |     |  |__ --|   _|   _|  _  |   _|  |  |  |  -__|    |__     |   _|  _  |   _|   _|    |       |  _  |  _  |  |  |  |  -__|\n", "");
	printf("%11s|___|___|_____|__|__|__|__|__|__|__|_____|____|__| |___._|____|__|\\___/|_____|    |_______|____|___._|__| |__|      |__|_|__|_____|_____|_____|__|_____|\n", "");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("\n%60s+============================================+\n", "");
	printf("%60s| Enter admin username and password to login |\n", "");
	printf("%60s+============================================+\n", "");
	printf("\n");
	do {
		printf("\t%81s", "Enter your username: ");
		scanf("%s", &username);
		rewind(stdin);

		if (strcmp(username, "Tarc") == 0) {

			do {
				printf("\t%81s", "Enter your password: ");
				scanf("%s", &password);
				rewind(stdin);

				if (strcmp(password, "Tarc") == 0) {
					SYSTEMTIME t;
					GetLocalTime(&t);

					FILE* fp;
					fp = fopen("loginDate.dat", "ab");
					if (fp == NULL)
					{
						printf("\tError opening file\n");
						exit(-1);
					}
					struct Date2 loginDate;
					loginDate.day = t.wDay;
					loginDate.month = t.wMonth;
					loginDate.year = t.wYear;
					loginDate.second = t.wSecond;
					loginDate.hour = t.wHour;
					loginDate.minute = t.wMinute;
					fwrite(&loginDate, sizeof(struct Date2), 1, fp);
					fclose(fp);
					//loading bar variable
					char a = 177, b = 219;
					int x;
					double y;

					printf("\n%76s", "Loading......\n");
					printf("%60s", "");

					//initial loading bar 
					for (int i = 0; i < 40; i++)
						printf("%c", a);

					//Set the cursor again starting 
					//point of loading bar 
					printf("\r");
					printf("%62s", "");

					//loading bar progress 
					for (int i = 0; i < 40; i++) {
						printf("%c", b);

						//stop for 1 second 
						Sleep(30);
					}
					printf(" 100%% \n");
					printf("\n");
					//animation text
					char text4[] = "                                                                        Login Successfully !!!";

					printf("\n");
					//animation text process
					for (x = 0; text4[x] != NULL; x++)
					{
						printf("%c", text4[x]);
						for (y = 0; y <= 7777777; y++)
						{
						}
					}
					printf("\n");
					system("CLS");
					menu2();

				}
				else {
					printf("\n\t\t\t\t\t\t%10s=====================================================", "");
					printf("\n\t\t\t\t\t\t%10sWrong password!!\n", "");
					printf("\t\t\t\t\t\t%10sDo you want to try again ? (Y = yes) (E = exit) > ", "");
					scanf("%c", &choice);
					rewind(stdin);
					printf("\t\t\t\t\t\t%10s=====================================================\n", "");
					if (toupper(choice) == 'E')
						exit(-1);
				}
			} while (toupper(choice) == 'Y');
		}
		else {
			printf("\n\t\t\t\t\t\t%10s=====================================================\n", "");
			printf("\t\t\t\t\t\t%10sUser doesn't exist!!\n", "");
			printf("\t\t\t\t\t\t%10sDo you want to try again ? (Y = yes) (E = exit) > ", "");
			scanf("%c", &option1);
			rewind(stdin);
			printf("\t\t\t\t\t\t%10s=====================================================\n", "");

			if (toupper(option1) == 'E')
				exit(-1);
		}
	} while (toupper(option1) == 'Y');
}

void administrativeStaff()
{
	login();
}

