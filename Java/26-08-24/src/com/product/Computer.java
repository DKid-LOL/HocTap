package product.computers;

import com.product.Product;
import java.util.Scanner;

public class Computer extends Product {
    private String speed;
    private String producer;

    // Constructor không có đối số
    public Computer() {
        super();
    }

    // Constructor đầy đủ tham số
    public Computer(String proId, String proName, int year, float price, String speed, String producer) {
        super(proId, proName, year, price);
        this.speed = speed;
        this.producer = producer;
    }

    // Getters và Setters
    public String getSpeed() {
        return speed;
    }

    public void setSpeed(String speed) {
        this.speed = speed;
    }

    public String getProducer() {
        return producer;
    }

    public void setProducer(String producer) {
        this.producer = producer;
    }

    // Triển khai phương thức input() và display()
    @Override
    public void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập ID sản phẩm: ");
        this.proId = scanner.nextLine();
        System.out.print("Nhập tên sản phẩm: ");
        this.proName = scanner.nextLine();
        System.out.print("Nhập năm sản xuất: ");
        this.year = scanner.nextInt();
        System.out.print("Nhập giá: ");
        this.price = scanner.nextFloat();
        scanner.nextLine(); // Consume newline
        System.out.print("Nhập tốc độ: ");
        this.speed = scanner.nextLine();
        System.out.print("Nhập nhà sản xuất: ");
        this.producer = scanner.nextLine();
    }

    @Override
    public void display() {
        System.out.println("ID: " + proId + ", Name: " + proName + ", Year: " + year + ", Price: " + price + ", Speed: " + speed + ", Producer: " + producer);
    }
}
