#include <stdio.h>
#include <string.h>
#include "moneyfolio.h"

int addIncome(Moneyfolio *mf){          // 수입내역 
    int month, day;
    char input_date[5] = "";
    char month_str[3] = "";
    char day_str[3] = "";
    printf("월을 입력하세요: ");
    scanf("%d", &month);
    printf("일을 입력하세요: ");
    scanf("%d", &day);
    if (month < 10)
        sprintf(month_str, "0%d", month);
    else
        sprintf(month_str, "%d", month);
    if (day < 10)
        sprintf(day_str, "0%d", day);
    else
        sprintf(day_str, "%d", day);
    strcat(input_date, month_str);
    strcat(input_date, day_str);
    strcpy(mf->date, input_date);
    printf("금액을 입력하세요: ");
    scanf("%d", &mf->price);
    printf("수입에 대한 내역을 입력하세요: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // 수입 분류 리스트 print 하기
    printf("수입에 대한 분류를 선택하세요: ");
    scanf("%d", &(mf->category));
    mf->IE = 0;
}
int addExpense(Moneyfolio *mf){        // 지출내역 
    int month, day;
    char input_date[5] = "";
    char month_str[3] = "";
    char day_str[3] = "";
    printf("월을 입력하세요: ");
    scanf("%d", &month);
    printf("일을 입력하세요: ");
    scanf("%d", &day);
    if (month < 10)
        sprintf(month_str, "0%d", month);
    else
        sprintf(month_str, "%d", month);
    if (day < 10)
        sprintf(day_str, "0%d", day);
    else
        sprintf(day_str, "%d", day);
    strcat(input_date, month_str);
    strcat(input_date, day_str);
    strcpy(mf->date, input_date);
    printf("금액을 입력하세요: ");
    scanf("%d", &mf->price);
    printf("지출에 대한 내역을 입력하세요: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // 지출 분류 리스트 print 하기
    printf("지출에 대한 분류를 선택하세요: ");
    scanf("%d", &mf->category);
    mf->IE = 1;
}
int addfIncome(Moneyfolio *mf);
int addfExpense(Moneyfolio *mf);

void updateIncome(Moneyfolio *mf);
void updateExpense(Moneyfolio *mf);
int deleteIncome(Moneyfolio *mf);
int deleteExpense(Moneyfolio *mf);

void sumList(Income *in[], Expense *ex[]);

void searchCateIn(Income * in[], int countIn){       // 수입 분류별 검색 기능
    char serach[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    while(1){
        printf("검색하실 수입 category(월급, 부수입, 용돈)를 입력해 주세요. ");
        scanf("%s", serach);
        if(strcmp("월급", serach) == 0 || strcmp("부수입", serach) == 0 || strcmp("용돈", serach) == 0){
            for(int i = 0; i < countIn; i++){
                month = in[i]->date[0] * 10 + in[i]->date[1];
                day = in[i]->date[2] * 10 + in[i]->date[3];
                if(strcmp(InCate[in[i]->category], serach) == 0){
                    if(pmonth != month)
                        printf("%d월 %d일-------------------------------\n", month, day);
                    printf("%s %s %d\n", InCate[in[i]->category], in[i]->note, in[i]->price);
                    if(pmonth != month)
                        printf("----------------------------------------\n");
                }
                pmonth = month;
                pday = day;
            }
            printf("----------------------------------------\n");
        }   
        else{
            printf("일치하는 category가 없습니다.\n");
            break;
        }
    }
}

void searchCateEx(Expense *ex[], int countEx){       // 지출 분류별 검색 기능
    char serach[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    while(1){
        printf("검색하실 수입 category(식비, 생활용품, 교통/차량)를 입력해 주세요. ");
        scanf("%s", serach);
        if(strcmp("식비", serach) == 0 || strcmp("생활용품", serach) == 0 || strcmp("교통/차량", serach) == 0){
            for(int i = 0; i < countEx; i++){
                month = ex[i]->date[0] * 10 + ex[i]->date[1];
                day = ex[i]->date[2] * 10 + ex[i]->date[3];
                if(strcmp(ExCate[ex[i]->category], serach) == 0){
                    if(pmonth != month)
                        printf("%d월 %d일-------------------------------\n", month, day);
                    printf("%s %s %d\n", ExCate[ex[i]->category], ex[i]->note, ex[i]->price);
                    if(pmonth != month)
                        printf("----------------------------------------\n");
                }
                pmonth = month;
                pday = day;
            }
            printf("----------------------------------------\n");
        }   
        else{
            printf("일치하는 category가 없습니다.\n");
            break;
        }
    }
}

void searchIncome(Income *in[], int countIn){         // 수입내역 검색 기능
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
    printf("----------------------------------------\n");
}  

void searchExpense(Expense *ex[], int countEx){         // 지출내역 검색 기능
    char serach[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    printf("검색하실 내용을 입력해 주세요. ");
    scanf("%s", serach);

    for(int i = 0; i < countEx; i++){
        month = ex[i]->date[0] * 10 + ex[i]->date[1];
        day = ex[i]->date[2] * 10 + ex[i]->date[3];
        if(strstr(ex[i]->note, serach) != NULL){
            if(pmonth != month)
                printf("%d월 %d일-------------------------------\n", month, day);
            printf("%s %s %d\n", ExCate[ex[i]->category], ex[i]->note, ex[i]->price);
            if(pmonth != month)
                printf("----------------------------------------\n");
        }
        pmonth = month;
        pday = day;
    }
    printf("----------------------------------------\n");
}

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
int compare_date(const void* first, const void* second){
    return strcmp(((Moneyfolio*)first)->date, ((Moneyfolio*)second)->date);
}
