#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int get_days_in_month(struct date d) {
    switch (d.month) {
        case 2:
            if (is_leap_year(d.year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int get_day_of_week(struct date d) {
    int y = d.year - (14 - d.month) / 12;
    int m = d.month + 12 * ((14 - d.month) / 12) - 2;
    int day = (d.day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    return day;
}

void print_calendar(struct date d) {
    // Print the month and year
    //printf("%d/%d/%d\n", d.month, d.year, d.day);

    // Print the header row
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Determine the number of days in the month
    int days_in_month = get_days_in_month(d);

    // Determine the day of the week of the first day of the month
    struct date first_day = {1, d.month, d.year};
    int day_of_week = get_day_of_week(first_day);

    // Print the days of the month in a grid format
    int day = 1;
    for (int i = 0; i < day_of_week; i++) {
        printf("    ");
    }
    for (int i = day_of_week; i < 7; i++) {
        printf("%3d ", day);
        day++;
    }
    printf("\n");
    while (day <= days_in_month) {
        for (int i = 0; i < 7 && day <= days_in_month; i++) {
            printf("%3d ", day);
            day++;
        }
        printf("\n");
    }
}

int main() {
    // Prompt the user for a month and year
    int month, year;
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    // Create a date struct with the input month and year
    struct date d = {1, month, year};

    // Print the calendar for the input month and year
    print_calendar(d);

    return 0;
}
