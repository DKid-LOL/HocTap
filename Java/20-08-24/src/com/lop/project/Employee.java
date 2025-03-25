package com.lop.project;

class Employee {
    String name;
    String employeeId;
    String position;
    double salary;

    Employee(String name, String employeeId, String position, double salary) {
        this.name = name;
        this.employeeId = employeeId;
        this.position = position;
        this.salary = salary;
    }

    double calculateAnnualSalary() {
        return salary * 12;
    }
}

