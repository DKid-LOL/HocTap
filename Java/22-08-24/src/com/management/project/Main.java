package com.management.project;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static List<Employee> employeeList = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean isRunning = true;

        while (isRunning) {
            System.out.println("\nChương Trình Quản Lý Nhân Sự");
            System.out.println("1. Nhập thông tin nhân sự");
            System.out.println("2. Sắp xếp nhân sự theo lương giảm dần");
            System.out.println("3. Phân tích theo quê quán");
            System.out.println("4. Tìm nhân sự theo quê quán và lương thấp nhất");
            System.out.println("5. Lưu danh sách nhân sự vào file");
            System.out.println("6. Mở file và hiển thị danh sách");
            System.out.println("7. Thoát");
            System.out.print("Vui lòng chọn chức năng: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    inputEmployeeData(scanner);
                    break;
                case 2:
                    sortEmployeesBySalary();
                    break;
                case 3:
                    analyzeByCountry();
                    break;
                case 4:
                    searchByCountryAndMinSalary(scanner);
                    break;
                case 5:
                    saveEmployeesToFile(scanner);
                    break;
                case 6:
                    loadEmployeesFromFile(scanner);
                    break;
                case 7:
                    isRunning = false;
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ. Vui lòng thử lại.");
                    break;
            }
        }
        scanner.close();
    }

    // Chức năng 1: Nhập thông tin nhân sự
    public static void inputEmployeeData(Scanner scanner) {
        System.out.print("Nhập số lượng nhân sự cần thêm: ");
        int numEmployees = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < numEmployees; i++) {
            System.out.print("Nhập tên nhân sự: ");
            String name = scanner.nextLine();
            System.out.print("Nhập quê quán: ");
            String country = scanner.nextLine();
            System.out.print("Nhập năm sinh: ");
            int birthYear = scanner.nextInt();
            System.out.print("Nhập lương: ");
            int salary = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            Employee employee = new Employee(name, country, birthYear, salary);
            employeeList.add(employee);
        }
    }

    // Chức năng 2: Sắp xếp nhân sự theo lương giảm dần
    public static void sortEmployeesBySalary() {
        employeeList.sort(Comparator.comparingInt(Employee::getSalary).reversed());
        System.out.println("Danh sách nhân sự sau khi sắp xếp theo lương giảm dần:");
        for (Employee employee : employeeList) {
            employee.displayInfo();
        }
    }

    // Chức năng 3: Phân tích theo quê quán
    public static void analyzeByCountry() {
        System.out.println("Phân tích nhân sự theo quê quán:");
        employeeList.stream()
                .map(Employee::getCountry)
                .distinct()
                .forEach(country -> {
                    long count = employeeList.stream().filter(e -> e.getCountry().equalsIgnoreCase(country)).count();
                    System.out.println("Quê quán: " + country + ", Số lượng: " + count);
                });
    }

    // Chức năng 4: Tìm nhân sự theo quê quán và lương thấp nhất
    public static void searchByCountryAndMinSalary(Scanner scanner) {
        System.out.print("Nhập quê quán cần tìm: ");
        String searchCountry = scanner.nextLine();
        System.out.print("Nhập mức lương thấp nhất: ");
        int minSalary = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        System.out.println("Danh sách nhân sự có quê quán " + searchCountry + " và lương cao hơn hoặc bằng " + minSalary + ":");
        employeeList.stream()
                .filter(e -> e.getCountry().equalsIgnoreCase(searchCountry) && e.getSalary() >= minSalary)
                .forEach(Employee::displayInfo);
    }

    // Chức năng 5: Lưu danh sách nhân sự vào file
    public static void saveEmployeesToFile(Scanner scanner) {
        System.out.print("Nhập tên file để lưu: ");
        String fileName = scanner.nextLine();

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(employeeList);
            System.out.println("Đã lưu danh sách nhân sự vào file: " + fileName);
        } catch (IOException e) {
            System.out.println("Lỗi khi lưu file: " + e.getMessage());
        }
    }

    // Chức năng 6: Mở file và hiển thị danh sách
    public static void loadEmployeesFromFile(Scanner scanner) {
        System.out.print("Nhập tên file để mở: ");
        String fileName = scanner.nextLine();

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            employeeList = (List<Employee>) ois.readObject();
            System.out.println("Đã mở danh sách nhân sự từ file: " + fileName);
            for (Employee employee : employeeList) {
                employee.displayInfo();
            }
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi khi mở file: " + e.getMessage());
        }
    }
}
