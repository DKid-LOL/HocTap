import java.util.*;

class ProductStockManager {
    private final Map<String, Integer> productStock;

    public ProductStockManager(List<String> productNames) {
        this.productStock = new HashMap<>();
        for (String productName : productNames) {
            // Khởi tạo số lượng nhập và xuất cho mỗi sản phẩm là 0
            productStock.put(productName, 0); // mặc định 0 sản phẩm nhập và xuất
        }
    }

    // Đồng bộ hóa phương thức nhập hàng
    public synchronized void addProduct(String productName) {
        int currentStock = productStock.getOrDefault(productName, 0);
        productStock.put(productName, currentStock + 1);
        System.out.println("Sản phẩm nhập: " + productName + ", Tổng số lượng: " + (currentStock + 1));
        notify(); // Thông báo luồng khác
    }

    // Đồng bộ hóa phương thức xuất hàng
    public synchronized void removeProduct(String productName) {
        int currentStock = productStock.getOrDefault(productName, 0);
        if (currentStock > 0) {
            productStock.put(productName, currentStock - 1);
            System.out.println("Sản phẩm xuất: " + productName + ", Tổng số lượng còn lại: " + (currentStock - 1));
        } else {
            System.out.println("Không đủ sản phẩm để xuất: " + productName);
        }
        notify(); // Thông báo luồng khác
    }

    // Hiển thị số lượng của từng sản phẩm
    public synchronized void displayStock() {
        for (Map.Entry<String, Integer> entry : productStock.entrySet()) {
            System.out.println("Sản phẩm: " + entry.getKey() + ", Số lượng: " + entry.getValue());
        }
    }
}

class ProductImportThread extends Thread {
    private final ProductStockManager stockManager;
    private final List<String> products;

    public ProductImportThread(ProductStockManager stockManager, List<String> products) {
        this.stockManager = stockManager;
        this.products = products;
    }

    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                Thread.sleep(1000); // Tạm dừng một giây
                String product = products.get(random.nextInt(products.size()));
                stockManager.addProduct(product);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

class ProductExportThread extends Thread {
    private final ProductStockManager stockManager;
    private final List<String> products;

    public ProductExportThread(ProductStockManager stockManager, List<String> products) {
        this.stockManager = stockManager;
        this.products = products;
    }

    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                Thread.sleep(1000); // Tạm dừng một giây
                String product = products.get(random.nextInt(products.size()));
                stockManager.removeProduct(product);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}


