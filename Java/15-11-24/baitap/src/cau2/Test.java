package cau2;

public class Test {
    public static void main(String[] args) {
        Data data = new Data();
        ThreadPrinter printer = new ThreadPrinter(data);
        ThreadProcessor processor = new ThreadProcessor(data, printer);

        printer.start();
        processor.start();
    }
}

