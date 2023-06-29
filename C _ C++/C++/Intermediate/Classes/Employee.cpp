#include <bits/stdc++.h>
using namespace std;

int main()
{
    class Employee
    {
        double age, salary;
    private:
        string name = "rohit";
    public:
        void setSalary(int s)
        {
            salary = s;
        }
        int getSalary()
        {
            return salary;
        }
    };
    
    Employee employee = Employee();
    employee.setSalary(10000);
    cout<<employee.getSalary()<<endl;

    return 0;
}