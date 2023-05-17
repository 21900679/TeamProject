#include <stdio.h>
#include <string.h>
#include <time.h>
#include "moneyfolio.h"

void getDate(Moneyfolio *mf){           // Date 
    int month, day;
    char input_date[6] = "";
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
}
int addIncome(Moneyfolio *mf){          // 수입내역 
    getDate(mf);
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
    getDate(mf);
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

void updateIncome(Moneyfolio *mf){
    getDate(mf);
    printf("금액을 입력하세요: ");
    scanf("%d", &mf->price);
    printf("수입에 대한 내역을 입력 해 주세요: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // 분류 리스트 print 하기
    printf("분류를 선택하세요: ");
    scanf("%d", &(mf->category));
}
void updateExpense(Moneyfolio *mf){
    getDate(mf);
    printf("금액을 입력하세요: ");
    scanf("%d", &mf->price);
    printf("수입에 대한 내역을 입력 해 주세요: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // 분류 리스트 print 하기
    printf("분류를 선택하세요: ");
    scanf("%d", &(mf->category));
}
int deleteIE(Moneyfolio *mf){               // 내역 삭제
    mf->date[0] = '\0';
    mf->price = -1;
    mf->note[0] = '\0';
    mf->category = -1;
}

void sumList(Moneyfolio *mf[], int total){      // 일별 내역 list + 합계 출력 기능
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int sum = 0;

    time_t t1;
    struct tm* ct;
    t1 = time(NULL);
    ct = localtime(&t1);

    month = mf[0]->date[0] * 10 + mf[0]->date[1];
    for(int i = 0; i < total, ct->tm_mon + 1 == month; i++){
        month = mf[i]->date[0] * 10 + mf[i]->date[1];
        day = mf[i]->date[2] * 10 + mf[i]->date[3];
        if(pmonth != month || pday != day)
            printf("%d월 %d일-------------------------------\n", month, day);
        if(mf[i]->IE == 0){
            printf("%s %s %d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum += mf[i]->price;
        }
        else{
            printf("%s %s %d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum -= mf[i]->price;
        }
        if(pmonth != month || pday != day)
            printf("----------------------------------------\n");
        pmonth = month;
        pday = day;
    }
    printf("---------------------------------- 합계 : %d ------\n", sum);
}

void searchCateIn(Moneyfolio *mf[], int total){       // 수입 분류별 검색 기능
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    while(1){
        printf("검색하실 수입 category(월급, 부수입, 용돈)를 입력해 주세요. ");
        scanf("%s", search);
        if(strcmp("월급", search) == 0 || strcmp("부수입", search) == 0 || strcmp("용돈", search) == 0){
            for(int i = 0; i < total; i++){
                month = mf[i]->date[0] * 10 + mf[i]->date[1];
                day = mf[i]->date[2] * 10 + mf[i]->date[3];
                if((strcmp(InCate[mf[i]->category], search) == 0) && (mf[i]->IE == 0)){
                    if(pmonth != month || pday != day)
                        printf("%d월 %d일-------------------------------\n", month, day);
                    printf("%s %s %d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
                    if(pmonth != month || pday != day)
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

void searchCateEx(Moneyfolio *mf[], int total){       // 지출 분류별 검색 기능
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    while(1){
        printf("검색하실 수입 category(식비, 생활용품, 교통/차량)를 입력해 주세요. ");
        scanf("%s", search);
        if(strcmp("식비", search) == 0 || strcmp("생활용품", search) == 0 || strcmp("교통/차량", search) == 0){
            for(int i = 0; i < total; i++){
                month = mf[i]->date[0] * 10 + mf[i]->date[1];
                day = mf[i]->date[2] * 10 + mf[i]->date[3];
                if(strcmp(ExCate[mf[i]->category], search) == 0){
                    if(pmonth != month || pday != day)
                        printf("%d월 %d일-------------------------------\n", month, day);
                    printf("%s %s %d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
                    if(pmonth != month || pday != day)
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

void searchIncome(Moneyfolio *mf[], int total){         // 수입내역 검색 기능
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    printf("검색하실 내용을 입력해 주세요. ");
    fflush(stdin);
    fgets(search, 100, stdin);
    search[strlen(search)-1] = '\0';

    for(int i = 0; i < total; i++){
        month = mf[i]->date[0] * 10 + mf[i]->date[1];
        day = mf[i]->date[2] * 10 + mf[i]->date[3];
        if((strstr(mf[i]->note, search) != NULL) && (mf[i]->IE == 0)){
            if(pmonth != month || pday != day)
                printf("%d월 %d일-------------------------------\n", month, day);
            printf("%s %s %d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
            if(pmonth != month || pday != day)
                printf("----------------------------------------\n");
        }
        pmonth = month;
        pday = day;
    }
    printf("----------------------------------------\n");
}

void searchExpense(Moneyfolio *mf[], int total){         // 지출내역 검색 기능
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    printf("검색하실 내용을 입력해 주세요. ");
    fflush(stdin);
    fgets(search, 100, stdin);
    search[strlen(search)-1] = '\0';

    for(int i = 0; i < total; i++){
        month = mf[i]->date[0] * 10 + mf[i]->date[1];
        day = mf[i]->date[2] * 10 + mf[i]->date[3];
        if((strstr(mf[i]->note, search) != NULL) && (mf[i]->IE == 1)){
            if(pmonth != month || pday != day)
                printf("%d월 %d일-------------------------------\n", month, day);
            printf("%s %s %d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
            if(pmonth != month || pday != day)
                printf("----------------------------------------\n");
        }
        pmonth = month;
        pday = day;
    }
    printf("----------------------------------------\n");
}

void dayList(Moneyfolio *mf[], int total){     // 일일 내역 list
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;

    time_t t1;
    struct tm* ct;
    t1 = time(NULL);
    ct = localtime(&t1);

    month = mf[0]->date[0] * 10 + mf[0]->date[1];
    for(int i = 0; i < total, ct->tm_mon + 1 == month; i++){
        month = mf[i]->date[0] * 10 + mf[i]->date[1];
        day = mf[i]->date[2] * 10 + mf[i]->date[3];
        if(pmonth != month || pday != day)
            printf("%d월 %d일-------------------------------\n", month, day);
        if(mf[i]->IE == 0)
            printf("%s %s %d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
        else
            printf("%s %s %d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
        if(pmonth != month || pday != day)
            printf("----------------------------------------\n");
        pmonth = month;
        pday = day;
    }
    printf("----------------------------------------\n");
}

void monthList(Moneyfolio *mf[], int total){
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;

    for(int i = 0; i < total; i++){
        month = mf[i]->date[0] * 10 + mf[i]->date[1];
        day = mf[i]->date[2] * 10 + mf[i]->date[3];
        if(month != pmonth)
            printf("%d월-------------------------------\n", month);
        if(mf[i]->IE == 0)
            printf("%d일 %s %s %d\n", day, InCate[mf[i]->category], mf[i]->note, mf[i]->price);
        else
            printf("%d일 %s %s %d\n", day, ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
        pmonth = month;
        pday = day;
    }
    printf("----------------------------------------\n");
}

void save(Moneyfolio *mf[], int total){
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int sum = 0;

    time_t t1;
    struct tm* ct;
    t1 = time(NULL);
    ct = localtime(&t1);

    FILE *file = fopen("moneyfolio.txt", "w");

    month = mf[0]->date[0] * 10 + mf[0]->date[1];
    for(int i = 0; i < total, ct->tm_mon + 1 == month; i++){
        month = mf[i]->date[0] * 10 + mf[i]->date[1];
        day = mf[i]->date[2] * 10 + mf[i]->date[3];
        if(pmonth != month || pday != day)
            fprintf(file, "%d월 %d일-------------------------------\n", month, day);
        if(mf[i]->IE == 0){
            fprintf(file, "%s %s %d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum += mf[i]->price;
        }
        else{
            fprintf(file, "%s %s %d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum -= mf[i]->price;
        }
        if(pmonth != month || pday != day)
            fprintf(file, "----------------------------------------\n");
        pmonth = month;
        pday = day;
    }
    fprintf(file, "---------------------------------- 합계 : %d ------\n", sum);
    fclose(file);
}

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
