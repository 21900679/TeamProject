#include <stdio.h>
#include <stdlib.h>
#include "moneyfolio.h"

int main(void){
    Moneyfolio *m[200];
    int menu;
    int IE;
    // int countIn = 0;
    // int countEx = 0;
    int count = 0;
    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1){
            if(count == 0)
                printf("입력된 내역이 없습니다.\n");
            else
                sumList(m, count);
        }   
        else if(menu == 2){
            IE = selectIE();
            if(IE == 1){
                m[count] = (Moneyfolio *) malloc (sizeof(Moneyfolio));
                count += addIncome(m[count]);
                qsort(m, count, sizeof(Moneyfolio*), compare_date);
            }
            else if(IE == 2){
                m[count] = (Moneyfolio *) malloc (sizeof(Moneyfolio));
                count += addExpense(m[count]);
                qsort(m, count, sizeof(Moneyfolio*), compare_date);
            }
        }
        else if(menu == 3){
            IE = selectIE();
            if(IE == 1){
                count += addfIncome(m, count);
                qsort(m, count, sizeof(Moneyfolio*), compare_date);
            }            
            else if(IE == 2){
                count += addfExpense(m, count);
                qsort(m, count, sizeof(Moneyfolio*), compare_date);
            }
        }
        else if(menu == 4){
            IE = selectIE();
            if(IE == 1)
                searchIncome(m, count);
            else if(IE == 2)
                searchExpense(m, count);
        }
        else if(menu == 5){
            IE = selectIE();
            if(IE == 1)
                searchCateIn(m, count);
            else if(IE == 2)
                searchCateEx(m, count);
        }
        else if(menu == 6){
            IE = selectIE();
            int no = selectNo(m, count);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            if(IE == 1){
                if(m[no-1]->IE != 0){
                    printf("수입 내역을 선택해주세요.\\n\n\n");
                    continue;
                }
                updateIncome(m[no-1]);
                qsort(m, count, sizeof(Moneyfolio*), compare_date);
            }
                
            else if(IE == 2){
                if(m[no-1]->IE != 1){
                    printf("지출 내역을 선택해주세요.\n\n\n");
                    continue;
                }
                updateExpense(m[no-1]);
                qsort(m, count, sizeof(Moneyfolio*), compare_date);
            }
        }
        else if(menu == 7){
            IE = selectIE();
            int no = selectNo(m, count);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            deleteIE(m[no-1]);
            qsort(m, count, sizeof(Moneyfolio*), compare_date);
            // if(IE == 1) count--;
            // else if(IE == 2) count--;
        }
        else if(menu == 8)  dayList(m, count);
        else if(menu == 9)  monthList(m, count);
        else if(menu == 10) save(m, count);
    }
    printf("=> 종료됨!\n");
    return 0;
}
