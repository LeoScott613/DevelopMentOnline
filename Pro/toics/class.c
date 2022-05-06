/**
 * @author Leo Scott
 * @brief 这是一个需要深深反思的程序
 * @date 2022-05-06
 */
#include "headerman.h"
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
char *tstart(int sequence) {
	static char time[10];
	switch(sequence) {
		case 1:strcpy(time,"083000");break;
		case 2:strcpy(time,"092000");break;
		case 3:strcpy(time,"102500");break;
		case 4:strcpy(time,"111500");break;
		case 5:strcpy(time,"135000");break;
		case 6:strcpy(time,"144000");break;
		case 7:strcpy(time,"153000");break;
		case 8:strcpy(time,"163000");break;
		case 9:strcpy(time,"172000");break;
		case 10:strcpy(time,"183000");break;
		case 11:strcpy(time,"192000");break;
		case 12:strcpy(time,"201000");break;
	}
	return time;
}
char *tend(int sequence) {
	static char time[10];
	switch(sequence) {
		case 1:strcpy(time,"091500");break;
		case 2:strcpy(time,"100500");break;
		case 3:strcpy(time,"111000");break;
		case 4:strcpy(time,"120000");break;
		case 5:strcpy(time,"143500");break;
		case 6:strcpy(time,"152500");break;
		case 7:strcpy(time,"161500");break;
		case 8:strcpy(time,"171500");break;
		case 9:strcpy(time,"180500");break;
		case 10:strcpy(time,"191500");break;
		case 11:strcpy(time,"200500");break;
		case 12:strcpy(time,"205500");break;
	}
	//printf("%s\n",time);
	return time;
}
dateTime operation(char classtime[],char datetime[]) {
	char dtdate[15];
	int j,k;
	for(j=k=0;j<8;j++,k++) 
		(datetime[k]=='-')?(j--):(dtdate[j]=datetime[k]);
	dtdate[8]='T';//at the end of the dtdate add an 'T'
	//date operation

	int oneClass;
	char *tbegin,*tover;
	int i=0;
	while(classtime[i]!='\0') {
		oneClass=(classtime[i++]-'0')*10+(classtime[i]-'0');//课序
		if(i==1)
			tbegin=tstart(oneClass);
		i++;
	}
	tover=tend(oneClass);
	char array_tbegin[10],array_tover[10];
	for(i=0;*(tbegin+i)!='\0';i++)
		array_tbegin[i]=*(tbegin+i);
	for(i=0;*(tover+i)!='\0';i++)
		array_tover[i]=*(tover+i);	
	//time operation

	char dtstart[50]={0},dtend[50]={0};
	strcat(dtstart,dtdate);
	strcat(dtend,dtdate);
	strcat(dtstart,array_tbegin);
	strcat(dtend,array_tover);
	//cat operation

	dateTime pack;
	pack.dtstart=dtstart;
	pack.dtend=dtend;
	return pack;
	//packup and return back
}

