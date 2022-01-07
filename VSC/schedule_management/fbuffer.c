#include "sched.h"
/*
indicator: 0,1,2
0:delete
1:edit
2:new
*/
void buff(int indicator, int year, int month) // create a linklist to interact with file
{
    static int initial = 1;
    if (initial)
    {
        FILE *f = fopen("data.t", "a"); // read file and make a link list
        event_st *p1, *new;
        p1 = (event_st *)malloc(sizeof(event_st));
        while (!feof(f))
        {
            int day = -1, hour = -1, min = -1, year, monthh;
            char content[50], place[50];
            fscanf(f, "%s %04d.%02d.%03d.%02d:%02d:\"%s\"", place, &year, &monthh, &day, &hour, &min, content);
            if (day != -1 && hour != -1 && min != -1)//Because at the end of the data.t, there will always be an empty line
            {
                p1->year = year;
                p1->month = monthh;
                p1->day = day;
                p1->hour = hour;
                p1->min = min;
                strcpy(p1->content, content);
                strcpy(p1->place, place);

                new = (event_st *)malloc(sizeof(event_st));
                new->next = NULL;
                p1->next = new;
                p1 = p1->next;
            }
        }
        
        initial = 0;
    }
    if (indicator == 0) // delete
    {
    }
    else if (indicator == 1) // edit
    {
    }
    else if (indicator == 2) // new
    {

    }; // renew the file
    ;  // fprintf
}