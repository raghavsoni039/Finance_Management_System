💼 Finance Management System

A simple yet powerful console-based application written in C++ to manage customer loan records and EMI calculations.

🛠 Features
- ✨ Login System: Admin login with password masking (⭐ Security Feature)
- 👤 Customer Management: Add new customers, save data to a local file for persistence
- 💰 Loan Processing: Apply for loans, automatically calculate credit score based on profession and salary, approve or reject loans
- 📄 EMI Calculation: Compute EMI based on interest rate and repayment period
- 📂 Data Storage: All data is stored in local .txt files:
    - customer.txt: Stores customer records
    - approved_loans.txt: Stores approved loan details
    - last_id.txt: Tracks the last used customer ID for continuity
- 📊 View Records: Display all customer data, display approved loan records

🚀 How to Run
1. Compile the code using a C++ compiler:
bash
g++ -o finance_app finance.cpp
2. Run the application:
bash
./finance_app
3. Login Credentials:
    - Admin ID: 28115
    - Password: 12345678 (input will be masked)

📌 Files Used
- customer.txt: Stores customer records
- approved_loans.txt: Stores approved loan details
- last_id.txt: Tracks the last used customer ID for continuity

🧠 Credit Score Logic
Your credit score is determined by:
- Profession: Government > Public > Private
- Salary Bracket: Higher salary means a better score
- Final score is capped between 300 and 900

🤝 Contributing
Feel free to contribute to this project by submitting pull requests or issues.
