#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "define.h"

char title1[TITLE_LENTH],title2[TITLE_LENTH],title3[TITLE_LENTH];

int now_car_num;

CarTypeNode *ct_p1=NULL,*head_ct=NULL;
CarStatsNode *cs_p1=NULL,*head_cs=NULL;
RentStatsNode *rs_p1=NULL,*head_rs=NULL;

//������������
void read_init();//? ��ȡǰ��ʼ��
void cartype_read_init(); //����������Ϣ��ȡ
void carstats_read_init(); //����������Ϣ��ȡ
void rentstats_read_init(); //������Ϣ��ȡ
void save_file(); //?  �ļ�����
void cartype_write(); //����������Ϣ����
void carstats_write(); //����������Ϣ����
void rentstats_write(); //������Ϣ����
void function_select();//?  ����ѡ��1.¼��2.ɾ��3.�޸�4.��ѯ��
void function_new(); //?  ¼�빦��
void new_cartype(char _code,char _typename[CARTYPENAME_LENTH],int _amount); // ¼�복��������Ϣ
void new_carstats(int _carnum,char _plate[PLATE_LENTH],char _code,char _carname[CARNAME_LENTH],char _mode[MODE_LENTH],float _rent,char _stats); //¼�복��������Ϣ
void new_rentstats(char _rentnum[RENTNUM_LENTH],char _id[ID_LENTH],char _name[GUESTNAME_LENTH],char _phone[PHONE_LENTH],int _carnum,char _taketime[TIME_LENTH],char _backtime[TIME_LENTH],float _deposit,char _rbacktime[TIME_LENTH],float _fee,float _rfee); //¼�붩����Ϣ
void function_delete(); //?  ɾ������
void delete_cartype(char _code); //ɾ������������Ϣ
void delete_carstats(int _carnum); //ɾ������������Ϣ
void delete_rentstats(char _rentnum[RENTNUM_LENTH]); //ɾ��������Ϣ
void function_change();  //?  �޸Ĺ���
void change_cartype(); //�޸ĳ���������Ϣ
void change_carstats(); //�޸ĳ���������Ϣ
void change_rentstats(); //�޸Ķ�����Ϣ
void function_search(); //?  ��ѯ����
void search_cartype(); //��ѯ����������Ϣ
void search_carstats(); //��ѯ����������Ϣ
void search_rentstats(); //��ѯ������Ϣ
void func_list();//�����б���ʾ
void end_word();//������
void new_ok();//��Ϣ¼��ɹ�
void delete_ok();//��Ϣɾ���ɹ�
void change_ok();//��Ϣ�޸ĳɹ�
int kmp(char* s, char* p); //kmp�㷨
void search_not();//��ѯʧ��
void data_analyze();
void cartype_inf();
void month_money();
void year_money();
void ten_high();
//���������
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
//        printf("1");
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
        case 5:
            data_analyze();
            break;
    }
}

