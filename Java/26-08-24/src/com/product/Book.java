package product.books;

import com.product.Product;
import java.util.Scanner;

public class Book extends Product {
    private String type;
    private String publisher;

    // Constructor không có đối số
    public Book() {
        super();
    }

    // Constructor đầy đủ tham số
    public Book(String proId, String proName, int year, float price, String type, String publisher) {
        super(proId, proName, year, price);
        this.type = type;
        this.publisher = publisher;
    }

    // Getters và Setters
    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    // Triển khai phương thức input() và display()
    @Override
    public void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập ID sách: ");
        this.proId = scanner.nextLine();
        System.out.print("Nhập tên sách: ");
        this.proName = scanner.nextLine();
        System.out.print("Nhập năm xuất bản: ");
        this.year = scanner.nextInt();
        System.out.print("Nhập giá: ");
        this.price = scanner.nextFloat();
        scanner.nextLine(); // Consume newline
        System.out.print("Nhập thể loại: ");
        this.type = scanner.nextLine();
        System.out.print("Nhập nhà xuất bản: ");
        this.publisher = scanner.nextLine();
    }

    @Override
    public void display() {
        System.out.println("ID: " + proId + ", Name: " + proName + ", Year: " + year + ", Price: " + price + ", Type: " + type + ", Publisher: " + publisher);
    }
}
