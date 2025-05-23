💼 Finance Management System
Welcome to the Finance Management System — a simple yet powerful console-based application written in C++ to manage customer loan records and EMI calculations. It allows admins to add customers, record loan applications, evaluate credit scores, approve/reject loans, and display stored data.

🛠 Features
✨ Login System

Admin login with password masking (⭐ Security Feature)

👤 Customer Management

Add new customers

Save data to a local file for persistence

💰 Loan Processing

Apply for loans

Automatically calculate a customer's credit score based on profession and salary

Approve or reject loans

📄 EMI Calculation

Compute EMI based on interest rate and repayment period

📂 Data Storage

All data is stored in local .txt files:

customer.txt

approved_loans.txt

last_id.txt

📊 View Records

Display all customer data

Display approved loan records

🚀 How to Run
Compile the code using a C++ compiler:

bash
Copy
Edit
g++ -o finance_app finance.cpp
Run the application:

bash
Copy
Edit
./finance_app
Login Credentials:

Admin ID: 28115

Password: 12345678 (input will be masked)

📌 Files Used
customer.txt: Stores customer records

approved_loans.txt: Stores approved loan details

last_id.txt: Tracks the last used customer ID for continuity

🧠 Credit Score Logic
Your credit score is determined by:

Profession: Government > Public > Private

Salary Bracket: Higher salary means a better score

Final score is capped between 300 and 900

