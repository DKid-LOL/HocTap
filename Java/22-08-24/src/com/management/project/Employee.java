package com.management.project;

import java.io.Serializable;

public class Employee implements Serializable {
    private String name;
    private String country;
    private int birthYear;
    private int salary;

    // Constructor không tham số
    public Employee() {
    }

    // Constructor đầy đủ tham số
    public Employee(String name, String country, int birthYear, int salary) {
        this.name = name;
        this.country = country;
        this.birthYear = birthYear;
        this.salary = salary;
    }

    // Getter và Setter
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCountry() {
        return country;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public int getBirthYear() {
        return birthYear;
    }

    public void setBirthYear(int birthYear) {
        this.birthYear = birthYear;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    // Phương thức hiển thị thông tin nhân viên
    public void displayInfo() {
        System.out.println("Name: " + name + ", Country: " + country + ", Birth Year: " + birthYear + ", Salary: " + salary);
    }
}
