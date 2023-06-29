package CWHPrac;

public class Class {
    public static class Employee {
        private String name = "Rohit";

        double S, a;

        Employee(double Salary, double age) {
            this.S = Salary;
            this.a = age;
        }

        public void setName(String Name) {
            this.name = Name;
        }

        public String getName() {
            return this.name;
        }
    }

    public static void main(String[] args) {
        Employee employee = new Employee(12000, 20);
        employee.setName("Rishit");
        System.out.println(employee.getName());
    }
}