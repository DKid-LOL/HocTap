package com.example.dictionary;

import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DictionaryController {
    @FXML
    private ListView<String> wordListView;
    @FXML
    private TextArea explanationArea;
    @FXML
    private TextField newWordField;
    @FXML
    private TextArea newExplainField;
    @FXML  
    private TextField wordToEditField;

    private Dictionary dictionary = new Dictionary(100);

    public void initialize() {
        loadDictionaryFromFile("dictionaries.txt");

        for (Word word : dictionary.getAllWords()) {
            if (word != null) {
                wordListView.getItems().add(word.getWordTarget());
            }
        }

        wordListView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                Word selectedWord = dictionary.findWord(newValue);
                if (selectedWord != null) {
                    explanationArea.setText(selectedWord.getWordExplain());
                }
            }
        });
    }

    // Phương thức thêm từ mới vào từ điển
    @FXML
    private void handleAddWord() {
        String newWord = newWordField.getText().trim();
        String newExplain = newExplainField.getText().trim();

        if (!newWord.isEmpty() && !newExplain.isEmpty()) {
            dictionary.addWord(new Word(newWord, newExplain));
            wordListView.getItems().add(newWord);
            newWordField.clear();
            newExplainField.clear();
        }
    }

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
    @FXML
    private void handleEditWord() {
        String wordToEdit = wordToEditField.getText().trim();
        Word word = dictionary.findWord(wordToEdit);
        if (word != null) {
            word.setWordExplain("Giải thích mới");  // Cập nhật giải thích cho từ
            explanationArea.setText(word.getWordExplain());
        }
    }

    @FXML
    private void handleDeleteWord() {
        String wordToDelete = wordToEditField.getText().trim();
        Word word = dictionary.findWord(wordToDelete);
        if (word != null) {
            dictionary.deleteWord(word);
            wordListView.getItems().remove(wordToDelete);
            explanationArea.clear();
        }
    }
    @FXML
    private TextField searchField;

    @FXML
    private void handleSearchWord() {
        String searchQuery = searchField.getText().trim();
        if (!searchQuery.isEmpty()) {
            Word foundWord = dictionary.findWord(searchQuery);
            if (foundWord != null) {
                explanationArea.setText(foundWord.getWordExplain());
            } else {
                explanationArea.setText("Không tìm thấy từ này.");
            }
        }
    }
    @FXML
    private void handlePronounceWord() {
        String wordToPronounce = wordListView.getSelectionModel().getSelectedItem();
        if (wordToPronounce != null) {
            try {
                // Tùy thuộc vào hệ điều hành, bạn có thể sử dụng công cụ phát âm của hệ điều hành.
                String command = "cmd.exe /c echo " + wordToPronounce + " | mshta vbscript:Execute(\"CreateObject(\"\"SAPI.SpVoice\"\").Speak(\"\"" + wordToPronounce + "\"\");close\")";
                Runtime.getRuntime().exec(command);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
