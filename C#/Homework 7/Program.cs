using System;
using System.Collections.Generic;
using System.Linq;

public class Student
{
    public int Id { get; set; }
    public string Name { get; set; }
}

public class StudentManager
{
    private List<Student> students = new List<Student>();
    private int nextId = 1;

    public void AddStudent(string name)
    {
        students.Add(new Student { Id = nextId++, Name = name });
        Console.WriteLine("Student added successfully.");
    }

    public void RemoveStudent(int id)
    {
        var student = students.FirstOrDefault(s => s.Id == id);
        if (student != null)
        {
            students.Remove(student);
            Console.WriteLine("Student removed successfully.");
        }
        else
        {
            Console.WriteLine("Student not found.");
        }
    }

    public void DisplayStudents()
    {
        if (students.Count == 0)
        {
            Console.WriteLine("No students in the list.");
        }
        else
        {
            foreach (var student in students)
            {
                Console.WriteLine($"ID: {student.Id}, Name: {student.Name}");
            }
        }
    }

    public void SearchStudentByName(string name)
    {
        var foundStudents = students.Where(s => s.Name.Contains(name, StringComparison.OrdinalIgnoreCase)).ToList();
        if (foundStudents.Count == 0)
        {
            Console.WriteLine("No students found with the given name.");
        }
        else
        {
            foreach (var student in foundStudents)
            {
                Console.WriteLine($"ID: {student.Id}, Name: {student.Name}");
            }
        }
    }
}

public class Program
{
    public static void Main()
    {
        StudentManager manager = new StudentManager();
        while (true)
        {
            Console.WriteLine("1. Add Student");
            Console.WriteLine("2. Remove Student");
            Console.WriteLine("3. Display Students");
            Console.WriteLine("4. Search Student by Name");
            Console.WriteLine("5. Exit");
            Console.Write("Choose an option: ");
            int choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.Write("Enter student name: ");
                    string name = Console.ReadLine();
                    manager.AddStudent(name);
                    break;
                case 2:
                    Console.Write("Enter student ID to remove: ");
                    int id = int.Parse(Console.ReadLine());
                    manager.RemoveStudent(id);
                    break;
                case 3:
                    manager.DisplayStudents();
                    break;
                case 4:
                    Console.Write("Enter student name to search: ");
                    string searchName = Console.ReadLine();
                    manager.SearchStudentByName(searchName);
                    break;
                case 5:
                    return;
                default:
                    Console.WriteLine("Invalid option. Please try again.");
                    break;
            }
        }
    }
}
