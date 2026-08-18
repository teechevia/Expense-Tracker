#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Expense{
    int id;
    string description;
    double amount;
    string category;
};

void Add_expense(Expense &e){
    cout << "ID: ";
    cin >> e.id;
    cout << "Description: ";
    cin.ignore();
    getline(cin, e.description);
    cout << "Amount: ";
    cin >> e.amount;
    cout << "Category: ";
    cin.ignore();
    getline(cin, e.category);
}

void Delete_expense(vector<Expense>& expenses){
    int deleteID;
    cout << "Enter the ID: ";
    cin >> deleteID;
    for(auto it = expenses.begin(); it!=expenses.end(); it++){
        if(it->id == deleteID){
            expenses.erase(it);
            break;
        }
    }
}

void List_expenses(const vector<Expense>& expenses){
    for(const auto& each: expenses){
        cout << "ID: " << each.id << '\n';
        cout << "Description: " << each.description << '\n';
        cout << "Amount: " << each.amount << '\n';
        cout << "Category: " << each.category << '\n';
        cout << "----------------------------------\n";
    }
}

void Total_expenses(const vector<Expense>& expenses){
    double amount = 0;
    for(auto i = expenses.begin(); i!=expenses.end(); i++){
        amount = amount + i->amount;
    }
    cout << "Your total expenses is " << amount << ".\n\n";
}

void Highest_expense(const vector<Expense>& expenses){
    if(expenses.empty()){
        cout << "You have 0 expense.";
        return;
    }
    double high = 0;
    for(const auto& e: expenses){
        if(e.amount > high){
            high = e.amount;
        }
    }
    for(const auto& e: expenses){
        if(e.amount == high){
            cout << "Your highest expense is: \n\n";
            cout << "ID: " << e.id << '\n';
            cout << "Description: " << e.description << '\n';
            cout << "Amount: " << e.amount << '\n';
            cout << "Category: " << e.category << "\n\n";
            break;
        }
    }
}

void Search_expenses(const vector<Expense>& expenses){
    int id, choice;
    string description, category;
    double amount;
    cout << "Select the target by which you want to search:\n\n1. ID\n2. Description\n3. Amount\n4. Category\n\nChoice: ";
    cin >> choice;
    switch(choice){
        case 1:
            system("cls");
            cout << "Enter ID: ";
            cin >> id;
            for(const auto& e: expenses){
                if(id == e.id){
                    cout << "ID: " << e.id << '\n';
                    cout << "Description: " << e.description << '\n';
                    cout << "Amount: " << e.amount << '\n';
                    cout << "Category: " << e.category << "\n\n";
                    break;
                }
            }
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Enter Description: ";
            cin.ignore();
            getline(cin, description);
            for(const auto& e: expenses){
                if(description == e.description){
                    cout << "ID: " << e.id << '\n';
                    cout << "Description: " << e.description << '\n';
                    cout << "Amount: " << e.amount << '\n';
                    cout << "Category: " << e.category << "\n\n";
                    break;
                }
            }
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Enter Amount: ";
            cin >> amount;
            for(const auto& e: expenses){
                if(amount == e.amount){
                    cout << "ID: " << e.id << '\n';
                    cout << "Description: " << e.description << '\n';
                    cout << "Amount: " << e.amount << '\n';
                    cout << "Category: " << e.category << "\n\n";
                    break;
                }
            }
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Enter Category: ";
            cin.ignore();
            getline(cin, category);
            for(const auto& e: expenses){
                if(category == e.category){
                    cout << "ID: " << e.id << '\n';
                    cout << "Description: " << e.description << '\n';
                    cout << "Amount: " << e.amount << '\n';
                    cout << "Category: " << e.category << "\n\n";
                }
            }
            system("pause");
            break;
        default:
            cout << "Invalid choice.\n";
    }
}

int main(){
    Expense expense;
    vector<Expense> expenses;
    while(true){
        system("cls");
        cout << "========================\n    Expense Tracker\n========================\n\n";
        cout << "1. Add expense\n2. Delete expense\n3. List expenses\n4. Total expenses\n5. Highest expense\n6. Search expenses\n7. Exit\n\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: 
                system("cls");
                Add_expense(expense);
                expenses.push_back(expense);
                break;
            case 2: 
                system("cls");
                Delete_expense(expenses);
                break;
            case 3: 
                system("cls");
                List_expenses(expenses);
                system("pause");
                break;
            case 4: 
                system("cls");
                Total_expenses(expenses);
                system("pause");
                break;
            case 5: 
                system("cls");
                Highest_expense(expenses); 
                system("pause");
                break;
            case 6: 
                system("cls");
                Search_expenses(expenses);
                system("pause");
                break;
            case 7: 
                return 0;
            default: 
                cout << "Invalid choice.";
        }
    }
    return 0;
}