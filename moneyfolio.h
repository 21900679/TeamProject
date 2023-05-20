typedef struct{
        char date[5];
        int price;
        char note[100];
        int category;
        int IE;         // 수입(0), 지출(1)
} Moneyfolio;

void getDate(Moneyfolio *mf);                   // Date 입력받는 수
int addIncome(Moneyfolio *mf);                  // 수입내역 추가
int addExpense(Moneyfolio *mf);                 // 지출내역 추가
int addfIncome(Moneyfolio *mf);                 // 고정수입내역 추가
int addfExpense(Moneyfolio *mf);                // 고정지출내역 추가

int selectNo(Moneyfolio *mf[], int count);      // 선택하고자 하는 내역의 index
void updateIncome(Moneyfolio *mf);              // 수입내역 수정
void updateExpense(Moneyfolio *mf);             // 지출내역 수정
int deleteIE(Moneyfolio *mf);                   // 내역 삭제

void searchCateEx(Moneyfolio *mf[], int total);               // 지출 분류별 검색 기능
void searchCateIn(Moneyfolio *mf[], int total);               // 수입 분류별 검색 기능
void searchIncome(Moneyfolio *mf[], int total);               // 수입내역 검색 기능
void searchExpense(Moneyfolio *mf[], int ctotal);              // 지출내역 검색 기능

void dayList(Moneyfolio *mf[], int total);                 // 일일 내역 list 기능
void monthList(Moneyfolio *mf[], int total);               // 월별 내역 list 기능
void sumList(Moneyfolio *mf[], int total);                 // 일별 내역 list + 합계 출력 기능
void save(Moneyfolio *mf[], int total);                     // 일별 내역 list +  합계 저장기능

int selectIE();                                 // 수입, 지출 고르는 기능
int selectMenu();                               // 메뉴 고르는 기능
int compare_date(const void* first, const void* second);        // 날짜 순서로 sorting하는 compare()
