#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
using namespace std;

class customer {
    string C_name, Acc_Detail, prof, cont_no;
    int age, sal;
    static int c_id; // Static variable for ID tracking
    int l_amt, l_term;
    string apply_date, l_type, Pan;
    int C_score, ROI, repay_time;
    char decision;

public:
    customer() : l_amt(0), l_term(0), C_score(0), ROI(0), repay_time(0), decision('R') {}

    static void initialize_id() {
        ifstream id_file("last_id.txt");
        if (id_file.is_open()) {
            id_file >> c_id;
            id_file.close();
        } else {
            c_id = 100;
        }
    }

    static void save_last_id() {
        ofstream id_file("last_id.txt");
        if (id_file.is_open()) {
            id_file << c_id;
            id_file.close();
        } else {
            cout << "Error saving last ID to file.\n";
        }
    }

    void input() {
        cin.ignore();
        cout << "Enter the Name of the customer: ";
        getline(cin, C_name);
        cout << "Enter the Account Number of the customer: ";
        getline(cin, Acc_Detail);
        cout << "Enter the Age of the customer: ";
        cin >> age;
        cout << "Enter the Profession (private, public, government) of the customer: ";
        cin >> prof;
        cout << "Enter the salary of the customer: ";
        cin >> sal;
        cin.ignore();
        cout << "Enter the contact no of the customer: ";
        getline(cin, cont_no);

        c_id++;
        cout << "Customer ID generated: " << c_id << endl;

        save_last_id();
        save_to_file();
    }

    void save_to_file() {
        ofstream out_file("customer.txt", ios::app);
        if (out_file.is_open()) {
            out_file << "Customer ID: " << c_id << endl;
            out_file << "Name: " << C_name << endl;
            out_file << "Account Detail: " << Acc_Detail << endl;
            out_file << "Age: " << age << endl;
            out_file << "Salary: " << sal << endl;
            out_file << "Profession: " << prof << endl;
            out_file << "Contact No: " << cont_no << endl;
            out_file << "----------------------------\n";
            out_file.close();
            cout << "Customer data saved to file successfully.\n";
        } else {
            cout << "Error opening file to save customer data.\n";
        }
    }

    void loan_apply() {
        cout<< "\n==========LOAN DETAILS==========\n";
        cout << "Enter the Amount for Loan: ";
        cin >> l_amt;
        cin.ignore();
        cout << "Enter the reason for application (Loan Type-- \"Personal\" or \"Educational\"): ";
        getline(cin, l_type);
        cout << "Enter Date of Application (DD-MM-YYYY): ";
        getline(cin, apply_date);
        cout << "Enter the duration of the loan (in years): ";
        cin >> l_term;
        cin.ignore();
        cout << "Enter your PAN Number: ";
        getline(cin, Pan);
    }

    int calculate_credit_score(string profession, double salary) {
        int base_score = 500;
        if (profession == "government" || profession == "Government") {
            base_score += 200;
        } else if (profession == "public" || profession == "Public") {
            base_score += 150;
        } else if (profession == "private" || profession == "Private") {
            base_score += 100;
        } else {
            base_score -= 50;
        }

        if (salary > 200000) {
            base_score += 150;
        } else if (salary > 100000) {
            base_score += 100;
        } else if (salary > 50000) {
            base_score += 50;
        } else {
            base_score -= 50;
        }

        return min(max(base_score, 300), 900);
    }

