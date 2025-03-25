package com.lop.project;

class Car {
    String brand;
    String model;
    int year;
    double price;

    Car(String brand, String model, int year, double price) {
        this.brand = brand;
        this.model = model;
        this.year = year;
        this.price = price;
    }

    double calculateDepreciation(int currentYear) {
        int yearsOld = currentYear - year;
        return price * Math.pow(0.95, yearsOld);
    }
}

