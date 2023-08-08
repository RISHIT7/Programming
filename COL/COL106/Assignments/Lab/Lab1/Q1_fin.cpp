/* ----------------------------------- OOPs ----------------------------------- */

#include <iostream> // including the i/o stream of cpp
#include <set>
using namespace std; // using the namespace std

set<int> database;     // creating a basic database, for maintaining unique ids
set<int> manager_data; // seperate database for manager id

class Employee // Employee class declaration
{
private:
    int password; //  a private varibale to store the password

protected:
    bool unique; // a protected variable to check if the id is unique

public:
    int id;                // a public variable id
    Employee(int identity) // constructor
    {
        id = identity;
        unique = true;               // initialize unique with true
        if (database.count(id) != 0) // if the count is 0, that means id is unique
            unique = false;

        if (unique)
            database.insert(id); // incase of a unique id, we would insert the new id into the database

        password = -1;
    }

    virtual void work()
    {
        if (not unique) // if not unique we inform the person that the id is not unique
            cout << "Not a unique id" << endl;

        else // printing
            cout << "I am Employee " << id << " and I am working." << endl;
    }

    void login(int pass)
    {
        if (unique) // checking for a unique id
        {
            if (password != -1) // checking if a password is already set
            {
                if (pass == password) // comparing password
                    cout << "Login Successful" << endl;

                else
                    cout << "Login Unsuccessful" << endl;
            }

            else // if not set, calling sign_up function
            {
                cout << "Password not set..." << endl;
                sign_up(pass);
                return;
            }
        }
        else
        {
            cout << "Not a unique ID" << endl;
            return;
        }
    }

    void sign_up(int pass)
    {
        if (unique) // checking for a unique id
        {
            if (password == -1) // checking if password not set
            {
                password = pass; // setting the password
                cout << "Sign Up successful" << endl;
            }
            else
            {
                cout << "Account already made, please log in" << endl;
                return;
            }
        }
        else
        {
            cout << "Not a unique ID" << endl;
            return;
        }
    }
};

class Developer : public Employee
{
private:
    int password; //  a private varibale to store the password

protected:
    bool unique; // a protected variable to check if the id is unique

public:
    Developer(int id) : Employee(id)
    {
    }
};

class Manager : public Employee
{
private:
    int password;

protected:
    bool unique;

public:
    int manager_id;
    Manager(int id, int m_id) : Employee(m_id)
    {
        manager_id = m_id;
        unique = true;                   // initialize unique with true
        if (manager_data.count(id) != 0) // if the count is 0, that means id is unique
            unique = false;

        if (unique)
            manager_data.insert(id); // incase of a unique id, we would insert the new id into the database

        password = -1;
    }

    void work()
    {
        if (not unique) // if not unique we inform the person that the id is not unique
            cout << "Not a unique id" << endl;

        else // printing
            cout << "I am Employee " << manager_id << " and I am working." << endl;
    }
};

int main() // main function
{
    /*--------------- Part 1 ----------------*/

    // Employee Rishit = Employee(230947);
    // Rishit.work();
    // cout << Rishit.id << endl;

    // Employee Raman = Employee(36554);
    // Raman.work();
    // cout << Raman.id << endl;

    // Employee Ram = Employee(230947);
    // Ram.work();
    // cout << Ram.id << endl;

    // Rishit.login(24755);
    // Raman.sign_up(24755);
    // Rishit.sign_up(24755);
    // Rishit.login(24777);
    // Rishit.login(24755);
    // Ram.sign_up(654);

    // /*-------------- Part 2 ----------------*/

    Manager Rishit = Manager(54456, 3543684);
    Rishit.work();
    cout << Rishit.manager_id << endl;

    Developer Raman = Developer(365431);
    Raman.work();
    cout << Raman.id << endl;

    Rishit.login(24755);
    Raman.sign_up(24755);
    Rishit.sign_up(24755);
    Rishit.login(22777);
    Rishit.login(24755);

    return 0;
}