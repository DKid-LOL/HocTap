using System;
using System.Text;

namespace MenuSelection
{
    public class Input
    {
        public static int MenuChoice(string? input, int min, int max)
        {
            if (int.TryParse(input, out int choice))
            {
                if (choice >= min && choice <= max)
                {
                    return choice;
                }
                else
                {
                    Console.WriteLine($"Lựa chọn phải nằm trong khoảng {min}-{max}. Hãy thử lại.");
                }
            }
            else
            {
                Console.WriteLine("Dữ liệu nhập vào phải là số. Hãy thử lại.");
            }
            return -1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            int choice;
            do
            {
                Console.WriteLine("\n===== MENU LỰA CHỌN THỰC ĐƠN =====");
                Console.WriteLine("1. Lựa chọn Đồ ăn Nhanh          =");
                Console.WriteLine("2. Lựa chọn Lẩu                  =");
                Console.WriteLine("3. Lựa chọn Đồ uống              =");
                Console.WriteLine("4. Thoát                         =");
                Console.WriteLine("Nhập lựa chọn của bạn (1-4):     =");
                Console.WriteLine("==================================");

                string? input = Console.ReadLine();
                choice = Input.MenuChoice(input, 1, 4);

                switch (choice)
                {
                    case 1:
                        Console.WriteLine("Bạn đã chọn Đồ ăn Nhanh.");
                        break;
                    case 2:
                        Console.WriteLine("Bạn đã chọn Lẩu.");
                        break;
                    case 3:
                        Console.WriteLine("Bạn đã chọn Đồ uống.");
                        break;
                    case 4:
                        Console.WriteLine("Cảm ơn bạn đã sử dụng chương trình. Tạm biệt!");
                        break;
                    case -1:
                        break;
                }

            } while (choice != 4);
        }
    }
}
