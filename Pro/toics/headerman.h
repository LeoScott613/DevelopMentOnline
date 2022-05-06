#ifndef LHXTOICS
#define LHXTOICS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct singleClass { 
	char name[20];
	char classtime[20];
	char position[20];
	char date_time[20];
}singleClass;
typedef struct dateTime {
	char *dtstart;
	char *dtend;
}dateTime;


char *tstart(int sequence);
char *tend(int sequence);
dateTime operation(char classtime[],char datetime[]);

#endif