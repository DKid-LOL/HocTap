namespace Homework_9
{
    public interface IEmployee
    {
        string EmployeeId { get; }
        string Name { get; set; }
        string Position { get; set; }
        DateTime StartDate { get; set; }
        decimal Salary { get; set; }
    }

}