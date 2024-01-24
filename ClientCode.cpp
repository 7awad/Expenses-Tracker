#include "ExpensesTracker.h"

// Client Code

int main() {
    ExpensesTracker tracker;

    int menuChoice;
    do {
        tracker.displayMenu();
        cout << "Enter your choice: ";
        while (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid input. Please enter a valid option.\n";
            cout << "Enter your choice: ";
        }

        switch (menuChoice) {
        case 1:
            tracker.addExpense();
            break;
        case 2:
            tracker.viewExpenses();
            break;
        case 3:
            tracker.saveExpensesToFile("expenses.txt");
            break;
        case 4:
            tracker.resetExpenses();
            cout << "\nExpenses file reset. Starting with an empty expense list.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (menuChoice != 3);

    system("pause");
}
