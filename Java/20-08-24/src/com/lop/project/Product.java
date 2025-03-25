package com.lop.project;

class Product {
    String name;
    int price;
    float quantity;

    Product(String name, int price, float quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    double calculateTotalPrice() {
        return price * quantity;
    }
}

