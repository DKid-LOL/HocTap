namespace Homework_9
{
    public class EmployeeManager
    {
        private List<IEmployee> employees = new List<IEmployee>();

        public void AddEmployee(IEmployee employee)
        {
            employees.Add(employee);
        }

        public void UpdateEmployee(string employeeId, string newPosition, decimal newSalary)
        {
            var employee = employees.FirstOrDefault(e => e.EmployeeId == employeeId);
            if (employee != null)
            {
                employee.Position = newPosition;
                employee.Salary = newSalary;
            }
        }

        public void RemoveEmployee(string employeeId)
        {
            var employee = employees.FirstOrDefault(e => e.EmployeeId == employeeId);
            if (employee != null)
            {
                employees.Remove(employee);
            }
        }

        public List<IEmployee> GetAllEmployees()
        {
            return employees;
        }

        public IEmployee FindEmployeeById(string employeeId)
        {
            return employees.FirstOrDefault(e => e.EmployeeId == employeeId);
        }

        public List<IEmployee> FindEmployeesByName(string name)
        {
            return employees.Where(e => e.Name.Contains(name, StringComparison.OrdinalIgnoreCase)).ToList();
        }

        public Dictionary<string, int> GetEmployeeCountByPosition()
        {
            return employees.GroupBy(e => e.Position)
                            .ToDictionary(g => g.Key, g => g.Count());
        }

        public decimal GetTotalSalary()
        {
            return employees.Sum(e => e.Salary);
        }
    }

}