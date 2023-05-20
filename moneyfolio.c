#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "moneyfolio.h"

char InCate[3][10] = {"����","�μ���","�뵷"};
char ExCate[3][20] = {"�ĺ�","��Ȱ��ǰ","����/����"};

void getDate(Moneyfolio *mf){           // Date 
    int month, day;
    char input_date[6] = "";
    char month_str[3] = "";
    char day_str[3] = "";
    printf("���� �Է��ϼ���: ");
    scanf("%d", &month);
    printf("���� �Է��ϼ���: ");
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
    // printf("[0] = %c, [1] = %c, [2] = %c, [3] = %c\n", mf->date[0], mf->date[1], mf->date[2], mf->date[3]);
}
int addIncome(Moneyfolio *mf){          // ���Գ��� 
    getDate(mf);
    printf("�ݾ��� �Է��ϼ���: ");
    scanf("%d", &mf->price);
    printf("���Կ� ���� ������ �Է��ϼ���: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // ���� �з� ����Ʈ print �ϱ�
    printf("���Կ� ���� �з��� �����ϼ���: ");
    scanf("%d", &(mf->category));
    mf->IE = 0;
    return 1;
}
int addExpense(Moneyfolio *mf){        // ���⳻�� 
    getDate(mf);
    printf("�ݾ��� �Է��ϼ���: ");
    scanf("%d", &mf->price);
    printf("���⿡ ���� ������ �Է��ϼ���: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // ���� �з� ����Ʈ print �ϱ�
    printf("���⿡ ���� �з��� �����ϼ���: ");
    scanf("%d", &mf->category);
    mf->IE = 1;
    return 1;
}
int addfIncome(Moneyfolio *mf){
    return 1;
}
int addfExpense(Moneyfolio *mf){
    return 1;
}

int selectNo(Moneyfolio *mf[], int count){
    int no;
    sumList(mf, count);
    printf("�����ϰ��� �ϴ� ������ ��ȣ�� �����ϼ��� (���: 0): ");
    scanf("%d", &no);
    return no;
}
void updateIncome(Moneyfolio *mf){
    getDate(mf);
    printf("�ݾ��� �Է��ϼ���: ");
    scanf("%d", &mf->price);
    printf("���Կ� ���� ������ �Է� �� �ּ���: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // �з� ����Ʈ print �ϱ�
    printf("�з��� �����ϼ���: ");
    scanf("%d", &(mf->category));
}
void updateExpense(Moneyfolio *mf){
    getDate(mf);
    printf("�ݾ��� �Է��ϼ���: ");
    scanf("%d", &mf->price);
    printf("���Կ� ���� ������ �Է� �� �ּ���: ");
    getchar();
    fgets(mf->note, 100, stdin);
    mf->note[strlen(mf->note)-1] = '\0';
    // �з� ����Ʈ print �ϱ�
    printf("�з��� �����ϼ���: ");
    scanf("%d", &(mf->category));
}
int deleteIE(Moneyfolio *mf){               // ���� ����
    mf->date[0] = '\0';
    mf->price = -1;
    mf->note[0] = '\0';
    mf->category = -1;
}

void sumList(Moneyfolio *mf[], int total){      // �Ϻ� ���� list + �հ� ��� ���
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int sum = 0;

    time_t t1;
    struct tm* ct;
    t1 = time(NULL);
    ct = localtime(&t1);

    month = (mf[0]->date[0] - '0') * 10 + (mf[0]->date[1] - '0');
    for(int i = 0; i < total; i++){
        if(mf[i]->price == -1)
            continue;
        month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
        day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
        if(pmonth != month || pday != day)
            printf("%d�� %d��-------------------------------\n", month, day);
        if(mf[i]->IE == 0){
            printf("%3s %20s %10d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum += mf[i]->price;
        }
        else{
            printf("%3s %20s %10d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum -= mf[i]->price;
        }
        pmonth = month;
        pday = day;
    }
    printf("------------------------ �հ� : %d --\n", sum);
}

void searchCateIn(Moneyfolio *mf[], int total){       // ���� �з��� �˻� ���
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int find = 0;

    while(1){
        printf("�˻��Ͻ� ���� category(����, �μ���, �뵷)�� �Է��� �ּ���. ");
        scanf("%s", search);
        if(strcmp("����", search) == 0 || strcmp("�μ���", search) == 0 || strcmp("�뵷", search) == 0){
            for(int i = 0; i < total; i++){
                if(mf[i]->price == -1)
                    continue;
                month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
                day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
                if((strcmp(InCate[mf[i]->category], search) == 0) && (mf[i]->IE == 0)){
                    if(pmonth != month || pday != day)
                        printf("%d�� %d��-------------------------------\n", month, day);
                    printf("%3s %20s %10d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
                    find = 1;
                    pmonth = month;
                    pday = day;
                }
            }
            if(find == 1)
                printf("----------------------------------------\n");
            else 
                printf("ã���ô� category ������ �����ϴ�.\n");
            break;
        }   
        else
            printf("��ġ�ϴ� category�� �����ϴ�.\n");
    }
}

void searchCateEx(Moneyfolio *mf[], int total){       // ���� �з��� �˻� ���
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int find = 0;

    while(1){
        printf("�˻��Ͻ� ���� category(�ĺ�, ��Ȱ��ǰ, ����/����)�� �Է��� �ּ���. ");
        scanf("%s", search);
        if(strcmp("�ĺ�", search) == 0 || strcmp("��Ȱ��ǰ", search) == 0 || strcmp("����/����", search) == 0){
            for(int i = 0; i < total; i++){
                if(mf[i]->price == -1)
                    continue;
                month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
                day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
                if(strcmp(ExCate[mf[i]->category], search) == 0 && (mf[i]->IE == 1)){
                    if(pmonth != month || pday != day)
                        printf("%d�� %d��-------------------------------\n", month, day);
                    printf("%3s %20s %10d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
                    pmonth = month;
                    pday = day;
                    find = 1;
                }
            }
            if(find == 1)
                printf("----------------------------------------\n");
            else 
                printf("ã���ô� category ������ �����ϴ�.\n");
            break;
        }   
        else
            printf("��ġ�ϴ� category�� �����ϴ�.\n");
    }
}

void searchIncome(Moneyfolio *mf[], int total){         // ���Գ��� �˻� ���
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int find = 0;

    printf("�˻��Ͻ� ������ �Է��� �ּ���. ");
    fflush(stdin);
    fgets(search, 100, stdin);
    search[strlen(search)-1] = '\0';

    for(int i = 0; i < total; i++){
        if(mf[i]->price == -1)
            continue;
        month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
        day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
        if((strstr(mf[i]->note, search) != NULL) && (mf[i]->IE == 0)){
            if(pmonth != month || pday != day)
                printf("%d�� %d��-------------------------------\n", month, day);
            printf("%3s %20s %10d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
            pmonth = month;
            pday = day;
            find = 1;
        }
    }
    if(find == 1)
        printf("---------------------------------------\n");
    else
        printf("ã���ô� ������ ������ �����ϴ�.\n");
}

void searchExpense(Moneyfolio *mf[], int total){         // ���⳻�� �˻� ���
    char search[100];
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;
    int find = 0;

    printf("�˻��Ͻ� ������ �Է��� �ּ���. ");
    fflush(stdin);
    fgets(search, 100, stdin);
    search[strlen(search)-1] = '\0';

    for(int i = 0; i < total; i++){
        if(mf[i]->price == -1)
            continue;
        month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
        day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
        if((strstr(mf[i]->note, search) != NULL) && (mf[i]->IE == 1)){
            if(pmonth != month || pday != day)
                printf("%d�� %d��-------------------------------\n", month, day);
            printf("%3s %20s %10d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
            pmonth = month;
            pday = day;
            find = 1;
        }
    }
    if(find == 1)
        printf("---------------------------------------\n");
    else
        printf("ã���ô� ������ ������ �����ϴ�.\n");
}

void dayList(Moneyfolio *mf[], int total){     // ���� ���� list
    int month = 0;
    int day = 0;
    int pmonth = 0;
    int pday = 0;

    time_t t1;
    struct tm* ct;
    t1 = time(NULL);
    ct = localtime(&t1);

    month = (mf[0]->date[0] - '0') * 10 + (mf[0]->date[1] - '0');
    for(int i = 0; i < total, ct->tm_mon + 1 == month; i++){
        if(mf[i]->price == -1)
            continue;
        month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
        day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
        if(pmonth != month || pday != day)
            printf("%d�� %d��-------------------------------\n", month, day);
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
        if(mf[i]->price == -1)
            continue;
        month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
        day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
        if(month != pmonth)
            printf("%d��-------------------------------\n", month);
        if(mf[i]->IE == 0)
            printf("%d�� %s %s %d\n", day, InCate[mf[i]->category], mf[i]->note, mf[i]->price);
        else
            printf("%d�� %s %s %d\n", day, ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
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

    month = (mf[0]->date[0] - '0') * 10 + (mf[0]->date[1] - '0');
    for(int i = 0; i < total; i++){
        if(mf[i]->price == -1)
            continue;
        month = (mf[i]->date[0] - '0') * 10 + (mf[i]->date[1] - '0');
        day = (mf[i]->date[2] - '0') * 10 + (mf[i]->date[3] - '0');
        if(pmonth != month || pday != day)
            fprintf(file, "%d�� %d��-------------------------------\n", month, day);
        if(mf[i]->IE == 0){
            fprintf(file, "%3s %20s %10d\n", InCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum += mf[i]->price;
        }
        else{
            fprintf(file, "%3s %20s %10d\n", ExCate[mf[i]->category], mf[i]->note, mf[i]->price);
            sum -= mf[i]->price;
        }
        pmonth = month;
        pday = day;
    }
    fprintf(file, "------------------------ �հ� : %d --\n", sum);
    fclose(file);
    printf("����Ǿ����ϴ�.\n");
}

int selectIE(){
    int IE;
    printf("����(1), ����(2)�� �������ּ���. ");
    scanf("%d", &IE);
    return IE;
}

int selectMenu(){
    int menu;
    printf("���������������������� MoneyFolio ����������������������������\n");
    printf("|    1. ��ȸ                        |\n");
    printf("|    2. ����/���� ���� �߰�         |\n");
    printf("|    3. ����(����/����) ���� �߰�   |\n");
    printf("|    4. ����/���� ���� �˻�         |\n");
    printf("|    5. �з��� �˻�                 |\n");
    printf("|    6. ����/���� ���� ����         |\n");
    printf("|    7. ����/���� ���� ����         |\n");
    printf("|    8. ���� ���� ��ȸ              |\n");
    printf("|    9. ���� ���� ��ȸ              |\n");
    printf("|    10. �����ϱ�                   |\n");
    printf("��������������������������������������������������������������������������\n");
    printf("���ϴ� �޴��� �����Ͻÿ�. ");
    scanf("%d", &menu);
    return menu;
}

int compare_date(const void* first, const void* second){
    return strcmp(((Moneyfolio*)first)->date, ((Moneyfolio*)second)->date);
}
