#pragma warning( disable : 4996)
#pragma comment(lib,"user32")
#pragma comment(lib,"gdi32")
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "define.h"

char title1[TITLE_LENTH], title2[TITLE_LENTH], title3[TITLE_LENTH];
char mons[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int now_car_num;

CarTypeNode* ct_p1 = NULL, * head_ct = NULL;
CarStatsNode* cs_p1 = NULL, * head_cs = NULL;
RentStatsNode* rs_p1 = NULL, * head_rs = NULL;

HWND WINAPI GetConsoleWindow();

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
void new_cartype(char _code, char _typename[CARTYPENAME_LENTH], int _amount); // 录入车辆分类信息
void new_carstats(int _carnum, char _plate[PLATE_LENTH], char _code, char _carname[CARNAME_LENTH], char _mode[MODE_LENTH], float _rent, char _stats); //录入车辆基本信息
void new_rentstats(char _rentnum[RENTNUM_LENTH], char _id[ID_LENTH], char _name[GUESTNAME_LENTH], char _phone[PHONE_LENTH], int _carnum, char _taketime[TIME_LENTH], char _backtime[TIME_LENTH], float _deposit, char _rbacktime[TIME_LENTH], float _fee, float _rfee); //录入订单信息
void function_delete(); //?  删除功能
void delete_cartype(char _code); //删除车辆分类信息
void delete_carstats(int _carnum); //删除车辆基本信息
void delete_rentstats(char _rentnum[RENTNUM_LENTH]); //删除订单信息
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
int kmp(char* s, char* p); //kmp算法
void search_not();//查询失败
void data_analyze();
void cartype_inf();
void month_money();
void year_money();
void ten_high();
int calc_day(char* a, char* b);
void version_inf();
void my_inf();
void print_image(int how_much[]);
HDC set_pen(int a, int b, int c, int d);
//输出调试用
void watch_cartype();
void watch_carstats();
void watch_rantstats();

int main() {
	read_init();
	int func_type = 0;
	while (func_type != 8) {
		func_list();
		scanf("%d", &func_type);
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
	char* line, * record;
	char delims[] = ",";
	int k = 0;
	FILE* fp = fopen("CarTypeFile.csv", "rb");
	if (fp == NULL) {
		printf("Open Error !\n");
		return;
	}
	fscanf(fp, "%[^\n]", title1);
	//   printf("%s\n",title);
	fseek(fp, 36L, SEEK_SET);
	while ((line = fgets(buf, sizeof(buf), fp)) != NULL) {
		record = strtok(line, delims);
		CarTypeNode* ct = calloc(1, sizeof(CarTypeNode));
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
				strcpy(ct->ct.TypeName, record);
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
			k = (k + 1) % 3;
			record = strtok(NULL, delims);
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
	char* line, * record;
	char delims[] = ",";
	int k = 0;
	FILE* fp = fopen("CarStatsFile.csv", "rb");
	if (fp == NULL) {
		printf("Open Error !\n");
		return;
	}
	fscanf(fp, "%[^\n]", title2);
	fseek(fp, 72L, SEEK_SET);
	while ((line = fgets(buf, sizeof(buf), fp)) != NULL) {
		record = strtok(line, delims);
		CarStatsNode* cs = calloc(1, sizeof(CarStatsNode));
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
				strcpy(cs->cs.plate, record);
				//                   printf("%s ",cs->cs.plate);
				break;
			case 2:
				cs->cs.code = record[0];
				//                    printf("%c ",cs->cs.code);
				break;
			case 3:
				strcpy(cs->cs.CarName, record);
				//                    printf("%s ",cs->cs.CarName);
				break;
			case 4:
				strcpy(cs->cs.mode, record);
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
			k = (k + 1) % 7;
			record = strtok(NULL, delims);
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
	char* line, * record;
	char delims[] = ",";
	int k = 0;
	FILE* fp = fopen("RentStatsFile.csv", "rb");
	if (fp == NULL) {
		printf("Open Error !\n");
		return;
	}
	fscanf(fp, "%[^\n]", title3);
	fseek(fp, 122L, SEEK_SET);
	while ((line = fgets(buf, sizeof(buf), fp)) != NULL) {
		record = strtok(line, delims);
		RentStatsNode* rs = calloc(1, sizeof(RentStatsNode));
		//       cars[csnum] = calloc(1,sizeof(CarStatsNode));
		//       cars[csnum++] = cs;
		while (record != NULL) {
			//           printf("%s",record);
			switch (k) {
			case 0:
				strcpy(rs->rs.RentNum, record);
				//                   printf("%s=",record);
				//                  printf("%s  ",rs->rs.RentNum);
				break;
			case 1:
				strcpy(rs->rs.id, record);
				//                   printf("%s ",cs->cs.plate);
				break;
			case 2:
				strcpy(rs->rs.name, record);
				//                    printf("%c ",cs->cs.code);
				break;
			case 3:
				strcpy(rs->rs.phone, record);
				//                    printf("%s ",rs->rs.id);
				break;
			case 4:
				rs->rs.CarNum = atoi(record);
				//                    printf("%d ",rs->rs.CarNum);
				break;
			case 5:
				strcpy(rs->rs.TakeTime, record);
				//                   printf("%.2f ",cs->cs.rent);
				break;
			case 6:
				strcpy(rs->rs.BackTime, record);
				//                   printf("%c ",cs->cs.stats);
				break;
			case 7:
				rs->rs.deposit = atof(record);
				break;
			case 8:
				strcpy(rs->rs.rBackTime, record);
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
			k = (k + 1) % 11;
			record = strtok(NULL, delims);
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
	FILE* fp = fopen("CarTypeFile(1).csv", "wb+");
	if (fp == NULL) {
		printf("Open Error !\n");
		return;
	}
	CarTypeNode* ct_p = head_ct;
	fprintf(fp, "%s\n", title1);
	while (ct_p->next != NULL) {
		//       printf("%c,%s,%d\n",ct_p->next->ct.code,ct_p->next->ct.TypeName,ct_p->next->ct.amount);
		fprintf(fp, "%c,%s,%d\n", ct_p->next->ct.code, ct_p->next->ct.TypeName, ct_p->next->ct.amount);
		ct_p = ct_p->next;
	}
	fclose(fp);
}

void carstats_write() {
	//   printf("1");
	FILE* fp = fopen("CarStatsFile(1).csv", "wb+");
	if (fp == NULL) {
		printf("Open Error !\n");
		return;
	}
	CarStatsNode* cs_p = head_cs;
	fprintf(fp, "%s\n", title2);
	while (cs_p->next != NULL) {
		//       printf("%c,%s,%d\n",ct_p->next->ct.code,ct_p->next->ct.TypeName,ct_p->next->ct.amount);
		fprintf(fp, "%d,%s,%c,%s,%s,%.2f,%c\n", cs_p->next->cs.CarNum, cs_p->next->cs.plate, cs_p->next->cs.code, cs_p->next->cs.CarName, cs_p->next->cs.mode, cs_p->next->cs.rent, cs_p->next->cs.stats);
		cs_p = cs_p->next;
	}
	fclose(fp);
}

void rentstats_write() {
	FILE* fp = fopen("RentStatsFile(1).csv", "wb+");
	if (fp == NULL) {
		printf("Open Error !\n");
		return;
	}
	RentStatsNode* rs_p = head_rs;
	fprintf(fp, "%s\n", title3);
	RentStats rs_n;
	while (rs_p->next != NULL) {
		rs_n = rs_p->next->rs;
		fprintf(fp, "%s,%s,%s,%s,%d,%s,%s,%.2f,%s,%.2f,%.2f\n", rs_n.RentNum, rs_n.id, rs_n.name, rs_n.phone, rs_n.CarNum, rs_n.TakeTime, rs_n.BackTime, rs_n.deposit, rs_n.rBackTime, rs_n.fee, rs_n.rfee);
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
	case 5:
		data_analyze();
		break;
	case 6:
		version_inf();
		break;
	case 7:
		my_inf();
		break;
	default:
		printf("功能选择错误!\n");
		break;
	}
}

void function_new() {
	int inf;
	char _code, _stats;
	char _typename[CARTYPENAME_LENTH], _rentnum[RENTNUM_LENTH], _id[ID_LENTH], _name[GUESTNAME_LENTH], _phone[PHONE_LENTH], _taketime[TIME_LENTH], _backtime[TIME_LENTH], _rbacktime[TIME_LENTH], _plate[PLATE_LENTH], _carname[CARNAME_LENTH], _mode[MODE_LENTH];
	int _amount, _carnum;
	float _deposit, _fee, _rfee, _rent;
	printf("请选择您要录入的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）: ");
	scanf("%d", &inf);
	switch (inf) {
	case 1:
		printf("请输入车辆分类信息\n");
		printf("车辆类型编码: ");
		getchar();
		scanf("%c", &_code);
		getchar();
		//            printf("%c",_code);
		printf("车辆类型名称: ");
		scanf("%s", _typename);
		printf("库存数量: ");
		scanf("%d", &_amount);
		//            printf("%c %s %d",_code,_typename,_amount);
		new_cartype(_code, _typename, _amount);
		break;
	case 2:
		printf("请输入车辆基本信息\n");
		_carnum = (++now_car_num);
		printf("车牌号: ");
		scanf("%s", _plate);
		printf("车辆类型编码: ");
		getchar(); scanf("%c", &_code); getchar();
		printf("车辆名称: ");
		scanf("%s", _carname);
		printf("排档方式: ");
		scanf("%s", _mode);
		printf("每日租金: ");
		scanf("%f", &_rent);
		printf("出租状态: ");
		getchar(); scanf("%c", &_stats); getchar();
		new_carstats(_carnum, _plate, _code, _carname, _mode, _rent, _stats);
		break;
	case 3:
		printf("请输入订单信息\n");
		printf("订单编号: ");
		scanf("%s", _rentnum);
		printf("身份证号: ");
		scanf("%s", _id);
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
		new_rentstats(_rentnum, _id, _name, _phone, _carnum, _taketime, _backtime, _deposit, _rbacktime, _fee, _rfee);
		break;
	default:
		printf("信息选择错误!\n");
		break;
	}
}

void new_cartype(char _code, char _typename[CARTYPENAME_LENTH], int _amount) {
	CarTypeNode* ct_p = head_ct;
	while (ct_p->next != NULL) ct_p = ct_p->next;
	CarTypeNode* ct = calloc(1, sizeof(CarTypeNode));
	ct->ct.code = _code;
	strcpy(ct->ct.TypeName, _typename);
	ct->ct.amount = _amount;
	ct->head = NULL;
	ct->next = NULL;
	ct_p->next = ct;
	new_ok();
	//    watch_cartype();
} //录入车辆分类信息

void new_carstats(int _carnum, char _plate[PLATE_LENTH], char _code, char _carname[CARNAME_LENTH], char _mode[MODE_LENTH], float _rent, char _stats) {
	CarStatsNode* cs_p = head_cs;
	while (cs_p->next != NULL) cs_p = cs_p->next;
	CarStatsNode* cs = calloc(1, sizeof(CarStatsNode));
	cs->cs.CarNum = _carnum;
	strcpy(cs->cs.plate, _plate);
	cs->cs.code = _code;
	strcpy(cs->cs.CarName, _carname);
	strcpy(cs->cs.mode, _mode);
	cs->cs.rent = _rent;
	cs->cs.stats = _stats;
	cs->head = NULL;
	cs->next = NULL;
	cs_p->next = cs;
	new_ok();
	//   watch_carstats();
}//录入车辆基本信息

void new_rentstats(char _rentnum[RENTNUM_LENTH], char _id[ID_LENTH], char _name[GUESTNAME_LENTH], char _phone[PHONE_LENTH], int _carnum, char _taketime[TIME_LENTH], char _backtime[TIME_LENTH], float _deposit, char _rbacktime[TIME_LENTH], float _fee, float _rfee) {
	RentStatsNode* rs_p = head_rs;
	while (rs_p->next != NULL) rs_p = rs_p->next;
	RentStatsNode* rs = calloc(1, sizeof(RentStatsNode));
	strcpy(rs->rs.RentNum, _rentnum);
	strcpy(rs->rs.id, _id);
	strcpy(rs->rs.name, _name);
	strcpy(rs->rs.phone, _phone);
	rs->rs.CarNum = _carnum;
	strcpy(rs->rs.TakeTime, _taketime);
	strcpy(rs->rs.BackTime, _backtime);
	rs->rs.deposit = _deposit;
	strcpy(rs->rs.rBackTime, _rbacktime);
	rs->rs.fee = _fee;
	rs->rs.rfee = _rfee;
	rs->next = NULL;
	rs_p->next = rs;
	new_ok();
	//    watch_rentstats();
} //录入订单信息

void function_delete() {
	int inf, _carnum;
	char _code;
	char _rentnum[RENTNUM_LENTH];
	printf("请选择您要删除的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）: ");
	scanf("%d", &inf);
	switch (inf) {
	case 1:
		printf("请输入车辆类型编码: ");
		getchar(); scanf("%c", &_code); getchar();
		//           printf("%c\n",_code);
		delete_cartype(_code);
		//           printf("1");
		break;
	case 2:
		printf("请输入车辆编号: ");
		scanf("%d", &_carnum);
		delete_carstats(_carnum);
		break;
	case 3:
		printf("请输入订单编号: ");
		scanf("%s", _rentnum);
		delete_rentstats(_rentnum);
		break;
	default:
		printf("信息选择错误 !\n");
		break;
	}
}

void delete_cartype(char _code) {
	CarTypeNode* ct_p = head_ct;
	while (ct_p->next != NULL) {
		if (ct_p->next->ct.code == _code) {
			//                printf("1");
			CarTypeNode* ct = ct_p->next;
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
} //删除车辆分类信息

void delete_carstats(int _carnum) {
	CarStatsNode* cs_p = head_cs;
	while (cs_p->next != NULL) {
		if (cs_p->next->cs.CarNum == _carnum) {
			CarStatsNode* cs = cs_p->next;
			cs_p->next = cs->next;
			free(cs);
			break;
		}
		cs_p = cs_p->next;
	}
	delete_ok();
} //删除车辆基本信息

void delete_rentstats(char _rentnum[RENTNUM_LENTH]) {
	RentStatsNode* rs_p = head_rs;
	while (rs_p->next != NULL) {
		if (!strcmp(rs_p->next->rs.RentNum, _rentnum)) {
			RentStatsNode* rs = rs_p->next;
			rs_p->next = rs->next;
			free(rs);
			break;
		}
		rs_p = rs_p->next;
	}
	delete_ok();
} //删除订单信息

void function_change() {
	CarTypeNode* ct_p = head_ct;
	CarStatsNode* cs_p = head_cs;
	RentStatsNode* rs_p = head_rs;
	int inf = 0;
	char _code, _stats;
	char _typename[CARTYPENAME_LENTH], _rentnum[RENTNUM_LENTH], _id[ID_LENTH], _name[GUESTNAME_LENTH], _phone[PHONE_LENTH], _taketime[TIME_LENTH], _backtime[TIME_LENTH], _rbacktime[TIME_LENTH], _plate[PLATE_LENTH], _carname[CARNAME_LENTH], _mode[MODE_LENTH];
	int _amount = 0, _carnum = 0;
	float _deposit = 0, _fee = 0, _rfee = 0, _rent = 0;
	printf("请选择您要修改的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）: ");
	scanf("%d", &inf);
	switch (inf) {
	case 1:
		printf("请输入车辆分类信息(不修改部分输入'-')\n");
		printf("车辆类型编码: ");
		getchar();
		scanf("%c", &_code);
		getchar();

		while (ct_p->next != NULL) {
			if (ct_p->next->ct.code == _code) {
				CarType ct = ct_p->next->ct;
				printf("车辆类型名称: %s    修改为: ", ct.TypeName);
				scanf("%s", _typename); if (_typename[0] != '-') strcpy(ct_p->next->ct.TypeName, _typename);
				printf("库存数量: %d     修改为: ", ct.amount);
				scanf("%d", &_amount); if (_amount) ct_p->next->ct.amount = _amount;
				break;
			}
			ct_p = ct_p->next;
		}
		//            printf("%c %s %d",_code,_typename,_amount);
		break;
	case 2:
		printf("请输入车辆基本信息(不修改部分输入'-')\n");
		printf("请输入车辆编号: ");
		scanf("%d", &_carnum);
		while (cs_p->next != NULL) {
			if (cs_p->next->cs.CarNum == _carnum) {
				CarStats cs = cs_p->next->cs;
				printf("车牌号: %s     修改为: ", cs.plate);
				scanf("%s", _plate); if (_plate[0] != '-') strcpy(cs_p->next->cs.plate, _plate);
				printf("车辆类型编码: %c     修改为: ", cs.code);
				getchar(); scanf("%c", &_code); getchar(); if (_code != '-') cs_p->next->cs.code = _code;
				printf("车辆名称: %s     修改为: ", cs.CarName);
				scanf("%s", _carname); if (_carname[0] != '-') strcpy(cs_p->next->cs.CarName, _carname);
				printf("排档方式: %s     修改为: ", cs.mode);
				scanf("%s", _mode); if (_mode[0] != '-') strcpy(cs_p->next->cs.mode, _mode);
				printf("每日租金: %.2f     修改为: ", cs.rent);
				scanf("%f", &_rent); if (_rent != 0) cs_p->next->cs.rent = _rent;
				printf("出租状态: %c     修改为: ", cs.stats);
				getchar(); scanf("%c", &_stats); getchar(); if (_stats != '-') cs_p->next->cs.stats = _stats;
				break;
			}
			cs_p = cs_p->next;
		}
		break;
	case 3:
		printf("请输入订单信息(不修改部分输入'-')\n");
		printf("订单编号: ");
		scanf("%s", _rentnum);
		while (rs_p->next != NULL) {
			if (!strcmp(rs_p->next->rs.RentNum, _rentnum)) {
				RentStats rs = rs_p->next->rs;
				printf("身份证号: %s     修改为: ", rs.id);
				scanf("%s", _id);  if (_id[0] != '-') strcpy(rs_p->next->rs.id, _id);
				printf("客人姓名: %s     修改为: ", rs.name);
				scanf("%s", _name); if (_name[0] != '-') strcpy(rs_p->next->rs.name, _name);
				printf("手机号码: %s     修改为: ", rs.phone);
				scanf("%s", _phone); if (_phone[0] != '-') strcpy(rs_p->next->rs.phone, _phone);
				printf("租用车辆编号: %d     修改为: ", rs.CarNum);
				scanf("%d", &_carnum); if (_carnum) rs_p->next->rs.CarNum = _carnum;
				printf("取车时间: %s     修改为: ", rs.TakeTime);
				scanf("%s", _taketime); if (_taketime[0] != '-') strcpy(rs_p->next->rs.TakeTime, _taketime);
				printf("预约还车时间: %s     修改为: ", rs.BackTime);
				scanf("%s", _backtime); if (_backtime[0] != '-') strcpy(rs_p->next->rs.BackTime, _backtime);
				printf("押金: %.2f     修改为: ", rs.deposit);
				scanf("%f", &_deposit); if (_deposit != 0) rs_p->next->rs.deposit = _deposit;
				printf("实际还车时间: %s     修改为: ", rs.rBackTime);
				scanf("%s", _rbacktime); if (_rbacktime[0] != '-') strcpy(rs_p->next->rs.rBackTime, _rbacktime);
				printf("应缴费用: %.2f     修改为: ", rs.fee);
				scanf("%f", &_fee); if (_fee != 0) rs_p->next->rs.fee = _fee;
				printf("实缴费用: %.2f     修改为: ", rs.rfee);
				scanf("%f", &_rfee); if (_rfee != 0) rs_p->next->rs.rfee = _rfee;
				break;
			}
			rs_p = rs_p->next;
		}
		break;
	default:
		printf("信息选择错误!\n");
		break;
	}
}

void change_cartype() {} //修改车辆分类信息

void change_carstats() {} //修改车辆基本信息

void change_rentstats() {} //修改订单信息

void function_search() {
	FILE* fp1 = fopen("车辆分类信息查询结果.csv", "wb+");
	FILE* fp2 = fopen("车辆基本信息查询结果.csv", "wb+");
	FILE* fp3 = fopen("订单信息查询结果.csv", "wb+");
	CarStatsNode* cs_p = head_cs;
	RentStatsNode* rs_p = head_rs;
	int inf = 0, flag = 0, inf2;
	int types = 0, _carnumr[1024], _carnumr1;
	char _typenamecode[10], _startime[TIME_LENTH], _endtime[TIME_LENTH];
	char _typename[CARTYPENAME_LENTH], _plate[PLATE_LENTH], _carname[CARNAME_LENTH], _code, _id[ID_LENTH], _phone[PHONE_LENTH];
	printf("请选择您要查找的信息（1——车辆分类信息||2——车辆基本信息||3——订单信息）:");
	scanf("%d", &inf);
	switch (inf) {
	case 1:
		flag = 0;
		cs_p = head_cs;
		printf("请输入您想查询几款车型?(0~5): ");
		scanf("%d", &types);
		fprintf(fp1, "车牌号,车辆类型编码,车辆名称,排档方式,每日租金\n");
		printf("\n");
		if (!types) { //模糊查询
			while (cs_p->next != NULL) {
				if (cs_p->next->cs.stats == 'y') {
					CarStats cs = cs_p->next->cs;
					printf("车牌号: %s\n", cs.plate);
					fprintf(fp1, "%s,", cs.plate);
					printf("车辆类型编码: %c\n", cs.code);
					fprintf(fp1, " %c,", cs.code);
					printf("车辆名称: %s\n", cs.CarName);
					fprintf(fp1, "%s,", cs.CarName);
					printf("排档方式: %s\n", cs.mode);
					fprintf(fp1, "%s,", cs.mode);
					printf("每日租金: %.2f\n\n", cs.rent);
					fprintf(fp1, "%.2f\n", cs.rent);
					flag = 1;
				}
				cs_p = cs_p->next;
			}
		}
		else {
			for (int i = 1; i <= types; i++) {  //处理输入车型(综合查找)
				printf("车型%d: ", i);
				scanf("%s", _typename);
				printf("\n");
				if (!strcmp(_typename, "经济型")) _typenamecode[i] = '1';
				else if (!strcmp(_typename, "商务型")) _typenamecode[i] = '2';
				else if (!strcmp(_typename, "豪华型")) _typenamecode[i] = '3';
				else if (!strcmp(_typename, "SUV")) _typenamecode[i] = '4';
				else _typenamecode[i] = '5';
				//                       printf("%c ",_typenamecode[i]);
			}
			for (int i = 1; i <= types; i++) {
				cs_p = head_cs;
				while (cs_p->next != NULL) {
					if (cs_p->next->cs.stats == 'y' && cs_p->next->cs.code == _typenamecode[i]) {
						CarStats cs = cs_p->next->cs;
						printf("车牌号: %s\n", cs.plate);
						fprintf(fp1, "%s,", cs.plate);
						printf("车辆类型编码: %c\n", cs.code);
						fprintf(fp1, " %c,", cs.code);
						printf("车辆名称: %s\n", cs.CarName);
						fprintf(fp1, "%s,", cs.CarName);
						printf("排档方式: %s\n", cs.mode);
						fprintf(fp1, "%s,", cs.mode);
						printf("每日租金: %.2f\n\n", cs.rent);
						fprintf(fp1, "%.2f\n", cs.rent);
						flag = 1;
					}
					cs_p = cs_p->next;
				}
			}
		}
		if (!flag) search_not();
		break;
	case 2:
		flag = 0;
		cs_p = head_cs;
		printf("请输入查询条件(不确定条件输入'-')\n");
		printf("车牌号: ");
		scanf("%s", _plate);
		printf("车辆名称: ");
		scanf("%s", _carname);
		printf("出租状态: ");
		getchar(); scanf("%c", &_code); getchar();
		fprintf(fp2, "车牌号,车辆类型编码,车辆名称,排档方式,每日租金\n");
		while (cs_p->next != NULL) {
			CarStats cs = cs_p->next->cs;
			//                    printf("%d ",kmp(cs.plate,_plate));
			if ((kmp(cs.plate, _plate) || _plate[0] == '-') && (kmp(cs.CarName, _carname) || _carname[0] == '-') && (cs.code == _code || _code == '-')) {
				printf("\n");
				fprintf(fp2, "%s,", cs.plate);
				printf("车牌号: %s\n", cs.plate);
				fprintf(fp2, "%c,", cs.code);
				printf("车辆类型编码: %c\n", cs.code);
				printf("车辆名称: %s\n", cs.CarName);
				fprintf(fp2, "%s,", cs.CarName);
				printf("排档方式: %s\n", cs.mode);
				fprintf(fp2, " %s,", cs.mode);
				printf("每日租金: %.2f\n\n", cs.rent);
				fprintf(fp2, "%.2f\n", cs.rent);
				flag = 1;
			}
			cs_p = cs_p->next;
		}
		if (!flag) search_not();
		break;
	case 3:
		flag = 0;
		rs_p = head_rs;
		printf("请输入查询条件(1——客人信息||2——车辆信息||3——租车时间范围)\n");
		scanf("%d", &inf2);
		fprintf(fp3, "订单编号,身份证号,客人姓名,手机号码,租用车辆编号,取车时间,预约还车时间,押金,实际还车时间,应缴费用,实缴费用\n");
		if (inf2 == 1) { //客人信息查询
			printf("请输入客人信息(不确定输入'-')\n");
			printf("身份证号: ");
			scanf("%s", _id);
			printf("电话号码: ");
			scanf("%s", _phone);
			while (rs_p->next != NULL) {
				RentStats rs = rs_p->next->rs;
				if ((kmp(rs.id, _id) || _id[0] == '-') && (kmp(rs.phone, _phone) || _phone[0] == '-')) {
					flag = 1;
					printf("\n");
					fprintf(fp3, "%s,", rs.RentNum);
					printf("订单编号: %s\n", rs.RentNum);
					fprintf(fp3, "%s,", rs.id);
					printf("身份证号: %s\n", rs.id);
					fprintf(fp3, "%s,", rs.name);
					printf("客人姓名: %s\n", rs.name);
					fprintf(fp3, "%s,", rs.phone);
					printf("手机号码: %s\n", rs.phone);
					fprintf(fp3, "%d,", rs.CarNum);
					printf("租用车辆编号: %d\n", rs.CarNum);
					fprintf(fp3, "%s,", rs.TakeTime);
					printf("取车时间: %s\n", rs.TakeTime);
					fprintf(fp3, "%s,", rs.BackTime);
					printf("预约还车时间: %s\n", rs.BackTime);
					fprintf(fp3, "%.2f,", rs.deposit);
					printf("押金: %.2f\n", rs.deposit);
					fprintf(fp3, "%s,", rs.rBackTime);
					printf("实际还车时间: %s\n", rs.rBackTime);
					fprintf(fp3, "%.2f,", rs.fee);
					printf("应缴费用: %.2f\n", rs.fee);
					fprintf(fp3, "%.2f\n", rs.rfee);
					printf("实缴费用: %.2f\n", rs.rfee);
				}
				rs_p = rs_p->next;
			}
		}
		else if (inf2 == 2) {
			_carnumr1 = 0;
			cs_p = head_cs;
			printf("请输入车辆信息(不确定输入'-')\n");
			printf("车牌号码: ");
			scanf("%s", _plate);
			printf("车辆名称: ");
			scanf("%s", _carname);
			while (cs_p->next != NULL) {
				CarStats cs = cs_p->next->cs;
				if ((kmp(cs.plate, _plate) || _plate[0] == '-') && (kmp(cs.CarName, _carname) || _carname[0] == '-')) {
					_carnumr[_carnumr1++] = cs.CarNum;
				}
				cs_p = cs_p->next;
			}
			while (rs_p->next != NULL) {
				RentStats rs = rs_p->next->rs;
				for (int i = 0; i < _carnumr1; i++) {
					if (rs.CarNum == _carnumr[i]) {
						flag = 1;
						printf("\n");
						fprintf(fp3, "%s,", rs.RentNum);
						printf("订单编号: %s\n", rs.RentNum);
						fprintf(fp3, "%s,", rs.id);
						printf("身份证号: %s\n", rs.id);
						fprintf(fp3, "%s,", rs.name);
						printf("客人姓名: %s\n", rs.name);
						fprintf(fp3, "%s,", rs.phone);
						printf("手机号码: %s\n", rs.phone);
						fprintf(fp3, "%d,", rs.CarNum);
						printf("租用车辆编号: %d\n", rs.CarNum);
						fprintf(fp3, "%s,", rs.TakeTime);
						printf("取车时间: %s\n", rs.TakeTime);
						fprintf(fp3, "%s,", rs.BackTime);
						printf("预约还车时间: %s\n", rs.BackTime);
						fprintf(fp3, "%.2f,", rs.deposit);
						printf("押金: %.2f\n", rs.deposit);
						fprintf(fp3, "%s,", rs.rBackTime);
						printf("实际还车时间: %s\n", rs.rBackTime);
						fprintf(fp3, "%.2f,", rs.fee);
						printf("应缴费用: %.2f\n", rs.fee);
						fprintf(fp3, "%.2f\n", rs.rfee);
						printf("实缴费用: %.2f\n", rs.rfee);
					}
				}
				rs_p = rs_p->next;
			}
		}
		else if (inf2 == 3) {
			printf("请输入时间区间(格式xxxx/xx/xx-xx:xx)\n");
			printf("起始时间: ");
			scanf("%s", _startime);
			printf("终止事件: ");
			scanf("%s", _endtime);
			while (rs_p->next != NULL) {
				RentStats rs = rs_p->next->rs;
				if (strcmp(_startime, rs.TakeTime) <= 0 && strcmp(_endtime, rs.rBackTime) >= 0) {
					flag = 1;
					printf("\n");
					fprintf(fp3, "%s,", rs.RentNum);
					printf("订单编号: %s\n", rs.RentNum);
					fprintf(fp3, "%s,", rs.id);
					printf("身份证号: %s\n", rs.id);
					fprintf(fp3, "%s,", rs.name);
					printf("客人姓名: %s\n", rs.name);
					fprintf(fp3, "%s,", rs.phone);
					printf("手机号码: %s\n", rs.phone);
					fprintf(fp3, "%d,", rs.CarNum);
					printf("租用车辆编号: %d\n", rs.CarNum);
					fprintf(fp3, "%s,", rs.TakeTime);
					printf("取车时间: %s\n", rs.TakeTime);
					fprintf(fp3, "%s,", rs.BackTime);
					printf("预约还车时间: %s\n", rs.BackTime);
					fprintf(fp3, "%.2f,", rs.deposit);
					printf("押金: %.2f\n", rs.deposit);
					fprintf(fp3, "%s,", rs.rBackTime);
					printf("实际还车时间: %s\n", rs.rBackTime);
					fprintf(fp3, "%.2f,", rs.fee);
					printf("应缴费用: %.2f\n", rs.fee);
					fprintf(fp3, " %.2f\n", rs.rfee);
					printf("实缴费用: %.2f\n", rs.rfee);
				}
				rs_p = rs_p->next;
			}
		}
		if (!flag) printf("很抱歉!没有符合条件的订单信息");
		break;
	default:
		printf("信息选择错误 !\n");
		break;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

void search_cartype() {} //查询车辆分类信息

void search_carstats() {} //查询车辆基本信息

void search_rentstats() {} //查询订单信息

void watch_cartype() {
	CarTypeNode* ct_p = head_ct;
	while (ct_p->next != NULL) {
		printf("%c %s %d\n", ct_p->next->ct.code, ct_p->next->ct.TypeName, ct_p->next->ct.amount);
		ct_p = ct_p->next;
	}
}

void watch_carstats() {
	CarStatsNode* cs_p = head_cs;
	while (cs_p->next != NULL) {
		CarStats cs = cs_p->next->cs;
		printf("%d %s %c %s %s %.2f %c", cs.CarNum, cs.plate, cs.code, cs.CarName, cs.mode, cs.rent, cs.stats);
		cs_p = cs_p->next;
	}
}

void watch_rentstats() {
	RentStatsNode* rs_p = head_rs;
	while (rs_p->next != NULL) {
		RentStats rs = rs_p->next->rs;
		printf("%s %s %s %s %d %s %s %.2f %s %.2f %.2f", rs.RentNum, rs.id, rs.name, rs.phone, rs.CarNum, rs.TakeTime, rs.BackTime, rs.deposit, rs.rBackTime, rs.fee, rs.rfee);
		rs_p = rs_p->next;
	}
}

void func_list() {
	while (getchar() != '\n');
	while (getchar() != '\n');
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

int kmp(char* s, char* p) {
	int i = 0;
	int j = 0;
	int next[20];
	int sLen = strlen(s);
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	while (j < pLen - 1) {
		//p[k]表示前缀，p[j]表示后缀    
		if (k == -1 || p[j] == p[k]) {
			++j;
			++k;
			if (p[j] != p[k])
				next[j] = k;
			else
				next[j] = next[k];
		}
		else {
			k = next[k];
		}
	}
	i = 0; j = 0;
	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == pLen)
		return 1;
	else
		return 0;
}

void search_not() {
	printf("很抱歉！没有符合您要求的车辆\n");
}

void data_analyze() {
	int inf;
	printf("请输入您想查看的数据分析(1——车型基本信息||2——车型当月营业额||3——车辆全年营业额||4——10款热租车): ");
	scanf("%d", &inf);
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
		printf("数据分析查看错误");
		break;
	}

}

void cartype_inf() {
	CarStatsNode* cs_p = head_cs;
	int _amount[6], _y[6], _n[6];
	memset(_amount, 0, sizeof(_amount));
	memset(_y, 0, sizeof(_y));
	memset(_n, 0, sizeof(_n));
	while (cs_p->next != NULL) {
		CarStats cs = cs_p->next->cs;
		int cd = (int)cs.code - '0';
		//        printf("%d %c\n",cd,cs.stats);
		_amount[cd]++;
		if (cs.stats == 'y') _y[cd]++;
		else _n[cd]++;
		cs_p = cs_p->next;
	}
	time_t currentTm = time(NULL);
	printf("\n统计时间:%s", asctime(localtime(&currentTm)));
	printf("——————————————————————\n");
	printf("| 车辆类型 | 车辆总数 | 已出租数 | 未出租数 |\n");
	printf("——————————————————————\n");
	printf("|  经济型  | %4d     | %4d     | %4d     |\n", _amount[1], _y[1], _n[1]);
	printf("——————————————————————\n");
	printf("|  商务型  | %4d     | %4d     | %4d     |\n", _amount[2], _y[2], _n[2]);
	printf("——————————————————————\n");
	printf("|  豪华型  | %4d     | %4d     | %4d     |\n", _amount[3], _y[3], _n[3]);
	printf("——————————————————————\n");
	printf("|   SUV    | %4d     | %4d     | %4d     |\n", _amount[4], _y[4], _n[4]);
	printf("——————————————————————\n");;
	printf("| 7座及以上| %4d     | %4d     | %4d     |\n", _amount[5], _y[5], _n[5]);
	printf("——————————————————————\n");
	printf("|   总计   | %4d     | %4d     | %4d     |\n", _amount[1] + _amount[2] + _amount[3] + _amount[4] + _amount[5], _y[1] + _y[2] + _y[3] + _y[4] + _y[5], _n[1] + _n[2] + _n[3] + _n[4] + _n[5]);
	printf("——————————————————————\n");
}

void month_money() {
	int _carmon1[10010], k = 0;
	float _money[10], _carmon2[10010];
	int _money1[10];
	char _time[TIME_LENTH], _time2[TIME_LENTH], _time3[TIME_LENTH];
	memset(_money, 0, sizeof(_money));
	printf("请输入年月(格式:xxxx/xx): ");
	scanf("%s", _time);
	for (int i = 0; i <= 6; i++) {
		_time2[i] = _time[i];
		_time3[i] = _time[i];
	}
	_time2[7] = _time3[7] = '/';
	_time2[8] = _time2[9] = '0';
	_time3[8] = _time3[9] = '9';
	_time2[10] = _time3[10] = '-';
	_time2[11] = _time2[12] = '0';
	_time3[11] = _time3[12] = '9';
	_time2[13] = _time3[13] = ':';
	_time2[14] = _time2[15] = '0';
	_time3[14] = _time3[15] = '9';
	//    printf("%s\n",_time2);
	//    printf("%s\n",_time3);
	RentStatsNode* rs_p = head_rs;
	CarStatsNode* cs_p = head_cs;
	while (rs_p->next != NULL) {
		RentStats rs = rs_p->next->rs;
		if (strcmp(rs.rBackTime, _time2) >= 0 && strcmp(rs.rBackTime, _time3) < 0) {
			_carmon1[k] = rs.CarNum;
//			printf("%d ",_carmon1[k]);
			_carmon2[k++] = rs.rfee;
		}
		rs_p = rs_p->next;
	}
	/*   for (int i=0;i<k;i++) {
		   printf("%d %.2f",_carmon1[i],_carmon2[i]);
	   }*/
	while (cs_p->next != NULL) {
		CarStats cs = cs_p->next->cs;
		for (int i = 0; i < k; i++) {
			if (cs.CarNum == _carmon1[i])
				_money[cs.code - '0'] += _carmon2[i];
		}
		cs_p = cs_p->next;
	}
	for (int i = 1; i <= 5; i++) _money1[i] = (int)_money[i];
	printf("\n红色——经济型|紫色——商务型|黄色——豪华型|绿色——SUV|蓝色——七座及以上\n\n");
	print_image(_money1);
	printf("统计时间: %s    计量单位: 元人民币\n", _time);
	printf("——————————————\n");
	printf("|  车辆类型   |    营业额   |\n");
	printf("——————————————\n");
	printf("|   经济型    |   %7.2f   |\n", _money[1]);
	printf("——————————————\n");
	printf("|   商务型    |   %7.2f   |\n", _money[2]);
	printf("——————————————\n");
	printf("|   豪华型    |   %7.2f   |\n", _money[3]);
	printf("——————————————\n");
	printf("|    SUV      |   %7.2f   |\n", _money[4]);
	printf("——————————————\n");
	printf("|  七座及以上 |   %7.2f   |\n", _money[5]);
	printf("——————————————\n");

}

void ten_high() {
	char _cp[1001][PLATE_LENTH], _cm[1001][CARNAME_LENTH];
	float _mon1[1001], _rate[1001];
	int _mon2[1001];
	char _time[TIME_LENTH], _time2[TIME_LENTH], _time3[TIME_LENTH];
	int k = 0, pd = 0;
	printf("请输入查看年份(格式: xxxx): ");
	scanf("%s", _time);
	for (int i = 0; i < 4; i++) {
		_time3[i] = _time[i];
		_time2[i] = _time[i];
	}
	_time2[4] = _time3[4] = '/';
	_time2[5] = _time2[6] = '0';
	_time3[5] = _time3[6] = '9';
	_time2[7] = _time3[7] = '/';
	_time2[8] = _time2[9] = '0';
	_time3[8] = _time3[9] = '9';
	_time2[10] = _time3[10] = '-';
	_time2[11] = _time2[12] = '0';
	_time3[11] = _time3[12] = '9';
	_time2[13] = _time3[13] = ':';
	_time2[14] = _time2[15] = '0';
	_time3[14] = _time3[15] = '9';
	//    printf("%s\n",_time2);
	//    printf("%s\n",_time3);
	RentStatsNode* rs_p = head_rs;
	CarStatsNode* cs_p = head_cs;
	while (rs_p->next != NULL) {
		RentStats rs = rs_p->next->rs;
		if (strcmp(rs.rBackTime, _time2) >= 0 && strcmp(rs.rBackTime, _time3) < 0) {
			for (int i = 0; i < k; i++)
				if (_mon2[i] == rs.CarNum) {
					pd = 1;
					_rate[i] += calc_day(rs.TakeTime, rs.rBackTime);
					break;
				}
			if (!pd) {
				_mon2[k] = rs.CarNum;
				_mon1[k] = rs.fee;
				_rate[k++] = calc_day(rs.TakeTime, rs.rBackTime);
			}
			pd = 0;
		}
		rs_p = rs_p->next;
	}
	while (cs_p->next != NULL) {
		CarStats cs = cs_p->next->cs;
		for (int i = 0; i < k; i++) {
			if (cs.CarNum == _mon2[i]) {
				strcpy(_cp[i], cs.plate);
				strcpy(_cm[i], cs.CarName);
			}
		}
		cs_p = cs_p->next;
	}
	for (int i = 0; i < k; i++)
		for (int j = k - 1; j > i; j--)
			if (_rate[j] > _rate[j - 1]) {
				char _ct[30];
				int pt1;
				float pt2;
				strcpy(_ct, _cp[j]);
				strcpy(_cp[j], _cp[j - 1]);
				strcpy(_cp[j - 1], _ct);
				strcpy(_ct, _cm[j]);
				strcpy(_cm[j], _cm[j - 1]);
				strcpy(_cm[j - 1], _ct);
				pt1 = _mon2[j];
				_mon2[j] = _mon2[j - 1];
				_mon2[j - 1] = pt1;
				pt2 = _mon1[j];
				_mon1[j] = _mon1[j - 1];
				_mon1[j - 1] = pt2;
				pt2 = _rate[j];
				_rate[j] = _rate[j - 1];
				_rate[j - 1] = pt2;
			}
	printf("年份: %s年\n", _time);
	printf("——————————————————————————————————\n");
	printf("|   车牌号   |    车辆名称     |累计租用天数|  营业额  |  租用率   |\n");
	printf("——————————————————————————————————\n");
	for (int i = 0; i < 10; i++) {
		printf("|  %8s  |   %12s  |    %4d    | %7.2f  |  %7.2f  |\n", _cp[i], _cm[i], (int)_rate[i], _mon1[i], _rate[i] / 365.0);
		printf("——————————————————————————————————\n");
	}
}

void year_money() {
	char _cp[1001][PLATE_LENTH], _cm[1001][CARNAME_LENTH];
	float _mon1[1001], _rate[1001];
	int _mon2[1001];
	char _time[TIME_LENTH], _time2[TIME_LENTH], _time3[TIME_LENTH];
	int k = 0, pd = 0;
	printf("请输入查看年份(格式: xxxx): ");
	scanf("%s", _time);
	for (int i = 0; i < 4; i++) {
		_time3[i] = _time[i];
		_time2[i] = _time[i];
	}
	_time2[4] = _time3[4] = '/';
	_time2[5] = _time2[6] = '0';
	_time3[5] = _time3[6] = '9';
	_time2[7] = _time3[7] = '/';
	_time2[8] = _time2[9] = '0';
	_time3[8] = _time3[9] = '9';
	_time2[10] = _time3[10] = '-';
	_time2[11] = _time2[12] = '0';
	_time3[11] = _time3[12] = '9';
	_time2[13] = _time3[13] = ':';
	_time2[14] = _time2[15] = '0';
	_time3[14] = _time3[15] = '9';
	//    printf("%s\n",_time2);
	//    printf("%s\n",_time3);
	RentStatsNode* rs_p = head_rs;
	CarStatsNode* cs_p = head_cs;
	while (rs_p->next != NULL) {
		RentStats rs = rs_p->next->rs;
		if (strcmp(rs.rBackTime, _time2) >= 0 && strcmp(rs.rBackTime, _time3) < 0) {
			for (int i = 0; i < k; i++)
				if (_mon2[i] == rs.CarNum) {
					//                printf("222222\n");
					pd = 1;
					_rate[i] += calc_day(rs.TakeTime, rs.rBackTime);
					break;
				}
			if (!pd) {
				_mon2[k] = rs.CarNum;
				_mon1[k] = rs.fee;
				_rate[k++] = calc_day(rs.TakeTime, rs.rBackTime);
			}
			pd = 0;
		}
		rs_p = rs_p->next;
	}
	while (cs_p->next != NULL) {
		CarStats cs = cs_p->next->cs;
		for (int i = 0; i < k; i++) {
			if (cs.CarNum == _mon2[i]) {
				strcpy(_cp[i], cs.plate);
				strcpy(_cm[i], cs.CarName);
			}
		}
		cs_p = cs_p->next;
	}
	printf("年份: %s年\n", _time);
	printf("———————————————————————————\n");
	printf("|   车牌号    |   车辆名称     |  营业额  |   租用率  |\n");
	printf("———————————————————————————\n");
	for (int i = 0; i < k; i++) {
		printf("|  %8s  |   %12s  | %7.2f  |  %7.2f  |\n", _cp[i], _cm[i], _mon1[i], _rate[i] / 365.0);
		printf("———————————————————————————\n");
	}
}

int calc_day(char* a, char* b) {
	char a_mon[TIME_LENTH], a_day[TIME_LENTH], b_mon[TIME_LENTH], b_day[TIME_LENTH];
	int am, ad, bm, bd;
	int sum = 0;
	strncpy(a_mon, a + 5, 2); strncpy(a_day, a + 8, 2);
	strncpy(b_mon, b + 5, 2); strncpy(b_day, b + 8, 2);
	am = atoi(a_mon); ad = atoi(a_day); bm = atoi(b_mon); bd = atoi(b_day);
	if (am < bm) {
		for (int i = am + 1; i < bm; i++) {
			sum += mons[i];
		}
		sum += mons[am] - ad;
		sum += bd;
	}
	if (am == bm) return bd - ad;
	return sum;
}

void version_inf() {
	printf("\nVersion 1.0(基本功能实现)\n"); 
	printf("Version 2.0(添加了绘制柱状图/版本信息/作者信息)——当前版本\n");
	printf("Version 3.0(Qt实现简单的图形化界面，集合成独立的软件)\n");
}

void my_inf() {
	printf("\n作者: 张昊林\n");
	printf("华中科技大学\n");
	printf("网络空间安全学院\n");
	printf("信息安全1801班\n");
	printf("学号: U201814831\n");
	printf("手机: 13127253129\n");
	printf("QQ: 374462522\n");
	printf("邮箱: 374462522@qq.com\n");
}

HDC set_pen(int a, int b, int c, int d)
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HPEN hPen;
	hPen = CreatePen(PS_INSIDEFRAME, d, RGB(a, b, c));
	SelectObject(hdc, hPen);
	return hdc;
}
void print_image(int how_much[])
{
	int x_offset = 1000;
	int y_offset = 1000;
	int x_border = 1600;
	HDC hdc1 = set_pen(255, 0, 0, 3);
	HDC hdc2 = set_pen(255, 0, 255, 3);
	HDC hdc3 = set_pen(255, 255, 0, 3);
	HDC hdc4 = set_pen(0, 255, 0, 3);
	HDC hdc5 = set_pen(0, 0, 255, 3);
	MoveToEx(hdc1, x_offset, y_offset, NULL);
	LineTo(hdc1, x_border, y_offset);
	int maxn = 0;
	for (int i = 1; i < 6; i++)
	{
		if (how_much[i] > maxn)
			maxn = how_much[i];
	}
	int seg = 120;
	Rectangle(hdc1,
		x_offset + seg / 4,
		y_offset - (int)((float)how_much[1] * 400.0 / maxn),
		x_offset + seg / 4 * 3,
		y_offset);
	Rectangle(hdc2,
		x_offset + seg + seg / 4,
		y_offset - (int)((float)how_much[2] * 400.0 / maxn),
		x_offset + seg + seg / 4 * 3,
		y_offset);
	Rectangle(hdc3,
		x_offset + seg * 2 + seg / 4,
		y_offset - (int)((float)how_much[3] * 400.0 / maxn),
		x_offset + seg * 2 + seg / 4 * 3,
		y_offset);
	Rectangle(hdc4,
		x_offset + seg * 3 + seg / 4,
		y_offset - (int)((float)how_much[4] * 400.0 / maxn),
		x_offset + seg * 3 + seg / 4 * 3,
		y_offset);
	Rectangle(hdc5,
		x_offset + seg * 4 + seg / 4,
		y_offset - (int)((float)how_much[5] * 400.0 / maxn),
		x_offset + seg * 4 + seg / 4 * 3,
		y_offset);
	return;
}