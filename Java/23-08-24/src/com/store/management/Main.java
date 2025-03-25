package com.store.management;

import java.util.*;
import java.util.stream.Collectors;

public class Main {
    private static final List<Product> productList = new ArrayList<>();
    private static final List<Order> orderHistory = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean isRunning = true;
        Main main = new Main();

        while (isRunning) {
            System.out.println("\nChương Trình Quản Lý Sản Phẩm");
            System.out.println("1. Nhập liệu");
            System.out.println("2. Báo cáo hết hàng");
            System.out.println("3. Sắp xếp theo giá");
            System.out.println("4. Bán hàng");
            System.out.println("5. Báo cáo lịch sử bán hàng");
            System.out.println("6. Thoát");
            System.out.print("Vui lòng chọn chức năng: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    inputProductData(scanner);
                    break;
                case 2:
                    reportLowStock();
                    break;
                case 3:
                    sortByPriceDescending();
                    break;
                case 4:
                    sellProduct(scanner);
                    break;
                case 5:
                    main.displayOrderHistory();
                    break;
                case 6:
                    isRunning = false;
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ. Vui lòng thử lại.");
                    break;
            }
        }
        scanner.close();
    }

    // Chức năng 1: Nhập liệu sản phẩm
    public static void inputProductData(Scanner scanner) {
        System.out.print("Nhập tổng số sản phẩm cần nhập: ");
        int numProducts = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < numProducts; i++) {
            System.out.print("Nhập ID sản phẩm: ");
            Integer id = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            System.out.print("Nhập tên sản phẩm: ");
            String name = scanner.nextLine();

            float price;
            do {
                System.out.print("Nhập giá sản phẩm (0 <= price <= 10000000): ");
                price = scanner.nextFloat();
                if (price < 0 || price > 10000000) {
                    System.out.println("Giá không hợp lệ, vui lòng nhập lại.");
                }
            } while (price < 0 || price > 10000000);

            int quantity;
            do {
                System.out.print("Nhập số lượng sản phẩm (>= 0): ");
                quantity = scanner.nextInt();
                if (quantity < 0) {
                    System.out.println("Số lượng không hợp lệ, vui lòng nhập lại.");
                }
            } while (quantity < 0);

            Product product = new Product(id, name, price, quantity);
            productList.add(product);
        }
    }

    // Chức năng 2: Báo cáo hết hàng (sản phẩm có số lượng thấp nhất)
    public static void reportLowStock() {
        List<Product> sortedProducts = productList.stream()
                .sorted(Comparator.comparingInt(Product::getQuantity))
                .limit(3)
                .collect(Collectors.toList());

        System.out.println("Top 3 sản phẩm có số lượng thấp nhất:");
        sortedProducts.forEach(Product::displayInfo);
    }

    // Chức năng 3: Sắp xếp sản phẩm theo giá giảm dần
    public static void sortByPriceDescending() {
        List<Product> sortedProducts = productList.stream()
                .sorted(Comparator.comparing(Product::getPrice).reversed())
                .collect(Collectors.toList());

        System.out.println("Danh sách sản phẩm sắp xếp theo giá giảm dần:");
        sortedProducts.forEach(Product::displayInfo);
    }

    // Chức năng 4: Bán hàng
    public static void sellProduct(Scanner scanner) {
        System.out.println("Danh sách sản phẩm:");
        productList.forEach(Product::displayInfo);

        System.out.print("Nhập ID sản phẩm cần bán: ");
        Integer productId = scanner.nextInt();
        Optional<Product> productOpt = productList.stream()
                .filter(p -> p.getId().equals(productId))
                .findFirst();

        if (!productOpt.isPresent()) {
            System.out.println("Sản phẩm không tồn tại.");
            return;
        }

        Product product = productOpt.get();
        int sellQuantity;
        do {
            System.out.print("Nhập số lượng cần bán: ");
            sellQuantity = scanner.nextInt();
            if (sellQuantity <= 0 || sellQuantity > product.getQuantity()) {
                System.out.println("Số lượng không hợp lệ, vui lòng nhập lại.");
            }
        } while (sellQuantity <= 0 || sellQuantity > product.getQuantity());

        // Cập nhật số lượng sản phẩm
        product.setQuantity(product.getQuantity() - sellQuantity);
        Order order = new Order(product.getId(), sellQuantity);
        orderHistory.add(order);

        System.out.println("Bán hàng thành công. Đã trừ số lượng sản phẩm.");
    }

    // Chức năng 5: Hiển thị lịch sử bán hàng
    public void displayOrderHistory() {
        if (orderHistory.isEmpty()) {
            System.out.println("Không có lịch sử bán hàng.");
        } else {
            System.out.println("Lịch sử bán hàng:");
            orderHistory.forEach(order -> order.displayInfo());

        }
    }
}