    void approved_or_not() {
        C_score = calculate_credit_score(prof, sal);
        cout << "Credit Score --> ";
        if (C_score < 200) {
            cout << "Very Poor Score\n";
        } else if (C_score >= 200 && C_score < 450)
            cout << "Poor Score\n";
        else if (C_score >= 450 && C_score < 600)
            cout << "Average Score\n";
        else if (C_score >= 600 && C_score < 750)
            cout << "Good Score\n";
        else
            cout << "Excellent Score\n";

        cout << "Approve (A) or Reject (R): ";
        cin >> decision;

        if (decision == 'A' || decision == 'a') {
            cout << "Loan application for " << C_name << " has been APPROVED.\n";

            ofstream out_file("approved_loans.txt", ios::app);
            if (out_file.is_open()) {
                out_file << "Customer ID: " << c_id << endl;
                out_file << "Name: " << C_name << endl;
                out_file << "Loan Amount: " << l_amt << endl;
                out_file << "Loan Type: " << l_type << endl;
                out_file << "Application Date: " << apply_date << endl;
                out_file << "Loan Duration: " << l_term << " years" << endl;
                out_file << "Credit Score: " << C_score << endl;
                out_file << "----------------------------\n";
                out_file.close();
                cout << "Approved loan details saved successfully.\n";
            } else {
                cout << "Error opening file to save approved loan details.\n";
            }
        } else if (decision == 'R' || decision == 'r') {
            cout << "Loan application for " << C_name << " has been REJECTED.\n";
        } else {
            cout << "Invalid input. Please enter 'A' or 'R'.\n";
        }
    }

    void Emis() {
        if (decision == 'A' || decision == 'a') {
            cout<<"\n========For EMI========\n";
            cout << "Enter Rate of Interest (in %): ";
            cin >> ROI;
            cout << "Enter repayment time (in years): ";
            cin >> repay_time;

            int si = (l_amt * ROI * l_term) / 100;
            int total = l_amt + si;
            int emi_amt = total / (repay_time * 12);

            cout << "\nLoan Details:\n";
            cout << "Loan Amount: " << l_amt << endl;
            cout << "Interest Amount: " << si << endl;
            cout << "Total Amount to be Paid: " << total << endl;
            cout << "Monthly EMI: " << emi_amt << endl;
            cout << "Total EMIs: " << repay_time * 12 << endl;
        } else {
            cout << "Loan application rejected. No EMI calculation required.\n";
        }
    }

    static void display_all() {
        ifstream in_file("customer.txt");
        if (in_file.is_open()) {
            cout << "\n--- Customer Records ---\n";
            string line;
            while (getline(in_file, line)) {
                cout << line << endl;
            }
            in_file.close();
        } else {
            cout << "No customer data found. File not available.\n";
        }
    }

    static void display_Loan() {
        ifstream in_file("approved_loans.txt");
        if (in_file.is_open()) {
            cout << "\n------ Loan Records ------\n";
            string line;
            while (getline(in_file, line)) {
                cout << line << endl;
            }
            in_file.close();
        } else {
            cout << "No customer data found. File not available.\n";
        }
    }
};

int customer::c_id = 100;

//Function for password masking
string get_password() {
    string password = "";
#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getline(cin, password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
    cout << endl;
    return password;
}

int main() {
    customer::initialize_id();

    int a_id, pass;
    int count = 0, ch;
    int id = 28115, passwrd = 12345678;

    cout << "==========WELCOME==========\n";
    cout << " FINANCE MANAGEMENT SYSTEM\n===========================\n\n";
    cout << "-----------Login-----------\n\n";

    do {
        if (count < 3) {
            cout << "Admin ID: ";
            cin >> a_id;
            cout << "Password: ";
            string password_input = get_password();
            pass = stoi(password_input);

            if (a_id == id && pass == passwrd) {
                cout << "Login successful!\n";
                break;
            } else {
                cout << "Invalid details! Attempts remaining: " << 2 - count << "\n";
                count++;
            }
        } else {
            cout << "Too many failed login attempts. Exiting.\n";
            return 0;
        }
    } while (true);

    customer c1;
    do {
        cout << "\n1. Add Customer\n2. Display all customer records\n3. Display Loan Records\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            c1.input();
            c1.loan_apply();
            c1.approved_or_not();
            c1.Emis();
            break;
        case 2:
            customer::display_all();
            break;
        case 3:
            customer::display_Loan();
            break;
        case 4:
            cout << "THANK YOU!!\nExiting...\n";
            exit(0);
            break;
        default:
            cout << "Invalid Input\n";
        }
    } while (true);

    return 0;
}
