package com.lop.project;

class Computer {
    String brand;
    String model;
    double price;

    Computer(String brand, String model, double price) {
        this.brand = brand;
        this.model = model;
        this.price = price;
    }

    void displayInfo() {
        System.out.println("Brand: " + brand + ", Model: " + model + ", Price: " + price);
    }
}

