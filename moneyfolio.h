typedef struct{
        int month;
        int day;
} Date;
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[3][20] = {"����","�μ���","�뵷"};
} Income;       // ����
typedef struct{
        Date d;
        char note[100];
        int price;
        char category[5][20] = {"�ĺ�","����/����","�ְ�/���","��ȭ��Ȱ","��Ȱ��ǰ"};
} Expense;      // ����

int addIncome(Income *in);
int addExpense(Expense *ex);
int addfIncome(Income *in);
int addfExpense(Expense *ex);

void updateIncome(Income *in);
void updateExpense(Expense *ex);
int deleteIncome(Income *in);
int deleteExpense(Expense *ex);

void sumList(Income *in, Expense *ex);          // �Ϻ� ���� list + �հ� ��� ���
int searchCategory(Income * in, Expense *ex);           // ���� & ���� �з��� �˻� ���
int searchIncome(Income *in);                   // ���Գ��� �˻� ���
int serachExpense(Expense *ex);                 // ���⳻�� �˻� ���
void dayList(Income * in, Expense *ex);         // ���� ���� list ���
void monthList(Income * in, Expense *ex);       // ���� ���� list ���
int save(Income * in, Expense *ex);             // �Ϻ� ���� list +  �հ� ������