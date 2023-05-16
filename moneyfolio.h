typedef struct{
        char date[4];
        char price;
        char note[100];
        int category;
} Income;       // 수입
typedef struct{
        char date[4];
        int price;
        char note[100];
        int category;
} Expense;      // 지출

char InCate[3][10] = {"월급","부수입","용돈"};
char ExCate[3][20] = {"식비","생활용품","교통/차량"};

int addIncome(Income *in);		                  // 수입내역 추가
int addExpense(Expense *ex);		                // 지출내역 추가
int addfIncome(Income *in);		                  // 고정수입내역 추가
int addfExpense(Expense *ex);		                // 고정지출내역 추가

void updateIncome(Income *in);		              // 수입내역 수정
void updateExpense(Expense *ex);	              // 지출내역 수정
int deleteIncome(Income *in); 		              // 수입내역 삭제
int deleteExpense(Expense *ex); 	              // 지출내역 삭제

void searchCateEx(Expense *ex[], int countEx);           // 지출 분류별 검색 기능
void searchCateIn(Income *in[], int countIn);            // 수입 분류별 검색 기능
void searchIncome(Income *in[], int countIn);                   // 수입내역 검색 기능
void searchExpense(Expense *ex[], int countEx);                 // 지출내역 검색 기능

void dayList(Income *in[], Expense *ex[]);         // 일일 내역 list 기능
void monthList(Income *in[], Expense *ex[]);       // 월별 내역 list 기능
void sumList(Income *in[], Expense *ex[]);          // 일별 내역 list + 합계 출력 기능
int save(Income *in[], Expense *ex[]);             // 일별 내역 list +  합계 저장기능

int selectIE();                                 // 수입, 지출 고르는 기능
int selectMenu();                               // 메뉴 고르는 기능
int compare_date(const void* first, const void* second);    // 날짜 순서로 sorting하는 compare()