void function_new() {
    int inf;
    char _code,_stats;
    char _typename[CARTYPENAME_LENTH],_rentnum[RENTNUM_LENTH],_id[ID_LENTH],_name[GUESTNAME_LENTH],_phone[PHONE_LENTH],_taketime[TIME_LENTH],_backtime[TIME_LENTH],_rbacktime[TIME_LENTH],_plate[PLATE_LENTH],_carname[CARNAME_LENTH],_mode[MODE_LENTH];
    int _amount,_carnum;
    float _deposit,_fee,_rfee,_rent;
    printf("��ѡ����Ҫ¼�����Ϣ��1��������������Ϣ||2��������������Ϣ||3����������Ϣ��: ");
    scanf("%d",&inf);
    switch (inf) {
        case 1:
            printf("�����복��������Ϣ\n");
            printf("�������ͱ���: ");
            getchar();
            scanf("%c",&_code);
            getchar();
//            printf("%c",_code);
            printf("������������: ");
            scanf("%s",_typename);
            printf("�������: ");
            scanf("%d",&_amount);
//            printf("%c %s %d",_code,_typename,_amount);
            new_cartype(_code,_typename,_amount);
            break;
        case 2:
            printf("�����복��������Ϣ\n");
            _carnum = (++now_car_num);
            printf("���ƺ�: ");
            scanf("%s", _plate);
            printf("�������ͱ���: ");
            getchar();scanf("%c", &_code);getchar();
            printf("��������: ");
            scanf("%s", _carname);
            printf("�ŵ���ʽ: ");
            scanf("%s", _mode);
            printf("ÿ�����: ");
            scanf("%f", &_rent);
            printf("����״̬: ");
            getchar();scanf("%c", &_stats);getchar();
            new_carstats(_carnum,_plate,_code,_carname,_mode,_rent,_stats);
            break;
        case 3:
            printf("�����붩����Ϣ\n");
            printf("�������: ");
            scanf("%s", _rentnum);
            printf("���֤��: ");
            scanf("%s",_id);
            printf("��������: ");
            scanf("%s", _name);
            printf("�ֻ�����: ");
            scanf("%s", _phone);
            printf("���ó������: ");
            scanf("%d", &_carnum);
            printf("ȡ��ʱ��: ");
            scanf("%s", _taketime);
            printf("ԤԼ����ʱ��: ");
            scanf("%s", _backtime);
            printf("Ѻ��: ");
            scanf("%f", &_deposit);
            printf("ʵ�ʻ���ʱ��: ");
            scanf("%s", _rbacktime);
            printf("Ӧ�ɷ���: ");
            scanf("%f", &_fee);
            printf("ʵ�ɷ���: ");
            scanf("%f", &_rfee);
            new_rentstats(_rentnum,_id,_name,_phone,_carnum,_taketime,_backtime,_deposit,_rbacktime,_fee,_rfee);
            break;
        default:
            printf("��Ϣѡ�����!\n");
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
    new_ok();
//    watch_cartype();
} //¼�복��������Ϣ

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
    new_ok();
 //   watch_carstats();
}//¼�복��������Ϣ

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
    new_ok();
//    watch_rentstats();
} //¼�붩����Ϣ

void function_delete() {
    int inf,_carnum;
    char _code;
    char _rentnum[RENTNUM_LENTH];
    printf("��ѡ����Ҫɾ������Ϣ��1��������������Ϣ||2��������������Ϣ||3����������Ϣ��: ");
    scanf("%d",&inf);
    switch (inf) {
       case 1:
            printf("�����복�����ͱ���: ");
            getchar();scanf("%c",&_code);getchar();
//           printf("%c\n",_code);
            delete_cartype(_code);
//           printf("1");
            break;
        case 2:
            printf("�����복�����: ");
            scanf("%d",&_carnum);
            delete_carstats(_carnum);
            break;
        case 3:
            printf("�����붩�����: ");
            scanf("%s",_rentnum);
            delete_rentstats(_rentnum);
            break;
        default:
            printf("��Ϣѡ����� !\n");
            break;
    }
} 

void delete_cartype(char _code) {
    CarTypeNode *ct_p = head_ct; 
    while (ct_p->next !=NULL) {
        if (ct_p->next->ct.code == _code) {
//                printf("1");
                CarTypeNode *ct = ct_p->next;
 //               printf("2");
                ct_p->next = ct->next;
 //               printf("3");
                free(ct);
 //               printf("4");
                break;
        }
        ct_p = ct_p->next;
    }
    delete_ok();
} //ɾ������������Ϣ

void delete_carstats(int _carnum) {
    CarStatsNode *cs_p = head_cs;
    while (cs_p->next !=NULL) {
        if (cs_p->next->cs.CarNum == _carnum) {
            CarStatsNode *cs = cs_p->next;
            cs_p->next = cs->next;
            free(cs);
            break;
        }
        cs_p = cs_p->next;
    }
    delete_ok();
} //ɾ������������Ϣ

void delete_rentstats(char _rentnum[RENTNUM_LENTH]) {
    RentStatsNode *rs_p = head_rs;
    while (rs_p->next !=NULL) {
        if (!strcmp(rs_p->next->rs.RentNum, _rentnum)) {
            RentStatsNode *rs = rs_p->next;
            rs_p->next = rs->next;
            free(rs);
            break;
        }
        rs_p = rs_p->next;
    }
    delete_ok();
} //ɾ��������Ϣ

