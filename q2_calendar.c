#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDays(int DAYSIZE) {
    int day = 0, extraDaySpaces = 0;
    char* dayArr[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    //prints DAYSIZE characters worth of each day, adds extraDaySpaces worth of spaces afterwards
    for (day = 0; day < 7; day++) {
        extraDaySpaces = 0;
        if ((strlen(dayArr[day])) < DAYSIZE) {
            extraDaySpaces = DAYSIZE - strlen(dayArr[day]);
        }
        printf("| %.*s%*s ", DAYSIZE, *(dayArr+day), extraDaySpaces, "");
    }

    printf("|\n"); //Print final pipe outside of loop
}

void printDates(int DAYSIZE, int FIRSTDAY) {
    int i = 0, j = 0, date = 1, totalSize = 0;

    //prints empty cells before FIRSTDAY
    for (i = 0; i < (FIRSTDAY - 1); i++) {
        printf("| %*s ", DAYSIZE, "");
        totalSize++;
    }

    for (i = FIRSTDAY; i < 8; i++) {
        printf("| %d%*s", date++, DAYSIZE, "");
        totalSize++;
    }

    printf("|\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            if (date > 30)
                break;
            printf("| %-*d ", DAYSIZE, date++);
            totalSize++;
        }
        if (date > 30)
            break;
        printf("|\n");
    }

    for (i = totalSize; i < 35; i++) {
        printf("| %*s ", DAYSIZE, "");
        totalSize++;
    }

    if (FIRSTDAY < 7)
        printf("|\n");

    if (FIRSTDAY == 7) {
        for (i = totalSize; i < 42; i++) {
            printf("| %*s ", DAYSIZE, "");
        }
        printf("|\n");
    }

}

void printMonth(int DAYSIZE, char* month) {
    int extraSpace = 0, lettersInMonth = 0, lineSize = 0;
    lineSize = ((DAYSIZE+3)*7 + 1);
    lettersInMonth = strlen(month);
    extraSpace = (lineSize - (lettersInMonth + 2)); //Total line size minus pipes and month size
    printf("|%*s%*s", (extraSpace/2 + lettersInMonth), month, (extraSpace/2), "");
    if (extraSpace % 2 != 0) //Handles int devision
        printf(" |\n");
    else
        printf("|\n");
}

void printDashedLine(int DAYSIZE) {
    int i = 0, linesize = 0;
    linesize = ((DAYSIZE+3)*7 - 2); //-2 to account for two pipes
    printf("|");
    for (i = 0; i <= linesize; i++) {
        printf("-");
    }
    printf("|\n");
}

int main(int argc, char *argv[]) {
/*    if (argc != 3) {
        printf("Error: Please submit exactly two int arguments");
        return(-1);
    }
*/
    int DAYSIZE = 8;//atoi(argv[1]);
    int FIRSTDAY = 1;//atoi(argv[2]);
    if (DAYSIZE < 2) {
        printf("ERROR: Cannot print days smaller than size 2.");
        return(-1);
    }
    if (FIRSTDAY < 1 || FIRSTDAY > 7) {
        printf("ERROR: The first day of the week must be between 1 and 7.");
        return(-1);
    }

    char* monthArr[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month = 0, i = 0;

    for (month = 0; month < 12; month++) {
        printDashedLine(DAYSIZE);
        printDays(DAYSIZE);
        printDashedLine(DAYSIZE);
        printMonth(DAYSIZE, monthArr[month]);
        printDashedLine(DAYSIZE);
        printDates(DAYSIZE, FIRSTDAY);
        FIRSTDAY = (FIRSTDAY + 2) % 7;
        if (FIRSTDAY == 0)
            FIRSTDAY++;
    }
    printDashedLine(DAYSIZE);
}



