package com.lop.project;

class Person {
    String name;
    int age;
    String gender;

    Person(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    void getInfo() {
        System.out.println("Name: " + name + ", Age: " + age + ", Gender: " + gender);
    }
}