void function_change() {
    CarTypeNode *ct_p=head_ct;
    CarStatsNode *cs_p=head_cs;
    RentStatsNode *rs_p=head_rs;
    int inf=0;
    char _code,_stats;
    char _typename[CARTYPENAME_LENTH],_rentnum[RENTNUM_LENTH],_id[ID_LENTH],_name[GUESTNAME_LENTH],_phone[PHONE_LENTH],_taketime[TIME_LENTH],_backtime[TIME_LENTH],_rbacktime[TIME_LENTH],_plate[PLATE_LENTH],_carname[CARNAME_LENTH],_mode[MODE_LENTH];
    int _amount=0,_carnum=0;
    float _deposit=0,_fee=0,_rfee=0,_rent=0;
    printf("��ѡ����Ҫ�޸ĵ���Ϣ��1��������������Ϣ||2��������������Ϣ||3����������Ϣ��: ");
    scanf("%d",&inf);
    switch (inf) {
        case 1:
            printf("�����복��������Ϣ(���޸Ĳ�������'-')\n");
            printf("�������ͱ���: ");
            getchar();
            scanf("%c",&_code);
            getchar();

            while (ct_p->next !=NULL) {
                if (ct_p->next->ct.code == _code) {
                    CarType ct = ct_p->next->ct;
                    printf("������������: %s    �޸�Ϊ: ",ct.TypeName);
                    scanf("%s",_typename); if (_typename[0] != '-') strcpy(ct_p->next->ct.TypeName,_typename); 
                    printf("�������: %d     �޸�Ϊ: ",ct.amount);
                    scanf("%d",&_amount); if (_amount) ct_p->next->ct.amount = _amount;
                    break;
                }
                ct_p = ct_p->next;
            }
//            printf("%c %s %d",_code,_typename,_amount);
            break;
        case 2:
            printf("�����복��������Ϣ(���޸Ĳ�������'-')\n");
            printf("�����복�����: ");
            scanf("%d",&_carnum);
            while (cs_p->next !=NULL) {
                if (cs_p->next->cs.CarNum == _carnum) {
                    CarStats cs = cs_p->next->cs;
                    printf("���ƺ�: %s     �޸�Ϊ: ",cs.plate);
                    scanf("%s", _plate); if (_plate[0] != '-') strcpy(cs_p->next->cs.plate,_plate); 
                    printf("�������ͱ���: %c     �޸�Ϊ: ",cs.code);
                    getchar();scanf("%c", &_code);getchar(); if (_code != '-') cs_p->next->cs.code = _code;
                    printf("��������: %s     �޸�Ϊ: ",cs.CarName);
                    scanf("%s", _carname); if (_carname[0] != '-') strcpy(cs_p->next->cs.CarName,_carname); 
                    printf("�ŵ���ʽ: %s     �޸�Ϊ: ",cs.mode);
                    scanf("%s", _mode); if (_mode[0] != '-') strcpy(cs_p->next->cs.mode,_mode); 
                    printf("ÿ�����: %.2f     �޸�Ϊ: ",cs.rent); 
                    scanf("%f", &_rent); if (_rent != 0) cs_p->next->cs.rent = _rent;
                    printf("����״̬: %c     �޸�Ϊ: ",cs.stats);
                    getchar();scanf("%c", &_stats);getchar(); if (_stats != '-') cs_p->next->cs.stats = _stats;
                    break;
                }
                cs_p = cs_p->next;
            }
            break;
        case 3:
            printf("�����붩����Ϣ(���޸Ĳ�������'-')\n");
            printf("�������: ");
            scanf("%s", _rentnum);
            while (rs_p->next != NULL) {
                if (!strcmp(rs_p->next->rs.RentNum,_rentnum)) {
                    RentStats rs = rs_p->next->rs;
                    printf("���֤��: %s     �޸�Ϊ: ",rs.id);
                    scanf("%s",_id);  if (_id[0] != '-') strcpy(rs_p->next->rs.id,_id); 
                    printf("��������: %s     �޸�Ϊ: ",rs.name);
                    scanf("%s", _name); if (_name[0] != '-') strcpy(rs_p->next->rs.name,_name); 
                    printf("�ֻ�����: %s     �޸�Ϊ: ",rs.phone);
                    scanf("%s", _phone); if (_phone[0] != '-') strcpy(rs_p->next->rs.phone,_phone); 
                    printf("���ó������: %d     �޸�Ϊ: ",rs.CarNum);
                    scanf("%d", &_carnum); if (_carnum) rs_p->next->rs.CarNum = _carnum;
                    printf("ȡ��ʱ��: %s     �޸�Ϊ: ",rs.TakeTime);
                    scanf("%s", _taketime); if (_taketime[0] != '-') strcpy(rs_p->next->rs.TakeTime,_taketime); 
                    printf("ԤԼ����ʱ��: %s     �޸�Ϊ: ",rs.BackTime);
                    scanf("%s", _backtime); if (_backtime[0] != '-') strcpy(rs_p->next->rs.BackTime,_backtime); 
                    printf("Ѻ��: %.2f     �޸�Ϊ: ",rs.deposit);
                    scanf("%f", &_deposit); if (_deposit != 0) rs_p->next->rs.deposit = _deposit;
                    printf("ʵ�ʻ���ʱ��: %s     �޸�Ϊ: ",rs.rBackTime);
                    scanf("%s", _rbacktime); if (_rbacktime[0] != '-') strcpy(rs_p->next->rs.rBackTime,_rbacktime);
                    printf("Ӧ�ɷ���: %.2f     �޸�Ϊ: ",rs.fee);
                    scanf("%f", &_fee); if (_fee != 0) rs_p->next->rs.fee = _fee;
                    printf("ʵ�ɷ���: %.2f     �޸�Ϊ: ",rs.rfee);
                    scanf("%f", &_rfee); if (_rfee != 0) rs_p->next->rs.rfee = _rfee;
                    break;
                }
                rs_p = rs_p ->next;
            }
            break;
        default:
            printf("��Ϣѡ�����!\n");
            break;
    }
} 

