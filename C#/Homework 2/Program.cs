using System;
using System.Text;

namespace CalculatorApp
{
    public class Calculator
    {
        public static double Cong(double a, double b)
        {
            return a + b;
        }

        public static double Tru(double a, double b)
        {
            return a - b;
        }

        public static double Nhan(double a, double b)
        {
            return a * b;
        }

        public static double Chia(double a, double b)
        {
            if (b == 0)
            {
                Console.WriteLine("Lỗi: Không thể chia cho 0.");
                return double.NaN;
            }
            return a / b;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;

            Console.WriteLine("===== CHƯƠNG TRÌNH MÁY TÍNH =====");

            Console.Write("Nhập số thứ nhất: ");
            double soThuNhat = NhapSo();

            Console.Write("Nhập số thứ hai: ");
            double soThuHai = NhapSo();

            Console.WriteLine("\nKết quả các phép tính:");
            Console.WriteLine($"Cộng: {soThuNhat} + {soThuHai} = {Calculator.Cong(soThuNhat, soThuHai)}");
            Console.WriteLine($"Trừ: {soThuNhat} - {soThuHai} = {Calculator.Tru(soThuNhat, soThuHai)}");
            Console.WriteLine($"Nhân: {soThuNhat} * {soThuHai} = {Calculator.Nhan(soThuNhat, soThuHai)}");

            double ketQuaChia = Calculator.Chia(soThuNhat, soThuHai);
            if (!double.IsNaN(ketQuaChia))
            {
                Console.WriteLine($"Chia: {soThuNhat} / {soThuHai} = {ketQuaChia}");
            }
        }

        static double NhapSo()
        {
            while (true)
            {
                string input = Console.ReadLine();
                if (double.TryParse(input, out double so))
                {
                    return so;
                }
                else
                {
                    Console.WriteLine("Lỗi: Dữ liệu nhập vào phải là số. Hãy thử lại.");
                }
            }
        }
    }
}
