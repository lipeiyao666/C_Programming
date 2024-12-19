#include <stdio.h>


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100!= 0) || (year % 400 == 0);
}


int getDayOfWeek(int year, int month, int day) {
    int days = 0;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    for(int y = 2024; y < year; y++) {
        days += isLeapYear(y)? 366 : 365;
    }
    for (int m = 10; m < month; m++) {
        days += daysInMonth[m - 1];
    }
    days += day - 29;
    return (days % 7 + 2) % 7;
}


void printMonthCalendar(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    int dayOfWeek = getDayOfWeek(year, month, 1);
    printf("    %d-%02d\n", year, month);
    printf("Su Mo Tu We Th Fr Sa\n");
    for (int i = 0; i < dayOfWeek; i++) {
        printf("   ");
    }
    for (int d = 1; d <= daysInMonth[month - 1]; d++) {
        printf("%2d ", d);
        if ((d + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }   printf("\n");
}

void printYearCalendar(int year) {
    for (int month = 1; month <= 12; month++) {
        printMonthCalendar(year, month);
    }
}

int main() {
    int choice, year, month, day;
    while (1) {
        printf("1. Find day of week for a specific date\n");
        printf("2. Print calendar for a specific month\n");
        printf("3. Print calendar for a specific year\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter year, month, and day: ");
                scanf("%d %d %d", &year, &month, &day);
                int dayOfWeek = getDayOfWeek(year, month, day);
                switch (dayOfWeek) {
                    case 0:
                        printf("Sunday\n");
                        break;
                    case 1:
                        printf("Monday\n");
                        break;
                    case 2:
                        printf("Tuesday\n");
                        break;
                    case 3:
                        printf("Wednesday\n");
                        break;
                    case 4:
                        printf("Thursday\n");
                                                          case 5:
                        printf("Friday\n");
                        break;
                    case 6:
                        printf("Saturday\n");
                        break;
                }
                break;
            case 2:
                printf("Enter year and month: ");
                scanf("%d %d", &year, &month);
                printMonthCalendar(year, month);
                break;
            case 3:
                printf("Enter year: ");
                scanf("%d", &year);
                printYearCalendar(year);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
} 