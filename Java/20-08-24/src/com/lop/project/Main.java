package com.lop.project;

import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("Vui lòng chọn tính năng:");
            System.out.println("1. Tạo đối tượng Person và hiển thị thông tin");
            System.out.println("2. Tạo đối tượng 4 Sinh viên và hiển thị điểm trung bình từng sinh viên");
            System.out.println("3. Tạo tài khoản ngân hàng và nạp rút");
            System.out.println("4. Tạo đối tượng máy tính và hiển thị thông tin");
            System.out.println("5. Tạo hình tròn và hiển thị tính chu vi diện tích");
            System.out.println("6. Tạo đối tượng động vật và in ra tiếng kêu");
            System.out.println("7. Tạo đối tượng xe hơi và in ra giảm giá");
            System.out.println("8. Tạo đối tượng nhân viên và in ra lương hàng năm");
            System.out.println("9. Thoát");
            System.out.print("Nhập lựa chọn của bạn: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Clear buffer

            switch (choice) {
                case 1:
                    // Tạo và sử dụng đối tượng Person
                    Person person = new Person("John", 30, "Male");
                    person.getInfo();
                    break;
                case 2:
                    // Tạo và sử dụng đối tượng Student với 4 constructor khác nhau
                    Student student1 = new Student();
                    Student student2 = new Student("S001", "Alice");
                    Student student3 = new Student("S002", "Bob", 22);
                    Student student4 = new Student("S003", "Charlie", 20, 3.5f);
                    System.out.println("Sinh viên 1: " + student1.calculateGPA(new float[] {3.0f, 3.5f, 4.0f}));
                    System.out.println("Sinh viên 2: " + student2.calculateGPA(new float[] {2.5f, 3.0f, 3.2f}));
                    break;
                case 3:
                    // Tạo tài khoản ngân hàng và nạp rút
                    BankAccount account = new BankAccount(1000);
                    account.deposit(500);
                    account.withdraw(200);
                    break;
                case 4:
                    // Tạo đối tượng máy tính
                    Computer computer = new Computer("Dell", "XPS 13", 1500);
                    computer.displayInfo();
                    break;
                case 5:
                    // Tạo hình tròn và tính diện tích, chu vi
                    Circle circle = new Circle(5);
                    System.out.println("Diện tích hình tròn: " + circle.calculateArea());
                    System.out.println("Chu vi hình tròn: " + circle.calculatePerimeter());
                    break;
                case 6:
                    // Tạo đối tượng động vật
                    Animal animal = new Animal("Dog", "Woof");
                    animal.makeSound();
                    break;
                case 7:
                    // Tạo đối tượng xe hơi
                    Car car = new Car("Toyota", "Camry", 2015, 20000);
                    System.out.println("Giá trị xe sau khấu hao: " + car.calculateDepreciation(2023));
                    break;
                case 8:
                    // Tạo đối tượng nhân viên
                    Employee employee = new Employee("Jane Doe", "E001", "Manager", 5000);
                    System.out.println("Lương hàng năm: " + employee.calculateAnnualSalary());
                    break;
                case 9:
                    System.out.println("Thoát chương trình.");
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ, vui lòng thử lại.");
                    break;
            }
        } while (choice != 9);
        scanner.close();
    }
}
