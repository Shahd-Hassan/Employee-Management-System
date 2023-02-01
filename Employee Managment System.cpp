#include <iostream>
using namespace std;
class Employee {
private:
    string full_name, phone, email, position;
    double salary;
public:
    Employee() {

    }
    Employee(string fn, string em, string ph, string pos, double sal) {
        full_name = fn;
        phone = ph;
        email = em;
        position = pos;
        salary = sal;
    }
    void display_employee_info() {
        cout << "****************************" << endl;
        cout << "Employee Information" << endl;
        cout << "============================" << endl;
        cout << "Employee Name: " << full_name << endl;
        cout << "Employee Phone: " << phone << endl;
        cout << "Employee Email: " << email << endl;
        cout << "Employee Position: " << position << endl;
        cout << "Employee Salary: " << salary << endl;
        cout << "****************************" << endl;
    }
    void set_email(string em) {
        email = em;
    }
    string get_email() {
        return email;
    }
    void set_salary(double sal) {
        salary = sal;
    }
    double get_salary() {
        return salary;
    }
    void set_phone(string ph) {
        phone = ph;
    }
    string get_phone() {
        return phone;
    }
    void set_position(string po) {
        position = po;
    }
    string get_position() {
        return position;
    }
    void set_name(string fn) {
        full_name = fn;
    }
    string get_name() {
        return full_name;
    }
};
template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T e) {
        data = e;
        next = NULL;
    }
};
template<class T>
class EmployeeList {
private:
    Node<T>* head;
public:
    EmployeeList() {
        head = NULL;
    }
    bool insert_employee(T e) {
        // We need to check first if this employee doesn't exit in the list.
        Node<T>* itr = head;
        bool found = false;
        while (itr != NULL) {
            if (itr->data.get_email() == e.get_email()) {
                found = true;
            }
            itr = itr->next;
        }
        if (found) {
            // Employee exits in the list
            cout << "Employee already in the list" << endl;
            return false;
        }
        else {
            // Employee doesn't exit in the list, you can add it now.
            Node<T>* newNode = new Node<T>(e);
            if (head == NULL) {
                head = newNode;
                cout << head->data.get_email() << " is added to the list" << endl;
                return true;
            }
            Node<T>* tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
            cout << newNode->data.get_email() << " is added to the list" << endl;
            return true;
        }
    }
    bool edit_salary(string email, double new_salary) {
        // Check first if this employee exits or not, if yes edit the salary, else don't
        Node<T>* itr = head;
        while (itr != NULL) {
            if (itr->data.get_email() == email) {
                if (itr->data.get_salary() != new_salary) {
                    itr->data.set_salary(new_salary);
                    cout << "Salary changed for " << itr->data.get_email() << endl;
                    return true;
                }
                else {
                    cout << "You're trying to edit the salary with the same value, try to change it" << endl;
                    return false;
                }
                break;
            }
            itr = itr->next;
        }
        cout << "Employee doesn't exist" << endl;
        return false;
    }
    bool delete_employee(string email) {
        // Check first if this employee exits or not, if yes delete it, else return false
        Node<T>* itr = head;
        Node<T>* tmp = NULL;
        while (itr != NULL) {
            if (itr->data.get_email() == email) {
                // if itr == head, this is the first employee in the list
                if (itr == head) {
                    head = head->next;
                    cout << "Employee: " << itr->data.get_email() << " deleted." << endl;
                    delete itr;
                    return true;
                }
                else {
                    tmp->next = itr->next;
                    itr->next = NULL;
                    cout << "Employee: " << itr->data.get_email() << " deleted." << endl;
                    delete itr;
                    return true;
                }
            }
            // if itr != head, we need to move until we reach the employee
            // so we need to move the itr, and keeping the tmp before the itr.
            tmp = itr;
            itr = itr->next;
        }
        cout << "Employee doesn't exist" << endl;
        return false;
    }
    bool update_info(string email) {
        // Check first if this employee exits or not, if yes start editing, else return false
        Node<T>* itr = head;
        Node<T>* tmp = NULL;
        while (itr != NULL) {
            if (itr->data.get_email() == email) {
                // Ask for what info user wants to change
                bool conti = true;
                while (conti) {
                    cout << "Please enter the number related to the info you want to change" << endl;
                    cout << "1. Name" << endl;
                    cout << "2. Email" << endl;
                    cout << "3. Phone" << endl;
                    cout << "4. Position" << endl;
                    cout << "5. Salary" << endl;
                    cout << "6. Exit editing" << endl;
                    int ans = 0;
                    cout << ">> "; cin >> ans;
                    // IF-ELSE could be replaced with SWITCH
                    if (ans == 6)
                        conti = false;
                    else {
                        if (ans == 1) {
                            string fn = "";
                            cout << "Enter the new full name" << endl;
                            cin >> fn;
                            itr->data.set_name(fn);
                            cout << "Name is changed" << endl;
                        }
                        else if (ans == 2) {
                            string em = "";
                            cout << "Enter the new email" << endl;
                            cin >> em;
                            itr->data.set_email(em);
                            cout << "Email is changed" << endl;
                        }
                        else if (ans == 3) {
                            string ph = "";
                            cout << "Enter the new phone" << endl;
                            cin >> ph;
                            itr->data.set_phone(ph);
                            cout << "Phone is changed" << endl;
                        }
                        else if (ans == 4) {
                            string po = "";
                            cout << "Enter the new position" << endl;
                            cin >> po;
                            itr->data.set_position(po);
                            cout << "Position is changed" << endl;
                        }
                        else if (ans == 5) {
                            cout << "Enter the new salary " << endl;
                            double nSalary;
                            cin >> nSalary;
                            edit_salary(email, nSalary);
                        }
                    }
                }
                return true;
            }
            itr = itr->next;
        }
        cout << "Employee doesn't exist" << endl;
        return false;
    }
    void print_all() {
        Node<T>* itr = head;
        while (itr != NULL) {
            itr->data.display_employee_info();
            itr = itr->next;
        }
    }
};

