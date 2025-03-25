package cau2;

public class ThreadProcessor extends Thread {
    private Data data;
    private ThreadPrinter printer;

    public ThreadProcessor(Data data, ThreadPrinter printer) {
        this.data = data;
        this.printer = printer;
    }

    @Override
    public void run() {
        int index = 0;
        String original;
        while ((original = data.getString(index)) != null) {
            String reversed = new StringBuilder(original).reverse().toString();
            data.setReversedString(reversed);
            index++;
        }
        // Gửi tín hiệu kết thúc
        data.setReversedString(null);
    }
}

