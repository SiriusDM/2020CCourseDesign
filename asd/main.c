#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "define.h"

char title1[TITLE_LENTH],title2[TITLE_LENTH],title3[TITLE_LENTH];

int now_car_num;

CarTypeNode *ct_p1=NULL,*head_ct=NULL;
CarStatsNode *cs_p1=NULL,*head_cs=NULL;
RentStatsNode *rs_p1=NULL,*head_rs=NULL;

//函数声明部分
void read_init();//? 读取前初始化
void cartype_read_init(); //车辆分类信息读取
void carstats_read_init(); //车辆基本信息读取
void rentstats_read_init(); //订单信息读取
void save_file(); //?  文件保存
void cartype_write(); //车辆分类信息保存
void carstats_write(); //车辆基本信息保存
void rentstats_write(); //订单信息保存
void function_select();//?  功能选择（1.录入2.删除3.修改4.查询）
void function_new(); //?  录入功能
void new_cartype(char _code,char _typename[CARTYPENAME_LENTH],int _amount); // 录入车辆分类信息
void new_carstats(int _carnum,char _plate[PLATE_LENTH],char _code,char _carname[CARNAME_LENTH],char _mode[MODE_LENTH],float _rent,char _stats); //录入车辆基本信息
void new_rentstats(char _rentnum[RENTNUM_LENTH],char _id[ID_LENTH],char _name[GUESTNAME_LENTH],char _phone[PHONE_LENTH],int _carnum,char _taketime[TIME_LENTH],char _backtime[TIME_LENTH],float _deposit,char _rbacktime[TIME_LENTH],float _fee,float _rfee); //录入订单信息
void function_delete(); //?  删除功能
void delete_cartype(); //删除车辆分类信息
void delete_carstats(); //删除车辆基本信息
void delete_rentstats(); //删除订单信息
void function_change();  //?  修改功能
void change_cartype(); //修改车辆分类信息
void change_carstats(); //修改车辆基本信息
void change_rentstats(); //修改订单信息
void function_search(); //?  查询功能
void search_cartype(); //查询车辆分类信息
void search_carstats(); //查询车辆基本信息
void search_rentstats(); //查询订单信息
void func_list();//功能列表显示
void end_word();//结束语
void new_ok();//信息录入成功
void delete_ok();//信息删除成功
void change_ok();//信息修改成功
//输出调试用
void watch_cartype(); 
void watch_carstats();
void watch_rantstats();

int main() {
    read_init();  
    int func_type=0;
    while (func_type != 8) {
        func_list();
        scanf("%d",&func_type);
        function_select(func_type);
        save_file();
    }
    end_word();  
    return 0;
}

void read_init() {
    head_ct = calloc(1, sizeof(CarType));
    head_cs = calloc(1, sizeof(CarStatsNode));
    head_rs = calloc(1, sizeof(RentStatsNode));
    ct_p1 = head_ct;
    cs_p1 = head_cs;
    rs_p1 = head_rs;
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
 //                   printf("%c",ct->ct.code);
                    break;
                case 1:
                    strcpy(ct->ct.TypeName,record);
 //                   printf("%s",ct->ct.TypeName);
                    break;
                case 2:
                    ct->ct.amount = atoi(record);
 //                   printf("%d ",ct->ct.amount);
//                     printf("%s",record);
                    break;
                default:
                    break;
            }
            k=(k+1)%3;
            record = strtok(NULL,delims);
        }
        ct_p1->next = ct;
        ct_p1 = ct;
        ct_p1->next = NULL;
        ct_p1->head = NULL;
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
                    now_car_num++;
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
        cs_p1->next = cs;
        cs_p1 = cs;
        cs_p1->next = NULL;
        cs_p1->head = NULL;
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
        rs_p1->next = rs;
        rs_p1 = rs;
        rs_p1->next = NULL;
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

void function_select(int func_type) {
    switch (func_type) {
        case 1:
            function_new();
            break;
        case 2:
            function_delete();
            break;
        case 3:
            function_change();
            break;
        case 4:
            function_search();
            break;
    }
}

