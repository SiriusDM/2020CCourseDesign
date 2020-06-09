#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "define.h"

CarTypeNode *head=NULL;
CarTypeNode *ct_p=NULL;
CarStatsNode *cs_p=NULL;
RentStatsNode *rs_p=NULL;

//函数声明部分
void read_init();//读取前初始化
void cartype_read_init(); //汽车分类信息读取初始化

int main () {
    read_init();
    cartype_read_init();
    return 0;
}

void read_init() {
    head = calloc(1, sizeof(CarType));
    ct_p = head;
    cs_p = NULL;
    rs_p = NULL;
}
void cartype_read_init() {
    char buf[LINE_LENTH];
    char *line,*record,*result=NULL;
    char delims[]=",";
    FILE *fp = fopen ("CarTypeFile.csv","rb");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    fseek(fp, 3L, SEEK_SET);
    while ((line = fgets(buf, sizeof(buf), fp))!=NULL) {
        record = strtok(line,delims);
        while (record != NULL) {
            printf("%s",record);
            record = strtok(NULL,delims);
        }
    }
}