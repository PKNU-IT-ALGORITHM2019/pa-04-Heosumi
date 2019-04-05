#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
char x[LEN];
char y[LEN];
int compareip();
int comparetime();
int month(char mon[]);
void read();
void print(int i);

typedef struct WEB {
	char IP[LEN];
	char Time[LEN];
	char URL[LEN];
	char Status[LEN];
};
struct WEB Web[LEN];
int n = 0;

int main() {
	int i;

	while (1) {
		printf("$ ");
		scanf_s("%s", x);
		if (strcmp(x, "read") == 0)
			read();
		else if (strcmp(x, "sort") == 0)
		{
			scanf_s("%s", y);
			if (strcmp(y, "-t") == 0) {
				qsort(Web,n,sizeof(Web),comparetime);
				i = 1;
			}
			else if (strcmp(y, "-ip") == 0) {
				qsort(Web, n, sizeof(Web), compareip);
				i = 2;
			}
		}
		else if (strcmp(x, "print") == 0)
			print(i);
		else if (strcmp(x, "exit") == 0)
			break;

	}
	getchar();
	return 0;
}

int month(char mon[]) {
	if (strcmp(mon, "Jan") == 0)
		return 1;
	else if (strcmp(mon, "Feb") == 0)
		return 2;
	else if (strcmp(mon, "Mar") == 0)
		return 3;
	else if (strcmp(mon, "Apr") == 0)
		return 4;
	else if (strcmp(mon, "May") == 0)
		return 5;
	else if (strcmp(mon, "Jun") == 0)
		return 6;
	else if (strcmp(mon, "Jul") == 0)
		return 7;
	else if (strcmp(mon, "Aug") == 0)
		return 8;
	else if (strcmp(mon, "Sep") == 0)
		return 9;
	else if (strcmp(mon, "Oct") == 0)
		return 10;
	else if (strcmp(mon, "Nov") == 0)
		return 11;
	else return 12;
}

void read() {
	char file[LEN];
	char str[500];
	FILE *fp;
	fopen_s(&fp, file, "r");
	fgets(str, 500, fp);

	while (!feof(fp)) {
		fgets(str, 500, fp);
		char *token = strtok(str, ",");
		strcpy(Web[n].IP, token);
		token = strtok(NULL, ",");
		strcpy(Web[n].Time, token);
		token = strtok(NULL, ",");
		strcpy(Web[n].URL, token);
		token = strtok(NULL, ",");
		strcpy(Web[n].Status, token);
		n++;
	}
	fclose(fp);
}

void print(int i) {
	if (i == 1) 
	{
		for (int j = 0; j < n; j++) {
			printf("%s\n", Web[j].Time);
			printf("IP: %s\n", Web[j].IP);
			printf("URL: %s\n", Web[j].URL);
			printf("Status: %s\n", Web[j].Status);
		}
	}
	else if (i == 2)
	{
		for (int j = 0; j < n; j++) {
			printf("%s\n", Web[j].IP);
			printf("Time: %s\n", Web[j].Time);
			printf("URL: %s\n", Web[j].URL);
			printf("Status: %s\n", Web[j].Status);
		}
	}
}

int compareip() {

}
int comparetime() {

}