void change_cartype() {} //�޸ĳ���������Ϣ

void change_carstats() {} //�޸ĳ���������Ϣ

void change_rentstats() {} //�޸Ķ�����Ϣ

void function_search() {
    CarStatsNode *cs_p=head_cs;
    RentStatsNode *rs_p=head_rs;
    int inf = 0,flag=0,inf2;
    int types = 0,_carnumr[1024],_carnumr1;
    char _typenamecode[10],_startime[TIME_LENTH],_endtime[TIME_LENTH];
    char _typename[CARTYPENAME_LENTH],_plate[PLATE_LENTH],_carname[CARNAME_LENTH],_code,_id[ID_LENTH],_phone[PHONE_LENTH];
    printf("��ѡ����Ҫ���ҵ���Ϣ��1��������������Ϣ||2��������������Ϣ||3����������Ϣ��:");
        scanf("%d",&inf);
        switch (inf) {
            case 1:
                flag=0;
                cs_p = head_cs;
                printf("�����������ѯ�����?(0~5): ");
                scanf("%d",&types);
                printf("\n");
                if (!types) { //ģ����ѯ
                    while (cs_p->next !=NULL) {
                        if (cs_p->next->cs.stats == 'y') {
                            CarStats cs = cs_p->next->cs;
                            printf("���ƺ�: %s\n",cs.plate);
                            printf("�������ͱ���: %c\n",cs.code);
                            printf("��������: %s\n",cs.CarName);
                            printf("�ŵ���ʽ: %s\n",cs.mode); 
                            printf("ÿ�����: %.2f\n\n",cs.rent); 
                            flag=1;
                        }
                        cs_p = cs_p->next;
                    }
                }
                else {
                    for (int i=1;i<=types;i++) {  //�������복��(�ۺϲ���)
                        printf("����%d: ",i);
                        scanf("%s", _typename);
                        printf("\n");
                        if (!strcmp(_typename,"������")) _typenamecode[i]='1';
                        else if (!strcmp(_typename,"������")) _typenamecode[i]='2';
                        else if (!strcmp(_typename,"������")) _typenamecode[i]='3';
                        else if (!strcmp(_typename,"SUV")) _typenamecode[i]='4';
                        else _typenamecode[i]='5';
 //                       printf("%c ",_typenamecode[i]);
                    }
                    for (int i=1;i<=types;i++) {
                        cs_p = head_cs;
                        while (cs_p->next !=NULL) {
                            if (cs_p->next->cs.stats == 'y' && cs_p->next->cs.code == _typenamecode[i]) {
                                CarStats cs = cs_p->next->cs;
                                printf("���ƺ�: %s\n",cs.plate);
                                printf("�������ͱ���: %c\n",cs.code);
                                printf("��������: %s\n",cs.CarName);
                                printf("�ŵ���ʽ: %s\n",cs.mode); 
                                printf("ÿ�����: %.2f\n\n",cs.rent); 
                                flag=1;
                            }
                            cs_p = cs_p->next;
                        }
                    }
                }
                if (!flag) search_not();
                break;
            case 2:
                flag=0;
                cs_p = head_cs;
                printf("�������ѯ����(��ȷ����������'-')\n");
                printf("���ƺ�: ");
                scanf("%s", _plate);
                printf("��������: ");
                scanf("%s",_carname);
                printf("����״̬: ");
                getchar();scanf("%c",&_code);getchar();
                while (cs_p->next !=NULL) {
                    CarStats cs = cs_p->next->cs;
//                    printf("%d ",kmp(cs.plate,_plate));
                    if ( ( kmp(cs.plate,_plate) || _plate[0] == '-' ) && ( kmp(cs.CarName,_carname) || _carname[0]=='-') && ( cs.code == _code || _code == '-') ) {
                        printf("\n");
                        printf("���ƺ�: %s\n",cs.plate);
                        printf("�������ͱ���: %c\n",cs.code);
                        printf("��������: %s\n",cs.CarName);
                        printf("�ŵ���ʽ: %s\n",cs.mode); 
                        printf("ÿ�����: %.2f\n\n",cs.rent); 
                        flag=1;
                    }
                    cs_p = cs_p->next;
                }
                if (!flag) search_not();
                break;
            case 3:
                flag=0;
                rs_p = head_rs;
                printf("�������ѯ����(1����������Ϣ||2����������Ϣ||3�����⳵ʱ�䷶Χ)\n");
                scanf("%d",&inf2);
                if (inf2 ==1 ) { //������Ϣ��ѯ
                    printf("�����������Ϣ(��ȷ������'-')\n");
                    printf("���֤��: ");
                    scanf("%s", _id);
                    printf("�绰����: ");
                    scanf("%s", _phone);
                    while (rs_p->next != NULL) {
                        RentStats rs = rs_p->next->rs;
                        if ( (kmp(rs.id,_id) || _id[0] == '-' ) && ( kmp(rs.phone,_phone) || _phone[0] == '-') ) {
                            flag = 1;
                            printf("\n");
                            printf("�������: %s\n",rs.RentNum);
                            printf("���֤��: %s\n",rs.id);
                            printf("��������: %s\n",rs.name);
                            printf("�ֻ�����: %s\n",rs.phone);
                            printf("���ó������: %d\n",rs.CarNum);
                            printf("ȡ��ʱ��: %s\n",rs.TakeTime); 
                            printf("ԤԼ����ʱ��: %s\n",rs.BackTime);
                            printf("Ѻ��: %.2f\n",rs.deposit);
                            printf("ʵ�ʻ���ʱ��: %s\n",rs.rBackTime);
                            printf("Ӧ�ɷ���: %.2f\n",rs.fee);
                            printf("ʵ�ɷ���: %.2f\n",rs.rfee);
                        }
                        rs_p = rs_p -> next;
                    }
                }
                else if (inf2 == 2) {
                    _carnumr1 = 0;
                    cs_p = head_cs;
                    printf("�����복����Ϣ(��ȷ������'-')\n");
                    printf("���ƺ���: ");
                    scanf("%s", _plate);
                    printf("��������: ");
                    scanf("%s", _carname);
                    while (cs_p->next !=NULL) {
                        CarStats cs = cs_p->next->cs;
                        if ( ( kmp(cs.plate,_plate) || _plate[0] == '-') && ( kmp(cs.CarName,_carname) || _carname[0] == '-') ) {
                            _carnumr[_carnumr1++] = cs.CarNum;
                        }
                        cs_p = cs_p->next;
                    }
                    while (rs_p->next != NULL) {
                        RentStats rs = rs_p->next->rs;
                        for (int i=0;i<_carnumr1;i++) {
                            if ( rs.CarNum == _carnumr[i]) {
                                flag = 1;
                                printf("\n");
                                printf("�������: %s\n",rs.RentNum);
                                printf("���֤��: %s\n",rs.id);
                                printf("��������: %s\n",rs.name);
                                printf("�ֻ�����: %s\n",rs.phone);
                                printf("���ó������: %d\n",rs.CarNum);
                                printf("ȡ��ʱ��: %s\n",rs.TakeTime); 
                                printf("ԤԼ����ʱ��: %s\n",rs.BackTime);
                                printf("Ѻ��: %.2f\n",rs.deposit);
                                printf("ʵ�ʻ���ʱ��: %s\n",rs.rBackTime);
                                printf("Ӧ�ɷ���: %.2f\n",rs.fee);
                                printf("ʵ�ɷ���: %.2f\n",rs.rfee);
                            }
                        }
                        rs_p = rs_p -> next;
                    }
                }
                else if (inf2 == 3) {
                    printf("������ʱ������(��ʽxxxx/xx/xx-xx:xx)\n");
                    printf("��ʼʱ��: ");
                    scanf("%s",_startime);
                    printf("��ֹ�¼�: ");
                    scanf("%s",_endtime);
                    while (rs_p->next !=NULL) {
                        RentStats rs = rs_p->next->rs;
                        if ( strcmp(_startime,rs.TakeTime)<=0 && strcmp(_endtime,rs.rBackTime)>=0 ) {
                                flag = 1;
                                printf("\n");
                                printf("�������: %s\n",rs.RentNum);
                                printf("���֤��: %s\n",rs.id);
                                printf("��������: %s\n",rs.name);
                                printf("�ֻ�����: %s\n",rs.phone);
                                printf("���ó������: %d\n",rs.CarNum);
                                printf("ȡ��ʱ��: %s\n",rs.TakeTime); 
                                printf("ԤԼ����ʱ��: %s\n",rs.BackTime);
                                printf("Ѻ��: %.2f\n",rs.deposit);
                                printf("ʵ�ʻ���ʱ��: %s\n",rs.rBackTime);
                                printf("Ӧ�ɷ���: %.2f\n",rs.fee);
                                printf("ʵ�ɷ���: %.2f\n",rs.rfee);
                        }
                        rs_p = rs_p->next;
                    }
                }
                if (!flag) printf("�ܱ�Ǹ!û�з��������Ķ�����Ϣ");
                break;
            default:
                printf("��Ϣѡ����� !\n");
                break;
        }
} 

