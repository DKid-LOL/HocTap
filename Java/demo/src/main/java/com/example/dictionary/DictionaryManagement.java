package com.example.dictionary;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class DictionaryManagement {

    public void insertFromCommandline(Dictionary dictionary) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of words to add:");
        int n = scanner.nextInt();
        scanner.nextLine(); // consume the leftover newline

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the English word:");
            String wordTarget = scanner.nextLine();
            System.out.println("Enter the Vietnamese explanation:");
            String wordExplain = scanner.nextLine();
            Word word = new Word(wordTarget, wordExplain);
            dictionary.addWord(word);
        }
    }

    public void showAllWords(Dictionary dictionary) {
        System.out.println("No | English | Vietnamese");
        Word[] words = dictionary.getAllWords();
        for (int i = 0; i < words.length; i++) {
            if (words[i] != null) {
                System.out.printf("%d | %s | %s\n", i + 1, words[i].getWordTarget(), words[i].getWordExplain());
            }
        }
    }

    public void insertFromFile(Dictionary dictionary) {
        try (BufferedReader reader = new BufferedReader(new FileReader("dictionaries.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // Kiểm tra xem line có chứa tab không và chia tách chính xác
                String[] parts = line.split("\t");
                if (parts.length == 2) {
                    String wordTarget = parts[0].trim();  // Loại bỏ khoảng trắng thừa
                    String wordExplain = parts[1].trim(); // Loại bỏ khoảng trắng thừa
                    Word word = new Word(wordTarget, wordExplain);
                    dictionary.addWord(word);
                } else {
                    System.out.println("Error: Invalid format in line: " + line);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading from file: " + e.getMessage());
        }
    }


    public void dictionaryLookup(Dictionary dictionary, String wordTarget) {
        Word[] words = dictionary.getAllWords();
        for (Word word : words) {
            if (word != null && word.getWordTarget().equals(wordTarget)) {
                System.out.println("Found: " + word.getWordTarget() + " - " + word.getWordExplain());
                return;
            }
        }
        System.out.println("Word not found.");
    }

    public void dictionaryAdvanced(Dictionary dictionary) {
        insertFromFile(dictionary); // Nhập từ điển từ file
        showAllWords(dictionary);    // Hiển thị tất cả các từ
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a word to look up:");
        String wordTarget = scanner.nextLine();
        dictionaryLookup(dictionary, wordTarget);  // Tra cứu từ
    }
    public void insertWord(Dictionary dictionary, String wordTarget, String wordExplain) {
        Word word = new Word(wordTarget, wordExplain);
        dictionary.addWord(word);
    }
    public void updateWord(Dictionary dictionary, String oldWordTarget, String newWordTarget, String newWordExplain) {
        Word[] words = dictionary.getAllWords();
        for (int i = 0; i < words.length; i++) {
            if (words[i] != null && words[i].getWordTarget().equalsIgnoreCase(oldWordTarget)) {
                words[i].setWordTarget(newWordTarget);
                words[i].setWordExplain(newWordExplain);
                System.out.println("Updated word: " + newWordTarget);
                return;
            }
        }
        System.out.println("Word not found for update.");
    }
    public void deleteWord(Dictionary dictionary, String wordTarget) {
        Word[] words = dictionary.getAllWords();
        for (int i = 0; i < words.length; i++) {
            if (words[i] != null && words[i].getWordTarget().equalsIgnoreCase(wordTarget)) {
                words[i] = null;  // Xóa từ
                System.out.println("Deleted word: " + wordTarget);
                return;
            }
        }
        System.out.println("Word not found for deletion.");
    }
    public void dictionarySearcher(Dictionary dictionary, String searchKeyword) {
        Word[] words = dictionary.getAllWords();
        ArrayList<String> results = new ArrayList<>();
        for (Word word : words) {
            if (word != null && word.getWordTarget().toLowerCase().startsWith(searchKeyword.toLowerCase())) {
                results.add(word.getWordTarget());
            }
        }
        if (results.isEmpty()) {
            System.out.println("No words found starting with: " + searchKeyword);
        } else {
            System.out.println("Words starting with '" + searchKeyword + "':");
            for (String result : results) {
                System.out.println(result);
            }
        }
    }
    // Xuất từ điển vào tệp dictionaries.txt (ghi đè)
    public void dictionaryExportToFile(Dictionary dictionary) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("dictionaries.txt"));
            Word[] words = dictionary.getAllWords();
            for (Word word : words) {
                if (word != null) {
                    writer.write(word.getWordTarget() + "\t" + word.getWordExplain() + "\n");
                }
            }
            writer.close();
            System.out.println("Dictionary exported to 'dictionaries.txt'.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
