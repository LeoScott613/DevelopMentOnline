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
        FILE *p = fopen("data.t", "a"); // read file and make a link list
        event_st *p1,*new;
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