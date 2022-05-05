/**
 * @author Leo Scott
 * @brief 没有什么思路它为什么卡住了
 * @date 2022-05-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singleClass { 
	char name[20];
	char classtime[20];
	char position[20];
	char date_time[20];
	int realtime;
}singleClass;
typedef struct dateTime {
	char *dtstart;
	char *dtend;
}dateTime;

char *tstart(int sequence) {
	static char time[10];
	switch(sequence) {
		case 1:strcat(time,"083000");
		case 2:strcat(time,"092000");
		case 3:strcat(time,"102500");
		case 4:strcat(time,"111500");
		case 5:strcat(time,"135000");
		case 6:strcat(time,"144000");
		case 7:strcat(time,"153000");
		case 8:strcat(time,"163000");
		case 9:strcat(time,"172000");
		case 10:strcat(time,"183000");
		case 11:strcat(time,"192000");
		case 12:strcat(time,"201000");
	}
	return time;
}
char *tend(int sequence) {
	static char time[10];
	switch(sequence) {
		case 1:strcat(time,"091500");
		case 2:strcat(time,"100500");
		case 3:strcat(time,"111000");
		case 4:strcat(time,"120000");
		case 5:strcat(time,"143500");
		case 6:strcat(time,"152500");
		case 7:strcat(time,"161500");
		case 8:strcat(time,"171500");
		case 9:strcat(time,"180500");
		case 10:strcat(time,"191500");
		case 11:strcat(time,"200500");
		case 12:strcat(time,"205500");
	}
	return time;
}
dateTime operation(char classtime[],char datetime[]) {
	char dtdate[15];
	int j,k;
	for(j=k=0;j<8;j++,k++) 
		(datetime[k]=='-')?(j--):(dtdate[j]=datetime[k]);
	//date operation

	int oneClass;
	char *tbegin,*tover;
	int i=0;
	while(classtime[i]!='\0') {
		oneClass=(classtime[i++]-'0')*10+(classtime[i]-'0');//课序
		if(i==1)
			tbegin=tstart(oneClass);
	}
	tover=tend(oneClass);printf("1");
	//time operation

	char dtstart[50]="lhx",dtend[50]="lhx";
	strcat(dtstart,dtdate);
	strcat(dtend,dtdate);
	strcat(dtstart,tbegin);
	strcat(dtend,tover);
	//cat operation

	dateTime pack;
	pack.dtstart=dtstart;
	pack.dtend=dtend;
	return pack;
	//packup and return back
}

int main(){
	FILE *classFile=fopen("classTable.txt","r");
	FILE *timeFile=fopen("timeTransed.txt","w");
	if(classFile!=NULL)
		while(!feof(classFile)) {
			singleClass readbuff;
			fscanf(classFile,"%s %s %s %s",readbuff.name,readbuff.classtime,readbuff.position,readbuff.date_time);
			dateTime currentEvent=operation(readbuff.classtime,readbuff.date_time);
			fprintf(timeFile,"%s %s %s %s\n",readbuff.name,readbuff.position,currentEvent.dtstart,currentEvent.dtend);
		}
	fclose(classFile);
	fclose(timeFile);
	return 0;
}
