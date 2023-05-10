typedef struct{
        int month;
        int day;
} Date;
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[3][20] = {"월급","부수입","용돈"};
} Income;       // 수입
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[5][20] = {"식비","교통/차량","주거/통신","문화생활","생활용품"};
} Expense;      // 지출

int addIncome(Income *in);
int addExpense(Expense *ex);
int addfIncome(Income *in);
int addfExpense(Expense *ex);

void updateIncome(Income *in);
void updateExpense(Expense *ex);
int deleteIncome(Income *in);
int deleteExpense(Expense *ex);

void sumList(Income *in, Expense *ex);          // 일별 내역 list + 합계 출력 기능
int searchCategory(Income * in, Expense *ex);           // 지출 & 수입 분류별 검색 기능
int searchIncome(Income *in);                   // 수입내역 검색 기능
int serachExpense(Expense *ex);                 // 지출내역 검색 기능
void dayList(Income * in, Expense *ex);         // 일일 내역 list 기능
void monthList(Income * in, Expense *ex);       // 월별 내역 list 기능
int save(Income * in, Expense *ex);             // 일별 내역 list +  합계 저장기능