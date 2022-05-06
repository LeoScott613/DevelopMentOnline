#include "headerman.h"
int main() {
    FILE *ics=fopen("finalClass.ics","w");
    FILE *transed=fopen("timeTransed.txt","r");

    fprintf(ics,"BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//LHX//GDUT CLASS//CN\nMETHOD:PUBLISH\n");
    while(!feof(transed)) {
        char class[4][20];
        fscanf(transed,"%s %s %s %s",class[0],class[1],class[2],class[3]);
        fprintf(ics,"BEGIN:VEVENT\n");
        fprintf(ics,"DTSTART:%s\nDTEND:%s\nSUMMARY:%s\nLOCATION:%s\n",class[2],class[3],class[0],class[1]);
        fprintf(ics,"END:VEVENT\n");
    }
    fprintf(ics,"END:VCALENDAR\n");
    fclose(ics);
    fclose(transed);
    return 0;
}