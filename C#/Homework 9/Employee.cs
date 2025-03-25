using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_9
{
    public class Employee : EmployeeBase
    {
        public Employee(string employeeId, string name, string position, DateTime startDate, decimal salary)
            : base(employeeId, name, position, startDate, salary)
        {
        }
    }

}