void function_new() {
    int inf;
    char _code,_stats;
    char _typename[CARTYPENAME_LENTH],_rentnum[RENTNUM_LENTH],_id[ID_LENTH],_name[GUESTNAME_LENTH],_phone[PHONE_LENTH],_taketime[TIME_LENTH],_backtime[TIME_LENTH],_rbacktime[TIME_LENTH],_plate[PLATE_LENTH],_carname[CARNAME_LENTH],_mode[MODE_LENTH];
    int _amount,_carnum;
    float _deposit,_fee,_rfee,_rent;
    printf("请选择您要录入的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）: ");
    scanf("%d",&inf);
    switch (inf) {
        case 1:
            printf("请输入车辆分类信息\n");
            printf("车辆类型编码: ");
            getchar();
            scanf("%c",&_code);
            getchar();
//            printf("%c",_code);
            printf("车辆类型名称: ");
            scanf("%s",_typename);
            printf("库存数量: ");
            scanf("%d",&_amount);
//            printf("%c %s %d",_code,_typename,_amount);
            new_cartype(_code,_typename,_amount);
            break;
        case 2:
            printf("请输入车辆基本信息\n");
            _carnum = (++now_car_num);
            printf("车牌号: ");
            scanf("%s", _plate);
            printf("车辆类型编码: ");
            getchar();scanf("%c", &_code);getchar();
            printf("车辆名称: ");
            scanf("%s", _carname);
            printf("拍档方式: ");
            scanf("%s", _mode);
            printf("每日租金: ");
            scanf("%f", &_rent);
            printf("出租状态: ");
            getchar();scanf("%c", &_stats);getchar();
            new_carstats(_carnum,_plate,_code,_carname,_mode,_rent,_stats);
            break;
        case 3:
            printf("请输入订单信息\n");
            printf("订单编号: ");
            scanf("%s", _rentnum);
            printf("身份证号: ");
            scanf("%s",_id);
            printf("客人姓名: ");
            scanf("%s", _name);
            printf("手机号码: ");
            scanf("%s", _phone);
            printf("租用车辆编号: ");
            scanf("%d", &_carnum);
            printf("取车时间: ");
            scanf("%s", _taketime);
            printf("预约还车时间: ");
            scanf("%s", _backtime);
            printf("押金: ");
            scanf("%f", &_deposit);
            printf("实际还车时间: ");
            scanf("%s", _rbacktime);
            printf("应缴费用: ");
            scanf("%f", &_fee);
            printf("实缴费用: ");
            scanf("%f", &_rfee);
            new_rentstats(_rentnum,_id,_name,_phone,_carnum,_taketime,_backtime,_deposit,_rbacktime,_fee,_rfee);
            break;
        default:
            printf("信息选择错误!\n");
            break;
    }
}

void new_cartype(char _code,char _typename[CARTYPENAME_LENTH],int _amount) {
    CarTypeNode *ct_p = head_ct;
    while (ct_p->next !=NULL) ct_p = ct_p->next;
    CarTypeNode *ct = calloc(1, sizeof (CarTypeNode));
    ct->ct.code = _code;
    strcpy(ct->ct.TypeName,_typename);
    ct->ct.amount = _amount;
    ct->head = NULL;
    ct->next =NULL;
    ct_p->next = ct; 
//    watch_cartype();
} //录入车辆分类信息

void new_carstats(int _carnum,char _plate[PLATE_LENTH],char _code,char _carname[CARNAME_LENTH],char _mode[MODE_LENTH],float _rent,char _stats) {
    CarStatsNode *cs_p = head_cs;
    while (cs_p->next != NULL) cs_p = cs_p->next;
    CarStatsNode *cs = calloc(1,sizeof (CarStatsNode));
    cs->cs.CarNum = _carnum;
    strcpy(cs->cs.plate,_plate);
    cs->cs.code = _code;
    strcpy(cs->cs.CarName,_carname);
    strcpy(cs->cs.mode,_mode);
    cs->cs.rent = _rent;
    cs->cs.stats = _stats;
    cs->head = NULL;
    cs->next = NULL;
    cs_p->next = cs;
 //   watch_carstats();
}//录入车辆基本信息

