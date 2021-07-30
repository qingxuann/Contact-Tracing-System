#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "main.h"

#pragma warning (disable:4996)
#pragma warning (disable:6031)

struct Date {
	int year;
	int month;
	int day;
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

void main() {
	int choice, select = -1, option, pCount = 0, i, correct = 0, correct1 = 0;
	char staffID[20] = { 0 }, option1 = "", choice1 = "";
	char password[20] = { 0 };
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
	fclose(fp);
	printf("%11s _    _        _                                _____        _____  ___  ______  _   _  _____     _____        _         _      _                    \n", "");
	printf("%11s| |  | |      | |                              |_   _|      |_   _|/ _ \\ | ___ \\| | | |/  __ \\   /  ___|      (_)       | |    | |                   \n", "");
	printf("%11s| |  | |  ___ | |  ___  ___   _ __ ___    ___    | |  ___     | | / /_\\ \\| |_/ /| | | || /  \\/   \\ `--.   ___  _   __ _ | |__  | |_  ___  _ __  __ _ \n", "");
	printf("%11s| |/\\| | / _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\   | | / _ \\    | | |  _  ||    / | | | || |        `--. \\ / _ \\| | / _` || '_ \\ | __|/ _ \\| '__|/ _` |\n", "");
	printf("%11s\\  /\\  /|  __/| || (__| (_) || | | | | ||  __/   | || (_) |   | | | | | || |\\ \\ | |_| || \\__/\\   /\\__/ /|  __/| || (_| || | | || |_|  __/| |  | (_| |\n", "");
	printf("%11s \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|   \\_/ \\___/    \\_/ \\_| |_/\\_| \\_| \\___/  \\____/   \\____/  \\___|| | \\__,_||_| |_| \\__|\\___||_|   \\__,_|\n", "");
	printf("%11s                                                                                                             _/ |                                    \n", "");
	printf("%11s                                                                                                            |__/                                     \n", "");
	printf("============================================================================================================================================================================\n\n\n");
	do {
		choice1 = 'N';
		select = 1;
		printf("%60sWho are you ? ( 1-staff ,  2-visitor ) > ", "");
		scanf("%d", &option);

		if (option == 1) {

			printf("\n%60s+===========================================+\n", "");
			printf("%60s| Enter your Staff ID and password to login |\n", "");
			printf("%60s+===========================================+\n", "");
			printf("\n");
			do {
				option1 = 'N';
				printf("\t%81s", "Enter your Staff ID: ");
				scanf("%s", &staffID);
				rewind(stdin);
				for (i = 0; i < pCount; i++)
				{
					if (strcmp(staff[i].id, staffID) == 0)
						correct = 1;
				}
				if (correct == 1) {

					do {
						choice1 = 'N';
						printf("\t%81s", "Enter your password: ");
						scanf("%s", &password);
						rewind(stdin);
						for (i = 0; i < pCount; i++)
						{
							if (strcmp(staff[i].password, password) == 0)
								correct1 = 1;
						}
						if (correct1 == 1)
						{
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


						}
						else {
							printf("\n\t\t\t\t\t\t%10s=====================================================", "");
							printf("\n\t\t\t\t\t\t%10sWrong password!!\n", "");
							printf("\t\t\t\t\t\t%10sDo you want to try again ? (Y = yes) (E = exit) > ", "");
							scanf("%c", &choice1);
							rewind(stdin);
							printf("\t\t\t\t\t\t%10s=====================================================\n", "");
							if (toupper(choice1) == 'E')
								exit(-1);
						}
					} while (toupper(choice1) == 'Y');
				}
				else {
					printf("\n\t\t\t\t\t\t%10s=====================================================\n", "");
					printf("\t\t\t\t\t\t%10sStaff ID doesn't exist!!\n", "");
					printf("\t\t\t\t\t\t%10sDo you want to try again ? (Y = yes) (E = exit) > ", "");
					scanf("%c", &option1);
					rewind(stdin);
					printf("\t\t\t\t\t\t%10s=====================================================\n", "");

					if (toupper(option1) == 'E')
						exit(-1);
				}
			} while (toupper(option1) == 'Y');
			system("CLS");
			printf("\n\n");
			printf("%11s _    _        _                                _____        _____  ___  ______  _   _  _____     _____        _         _      _                    \n", "");
			printf("%11s| |  | |      | |                              |_   _|      |_   _|/ _ \\ | ___ \\| | | |/  __ \\   /  ___|      (_)       | |    | |                   \n", "");
			printf("%11s| |  | |  ___ | |  ___  ___   _ __ ___    ___    | |  ___     | | / /_\\ \\| |_/ /| | | || /  \\/   \\ `--.   ___  _   __ _ | |__  | |_  ___  _ __  __ _ \n", "");
			printf("%11s| |/\\| | / _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\   | | / _ \\    | | |  _  ||    / | | | || |        `--. \\ / _ \\| | / _` || '_ \\ | __|/ _ \\| '__|/ _` |\n", "");
			printf("%11s\\  /\\  /|  __/| || (__| (_) || | | | | ||  __/   | || (_) |   | | | | | || |\\ \\ | |_| || \\__/\\   /\\__/ /|  __/| || (_| || | | || |_|  __/| |  | (_| |\n", "");
			printf("%11s \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|   \\_/ \\___/    \\_/ \\_| |_/\\_| \\_| \\___/  \\____/   \\____/  \\___|| | \\__,_||_| |_| \\__|\\___||_|   \\__,_|\n", "");
			printf("%11s                                                                                                             _/ |                                    \n", "");
			printf("%11s                                                                                                            |__/                                     \n", "");
			printf("============================================================================================================================================================================\n\n\n");
			printf("\t\t\tPlease choose the number to continue. \n");
			printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 183);
			printf("\t\t\t%c   1. Administrative Staff %9c\n", 186, 186);
			printf("\t\t\t%c   2. Sanitization records %9c\n", 186, 186);
			printf("\t\t\t%c   3. Visits and Exits Module%7c\n", 186, 186);
			printf("\t\t\t%c   4. Exit Programme%16c\n", 186, 186);
			printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 211, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 189);
			do {
				printf("\t\t\tEnter your choice > ");
				scanf("%d", &choice);
				rewind(stdin);
				printf("\n");
				if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
					printf("%54s", "+==========================+\n");
					printf("%26s", "|");
					BoldRed();
					printf("    Number is not valid   ");
					Reset();
					printf("|\n");
					printf("%54s", "+==========================+\n");
					printf("\n");
				}

			} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
			system("CLS");

