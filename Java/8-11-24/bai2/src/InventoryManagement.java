import java.util.Arrays;
import java.util.List;

public class InventoryManagement {

    public static void main(String[] args) {
        List<String> productNames = Arrays.asList("Điện thoại", "Tivi", "Laptop", "Máy tính bảng", "Tai nghe");

        ProductStockManager stockManager = new ProductStockManager(productNames);

        // Tạo hai luồng: Một cho nhập hàng, một cho xuất hàng
        ProductImportThread importThread = new ProductImportThread(stockManager, productNames);
        ProductExportThread exportThread = new ProductExportThread(stockManager, productNames);

        // Bắt đầu hai luồng
        importThread.start();
        exportThread.start();

        // Chờ các luồng thực thi
        try {
            importThread.join();
            exportThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}