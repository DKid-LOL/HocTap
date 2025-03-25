package product.test;

import product.computers.Computer;
import product.books.Book;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Computer[] computers = null;
        Book[] books = null;
        boolean isRunning = true;

        while (isRunning) {
            System.out.println("\nPlease select:");
            System.out.println("1. Input information for n Computers.");
            System.out.println("2. Input information for n Books.");
            System.out.println("3. Display information of n Computers by sorting the price descending.");
            System.out.println("4. Display information of n Books by sorting the publisher ascending.");
            System.out.println("5. Exit.");
            System.out.print("Your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Nhập số lượng máy tính: ");
                    int nComputers = scanner.nextInt();
                    computers = new Computer[nComputers];
                    for (int i = 0; i < nComputers; i++) {
                        computers[i] = new Computer();
                        System.out.println("Nhập thông tin máy tính thứ " + (i + 1) + ":");
                        computers[i].input();
                    }
                    break;
                case 2:
                    System.out.print("Nhập số lượng sách: ");
                    int nBooks = scanner.nextInt();
                    books = new Book[nBooks];
                    for (int i = 0; i < nBooks; i++) {
                        books[i] = new Book();
                        System.out.println("Nhập thông tin sách thứ " + (i + 1) + ":");
                        books[i].input();
                    }
                    break;
                case 3:
                    if (computers != null) {
                        Arrays.sort(computers, Comparator.comparing(Computer::getPrice).reversed());
                        System.out.println("Thông tin các máy tính sắp xếp theo giá giảm dần:");
                        for (Computer computer : computers) {
                            computer.display();
                        }
                    } else {
                        System.out.println("Không có máy tính nào để hiển thị.");
                    }
                    break;
                case 4:
                    if (books != null) {
                        Arrays.sort(books, Comparator.comparing(Book::getPublisher));
                        System.out.println("Thông tin các sách sắp xếp theo nhà xuất bản tăng dần:");
                        for (Book book : books) {
                            book.display();
                        }
                    } else {
                        System.out.println("Không có sách nào để hiển thị.");
                    }
                    break;
                case 5:
                    isRunning = false;
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ. Vui lòng thử lại.");
                    break;
            }
        }
        scanner.close();
    }
}
