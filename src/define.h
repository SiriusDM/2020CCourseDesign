//对于租赁汽车管理系统的结构定义
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

struct CarType {
    char code;//车辆类型编码 1~5
    char TypeName[CARTYPENAME_LENTH]; //车辆类型名称
    int amount;//库存数量
};
typedef struct CarType CarType;

struct CarStats {
    int CarNum; //车辆编号（自增长）
    char plate[PLATE_LENTH]; //车牌号
    char code; //车辆类型编码1~5
    char CarName[CARNAME_LENTH];//车辆名称
    char mode[MODE_LENTH];//排挡方式
    float rent;//每日租金
    char stats;//出租状态
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

//链表数据结构定义
struct RentStatsNode {
    RentStats rs;
    struct RentStatsNode *next;
};
typedef struct RentStatsNode RentStatsNode;

struct CarStatsNode {
    CarStats cs;
    RentStatsNode *head;
    struct CarStatsNode *next;
};
typedef struct CarStatsNode CarStatsNode;

struct CarTypeNode {
    CarType ct;
    CarStatsNode *head;
    struct CarTypeNode *node;
};
typedef struct CarTypeNode CarTypeNode;




