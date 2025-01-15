# Cpp-BankSystemProject

A comprehensive **Bank System Application** built in C++ with a modular design for managing clients, employees, and administrators efficiently.

---

## Features

### **Client Module**
- **Details**: ID, name, password, balance.
- **Functionalities**:
  - Login using ID and password.
  - Deposit and withdraw money.
  - Check account balance.
  - Transfer money to another client.

### **Employee Module**
- **Details**: ID, name, password, salary.
- **Functionalities**:
  - Login using ID and password.
  - Add new clients and manage their details.
  - Search for clients by ID.
  - List all clients.
  - Edit client information.
  - View personal information.

### **Admin Module**
- Inherits all features from the **Employee Module**.
- **Additional Functionalities**:
  - Add, edit, search, and list employees.

---

## Project Architecture

### **Inheritance Structure**
- **Person Class**: Base class containing `name`, `id`, and `password`.
- **Client & Employee Classes**: Inherit from `Person`.
- **Admin Class**: Inherits from `Employee`.

### **Data Persistence**
- Data is stored in:
  - `Clients.txt`
  - `Employees.txt`
  - `Admins.txt`

### **Validation**
- Name: Alphabetic only, length 5-20.
- Password: Length 8-20.
- Minimum client balance: 1500.
- Minimum employee/admin salary: 5000.

---

## Phase Breakdown

### **Phase 1**
- Implement core classes (`Client`, `Employee`, `Admin`).
- Add validation logic using a `Validation` helper class.
- Implement basic operations (deposit, withdraw, transfer, etc.).

### **Phase 2**
- File handling:
  - Save and retrieve data from text files.
  - Parse data using a `Parser` class.
- Create `DataSourceInterface` for file operations and implement it in a `FileManager` class.

### **Phase 3**
- Add interactive user interfaces:
  - Client operations via `ClientManager`.
  - Employee operations via `EmployeeManager`.
  - Admin operations via `AdminManager`.
- Include a `Screens` class for navigation and user interaction.

---

## Getting Started

### Prerequisites
- **C++ Compiler** (e.g., GCC, Clang).
- Basic understanding of object-oriented programming.

### Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/BishoySameh98/Cpp-BankSystemProject.git