int main() {
    EmployeeList<Employee> el;
    cout << "Welcome to the Employee Management System" << endl;
    cout << "Choose of the following to use the system features" << endl;
    cout << "1. Insert a new Employee" << endl;
    cout << "2. Edit employee's salary" << endl;
    cout << "3. Delete an employee" << endl;
    cout << "4. Print all employees" << endl;
    cout << "5. Close the program" << endl;
    int x=0;
    cout << "################################################################################" << endl;


    while (x != 6) {
        cout << "Enter a Number: " << endl;
        cin >> x;

        switch (x) {
        case 1:
        {

            string em, fn, ph, po;
            double sal;
            cout << "Enter The Email To Add: " << endl;
            cin >> em;
            cout << "Enter The Full Name: " << endl;
            cin >> fn;
            cout << "Enter The Phone: " << endl;
            cin >> ph;
            cout << "Enter The Position: " << endl;
            cin >> po;
            cout << "Enter The salary: " << endl;
            cin >> sal;
            Employee Employee1(em, fn, ph, po, sal);

            Employee1.set_email(em);
            Employee1.set_name(fn);
            Employee1.set_phone(ph);
            Employee1.set_position(po);
            Employee1.set_salary(sal);
            el.insert_employee(Employee1);
            el.print_all();
        }
        break;
        case 2:
        {

            double new_salary;
            string email2;
            cout << "Enter The Email To search: " << endl;
            cin >> email2;
            cout << "Enter The New Salary: " << endl;
            cin >> new_salary;
           el.edit_salary(email2, new_salary);
        }
        continue;
        case 3:
        {

            string emailsr;
            cout << "Enter Email To Search: " << endl;
            cin >> emailsr;
            el.delete_employee(emailsr);
        }
        continue;
        case 4:

            cout << "The List Of Employees: " << endl;
            el.print_all();

            continue;
        case 5:
        {
            string emailit;
            cout << "Enter Email To Search: " << endl;
            cin >> emailit;
            el.update_info(emailit);
           el.print_all();
            continue;
        }
        case 6:
            break;
        default:
            cout << "Invalid input! Please Try Again..." << endl;
            continue;
        }
    }


    return 0;
}

    // Handling menu will be here
    // You shouldn't provide static access to the user, user need to choose options,
    // Create objects, for whatever the case
  /*  Employee e("Tawfik", "tyasser@nu.edu.eg", "11111111", "TA", 6000.0);
    cout << el.insert_employee(e) << endl;
    Employee e1("Ahmed", "ahmed@nu.edu.eg", "11111111111", "RA", 5000.0);
    cout << el.insert_employee(e1) << endl;
    Employee e2("Ahmed", "ahmed@nu.edu.eg", "111111", "RA", 5000.0);
    cout << el.insert_employee(e2) << endl;
    el.print_all();
    el.edit_salary("tyasser@nu.edu.eg", 7000.0);
    el.delete_employee("tyassernu.edu.eg");
    el.update_info("tyasser@nu.edu.eg");
    el.print_all();*/

  