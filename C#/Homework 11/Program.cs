using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Homework_11
{
    public class Student
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public double GPA { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            List<Student> students = new List<Student>();

            bool exit = false;
            while (!exit)
            {
                ShowMenu();
                Console.Write("Chọn một tùy chọn: ");
                string option = Console.ReadLine();

                switch (option)
                {
                    case "1":
                        AddStudent(students);
                        break;
                    case "2":
                        DisplayStudentsGPAAbove3(students);
                        break;
                    case "3":
                        DisplayStudentsOver20Sorted(students);
                        break;
                    case "4":
                        DisplayTopStudent(students);
                        break;
                    case "5":
                        DisplayGroupByAge(students);
                        break;
                    case "0":
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("Tùy chọn không hợp lệ. Vui lòng chọn lại.");
                        break;
                }
                Console.WriteLine();
            }
        }

        static void ShowMenu()
        {
            Console.WriteLine("===== MENU =====");
            Console.WriteLine("1. Thêm sinh viên");
            Console.WriteLine("2. Hiển thị danh sách sinh viên có GPA > 3.0");
            Console.WriteLine("3. Hiển thị danh sách sinh viên trên 20 tuổi (sắp xếp theo GPA giảm dần)");
            Console.WriteLine("4. Hiển thị sinh viên có GPA cao nhất");
            Console.WriteLine("5. Nhóm sinh viên theo độ tuổi và đếm số lượng");
            Console.WriteLine("0. Thoát");
        }
        static void AddStudent(List<Student> students)
        {
            Console.WriteLine("Nhập thông tin sinh viên:");

            int id = ReadInt("Nhập ID: ");
            Console.Write("Nhập tên: ");
            string name = Console.ReadLine();
            int age = ReadInt("Nhập tuổi: ");
            double gpa = ReadDouble("Nhập GPA: ");

            students.Add(new Student { ID = id, Name = name, Age = age, GPA = gpa });
            Console.WriteLine("Đã thêm sinh viên thành công!");
        }

        static int ReadInt(string prompt)
        {
            int value;
            while (true)
            {
                Console.Write(prompt);
                if (int.TryParse(Console.ReadLine(), out value))
                    return value;
                Console.WriteLine("Giá trị nhập không hợp lệ, vui lòng nhập lại số nguyên.");
            }
        }

        static double ReadDouble(string prompt)
        {
            double value;
            while (true)
            {
                Console.Write(prompt);
                if (double.TryParse(Console.ReadLine(), out value))
                    return value;
                Console.WriteLine("Giá trị nhập không hợp lệ, vui lòng nhập lại số thực.");
            }
        }

        static void DisplayStudentsGPAAbove3(List<Student> students)
        {
            var result = students.Where(s => s.GPA > 3.0).ToList();
            if (result.Count == 0)
            {
                Console.WriteLine("Không có sinh viên nào có GPA > 3.0.");
                return;
            }

            Console.WriteLine("Danh sách sinh viên có GPA > 3.0:");
            foreach (var s in result)
            {
                Console.WriteLine($"ID: {s.ID}, Tên: {s.Name}, Tuổi: {s.Age}, GPA: {s.GPA}");
            }
        }

        static void DisplayStudentsOver20Sorted(List<Student> students)
        {
            var result = students.Where(s => s.Age > 20)
                                 .OrderByDescending(s => s.GPA)
                                 .ToList();
            if (result.Count == 0)
            {
                Console.WriteLine("Không có sinh viên nào trên 20 tuổi.");
                return;
            }

            Console.WriteLine("Danh sách sinh viên trên 20 tuổi (sắp xếp theo GPA giảm dần):");
            foreach (var s in result)
            {
                Console.WriteLine($"ID: {s.ID}, Tên: {s.Name}, Tuổi: {s.Age}, GPA: {s.GPA}");
            }
        }

        static void DisplayTopStudent(List<Student> students)
        {
            if (students.Count == 0)
            {
                Console.WriteLine("Danh sách sinh viên trống.");
                return;
            }

            var topStudent = students.OrderByDescending(s => s.GPA).FirstOrDefault();
            Console.WriteLine("Sinh viên có GPA cao nhất:");
            Console.WriteLine($"ID: {topStudent.ID}, Tên: {topStudent.Name}, Tuổi: {topStudent.Age}, GPA: {topStudent.GPA}");
        }
        static void DisplayGroupByAge(List<Student> students)
        {
            if (students.Count == 0)
            {
                Console.WriteLine("Danh sách sinh viên trống.");
                return;
            }

            var groups = students.GroupBy(s => s.Age)
                                 .Select(g => new { Age = g.Key, Count = g.Count() })
                                 .ToList();
            Console.WriteLine("Nhóm sinh viên theo độ tuổi:");
            foreach (var group in groups)
            {
                Console.WriteLine($"Tuổi: {group.Age} - Số lượng: {group.Count}");
            }
        }
    }
}
