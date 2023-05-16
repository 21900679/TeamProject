#include <stdio.h>
#include "moneyfolio.h"

int addIncome(Income *in);
int addExpense(Expense *ex);
int addfIncome(Income *in);
int addfExpense(Expense *ex);

void updateIncome(Income *in);
void updateExpense(Expense *ex);
int deleteIncome(Income *in);
int deleteExpense(Expense *ex);

void sumList(Income *in[], Expense *ex[]);
int searchCategory(Income * in[], Expense *ex[]);

int searchIncome(Income *in[], int countIn){         // 수입내역 검색 기능
    char serach[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    printf("검색하실 내용을 입력해 주세요. ");
    scanf("%s", serach);

    for(int i = 0; i < countIn; i++){
        month = in[i]->date[0] * 10 + in[i]->date[1];
        day = in[i]->date[2] * 10 + in[i]->date[3];
        if(strstr(in[i]->note, serach) != NULL){
            if(pmonth != month)
                printf("%d월 %d일-------------------------------\n", month, day);
            printf("%s %s %d\n", InCate[in[i]->category], in[i]->note, in[i]->price);
            if(pmonth != month)
                printf("----------------------------------------\n");
        }
        pmonth = month;
        pday = day;
    }
}  

int searchExpense(Expense *ex[]);
void dayList(Income *in[], Expense *ex[]);
void monthList(Income *in[], Expense *ex[]);
int save(Income *in[], Expense *ex[]);
int selectIE(){
    int IE;
    printf("수입(1), 지출(2)을 선택해주세요. ");
    scanf("%d", &IE);
    return IE;
}
int selectMenu(){
    int menu;
    printf("┌────────── MoneyFolio ─────────────┐\n");
    printf("|    1. 조회                        |\n");
    printf("|    2. 수입/지출 내역 추가         |\n");
    printf("|    3. 고정(수입/지출) 내역 추가   |\n");
    printf("|    4. 수입/지출 내역 검색         |\n");
    printf("|    5. 분류별 검색                 |\n");
    printf("|    6. 수입/지출 내역 수정         |\n");
    printf("|    7. 수입/지출 내역 삭제         |\n");
    printf("|    8. 일일 내역 조회              |\n");
    printf("|    9. 월별 내역 조회              |\n");
    printf("|    10. 저장하기                   |\n");
    printf("└───────────────────────────────────┘\n");
    printf("원하는 메뉴를 선택하시오. ");
    scanf("%d", &menu);
    return menu;
}