void search_cartype() {} //��ѯ����������Ϣ

void search_carstats() {} //��ѯ����������Ϣ

void search_rentstats() {} //��ѯ������Ϣ

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
    while (getchar()!='\n');
    while (getchar()!='\n');
    printf("\n\n");
    printf("*************��ӭʹ�ó������޹���ϵͳ************\n");
    printf("====================�����б�=====================\n");
    printf("||                 1.��Ϣ¼��                  ||\n");
    printf("||                 2.��Ϣɾ��                  ||\n");
    printf("||                 3.��Ϣ�޸�                  ||\n");
    printf("||                 4.��Ϣ��ѯ                  ||\n");
    printf("||                 5.���ݷ���                  ||\n");
    printf("||                 6.�汾��Ϣ                  ||\n");
    printf("||                 7.��ϵ����                  ||\n");
    printf("||                 8.�˳�ϵͳ                  ||\n");
    printf("================================================\n");
    printf("����������ʹ�õĹ���(1~8): ");
}

void end_word() {
    printf("\n����ʹ�ý������������޹���ϵͳ�˳��ɹ�!\n");
}

void new_ok() {
    printf("��Ϣ¼��ɹ�!\n");
}

void delete_ok() {
    printf("��Ϣɾ���ɹ�!\n");
}

