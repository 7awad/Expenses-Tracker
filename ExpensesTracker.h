#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Header file

const int MAX_EXPENSES = 100;

struct Expense {
    string category;
    double amount;
};

class ExpensesTracker {
public:
    ExpensesTracker();

    void displayMenu();
    void addExpense();
    void viewExpenses() const;
    void saveExpensesToFile(const string& filename) const;
    void loadExpensesFromFile(const string& filename);
    double calculateTotal() const;
    void resetExpenses();

private:
    Expense expenses[MAX_EXPENSES];
    int count;
};
