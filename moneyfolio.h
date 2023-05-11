typedef struct{
        int month;
        int day;
} Date;
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[3][20];
} Income;       // 수입
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[5][20];
} Expense;      // 지출

Income i = {.category = {"월급", "부수입", "용돈"}};
Expense e = {.category = {"식비", "교통/차량", "주거/통신", "문화생활", "생활용품"}};

int addIncome(Income *in);		                  // 수입내역 추가
int addExpense(Expense *ex);		                // 지출내역 추가
int addfIncome(Income *in);		                  // 고정수입내역 추가
int addfExpense(Expense *ex);		                // 고정지출내역 추가

void updateIncome(Income *in);		              // 수입내역 수정
void updateExpense(Expense *ex);	              // 지출내역 수정
int deleteIncome(Income *in); 		              // 수입내역 삭제
int deleteExpense(Expense *ex); 	              // 지출내역 삭제

void sumList(Income *in, Expense *ex);          // 일별 내역 list + 합계 출력 기능
int searchCategory(Income * in, Expense *ex);           // 지출 & 수입 분류별 검색 기능
int searchIncome(Income *in);                   // 수입내역 검색 기능
int searchExpense(Expense *ex);                 // 지출내역 검색 기능
void dayList(Income * in, Expense *ex);         // 일일 내역 list 기능
void monthList(Income * in, Expense *ex);       // 월별 내역 list 기능
int save(Income * in, Expense *ex);             // 일별 내역 list +  합계 저장기능
int selectIE();                                 // 수입, 지출 고르는 기능
int selectMenu();                               // 메뉴 고르는 기능