void change_ok() {
    printf("��Ϣ�޸ĳɹ�!\n");
}

int kmp(char* s, char* p)  {  
    int i = 0;  
    int j = 0;  
    int next[20];
    int sLen = strlen(s);  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    while (j < pLen - 1)  {  
        //p[k]��ʾǰ׺��p[j]��ʾ��׺    
        if (k == -1 || p[j] == p[k])  {  
            ++j;  
            ++k;  
            if (p[j] != p[k])  
                next[j] = k;   
            else  
                next[j] = next[k];  
        }  
        else  {  
            k = next[k];  
        }  
    }  
    i=0;j=0;
    while (i < sLen && j < pLen)  {  
        if (j == -1 || s[i] == p[j])  {  
            i++;  
            j++;  
        }  
        else  {  
            j = next[j];  
        }  
    }  
    if (j == pLen)  
        return 1;  
    else  
        return 0;  
}  

void search_not() {
    printf("�ܱ�Ǹ��û�з�����Ҫ��ĳ���\n");
}

void data_analyze() {
    int inf;
    printf("����������鿴�����ݷ���(1�������ͻ�����Ϣ||2�������͵���Ӫҵ��||3��������ȫ��Ӫҵ��||4����10�����⳵): ");
    scanf("%d",&inf);
    switch (inf) {  
        case 1:
            cartype_inf();
            break;
        case 2:
            month_money();
            break;
        case 3:
            year_money();
            break;
        case 4:
            ten_high();
            break;
        default:
            printf("���ݷ����鿴����");
            break;
    }

}

