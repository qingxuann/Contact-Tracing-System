#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "main.h"
#pragma warning (disable:4996)
#pragma warning (disable:6031)

int visitorAdded = 1;
typedef struct {
    char name[35];
    char IC[20];
    char contact[15];
    char mask;
    char sanitize;
    double temp;
}Visitor;

typedef struct {
    Visitor visitor;
    int id;
    char venue[30];
    int day, month, year, hour, min;
}visitorDt;

void addVisitor() {
    visitorDt VisitorDetails;
    char decision;
    int record = 0;
    FILE* fptr;
    fptr = fopen("visitor.txt", "a");
    if (fptr == NULL)
    {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("%70s  \n", "Add Visitor Information ");
    printf("--------------------------------------------------------------------------------------------------------\n");


    do {
        record++;
        rewind(stdin);
        VisitorDetails.id = visitorAdded;
        printf("\n---------------------\n");
        printf("Please enter your: \n");
        printf("---------------------\n");

        printf("Name :");
        printf("(eg: Johnny Tan / Tan Mei Mei) \n");
        scanf("%[^\n]", &VisitorDetails.visitor.name);
        rewind(stdin);

        printf("IC number :");
        printf("(eg 010101-01-0101) \n");
        scanf("%[^\n]", &VisitorDetails.visitor.IC);
        rewind(stdin);

        printf("Phone number :");
        printf("(eg: 012-3456789) \n");
        scanf("%[^\n]", &VisitorDetails.visitor.contact);
        rewind(stdin);

        printf("Temperature :");
        printf("(eg: 36.7) \n");
        scanf("%lf", &VisitorDetails.visitor.temp);
        rewind(stdin);

        printf("Last venue visited :");
        printf("(eg: canteen / school / carpark) \n");
        scanf("%[^\n]", &VisitorDetails.venue);
        rewind(stdin);

        printf("Please enter the sanitize (y-yes , n-no): ");
        scanf("%c", &VisitorDetails.visitor.sanitize);
        rewind(stdin);

        while (VisitorDetails.visitor.sanitize != 'y' && VisitorDetails.visitor.sanitize != 'n')
        {
            rewind(stdin);
            printf("Incorrect input! Please enter again. \n");
            printf("Please enter the sanitize (y-yes , n-no): ");
            scanf("%c", &VisitorDetails.visitor.sanitize);
            rewind(stdin);
        }
        rewind(stdin);
        printf("Please enter the mask (y-yes , n-no): ");
        scanf("%c", &VisitorDetails.visitor.mask);
        rewind(stdin);
        while (VisitorDetails.visitor.mask != 'y' && VisitorDetails.visitor.mask != 'n') {
            printf("Incorrect input! Please enter again. \n");
            printf("Please enter the mask (y-yes , n-no): ");
            scanf("%c", &VisitorDetails.visitor.mask);
            rewind(stdin);
        }
        rewind(stdin);

        printf("\n---------------------\n");
        printf("Please enter the date \n");
        printf("---------------------\n");

        printf("Day  :");
        scanf("%02d", &VisitorDetails.day);
        rewind(stdin);
        while (VisitorDetails.day < 1 || VisitorDetails.day >31)
        {
            printf("Incorrect input! Please enter a day between 1 - 31. \n");
            printf("Day  :");
            scanf("%02d", &VisitorDetails.day);
            rewind(stdin);
        }
        printf("Month :");
        scanf("%02d", &VisitorDetails.month);
        rewind(stdin);
        while (VisitorDetails.month < 1 || VisitorDetails.month > 12)
        {
            printf("Incorrect input! Please enter a month between 1 - 12. \n");
            printf("Month  :");
            scanf("%02d", &VisitorDetails.month);
            rewind(stdin);
        }
        VisitorDetails.year = 2021;
        printf("%02d/%02d/%d\n", VisitorDetails.day, VisitorDetails.month, VisitorDetails.year);

        printf("\n---------------------\n");
        printf("Please enter the time \n");
        printf("---------------------\n");
        printf("Hour  :");
        scanf("%d", &VisitorDetails.hour);
        rewind(stdin);
        while (VisitorDetails.hour <= 0 || VisitorDetails.hour > 24) {
            printf("Incorrect input! Please enter a time between 1 - 24. \n");
            printf("Hour  :");
            scanf("%d", &VisitorDetails.hour);
            rewind(stdin);
        }

        printf("Minutes :");
        scanf("%d", &VisitorDetails.min);
        rewind(stdin);
        while (VisitorDetails.min < 0 || VisitorDetails.min > 59)
        {
            printf("Incorrect input! Please enter a minute between 0 - 59. \n");
            printf("Minutes :");
            scanf("%d", &VisitorDetails.min);
            rewind(stdin);
        }
        printf("%d:%d \n", VisitorDetails.hour, VisitorDetails.min);

        printf("Do you want to add another visitor? (y-yes , n-no) :");
        scanf("%c", &decision);
        rewind(stdin);

        fprintf(fptr, "%d|%s|%s|%s|%lf|%c|%d-%d-%d|%s|%d:%d|%c", VisitorDetails.id, VisitorDetails.visitor.name, VisitorDetails.visitor.IC, VisitorDetails.visitor.contact,
            VisitorDetails.visitor.temp, VisitorDetails.visitor.sanitize, VisitorDetails.day, VisitorDetails.month, VisitorDetails.year, VisitorDetails.venue, VisitorDetails.hour,
            VisitorDetails.min, VisitorDetails.visitor.mask);

        visitorAdded++;
    } while (toupper(decision) != 'N');
    printf("%d Record sucessfully added.\n\n", record);
    fclose(fptr);
}

void displayVisitor() {
    visitorDt VisitorDetails;

    FILE* fptr2;
    fptr2 = fopen("visitor.txt", "r");

    if (fptr2 == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }

    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("%70s  \n", "Visitor Information Module ");
    printf("------------------------------------------------------------------------------------------------------------\n");

    printf("|%s|%-15s|%-15s|%-11s|%-12s|%-14s|%-10s|%-5s|%-5s|%-8s|\n",
        "ID", "Name", "IC Number", "Contact", "Temperature", "Last Venue", " Date", "Time", "Mask", "Sanitize");

    while (fscanf(fptr2, "%d|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d:%d|%c|\n", &VisitorDetails.id, VisitorDetails.visitor.name, VisitorDetails.visitor.IC, VisitorDetails.visitor.contact, &VisitorDetails.visitor.temp,
        &VisitorDetails.visitor.sanitize, &VisitorDetails.day, &VisitorDetails.month, &VisitorDetails.year, VisitorDetails.venue,
        &VisitorDetails.hour, &VisitorDetails.min, &VisitorDetails.visitor.mask) != EOF)
    {
        printf("|%2d|%-15s|%-15s|%-11s|%12.2f|%-14s|%02d/%02d/%02d|%02d:%02d|%-5c|%-8c|\n", VisitorDetails.id, VisitorDetails.visitor.name, VisitorDetails.visitor.IC, VisitorDetails.visitor.contact, VisitorDetails.visitor.temp, VisitorDetails.venue, VisitorDetails.day, VisitorDetails.month, VisitorDetails.year,
            VisitorDetails.hour, VisitorDetails.min, VisitorDetails.visitor.mask, VisitorDetails.visitor.sanitize);
    }
    fclose(fptr2);
}

void modifyVisitor() {
    visitorDt VisitorDetails[50];
    int i = 0, x, y;
    FILE* fptr;
    int editId;
    int recordsFound = 1;
    fptr = fopen("visitor.txt", "r");

    if (fptr == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }
    while (fscanf(fptr, "%d|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d:%d|%c|\n", &VisitorDetails[i].id, VisitorDetails[i].visitor.name, VisitorDetails[i].visitor.IC, VisitorDetails[i].visitor.contact, &VisitorDetails[i].visitor.temp,
        &VisitorDetails[i].visitor.sanitize, &VisitorDetails[i].day, &VisitorDetails[i].month, &VisitorDetails[i].year, VisitorDetails[i].venue,
        &VisitorDetails[i].hour, &VisitorDetails[i].min, &VisitorDetails[i].visitor.mask) != EOF)
    {

        i++;
    }
    printf("---------- Modify Visitor Record ---------- \n");
    printf("Please enter the ID you want to modify (eg: 1/2/3/4): ");
    scanf("%d", &editId);
    printf("\n");
    for (x = 0; x < i; x++) {

        if (editId == VisitorDetails[x].id) {
            recordsFound = 0;
            VisitorDetails[x].id = x + 1;
            rewind(stdin);

            printf("\n---------------------\n");
            printf("Please enter your: \n");
            printf("---------------------\n");

            printf("Name :");
            printf("(eg: Johnny Tan / Tan Mei Mei) \n");
            scanf("%[^\n]", &VisitorDetails[x].visitor.name);
            rewind(stdin);

            printf("IC number :");
            printf("(eg 010101-01-0101) \n");
            scanf("%[^\n]", &VisitorDetails[x].visitor.IC);
            rewind(stdin);

            printf("Phone number :");
            printf("(eg: 012-3456789) \n");
            scanf("%[^\n]", &VisitorDetails[x].visitor.contact);
            rewind(stdin);

            printf("Temperature :");
            printf("(eg: 36.7) \n");
            scanf("%lf", &VisitorDetails[x].visitor.temp);
            rewind(stdin);

            printf("Last venue visited :");
            printf("(eg: canteen / school / carpark) \n");
            scanf("%[^\n]", &VisitorDetails[x].venue);
            rewind(stdin);

            printf("Please enter the sanitize (y-yes , n-no): ");
            scanf("%c", &VisitorDetails[x].visitor.sanitize);
            rewind(stdin);
            while (VisitorDetails[x].visitor.sanitize != 'y' && VisitorDetails[x].visitor.sanitize != 'n')
            {
                printf("Incorrect input! Please enter again. \n");
                printf("Please enter the sanitize (y-yes , n-no): ");
                scanf("%c", &VisitorDetails[x].visitor.sanitize);
                rewind(stdin);
            }
            printf("Please enter the mask (y-yes , n-no): ");
            scanf("%c", &VisitorDetails[x].visitor.mask);
            rewind(stdin);
            while (VisitorDetails[x].visitor.mask != 'y' && VisitorDetails[x].visitor.mask != 'n')
            {
                printf("Incorrect input! Please enter again. \n");
                printf("Please enter the mask (y-yes , n-no): ");
                scanf("%c", &VisitorDetails[x].visitor.mask);
                rewind(stdin);
            }

            printf("\n---------------------\n");
            printf("Please enter the date \n");
            printf("---------------------\n");
            printf("Day : ");
            scanf("%02d", &VisitorDetails[x].day);
            rewind(stdin);
            while (VisitorDetails[x].day < 1 || VisitorDetails[x].day >31)
            {
                printf("Incorrect input! Please enter a day between 1 - 31. \n");
                printf("Day :");
                scanf("%02d", &VisitorDetails[x].day);
                rewind(stdin);
            }
            printf("Month :");
            scanf("%02d", &VisitorDetails[x].month);
            rewind(stdin);
            while (VisitorDetails[x].month < 1 || VisitorDetails[x].month >12)
            {
                printf("Incorrect input! Please enter a month between 1 - 12. \n");
                printf("Month  :");
                scanf("%02d", &VisitorDetails[x].month);
                rewind(stdin);
            }
            VisitorDetails[x].year = 2021;
            printf("%02d/%02d/%d\n", VisitorDetails[x].day, VisitorDetails[x].month, VisitorDetails[x].year);


            printf("\n---------------------\n");
            printf("Please enter the time \n");
            printf("---------------------\n");
            printf("Hour :");
            scanf("%d", &VisitorDetails[x].hour);
            rewind(stdin);
            while (VisitorDetails[x].hour <= 0 || VisitorDetails[x].hour > 24) {
                printf("Incorrect input! Please enter a time between 1 - 24. \n");
                printf("Hour :");
                scanf("%d", &VisitorDetails[x].hour);
                rewind(stdin);
            }

            printf("Minutes :");
            scanf("%d", &VisitorDetails[x].min);
            rewind(stdin);
            while (VisitorDetails[x].min < 0 || VisitorDetails[x].min > 59)
            {
                printf("Incorrect input! Please enter a minute between 0 - 59. \n");
                printf("Minutes :");
                scanf("%d", &VisitorDetails[x].min);
                rewind(stdin);
            }
            printf("%d:%d \n", VisitorDetails[x].hour, VisitorDetails[x].min);
        }
    }
    if (recordsFound == 1) {
        printf("Record Not found");
    }
    FILE* fptr4;
    fptr4 = fopen("visitor.txt", "w");

    if (fptr4 == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }
    for (y = 0; y < i; y++) {
        fprintf(fptr4, "%d|%s|%s|%s|%lf|%c|%d-%d-%d|%s|%d:%d|%c", VisitorDetails[y].id, VisitorDetails[y].visitor.name, VisitorDetails[y].visitor.IC, VisitorDetails[y].visitor.contact,
            VisitorDetails[y].visitor.temp, VisitorDetails[y].visitor.sanitize, VisitorDetails[y].day, VisitorDetails[y].month, VisitorDetails[y].year, VisitorDetails[y].venue, VisitorDetails[y].hour,
            VisitorDetails[y].min, VisitorDetails[y].visitor.mask);
    }
    fclose(fptr4);
}

void searchVisitor() {
    visitorDt VisitorDetails[50];
    int i = 0, x;
    FILE* fptr;
    int searchId;
    int searchFound = 1;
    fptr = fopen("visitor.txt", "r");

    if (fptr == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }
    while (fscanf(fptr, "%d|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d:%d|%c|\n", &VisitorDetails[i].id, VisitorDetails[i].visitor.name, VisitorDetails[i].visitor.IC, VisitorDetails[i].visitor.contact, &VisitorDetails[i].visitor.temp,
        &VisitorDetails[i].visitor.sanitize, &VisitorDetails[i].day, &VisitorDetails[i].month, &VisitorDetails[i].year, VisitorDetails[i].venue,
        &VisitorDetails[i].hour, &VisitorDetails[i].min, &VisitorDetails[i].visitor.mask) != EOF)
    {

        i++;
    }
    printf("---------- Search Visitor Record ---------- \n");
    printf("Please enter the ID you want to search: ");
    scanf("%d", &searchId);
    rewind(stdin);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("|%s|%-15s|%-15s|%-11s|%-12s|%-14s|%-10s|%-5s|%-5s|%-8s|\n",
        "ID", "Name", "IC Number", "Contact", "Temperature", "Last Venue", " Date", "Time", "Mask", "Sanitize");
    for (x = 0; x < i; x++) {
        if (searchId == VisitorDetails[x].id) {
            printf("|%2d|%-15s|%-15s|%-11s|%12.2f|%-14s|%02d/%02d/%02d|%02d:%02d|%-5c|%-8c|\n", VisitorDetails[x].id, VisitorDetails[x].visitor.name, VisitorDetails[x].visitor.IC, VisitorDetails[x].visitor.contact, VisitorDetails[x].visitor.temp, VisitorDetails[x].venue, VisitorDetails[x].day, VisitorDetails[x].month, VisitorDetails[x].year,
                VisitorDetails[x].hour, VisitorDetails[x].min, VisitorDetails[x].visitor.mask, VisitorDetails[x].visitor.sanitize);
            searchFound = 0;
        }
    }
    if (searchFound == 1) {
        printf("No Visitor found");
    }
}
void visitorReport() {
    visitorDt VisitorDetails[50];
    int i = 0, x;
    FILE* fptr;
    int searchId;
    int searchFound = 1;
    int sanitizeY = 0, sanitizeN = 0, maskY = 0, maskN = 0, monthJan = 0, monthFeb = 0, monthMar = 0, monthApr = 0, monthMay = 0, monthJun = 0, monthJul = 0, monthAug = 0, monthSep = 0;
    int monthOct = 0, monthNov = 0, monthDec = 0, highTemp = 0, lowTemp = 0;
    fptr = fopen("visitor.txt", "r");

    if (fptr == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }
    while (fscanf(fptr, "%d|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d:%d|%c|\n", &VisitorDetails[i].id, VisitorDetails[i].visitor.name, VisitorDetails[i].visitor.IC, VisitorDetails[i].visitor.contact, &VisitorDetails[i].visitor.temp,
        &VisitorDetails[i].visitor.sanitize, &VisitorDetails[i].day, &VisitorDetails[i].month, &VisitorDetails[i].year, VisitorDetails[i].venue,
        &VisitorDetails[i].hour, &VisitorDetails[i].min, &VisitorDetails[i].visitor.mask) != EOF)
    {
        i++;
    }

    for (x = 0; x < i; x++) {

        if (VisitorDetails[x].visitor.sanitize == 'y' || VisitorDetails[x].visitor.sanitize == 'Y') {
            sanitizeY++;

        }
        else {
            sanitizeN++;

        }

        if (VisitorDetails[x].visitor.mask == 'y' || VisitorDetails[x].visitor.mask == 'Y') {
            maskY++;

        }
        else {
            maskN++;

        }


        if (VisitorDetails[x].month == 1) {
            monthJan++;

        }
        else if (VisitorDetails[x].month == 2) {
            monthFeb++;

        }
        else if (VisitorDetails[x].month == 3) {
            monthMar++;

        }
        else if (VisitorDetails[x].month == 4) {
            monthApr++;

        }
        else if (VisitorDetails[x].month == 5) {
            monthMay++;

        }
        else if (VisitorDetails[x].month == 6) {
            monthJun++;

        }
        else if (VisitorDetails[x].month == 7) {
            monthJul++;

        }
        else if (VisitorDetails[x].month == 8) {
            monthAug++;

        }
        else if (VisitorDetails[x].month == 9) {
            monthSep++;

        }
        else if (VisitorDetails[x].month == 10) {
            monthOct++;

        }
        else if (VisitorDetails[x].month == 11) {
            monthNov++;

        }
        else if (VisitorDetails[x].month == 12) {
            monthDec++;

        }

        if (VisitorDetails[x].visitor.temp >= 37.40) {
            highTemp++;
        }
        else {
            lowTemp++;
        }
    }
    printf("---------- Visitor Information Report ----------\n");

    printf("\n---------------------\n");
    printf("Temperature: \n");
    printf("---------------------\n");;
    printf("37.5 or higher: %d\n", highTemp);
    printf("Below 37.5: %d\n", lowTemp);

    printf("\n---------------------\n");
    printf("Sanitize: \n");
    printf("---------------------\n");;
    printf("Yes: %d\n", sanitizeY);
    printf("No: %d\n", sanitizeN);

    printf("\n---------------------\n");
    printf("Mask: \n");
    printf("---------------------\n");
    printf("Yes: %d\n", maskY);
    printf("No: %d\n", maskN);

    printf("\n---------------------------\n");
    printf("Total Visitor for each month: \n");
    printf("-----------------------------\n");
    printf("January: %d\n", monthJan);
    printf("February: %d\n", monthFeb);
    printf("March: %d\n", monthMar);
    printf("April: %d\n", monthApr);
    printf("May: %d\n", monthMay);
    printf("June: %d\n", monthJun);
    printf("July: %d\n", monthJul);
    printf("August: %d\n", monthAug);
    printf("September: %d\n", monthSep);
    printf("October: %d\n", monthOct);
    printf("November: %d\n", monthNov);
    printf("December: %d\n", monthDec);
}

void deleteVisitor()
{
    visitorDt VisitorDetails[50];
    int i = 0, x, y, z;
    FILE* fptr;
    int deleteId;
    int deleteFound = 1;
    fptr = fopen("visitor.txt", "r");

    if (fptr == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }
    while (fscanf(fptr, "%d|%[^\|]|%[^\|]|%[^\|]|%lf|%c|%d-%d-%d|%[^\|]|%d:%d|%c|\n", &VisitorDetails[i].id, VisitorDetails[i].visitor.name, VisitorDetails[i].visitor.IC, VisitorDetails[i].visitor.contact, &VisitorDetails[i].visitor.temp,
        &VisitorDetails[i].visitor.sanitize, &VisitorDetails[i].day, &VisitorDetails[i].month, &VisitorDetails[i].year, VisitorDetails[i].venue,
        &VisitorDetails[i].hour, &VisitorDetails[i].min, &VisitorDetails[i].visitor.mask) != EOF)
    {
        i++;
    }
    printf("---------- Delete Visitor Record ---------- \n");
    printf("\n");
    printf("Please enter the ID you want to delete: ");

    scanf("%d", &deleteId);
    rewind(stdin);
    for (x = 0; x < i; x++)
    {
        if (deleteId == VisitorDetails[x].id)
        {
            deleteFound = 0;
            visitorAdded--;
            for (z = deleteId - 1; z < i - 1; z++) {
                \
                    VisitorDetails[z] = VisitorDetails[z + 1];
                VisitorDetails[z].id = VisitorDetails[z].id - 1;
            }
        }
    }
    if (deleteFound == 1) {
        printf("This visitor is not found from the system \n");
        printf("\n");
    }
    FILE* fptr3;
    fptr3 = fopen("visitor.txt", "w");
    if (fptr3 == NULL) {
        printf("Unable to open the visitor.txt file!");
        exit(-1);
    }
    for (y = 0; y < i - 1; y++) {
        fprintf(fptr3, "%d|%s|%s|%s|%lf|%c|%d-%d-%d|%s|%d:%d|%c", VisitorDetails[y].id, VisitorDetails[y].visitor.name, VisitorDetails[y].visitor.IC, VisitorDetails[y].visitor.contact,
            VisitorDetails[y].visitor.temp, VisitorDetails[y].visitor.sanitize, VisitorDetails[y].day, VisitorDetails[y].month, VisitorDetails[y].year, VisitorDetails[y].venue, VisitorDetails[y].hour,
            VisitorDetails[y].min, VisitorDetails[y].visitor.mask);
    }
    fclose(fptr3);

}
void visitorInformation() {
    system("cls");
    int choice;

    do {
        system("cls");
        printf("\n===============\n");
        printf("VISITOR MENU");
        printf("\n===============\n");
        printf("1. Add Visitor\n2. Display Visitor\n");
        printf("3. Edit Visitor\n4. Display Sumary Record\n5. Search Visitor\n6. Delete Visitor\n7. Exit");
        printf("\nYour menu choice :");
        scanf("%d", &choice);
        rewind(stdin);

        switch (choice) {
        case 1:
            addVisitor();
            system("pause");
            break;
        case 2:
            displayVisitor();
            system("pause");
            break;
        case 3:
            modifyVisitor();
            system("pause");
            break;
        case 4:
            visitorReport();
            system("pause");
            break;
        case 5:
            searchVisitor();
            system("pause");
            break;
        case 6:
            deleteVisitor();
            system("pause");
            break;
        }
    } while (choice != 7);

}
