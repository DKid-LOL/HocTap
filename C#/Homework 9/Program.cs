namespace Homework_9
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            EmployeeManager manager = new EmployeeManager();

            // Thêm nhân viên mới
            manager.AddEmployee(new Employee("E001", "John Doe", "Developer", DateTime.Now, 60000));
            manager.AddEmployee(new Employee("E002", "Jane Smith", "Manager", DateTime.Now, 80000));

            // Hiển thị danh sách nhân viên
            var employees = manager.GetAllEmployees();
            foreach (var employee in employees)
            {
                Console.WriteLine($"{employee.EmployeeId} - {employee.Name} - {employee.Position} - {employee.Salary}");
            }

            // Cập nhật thông tin nhân viên
            manager.UpdateEmployee("E001", "Senior Developer", 70000);

            // Xóa nhân viên
            manager.RemoveEmployee("E002");

            // Tìm kiếm nhân viên
            var employeeById = manager.FindEmployeeById("E001");
            Console.WriteLine($"Found by ID: {employeeById.Name}");

            var employeesByName = manager.FindEmployeesByName("John");
            foreach (var employee in employeesByName)
            {
                Console.WriteLine($"Found by Name: {employee.Name}");
            }

            // Thống kê số lượng nhân viên theo vị trí công việc
            var countByPosition = manager.GetEmployeeCountByPosition();
            foreach (var kvp in countByPosition)
            {
                Console.WriteLine($"{kvp.Key}: {kvp.Value}");
            }

            // Tính toán tổng mức lương của tất cả nhân viên
            var totalSalary = manager.GetTotalSalary();
            Console.WriteLine($"Total Salary: {totalSalary}");
        }
    }

}