void cartype_inf() {
    CarStatsNode *cs_p = head_cs;
    int _amount[6],_y[6],_n[6];
    memset(_amount, 0, sizeof(_amount));
    memset(_y, 0, sizeof(_y));
    memset(_n, 0, sizeof(_n));
    while (cs_p->next !=NULL) {
        CarStats cs = cs_p->next->cs;
        int cd=(int)cs.code-'0';
//        printf("%d %c\n",cd,cs.stats);
        _amount[cd]++;
        if (cs.stats == 'y') _y[cd]++;
        else _n[cd]++;
        cs_p = cs_p->next;
    }
    time_t currentTm = time(NULL);		
	printf("\nͳ��ʱ��:%s",asctime(localtime(&currentTm)));
    printf("������������������������������������������������������������������������������������������\n");
    printf("| �������� | �������� | �ѳ����� | δ������ |\n" );
    printf("������������������������������������������������������������������������������������������\n");
    printf("|  ������  | %4d     | %4d     | %4d     |\n",_amount[1],_y[1],_n[1]);
    printf("������������������������������������������������������������������������������������������\n");
    printf("|  ������  | %4d     | %4d     | %4d     |\n",_amount[2],_y[2],_n[2]);
    printf("������������������������������������������������������������������������������������������\n");
    printf("|  ������  | %4d     | %4d     | %4d     |\n",_amount[3],_y[3],_n[3]);
    printf("������������������������������������������������������������������������������������������\n");
    printf("|   SUV    | %4d     | %4d     | %4d     |\n",_amount[4],_y[4],_n[4]);
    printf("������������������������������������������������������������������������������������������\n");
    printf("| 7��������| %4d     | %4d     | %4d     |\n",_amount[5],_y[5],_n[5]);
    printf("������������������������������������������������������������������������������������������\n");
    printf("|   �ܼ�   | %4d     | %4d     | %4d     |\n",_amount[1]+_amount[2]+_amount[3]+_amount[4]+_amount[5],_y[1]+_y[2]+_y[3]+_y[4]+_y[5],_n[1]+_n[2]+_n[3]+_n[4]+_n[5]);
    printf("������������������������������������������������������������������������������������������\n");
}

