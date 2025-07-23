#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 定义学生结构体
struct Student
{
    int id;
    std::string name;
    float grade;
};

// 打印学生信息
void printStudent(const Student& student)
{
    std::cout << "ID: " << student.id << ",Name: " << student.name << ",Grade: "
        << student.grade << std::endl;
}

// 添加学生信息
void addStudent(std::vector<Student>& students)
{
    Student t;
    std::cout << "Enter student ID: ";
    std::cin >> t.id;
    std::cout << "Enter student name: ";
    std::cin.ignore();
    std::getline(std::cin, t.name);
    std::cout << "Enter student grade: ";
    std::cin >> t.grade;
    students.push_back(t);
    std::cout << "Student added successfully!" << std::endl;
}

// 删除学生信息
void deleteStudent(std::vector<Student>& students)
{
    int id;
    std::cout << "Enter student ID to delete: ";
    std::cin >> id;
    auto it = std::find_if(students.begin(),
                           students.end(), [id](const Student& s)
                           {
                               return s.id == id;
                           });
    if (it != students.end())
    {
        students.erase(it);
        std::cout << "Student deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Student not found!" << std::endl;
    }
}

// 查找学生信息
void findStudent(std::vector<Student>& students)
{
    int id;
    std::cout << "Enter Student ID to find: ";
    std::cin >> id;
    auto it = std::find_if(students.begin(),
                           students.end(), [id](const Student& s)
                           {
                               return s.id == id;
                           });
    if (it != students.end())
    {
        std::cout << "Student Found:\n";
        printStudent(*it);
    }
    else
    {
        std::cout << "Student with ID " << id << " not found.\n";
    }
}

// 显示所有学生信息
void showStudents(std::vector<Student>& students)
{
    if (students.empty())
    {
        std::cout << "No student available!" << std::endl;
        return;
    }
    std::cout << "Student list:\n";
    for (auto student : students)
    {
        printStudent(student);
    }
}

int main()
{
    std::vector<Student> students;
    int choice;

    do
    {
        std::cout << "\n=== Student Management System ===\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Delete Student\n";
        std::cout << "3. Display All Students\n";
        std::cout << "4. Find Student by ID\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;
            case 2:
                deleteStudent(students);
                break;
            case 3:
                showStudents(students);
                break;
            case 4:
                findStudent(students);
                break;
            case 5:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please choose between 1-5.\n";
        }
    } while (choice != 5);
    return 0;
}