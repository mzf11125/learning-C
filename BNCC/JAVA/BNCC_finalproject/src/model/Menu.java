package model;

public class Menu {
    private String code;
    private String name;
    private double price;
    private int stock;

    public Menu(String code, String name, double price, int stock) {
        this.code = code;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }

    public String getCode() {
        return code;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getStock() {
        return stock;
    }

    @Override
    public String toString() {
        return name + " (Code: " + code + ", Price: " + price + ", Stock: " + stock + ")";
    }
}