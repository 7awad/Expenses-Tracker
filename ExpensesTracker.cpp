#include "ExpensesTracker.h"

// Implementation file

ExpensesTracker::ExpensesTracker() : count(0) {
    loadExpensesFromFile("expenses.txt");
}

void ExpensesTracker::displayMenu() {
    cout << "        Personal Expenses Tracker\n";
    cout << "----------------------------------------\n";
    cout << "1. Add Expense\n";
    cout << "2. View Expenses\n";
    cout << "3. Save and Exit\n";
    cout << "4. Reset Expenses File\n";
    cout << "----------------------------------------\n";
}

void ExpensesTracker::addExpense() {
    if (count < MAX_EXPENSES) {
        Expense newExpense;

        cout << "\nEnter expense category: ";
        cin >> ws;  // Skip leading whitespaces
        getline(cin, newExpense.category);

        while (true) {
            cout << "Enter expense amount: ";
            cin >> newExpense.amount;

            if (cin.fail() || newExpense.amount < 0) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invalid input. Please enter a valid positive number.\n";
            }
            else {
                break;
            }
        }

        expenses[count++] = newExpense;
        cout << "\nExpense added successfully! Do you want to add another? (y/n): ";
        char addAnother;
        cin >> addAnother;
        if (addAnother != 'y' && addAnother != 'Y') {
            cout << "Returning to the main menu.\n";
        }
    }
    else {
        cout << "\nMax number of expenses reached. Cannot add more.\n";
    }
}

void ExpensesTracker::viewExpenses() const {
    if (count == 0) {
        cout << "\nNo expenses recorded.\n";
    }
    else {
        cout << "\n----------------------------------------\n";
        cout << left << setw(25) << "Expense Category" << right << setw(15) << "Amount" << endl;
        cout << "----------------------------------------\n";

        for (int expenseIndex = 0; expenseIndex < count; ++expenseIndex) {
            cout << left << setw(25) << expenses[expenseIndex].category << right << setw(15) << fixed << setprecision(2) << expenses[expenseIndex].amount << endl;
        }

        cout << "----------------------------------------\n";
        cout << left << setw(25) << "Total:" << right << setw(15) << calculateTotal() << endl << endl;
    }
}

void ExpensesTracker::saveExpensesToFile(const string& filename) const {
    ofstream outFile(filename);

    if (outFile.is_open()) {
        for (int expenseIndex = 0; expenseIndex < count; ++expenseIndex) {
            outFile << expenses[expenseIndex].category << " " << fixed << setprecision(2) << expenses[expenseIndex].amount << endl;
        }

        outFile.close();
        cout << "\nExpenses saved to file: " << filename << endl;
    }
    else {
        cerr << "\nError: Unable to open file for saving expenses.\n";
    }
}

void ExpensesTracker::loadExpensesFromFile(const string& filename) {
    ifstream inFile(filename);

    if (inFile.is_open()) {
        while (inFile >> expenses[count].category >> expenses[count].amount) {
            ++count;
            if (count >= MAX_EXPENSES) {
                cout << "\nError: Maximum number of expenses reached. Additional expenses ignored.\n";
                break;
            }
        }

        inFile.close();
        cout << "\nExpenses loaded from file: " << filename << endl;
    }
    else {
        cout << "\nNo existing file found. Starting with an empty expense list.\n";
    }
}

double ExpensesTracker::calculateTotal() const {
    double total = 0.0;
    for (int expenseIndex = 0; expenseIndex < count; ++expenseIndex) {
        total += expenses[expenseIndex].amount;
    }
    return total;
}

void ExpensesTracker::resetExpenses() {
    cout << "\nAre you sure you want to reset expenses? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        count = 0;
        cout << "Expenses reset successfully.\n";
    }
    else {
        cout << "Reset canceled.\n";
    }
}