			switch (choice)
			{
			case 1:
				administrativeStaff();
				break;
			case 2:
				sanitizationRecord();
				break;
			case 3:
				visitAndExit();
				break;
			case 4:
				exit(0);
				break;
			}
		}
		else if (option == 2) {
			select = 1;
			system("CLS");
			printf("\n\n");
			printf("%11s _    _        _                                _____        _____  ___  ______  _   _  _____     _____        _         _      _                    \n", "");
			printf("%11s| |  | |      | |                              |_   _|      |_   _|/ _ \\ | ___ \\| | | |/  __ \\   /  ___|      (_)       | |    | |                   \n", "");
			printf("%11s| |  | |  ___ | |  ___  ___   _ __ ___    ___    | |  ___     | | / /_\\ \\| |_/ /| | | || /  \\/   \\ `--.   ___  _   __ _ | |__  | |_  ___  _ __  __ _ \n", "");
			printf("%11s| |/\\| | / _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\   | | / _ \\    | | |  _  ||    / | | | || |        `--. \\ / _ \\| | / _` || '_ \\ | __|/ _ \\| '__|/ _` |\n", "");
			printf("%11s\\  /\\  /|  __/| || (__| (_) || | | | | ||  __/   | || (_) |   | | | | | || |\\ \\ | |_| || \\__/\\   /\\__/ /|  __/| || (_| || | | || |_|  __/| |  | (_| |\n", "");
			printf("%11s \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|   \\_/ \\___/    \\_/ \\_| |_/\\_| \\_| \\___/  \\____/   \\____/  \\___|| | \\__,_||_| |_| \\__|\\___||_|   \\__,_|\n", "");
			printf("%11s                                                                                                             _/ |                                    \n", "");
			printf("%11s                                                                                                            |__/                                     \n", "");
			printf("============================================================================================================================================================================\n\n\n");
			printf("\t\t\tPlease choose the number to continue. \n");
			printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 183);
			printf("\t\t\t%c   1. Visitor Information %10c\n", 186, 186);
			printf("\t\t\t%c   2. Visits and Exits Module%7c\n", 186, 186);
			printf("\t\t\t%c   3. Exit Programme%16c\n", 186, 186);
			printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 211, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 189);
			do {
				printf("\t\t\tEnter your choice > ");
				scanf("%d", &choice);
				rewind(stdin);
				printf("\n");
				if (choice != 1 && choice != 2 && choice != 3) {
					printf("%54s", "+==========================+\n");
					printf("%26s", "|");
					BoldRed();
					printf("    Number is not valid   ");
					Reset();
					printf("|\n");
					printf("%54s", "+==========================+\n");
					printf("\n");
				}

			} while (choice != 1 && choice != 2 && choice != 3);
			system("CLS");

			switch (choice)
			{
			case 1:
				visitorInformation();
				break;
			case 2:
				visitAndExit();
				break;
			case 3:
				exit(0);
				break;
			}

		}
		else {
			printf("\n");
			printf("%95s", "+=========================+\n");
			printf("%68s", "|");
			BoldRed();
			printf("    Input is not valid   ");
			Reset();
			printf("|\n");
			printf("%95s", "+=========================+\n");
			printf("\n");
			select = -1;
		}
	} while (select == -1);


	system("pause");
}

