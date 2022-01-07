#include "sched.h"
event_st *buff() // create a linklist to interact with file
/*
Create buffer at first, return the address of the buffer every time when called, and renew the data.t from the buffer
*/
{
    static int initial = 1;
    static event_st *bufferhead;
    if (initial) // initialization: create buffer
    {
        FILE *f = fopen("data.t", "r"); // read file and make a link list
        event_st *p1, *new;
        int once = 1;
        // p1 = (event_st *)malloc(sizeof(event_st));
        while (!feof(f))
        {
            int day = -1, hour = -1, min = -1, year, monthh;
            char content[50], place[50];
            fscanf(f, "%s %04d.%02d.%03d.%02d:%02d:\"%s\"", place, &year, &monthh, &day, &hour, &min, content);
            if (day != -1 && hour != -1 && min != -1) // Because at the end of the data.t, there will always be an empty line
            {
                if (once)
                {
                    bufferhead = (event_st *)malloc(sizeof(event_st));
                    p1 = bufferhead;
                    p1->next = NULL;
                    once = 0;
                }
                else
                {
                    new = (event_st *)malloc(sizeof(event_st));
                    new->next = NULL;
                    p1->next = new; // not "p1=new" because the will cause "dishook"
                    p1 = p1->next;
                }

                p1->year = year;
                p1->month = monthh;
                p1->day = day;
                p1->hour = hour;
                p1->min = min;
                strcpy(p1->content, content);
                strcpy(p1->place, place);
            }
        }
        fclose(f);

        initial = 0;
    }
    else // every time when called: renew the data file from buffer
    {
        FILE *f;
        f = fopen("data.t", "w");
        event_st *p = bufferhead;
        while (p->next != NULL)
            fprintf(f, "%s %04d.%02d.%03d.%02d:%02d:\"%s\"\n", p->place, p->year, p->month, p->day, p->hour, p->min, p->content);
        fprintf(f, "%s %04d.%02d.%03d.%02d:%02d:\"%s\"\n", p->place, p->year, p->month, p->day, p->hour, p->min, p->content);
        fclose(f);

    } // renew the file
    return bufferhead;
}