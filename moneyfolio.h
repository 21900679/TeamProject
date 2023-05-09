typedef struct{
        int month;
        int day;
} Date;
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[20];
} Income;
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[20];
} Expense;

int addIncome(Income *in);
int addExpense(Expence *ex);
int addfIncome(Income *in);
int addfExpense(Expense *ex);

void updateIncome(Income *in);
void updateExpense(Expense *ex);
int deleteIncome(Income *in);
int deleteExpense(Expense *ex);

