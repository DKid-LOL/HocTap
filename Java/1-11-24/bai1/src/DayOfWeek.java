import java.util.Random;

class SharedData {
    private String dayInVietnamese;
    private boolean isAvailable = false;

    // Đồng bộ hóa phương thức để set ngày tiếng Việt
    public synchronized void setDayInVietnamese(String day) {
        while (isAvailable) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        this.dayInVietnamese = day;
        isAvailable = true;
        notify();
    }

    // Đồng bộ hóa phương thức để get ngày tiếng Việt và chuyển đổi sang tiếng Anh
    public synchronized String getDayInVietnamese() {
        while (!isAvailable) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        isAvailable = false;
        notify();
        return dayInVietnamese;
    }
}

class VietnameseDayThread extends Thread {
    private final SharedData sharedData;
    private final String[] daysInVietnamese = {
            "Chu nhat", "Thu hai", "Thu ba", "Thu tu", "Thu nam", "Thu sau", "Thu bay"
    };

    public VietnameseDayThread(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                Thread.sleep(1000);  // Tạm dừng 1 giây
                int dayIndex = random.nextInt(daysInVietnamese.length);
                String day = daysInVietnamese[dayIndex];
                System.out.println("Tiếng Việt: " + day);
                sharedData.setDayInVietnamese(day);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}

class EnglishDayThread extends Thread {
    private final SharedData sharedData;
    private final String[] daysInEnglish = {
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    public EnglishDayThread(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    @Override
    public void run() {
        while (true) {
            String dayInVietnamese = sharedData.getDayInVietnamese();
            String dayInEnglish = getEnglishDay(dayInVietnamese);
            System.out.println("Tiếng Anh: " + dayInEnglish);
        }
    }

    private String getEnglishDay(String dayInVietnamese) {
        return switch (dayInVietnamese) {
            case "Chu nhat" -> "Sunday";
            case "Thu hai" -> "Monday";
            case "Thu ba" -> "Tuesday";
            case "Thu tu" -> "Wednesday";
            case "Thu nam" -> "Thursday";
            case "Thu sau" -> "Friday";
            case "Thu bay" -> "Saturday";
            default -> "Unknown Day";
        };
    }
}

public class DayOfWeek {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();
        VietnameseDayThread vietnameseDayThread = new VietnameseDayThread(sharedData);
        EnglishDayThread englishDayThread = new EnglishDayThread(sharedData);

        vietnameseDayThread.start();
        englishDayThread.start();
    }
}
