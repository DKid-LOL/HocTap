import org.w3c.dom.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;

public class PhoneStoreApp extends JFrame {
    private static final String XML_FILE = "phone.xml";
    private JTable table;
    private DefaultTableModel model;

    public PhoneStoreApp() {
        setTitle("Quản lý điện thoại - Thế Giới Di Động");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        String[] columnNames = {"Chi nhánh", "Hãng", "Model", "Giá", "Số lượng"};
        model = new DefaultTableModel(columnNames, 0);
        table = new JTable(model);

        add(new JScrollPane(table));
        loadFromXML();
    }

    private void loadFromXML() {
        try {
            File file = new File(XML_FILE);
            if (!file.exists()) {
                JOptionPane.showMessageDialog(this, "Không tìm thấy dữ liệu XML!");
                return;
            }
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(file);
            doc.getDocumentElement().normalize();

            model.setRowCount(0);
            NodeList stores = doc.getElementsByTagName("Store");

            for (int i = 0; i < stores.getLength(); i++) {
                Element store = (Element) stores.item(i);
                String branch = store.getElementsByTagName("Branch").item(0).getTextContent();
                NodeList phones = store.getElementsByTagName("Phone");

                for (int j = 0; j < phones.getLength(); j++) {
                    Element phone = (Element) phones.item(j);
                    model.addRow(new Object[]{
                        branch,
                        phone.getElementsByTagName("Brand").item(0).getTextContent(),
                        phone.getElementsByTagName("Model").item(0).getTextContent(),
                        phone.getElementsByTagName("Price").item(0).getTextContent(),
                        phone.getElementsByTagName("Stock").item(0).getTextContent()
                    });
                }
            }
            JOptionPane.showMessageDialog(this, "Dữ liệu đã được tải lên!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new PhoneStoreApp().setVisible(true));
    }
}
