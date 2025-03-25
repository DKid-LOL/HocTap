package com.store.management;

import java.time.LocalDateTime;

public class Order {
    private Integer id;
    private Integer quantity;
    private LocalDateTime date;

    // Constructor
    public Order(Integer id, Integer quantity) {
        this.id = id;
        this.quantity = quantity;
        this.date = LocalDateTime.now();
    }

    // Getter và Setter
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    // Hiển thị thông tin đơn hàng
    public void displayInfo() {
        System.out.println("Order ID: " + id + ", Quantity: " + quantity + ", Date: " + date);
    }
}
