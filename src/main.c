#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "define.h"

char title1[TITLE_LENTH],title2[TITLE_LENTH],title3[TITLE_LENTH];

CarTypeNode *ct_p=NULL,*head_ct=NULL;
CarStatsNode *cs_p=NULL,*head_cs=NULL;
RentStatsNode *rs_p=NULL,*head_rs=NULL;

//函数声明部分
void read_init();//读取初始化
void cartype_read_init(); //车辆分类信息读取初始化
void carstats_read_init(); //车辆基本信息读取初始化
void rentstats_read_init(); //租车信息读取初始化
void save_file(); //文件保存函数
void cartype_write(); //向文件写入车辆分类信息
void carstats_write(); //向文件写入车辆基本信息
void rentstats_write(); //向文件写入租车信息

int main() {
    read_init();  //读入文件
    save_file();  //保存文件
    return 0;
}

void read_init() {
    head_ct = calloc(1, sizeof(CarType));
    head_cs = calloc(1, sizeof(CarStatsNode));
    head_rs = calloc(1, sizeof(RentStatsNode));
    ct_p = head_ct;
    cs_p = head_cs;
    rs_p = head_rs;
    cartype_read_init();
    carstats_read_init();
    rentstats_read_init();
}
void cartype_read_init() {
    char buf[LINE_LENTH];
    char *line,*record;
    char delims[]=",";
    int k=0;
    FILE *fp = fopen ("CarTypeFile.csv","rb");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    fscanf(fp,"%[^\n]", title1);
 //   printf("%s\n",title);
    fseek(fp, 36L, SEEK_SET);
    while ((line = fgets(buf, sizeof(buf), fp))!=NULL) {
        record = strtok(line,delims);
        CarTypeNode *ct = calloc (1, sizeof (CarTypeNode));
 //       cart[ctnum] = calloc (1, sizeof (CarTypeNode));
 //       cart[ctnum++] = ct;
        while (record != NULL) {
 //           printf("%s",record);
            switch (k) {
                case 0:
                    ct->ct.code = record[0];
//                    printf("%c",ct->ct.code);
                    break;
                case 1:
                    strcpy(ct->ct.TypeName,record);
//                    printf("%s",ct->ct.TypeName);
                    break;
                case 2:
                    ct->ct.amount = atoi(record);
//                    printf("%d ",ct->ct.amount);
//                     printf("%s",record);
                    break;
                default:
                    break;
            }
            k=(k+1)%3;
            record = strtok(NULL,delims);
        }
        ct_p->next = ct;
        ct_p = ct;
        ct_p->next = NULL;
        ct_p->head = NULL;
    }
    fclose(fp);
}
void carstats_read_init() {
    char buf[LINE_LENTH];
    char *line,*record;
    char delims[]=",";
    int k=0;
    FILE *fp = fopen ("CarStatsFile.csv","rb");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    fscanf(fp,"%[^\n]", title2);
    fseek(fp, 72L, SEEK_SET);
    while ((line = fgets(buf, sizeof(buf), fp))!=NULL) {
        record = strtok(line,delims);
        CarStatsNode *cs = calloc(1,sizeof(CarStatsNode));
 //       cars[csnum] = calloc(1,sizeof(CarStatsNode));
 //       cars[csnum++] = cs;
        while (record != NULL) {
//            printf("%s",record);
            switch (k) {
                case 0:
                    cs->cs.CarNum = atoi(record);
 //                   printf("%s=",record);
 //                  printf("%d  ",cs->cs.CarNum);
                    break;
                case 1:
                    strcpy(cs->cs.plate,record);
 //                   printf("%s ",cs->cs.plate);
                    break;
                case 2:
                    cs->cs.code = record[0];
//                    printf("%c ",cs->cs.code);
                    break;
                case 3:
                    strcpy(cs->cs.CarName,record);
//                    printf("%s ",cs->cs.CarName);
                    break;
                case 4:
                    strcpy(cs->cs.mode,record);
 //                   printf("%s ",cs->cs.mode);
                    break;
                case 5:
                    cs->cs.rent = atof(record);
 //                   printf("%.2f ",cs->cs.rent);
                    break;
                case 6:
                    cs->cs.stats = record[0];
 //                   printf("%c ",cs->cs.stats);
                    break;
                default:
                    break;
            }
            k = (k+1) % 7;
            record=strtok(NULL,delims);
        }
        cs_p->next = cs;
        cs_p = cs;
        cs_p->next = NULL;
        cs_p->head = NULL;
    }
    fclose(fp);
}
void rentstats_read_init() {
    char buf[LINE_LENTH];
    char *line,*record;
    char delims[]=",";
    int k=0;
    FILE *fp = fopen ("RentStatsFile.csv","rb");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    fscanf(fp,"%[^\n]", title3);
    fseek(fp, 122L, SEEK_SET);
    while ((line = fgets(buf, sizeof(buf), fp))!=NULL) {
        record = strtok(line,delims);
        RentStatsNode *rs = calloc(1,sizeof(RentStatsNode));
 //       cars[csnum] = calloc(1,sizeof(CarStatsNode));
 //       cars[csnum++] = cs;
        while (record != NULL) {
 //           printf("%s",record);
            switch (k) {
                case 0:
                    strcpy(rs->rs.RentNum,record);
 //                   printf("%s=",record);
 //                  printf("%s  ",rs->rs.RentNum);
                    break;
                case 1:
                    strcpy(rs->rs.id,record);
 //                   printf("%s ",cs->cs.plate);
                    break;
                case 2:
                    strcpy(rs->rs.name,record);
//                    printf("%c ",cs->cs.code);
                    break;
                case 3:
                    strcpy(rs->rs.phone,record);
//                    printf("%s ",rs->rs.id);
                    break;
                case 4:
                    rs->rs.CarNum = atoi(record);
//                    printf("%d ",rs->rs.CarNum);
                    break;
                case 5:
                    strcpy(rs->rs.TakeTime,record);
 //                   printf("%.2f ",cs->cs.rent);
                    break;
                case 6:
                    strcpy(rs->rs.BackTime,record);
 //                   printf("%c ",cs->cs.stats);
                    break;
                case 7:
                    rs->rs.deposit = atof(record);
                    break;
                case 8:
                    strcpy(rs->rs.rBackTime,record);
                    break;
                case 9:
                    rs->rs.fee = atof(record);
                    break;
                case 10:
                    rs->rs.rfee = atof(record);
                    break;
                default:
                    break;
            }
            k = (k+1) % 11;
            record=strtok(NULL,delims);
        }
        rs_p->next = rs;
        rs_p = rs;
        rs_p->next = NULL;
    }
    fclose(fp);
}

