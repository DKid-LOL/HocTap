using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_9
{
    public abstract class EmployeeBase : IEmployee
    {
        public string EmployeeId { get; private set; }
        public string Name { get; set; }
        public string Position { get; set; }
        public DateTime StartDate { get; set; }
        public decimal Salary { get; set; }

        protected EmployeeBase(string employeeId, string name, string position, DateTime startDate, decimal salary)
        {
            EmployeeId = employeeId;
            Name = name;
            Position = position;
            StartDate = startDate;
            Salary = salary;
        }
    }

}
