import java.io.*;
import java.util.*;

class Product implements Serializable {
    private String productId;
    private String productName;
    private double price;
    private int quantity;
    private String category;

    public Product(String productId, String productName, double price, int quantity, String category) {
        this.productId = productId;
        this.productName = productName;
        this.price = price;
        this.quantity = quantity;
        this.category = category;
    }

    public String getProductId() {
        return productId;
    }

    public String getProductName() {
        return productName;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public String getCategory() {
        return category;
    }

    @Override
    public String toString() {
        return "Mã sản phẩm: " + productId + ", Tên sản phẩm: " + productName + ", Giá: " + price + ", Số lượng: " + quantity + ", Danh mục: " + category;
    }
}

public class InventoryManager {

    // Kiểm tra tính hợp lệ của tên sản phẩm và giá
    public static boolean isValidProductName(String name) {
        return name.length() >= 3;
    }

    public static boolean isValidPrice(double price) {
        return price > 0;
    }

    // Lưu dữ liệu vào tệp
    public static void saveProductsToFile(List<Product> products, String filename) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))) {
            oos.writeObject(products);
            System.out.println("Dữ liệu đã được lưu vào tệp.");
        } catch (IOException e) {
            System.out.println("Lỗi khi lưu tệp: " + e.getMessage());
        }
    }

    // Đọc dữ liệu từ tệp
    public static List<Product> loadProductsFromFile(String filename) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))) {
            return (List<Product>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi khi đọc tệp: " + e.getMessage());
            return new ArrayList<>();
        }
    }

    // Tìm kiếm sản phẩm theo tên hoặc danh mục
    public static void searchProducts(List<Product> products, String searchTerm) {
        boolean found = false;
        for (Product product : products) {
            if (product.getProductName().toLowerCase().contains(searchTerm.toLowerCase()) ||
                    product.getCategory().toLowerCase().contains(searchTerm.toLowerCase())) {
                System.out.println(product);
                found = true;
            }
        }
        if (!found) {
            System.out.println("KHÔNG TÌM THẤY");
        }
    }

    public static void main(String[] args) {
        List<Product> products = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Nhập dữ liệu cho 5 sản phẩm
        for (int i = 0; i < 5; i++) {
            System.out.println("Nhập thông tin sản phẩm thứ " + (i + 1) + ":");

            System.out.print("Mã sản phẩm: ");
            String productId = scanner.nextLine();

            String productName;
            while (true) {
                System.out.print("Tên sản phẩm: ");
                productName = scanner.nextLine();
                if (isValidProductName(productName)) {
                    break;
                } else {
                    System.out.println("Tên sản phẩm phải có ít nhất 3 ký tự. Hãy nhập lại.");
                }
            }

            double price;
            while (true) {
                System.out.print("Giá bán: ");
                try {
                    price = Double.parseDouble(scanner.nextLine());
                    if (isValidPrice(price)) {
                        break;
                    } else {
                        System.out.println("Giá bán phải lớn hơn 0. Hãy nhập lại.");
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Giá bán phải là một số hợp lệ. Hãy nhập lại.");
                }
            }

            System.out.print("Số lượng: ");
            int quantity = Integer.parseInt(scanner.nextLine());

            System.out.print("Danh mục: ");
            String category = scanner.nextLine();

            products.add(new Product(productId, productName, price, quantity, category));
        }

        // Lưu danh sách sản phẩm vào tệp
        saveProductsToFile(products, "inventory_data.txt");

        // Đọc dữ liệu từ tệp và hiển thị trên console
        System.out.println("\nDữ liệu từ tệp:");
        List<Product> loadedProducts = loadProductsFromFile("inventory_data.txt");
        for (Product product : loadedProducts) {
            System.out.println(product);
        }

        // Tìm kiếm sản phẩm theo tên hoặc danh mục
        System.out.print("\nNhập tên hoặc danh mục để tìm kiếm: ");
        String searchTerm = scanner.nextLine();
        searchProducts(loadedProducts, searchTerm);
    }
}
