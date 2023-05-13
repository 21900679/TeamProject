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
int searchIncome(Income *in[]);
int searchExpense(Expense *ex[]);
void dayList(Income *in[], Expense *ex[]);
void monthList(Income *in[], Expense *ex[]);
int save(Income *in[], Expense *ex[]);
int selectIE(){
    int IE;
    printf("수입(1), 지출(2)을 선택해주세요.\n");
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
