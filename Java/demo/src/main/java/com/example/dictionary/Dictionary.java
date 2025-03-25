package com.example.dictionary;
public class Dictionary {
    private Word[] words;
    private int wordCount;

    public Dictionary(int capacity) {
        words = new Word[capacity];
        wordCount = 0;
    }

    public void addWord(Word word) {
        if (wordCount < words.length) {
            words[wordCount++] = word;
        }
    }

    public Word[] getAllWords() {
        return words;
    }

    // Phương thức tìm từ theo wordTarget
    public Word findWord(String wordTarget) {
        for (Word word : words) {
            if (word != null && word.getWordTarget().equalsIgnoreCase(wordTarget)) {
                return word;
            }
        }
        return null;
    }
    public void deleteWord(Word word) {
        for (int i = 0; i < wordCount; i++) {
            if (words[i].equals(word)) {
                // Di chuyển các phần tử còn lại lên
                for (int j = i; j < wordCount - 1; j++) {
                    words[j] = words[j + 1];
                }
                words[--wordCount] = null;  // Giảm số lượng từ và xóa phần tử cuối
                break;
            }
        }
    }
}