void new_rentstats(char _rentnum[RENTNUM_LENTH],char _id[ID_LENTH],char _name[GUESTNAME_LENTH],char _phone[PHONE_LENTH],int _carnum,char _taketime[TIME_LENTH],char _backtime[TIME_LENTH],float _deposit,char _rbacktime[TIME_LENTH],float _fee,float _rfee) {
    RentStatsNode *rs_p = head_rs;
    while (rs_p->next !=NULL) rs_p = rs_p->next;
    RentStatsNode *rs = calloc(1,sizeof(RentStatsNode));
    strcpy(rs->rs.RentNum,_rentnum);
    strcpy(rs->rs.id,_id);
    strcpy(rs->rs.name,_name);
    strcpy(rs->rs.phone,_phone);
    rs->rs.CarNum = _carnum;
    strcpy(rs->rs.TakeTime,_taketime);
    strcpy(rs->rs.BackTime,_backtime);
    rs->rs.deposit = _deposit;
    strcpy(rs->rs.rBackTime,_rbacktime);
    rs->rs.fee = _fee;
    rs->rs.rfee = _rfee;
    rs->next = NULL;
    rs_p->next = rs;
//    watch_rentstats();
} //录入订单信息

void function_delete() {
    int inf;
    printf("请选择您要录入的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）: ");
    scanf("%d",&inf);
    switch (inf) {
       case 1:
            delete_cartype();
            break;
        case 2:
            delete_carstats();
            break;
        case 3:
            delete_rentstats();
            break;
        default:
            printf("信息选择错误 !\n");
            break;
    }
} 
void delete_cartype() {} //删除车辆分类信息
void delete_carstats() {} //删除车辆基本信息
void delete_rentstats() {} //删除订单信息
void function_change() {
    int inf;
    printf("请选择您要录入的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）:");
    scanf("%d",&inf);
    switch (inf) {
        case 1:
            change_cartype();
            break;
        case 2:
            change_carstats();
            break;
        case 3:
            change_rentstats();
            break;
        default:
            printf("信息选择错误 !\n");
            break;
    }
} 
void change_cartype() {} //修改车辆分类信息
void change_carstats() {} //修改车辆基本信息
void change_rentstats() {} //修改订单信息
void function_search() {
    int inf = 0;
    printf("请选择您要查找的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）:");
        scanf("%d",&inf);
        switch (inf) {
            case 1:
                change_cartype();
                break;
            case 2:
                change_carstats();
                break;
            case 3:
                change_rentstats();
                break;
            default:
                printf("信息选择错误 !\n");
                break;
        }
} 
void search_cartype() {} //查询车辆分类信息
void search_carstats() {} //查询车辆基本信息
void search_rentstats() {} //查询订单信息

void watch_cartype() {
    CarTypeNode *ct_p =head_ct;
    while (ct_p->next != NULL) {
        printf("%c %s %d\n",ct_p->next->ct.code,ct_p->next->ct.TypeName,ct_p->next->ct.amount);
        ct_p =  ct_p->next;
    }
}

void watch_carstats() {
    CarStatsNode *cs_p = head_cs;
    while (cs_p->next != NULL) {
        CarStats cs = cs_p->next->cs;
        printf("%d %s %c %s %s %.2f %c",cs.CarNum,cs.plate,cs.code,cs.CarName,cs.mode,cs.rent,cs.stats);
        cs_p = cs_p->next;
    }
}

void watch_rentstats() {
    RentStatsNode *rs_p = head_rs;
    while (rs_p->next != NULL) {
        RentStats rs = rs_p->next->rs;
        printf("%s %s %s %s %d %s %s %.2f %s %.2f %.2f",rs.RentNum,rs.id,rs.name,rs.phone,rs.CarNum,rs.TakeTime,rs.BackTime,rs.deposit,rs.rBackTime,rs.fee,rs.rfee);
        rs_p = rs_p->next;
    }
}

void func_list() {
    printf("\n\n");
    printf("*************欢迎使用车辆租赁管理系统************\n");
    printf("====================功能列表=====================\n");
    printf("||                 1.信息录入                  ||\n");
    printf("||                 2.信息删除                  ||\n");
    printf("||                 3.信息修改                  ||\n");
    printf("||                 4.信息查询                  ||\n");
    printf("||                 5.数据分析                  ||\n");
    printf("||                 6.版本信息                  ||\n");
    printf("||                 7.联系作者                  ||\n");
    printf("||                 8.退出系统                  ||\n");
    printf("================================================\n");
    printf("请输入您想使用的功能(1~8): ");
}

void end_word() {
    printf("\n本次使用结束，车辆租赁管理系统退出成功!\n");
}

void new_ok() {
    printf("信息录入成功!\n");
}

void delete_ok() {
    printf("信息删除成功!\n");
}

void change_ok() {
    printf("信息修改成功!\n");
}