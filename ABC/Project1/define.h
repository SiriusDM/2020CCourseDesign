//����������������ϵͳ�Ľṹ����
#define CARTYPENAME_LENTH 20
#define PLATE_LENTH 10
#define CARNAME_LENTH 20
#define MODE_LENTH 10
#define RENTNUM_LENTH 20
#define ID_LENTH 20
#define GUESTNAME_LENTH 20
#define PHONE_LENTH 20
#define TIME_LENTH 18
#define LINE_LENTH 10240
#define POINTS_NUM 30
#define TITLE_LENTH 1024

struct CarType {
	char code;//�������ͱ��� 1~5
	char TypeName[CARTYPENAME_LENTH]; //������������
	int amount;//�������
};
typedef struct CarType CarType;

struct CarStats {
	int CarNum; //������ţ���������
	char plate[PLATE_LENTH]; //���ƺ�
	char code; //�������ͱ���1~5
	char CarName[CARNAME_LENTH];//��������
	char mode[MODE_LENTH];//�ŵ���ʽ
	float rent;//ÿ�����
	char stats;//����״̬
};
typedef struct CarStats CarStats;

struct RentStats {
	char RentNum[RENTNUM_LENTH];
	char id[ID_LENTH];
	char name[GUESTNAME_LENTH];
	char phone[PHONE_LENTH];
	int CarNum;
	char TakeTime[TIME_LENTH];
	char BackTime[TIME_LENTH];
	float deposit;
	char rBackTime[TIME_LENTH];
	float fee;
	float rfee;
};
typedef struct RentStats RentStats;

//�������ݽṹ����
struct RentStatsNode {
	RentStats rs;
	struct RentStatsNode* next;
};
typedef struct RentStatsNode RentStatsNode;

struct CarStatsNode {
	CarStats cs;
	RentStatsNode* head;
	struct CarStatsNode* next;
};
typedef struct CarStatsNode CarStatsNode;

struct CarTypeNode {
	CarType ct;
	CarStatsNode* head;
	struct CarTypeNode* next;
};
typedef struct CarTypeNode CarTypeNode;