void month_money() {
    int _carmon1[10010],k=0;
    float _money[10],_carmon2[10010];
    char _time[TIME_LENTH]={},_time2[TIME_LENTH]={},_time3[TIME_LENTH]={};
    memset(_money,0,sizeof(_money));
    printf("����������(��ʽ:xxxx/xx): ");
    scanf("%s",_time);
    for (int i=0;i<=6;i++) {
        _time2[i] = _time[i];
        _time3[i] = _time[i];
    }
    _time2[7]=_time3[7]='/';
    _time2[8]=_time2[9]='0';
    _time3[8]=_time3[9]='9';
    _time2[10]=_time3[10]='-';
    _time2[11]=_time2[12]='0';
    _time3[11]=_time3[12]='9';
    _time2[13]=_time3[13]=':';
    _time2[14]=_time2[15]='0';
    _time3[14]=_time3[15]='9';
//    printf("%s\n",_time2);
//    printf("%s\n",_time3);
    RentStatsNode *rs_p = head_rs;
    CarStatsNode *cs_p = head_cs;
    while (rs_p->next !=NULL) {
        RentStats rs= rs_p->next->rs;
        if ( strcmp(rs.rBackTime,_time2)>=0 && strcmp(rs.rBackTime,_time3)<0 ) {
            _carmon1[k] = rs.CarNum;
            _carmon2[k++] = rs.rfee;
        }
        rs_p = rs_p->next;
    }
 /*   for (int i=0;i<k;i++) {
        printf("%d %.2f",_carmon1[i],_carmon2[i]);
    }*/
    while (cs_p->next !=NULL) {
        CarStats cs = cs_p->next->cs;
        for (int i=0;i<k;i++) {
            if (cs.CarNum == _carmon1[i]) 
                _money[cs.code-'0']+=_carmon2[i];
        }
        cs_p=cs_p->next;
    }
    printf("ͳ��ʱ��: %s    ������λ: Ԫ�����\n",_time);
    printf("����������������������������������������������������������\n");
    printf("|  ��������   |    Ӫҵ��   |\n");
    printf("����������������������������������������������������������\n");
    printf("|   ������    |   %7.2f   |\n",_money[1]);
    printf("����������������������������������������������������������\n");
    printf("|   ������    |   %7.2f   |\n",_money[2]);
    printf("����������������������������������������������������������\n");
    printf("|   ������    |   %7.2f   |\n",_money[3]);
    printf("����������������������������������������������������������\n");
    printf("|    SUV      |   %7.2f   |\n",_money[4]);
    printf("����������������������������������������������������������\n");
    printf("|  ���������� |   %7.2f   |\n",_money[5]);
    printf("����������������������������������������������������������\n");

}

void year_money() {
    char _cp[1001][PLATE_LENTH],_cm[1001][CARNAME_LENTH];
    float _mon1[1001],_rate[1001];
    int _mon2[1001];
    char _time[TIME_LENTH]={},_time2[TIME_LENTH]={},_time3[TIME_LENTH]={};
    int k;
    printf("������鿴���(��ʽ: xxxx): ");
    scanf("%s",_time);
    for (int i=0;i<4;i++) {
        _time3[i]=_time[i];
        _time2[i]=_time[i];
    }
    _time2[4]=_time3[4]='/';
    _time2[5]=_time2[6]='0';
    _time3[5]=_time3[6]='9';
    _time2[7]=_time3[7]='/';
    _time2[8]=_time2[9]='0';
    _time3[8]=_time3[9]='9';
    _time2[10]=_time3[10]='-';
    _time2[11]=_time2[12]='0';
    _time3[11]=_time3[12]='9';
    _time2[13]=_time3[13]=':';
    _time2[14]=_time2[15]='0';
    _time3[14]=_time3[15]='9';
//    printf("%s\n",_time2);
//    printf("%s\n",_time3);
    RentStatsNode *rs_p = head_rs;
    CarStatsNode *cs_p = head_cs;
    while (rs_p->next !=NULL) {
        RentStats rs= rs_p->next->rs;
        if ( strcmp(rs.rBackTime,_time2)>=0 && strcmp(rs.rBackTime,_time3)<0 ) {
            _mon2[k] = rs.CarNum;
            _mon1[k] = rs.fee;
            _rate[k] = rs.rBackTime - rs.TakeTime;
        }
        rs_p = rs_p->next;
    }
    while (cs_p->next !=NULL) {
        CarStats cs = cs_p->next->cs;
        for (int i=0;i<k;i++) {
            if (cs.CarNum == _mon2[i]) {
                strcpy(_cp[i],cs.plate);
                strcpy(_cm[i],cs.CarName);
            }
        }
        cs_p=cs_p->next;
    }
    printf("���: %s��\n",_time);
    printf("������������������������������������������������������������������������������������������������\n");
    printf("|  ���ƺ�  |  ��������  |  Ӫҵ��  |  ������  |\n");
    for 
}

void ten_high() {}

