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

void sumList(Income *in, Expense *ex);
int searchCategory(Income * in, Expense *ex);
int searchIncome(Income *in);
int searchExpense(Expense *ex);
void dayList(Income * in, Expense *ex);
void monthList(Income * in, Expense *ex);
int save(Income * in, Expense *ex);
int selectIE();
int selectMenu();
