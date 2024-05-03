package database;

import model.Menu;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MenuDatabase {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/pudding_db";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

    public MenuDatabase() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void insertMenu(String name, double price, int stock) {
        String code = generateCode();
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "INSERT INTO menu (code, name, price, stock) VALUES (?, ?, ?, ?)";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, code);
            stmt.setString(2, name);
            stmt.setDouble(3, price);
            stmt.setInt(4, stock);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Menu> getMenus() {
        List<Menu> menus = new ArrayList<>();
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "SELECT code, name, price, stock FROM menu";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                String code = rs.getString("code");
                String name = rs.getString("name");
                double price = rs.getDouble("price");
                int stock = rs.getInt("stock");
                menus.add(new Menu(code, name, price, stock));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return menus;
    }

    public void updateMenu(String code, double newPrice, int newStock) {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "UPDATE menu SET price = ?, stock = ? WHERE code = ?";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setDouble(1, newPrice);
            stmt.setInt(2, newStock);
            stmt.setString(3, code);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteMenu(String code) {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "DELETE FROM menu WHERE code = ?";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, code);
            stmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private String generateCode() {
        Random rand = new Random();
        int randomNum = rand.nextInt(900) + 100;
        return "PD-" + randomNum;
    }
}