void save_file() {
    cartype_write();
    carstats_write();
    rentstats_write();
}
void cartype_write() {
 //   printf("1");
    FILE *fp = fopen ("CarTypeFile(1).csv","wb+");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    CarTypeNode *ct_p = head_ct;
    fprintf(fp,"%s\n",title1);
    while (ct_p->next != NULL) {
 //       printf("%c,%s,%d\n",ct_p->next->ct.code,ct_p->next->ct.TypeName,ct_p->next->ct.amount);
        fprintf(fp,"%c,%s,%d\n",ct_p->next->ct.code,ct_p->next->ct.TypeName,ct_p->next->ct.amount);
        ct_p = ct_p->next;
    }
    fclose(fp);
}

void carstats_write() {
     //   printf("1");
    FILE *fp = fopen ("CarStatsFile(1).csv","wb+");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    CarStatsNode *cs_p = head_cs;
    fprintf(fp,"%s\n",title2);
    while (cs_p->next != NULL) {
 //       printf("%c,%s,%d\n",ct_p->next->ct.code,ct_p->next->ct.TypeName,ct_p->next->ct.amount);
        fprintf(fp,"%d,%s,%c,%s,%s,%.2f,%c\n",cs_p->next->cs.CarNum,cs_p->next->cs.plate,cs_p->next->cs.code,cs_p->next->cs.CarName,cs_p->next->cs.mode,cs_p->next->cs.rent,cs_p->next->cs.stats);
        cs_p = cs_p->next;
    }
    fclose(fp);
}

void rentstats_write(){
    FILE *fp = fopen("RentStatsFile(1).csv","wb+");
    if (fp == NULL) {
        printf("Open Error !\n");
        return;
    }
    RentStatsNode *rs_p =head_rs;
    fprintf(fp,"%s\n",title3);
    RentStats rs_n;
    while (rs_p->next !=NULL) {
        rs_n = rs_p->next->rs;
        fprintf(fp,"%s,%s,%s,%s,%d,%s,%s,%.2f,%s,%.2f,%.2f\n",rs_n.RentNum,rs_n.id,rs_n.name,rs_n.phone,rs_n.CarNum,rs_n.TakeTime,rs_n.BackTime,rs_n.deposit,rs_n.rBackTime,rs_n.fee,rs_n.rfee);
        rs_p = rs_p->next;
    }
    fclose(fp);
}