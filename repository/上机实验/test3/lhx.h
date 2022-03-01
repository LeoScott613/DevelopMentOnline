#ifndef _LHX_
void reduce_blank(char tpa[], char ans[])
{
    for (int i(0), j(0); i < 100; i++)
        if (tpa[i] != ' ')
        {
            ans[j] = tpa[i];
            j++;
        }
    return;
}
#endif