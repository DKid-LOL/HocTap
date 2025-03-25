package cau1;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BookTest {
    private static final String FILE_NAME = "books.dat";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Book> books = new ArrayList<>();

        // Nhập 5 quyển sách từ bàn phím
        for (int i = 0; i < 5; i++) {
            System.out.println("Nhập thông tin cho quyển sách thứ " + (i + 1) + ":");
            String ISBN;
            while (true) {
                System.out.print("Nhập ISBN (định dạng 3 chữ số - 2 ký tự chữ - 4 chữ số): ");
                ISBN = scanner.nextLine();
                if (ISBN.matches("\\d{3}-[A-Za-z]{2}-\\d{4}")) {
                    break;
                }
                System.out.println("ISBN không hợp lệ. Vui lòng nhập lại!");
            }
            System.out.print("Nhập tiêu đề: ");
            String title = scanner.nextLine();
            System.out.print("Nhập tác giả: ");
            String author = scanner.nextLine();
            System.out.print("Nhập giá: ");
            double price = Double.parseDouble(scanner.nextLine());

            books.add(new Book(ISBN, title, author, price));
        }

        // Ghi danh sách sách vào tệp tin
        writeBooksToFile(books);

        // Đọc danh sách sách từ tệp tin
        List<Book> booksFromFile = readBooksFromFile();

        // Hiển thị danh sách sách
        System.out.println("\nDanh sách sách từ tệp tin:");
        for (Book book : booksFromFile) {
            System.out.println(book);
        }

        // Hiển thị sách có giá dưới 50
        System.out.println("\nCác sách có giá dưới 50:");
        for (Book book : booksFromFile) {
            if (book.getPrice() < 50) {
                System.out.println(book);
            }
        }
    }

    // Ghi danh sách sách vào tệp tin
    private static void writeBooksToFile(List<Book> books) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_NAME))) {
            oos.writeObject(books);
            System.out.println("\nGhi danh sách sách vào tệp tin thành công.");
        } catch (IOException e) {
            System.err.println("Lỗi khi ghi vào tệp tin: " + e.getMessage());
        }
    }

    // Đọc danh sách sách từ tệp tin
    private static List<Book> readBooksFromFile() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_NAME))) {
            return (List<Book>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Lỗi khi đọc tệp tin: " + e.getMessage());
        }
        return new ArrayList<>();
    }
}

