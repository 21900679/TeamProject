#include <stdio.h>
#include "moneyfolio.h"

int main(void){
    Moneyfolio *m[200];
    int menu;
    int IE;
    int countIn = 0;
    int countEx = 0;

    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1)   sumList(m, countIn + countEx);
        else if(menu == 2){
            IE = selectIE();
            if(IE == 1)
                addIncome(m);
            else if(IE == 2)
                addExpense(m);
        }
        else if(menu == 3){
            IE = selectIE();
            if(IE == 1)
                addfIncome(m);
            else if(IE == 2)
                addfExpense(m);
        }
        else if(menu == 4){
            IE = selectIE();
            if(IE == 1)
                searchIncome(m, countIn + countEx);
            else if(IE == 2)
                searchExpense(m, countIn + countEx);
        }
        else if(menu == 5){
            IE = selectIE();
            if(IE == 1)
                searchCateIn(m, countIn + countEx);
            else if(IE == 2)
                searchCateEx(m, countIn + countEx);
        }
        else if(menu == 6){
            IE = selectIE();
            if(IE == 1)
                updateIncome(m);
            else if(IE == 2)
                updateExpense(m);
        }
        else if(menu == 7){
            deleteIE(m);
        }
        else if(menu == 8)  dayList(m, countIn + countEx);
        else if(menu == 9)  monthList(m, countIn + countEx);
        else if(menu == 10) save(m, countIn + countEx);
    }
    printf("=> 종료됨!\n");
    return 0;
}
