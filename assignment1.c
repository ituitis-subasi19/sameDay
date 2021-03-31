#include <stdio.h>
#include <stdlib.h>

int main() {
	int input_year, month, day;
	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &input_year, &month, &day);
	
	if (month > 0 && month < 8) {
		if (month == 2) {
			if (day > 28) {
				printf("Invalid date.\n");
				return 1;
			}
		} else if (month % 2 == 0) {
			if (day > 30) {
				printf("Invalid date.\n");
				return 1;
			}
		} else {
			if (day > 31) {
				printf("Invalid date.\n");
				return 1;
			}
		}
	} else if (month >= 8 && month <= 12) {
		if (month % 2 == 0) {
			if (day > 31) {
				printf("Invalid date.\n");
				return 1;
			}
		} else {
			if (day > 30) {
				printf("Invalid date.\n");
				return 1;
			}
		}
	} else {
		printf("Invalid date.\n");
		return 1;
	}
	
	int input_end_year;
	printf("Enter end year: ");
	scanf("%d", &input_end_year);
	
	int year = input_year;
	int end_year = input_end_year;
	
	if (month == 1 || month == 2) {
		month += 12;
		year -= 1;
		end_year -= 1;
	}
	
	int q = day;
	int m = month;
	int j = year / 100;
	int k = year % 100;
	
	int weekday = (q + (13 * (m + 1) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
	
	switch (weekday) {
		case 0:
			printf("It's a Saturday.\n");
			break;
		case 1:
			printf("It's a Sunday.\n");
			break;
		case 2:
			printf("It's a Monday.\n");
			break;
		case 3:
			printf("It's a Tuesday.\n");
			break;
		case 4:
			printf("It's a Wednesday.\n");
			break;
		case 5:
			printf("It's a Thursday.\n");
			break;
		case 6:
			printf("It's a Friday.\n");
			break;
	}
	
	int same_weekday = 0;
	int remaning_weekday;
	
	
	while (year < end_year) {
		year++;
		int j = year / 100;
		int k = year % 100;
		remaning_weekday = (q + (13 * (m + 1) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
		if (weekday == remaning_weekday) {
			same_weekday ++;
		}
	}
	
	int first_year = input_year + 1;
	printf("Same day-and-month on same weekday between %d and %d: %d\n", first_year, input_end_year, same_weekday);
	return 0;
	
}
