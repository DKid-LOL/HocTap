import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DictionaryApplication extends Application {
    private Dictionary dictionary = new Dictionary(100);  // Khởi tạo dictionary với kích thước

    @Override
    public void start(Stage primaryStage) {
        loadDictionaryFromFile("dictionaries.txt");  // Nạp dữ liệu từ tệp

        // Tạo danh sách từ vựng
        ListView<String> wordListView = new ListView<>();
        for (Word word : dictionary.getAllWords()) {
            if (word != null) {
                wordListView.getItems().add(word.getWordTarget());
            }
        }

        // Tạo khu vực hiển thị giải thích từ
        TextArea explanationArea = new TextArea();
        explanationArea.setEditable(false); // Không cho phép chỉnh sửa

        // Xử lý sự kiện khi chọn từ
        wordListView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                Word selectedWord = dictionary.findWord(newValue);
                if (selectedWord != null) {
                    explanationArea.setText(selectedWord.getWordExplain());
                }
            }
        });

        // Tạo bố cục chính
        BorderPane root = new BorderPane();
        root.setLeft(wordListView);       // Danh sách từ ở bên trái
        root.setCenter(explanationArea);  // Phần giải thích từ ở giữa

        // Tạo và hiển thị cửa sổ
        Scene scene = new Scene(root, 600, 400);
        primaryStage.setTitle("Dictionary Application");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    // Phương thức nạp dữ liệu từ tệp dictionaries.txt
    private void loadDictionaryFromFile(String filePath) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("\t");
                if (parts.length == 2) {
                    String wordTarget = parts[0].trim();
                    String wordExplain = parts[1].trim();
                    dictionary.addWord(new Word(wordTarget, wordExplain));
                }
            }
        } catch (IOException e) {
            System.out.println("Error loading dictionary: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        launch(args);  // Khởi động ứng dụng JavaFX
    }
}
