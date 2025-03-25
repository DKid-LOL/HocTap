using System;
using System.Collections.Generic;
using System.Text;

namespace Homework_12
{
    abstract class HotelStaff
    {
        private int id;
        private string name;
        private double baseSalary;
        public int ID { get => id; set => id = value; }
        public string Name { get => name; set => name = value; }
        public double BaseSalary { get => baseSalary; set => baseSalary = value; }
        public HotelStaff() { }
        public HotelStaff(int id, string name, double baseSalary)
        {
            this.id = id;
            this.name = name;
            this.baseSalary = baseSalary;
        }
        public abstract double CalculateSalary();
    }
    class Receptionist : HotelStaff
    {
        private double bonus;
        public double Bonus { get => bonus; set => bonus = value; }
        public Receptionist() : base() { }
        public Receptionist(int id, string name, double baseSalary, double bonus) : base(id, name, baseSalary)
        {
            this.bonus = bonus;
        }
        public override double CalculateSalary()
        {
            return BaseSalary + Bonus;
        }
    }
    class Housekeeper : HotelStaff
    {
        private int roomsCleaned;
        public int RoomsCleaned { get => roomsCleaned; set => roomsCleaned = value; }
        public Housekeeper() : base() { }
        public Housekeeper(int id, string name, double baseSalary, int roomsCleaned) : base(id, name, baseSalary)
        {
            this.roomsCleaned = roomsCleaned;
        }
        public override double CalculateSalary()
        {
            return BaseSalary + (RoomsCleaned * 50);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            List<HotelStaff> staffList = new List<HotelStaff>();
            bool exit = false;
            while (!exit)
            {
                Console.WriteLine("===== MENU =====");
                Console.WriteLine("1. Thêm nhân viên Lễ tân");
                Console.WriteLine("2. Thêm nhân viên Dọn phòng");
                Console.WriteLine("3. Hiển thị danh sách nhân viên và lương");
                Console.WriteLine("0. Thoát");
                Console.Write("Chọn một tùy chọn: ");
                string option = Console.ReadLine();
                switch (option)
                {
                    case "1":
                        AddReceptionist(staffList);
                        break;
                    case "2":
                        AddHousekeeper(staffList);
                        break;
                    case "3":
                        DisplayStaffList(staffList);
                        break;
                    case "0":
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("Tùy chọn không hợp lệ");
                        break;
                }
                Console.WriteLine();
            }
        }
        static void AddReceptionist(List<HotelStaff> staffList)
        {
            Console.Write("Nhập ID: ");
            int id = ReadInt();
            Console.Write("Nhập tên: ");
            string name = Console.ReadLine();
            Console.Write("Nhập lương cơ bản: ");
            double baseSalary = ReadDouble();
            Console.Write("Nhập thưởng: ");
            double bonus = ReadDouble();
            Receptionist r = new Receptionist(id, name, baseSalary, bonus);
            staffList.Add(r);
            Console.WriteLine("Đã thêm nhân viên Lễ tân thành công");
        }
        static void AddHousekeeper(List<HotelStaff> staffList)
        {
            Console.Write("Nhập ID: ");
            int id = ReadInt();
            Console.Write("Nhập tên: ");
            string name = Console.ReadLine();
            Console.Write("Nhập lương cơ bản: ");
            double baseSalary = ReadDouble();
            Console.Write("Nhập số phòng dọn: ");
            int roomsCleaned = ReadInt();
            Housekeeper h = new Housekeeper(id, name, baseSalary, roomsCleaned);
            staffList.Add(h);
            Console.WriteLine("Đã thêm nhân viên Dọn phòng thành công");
        }
        static void DisplayStaffList(List<HotelStaff> staffList)
        {
            if (staffList.Count == 0)
            {
                Console.WriteLine("Danh sách trống");
                return;
            }
            Console.WriteLine("Danh sách nhân viên và lương:");
            foreach (var staff in staffList)
            {
                Console.WriteLine("ID: " + staff.ID + " - Tên: " + staff.Name + " - Lương: " + staff.CalculateSalary());
            }
        }
        static int ReadInt()
        {
            int value;
            while (!int.TryParse(Console.ReadLine(), out value))
            {
                Console.Write("Giá trị nhập không hợp lệ, vui lòng nhập lại: ");
            }
            return value;
        }
        static double ReadDouble()
        {
            double value;
            while (!double.TryParse(Console.ReadLine(), out value))
            {
                Console.Write("Giá trị nhập không hợp lệ, vui lòng nhập lại: ");
            }
            return value;
        }
    }
}
