module com.example.demo {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.dictionary to javafx.fxml;
    exports com.example.dictionary;
}