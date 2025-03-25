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
}
