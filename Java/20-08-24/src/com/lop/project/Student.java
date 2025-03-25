package com.lop.project;

class Student {
    String name;
    int age;
    String studentId;
    float grade;

    Student() {}

    Student(String studentId, String name) {
        this.studentId = studentId;
        this.name = name;
    }

    Student(String studentId, String name, int age) {
        this.studentId = studentId;
        this.name = name;
        this.age = age;
    }

    Student(String studentId, String name, int age, float grade) {
        this.studentId = studentId;
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    float calculateGPA(float[] grades) {
        float sum = 0;
        for (float grade : grades) {
            sum += grade;
        }
        return sum / grades.length;
    }
}

