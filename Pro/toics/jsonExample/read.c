/**
 * @file read.c
 * @author Leo Scott
 * @brief 只能读取字符串类型的一个json对象. C语言读取json数据过于复杂，因此用空格分隔作为数据文件就好了
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    FILE *op=fopen("example.json","r");
    if(op==NULL) 
        exit(0);
    char key[30],value[30];
    fscanf(op,"{\n\t");
    int i,j;
    char reader;
    int branch=0;
    i=j=0;
    while(reader!='}') {
        fscanf(op,"%c",&reader);
        if(reader=='\"')
            branch++;
    }
    /*
    note 1:fscanf会跳过在format字段中指定的字符
    note 2:%s符号的意义是使fscanf函数读取字符一直读取到空白字符为止, 即使在%s后面有指定字符，也会被读入
    */
    printf("key:%s\nvalue:%s",key,value);
    fclose(op);
    return 0;
}