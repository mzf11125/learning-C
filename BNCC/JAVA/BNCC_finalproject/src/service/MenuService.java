package service;

import database.MenuDatabase;
import model.Menu;

import java.util.List;

public class MenuService {
    private MenuDatabase menuDatabase;

    public MenuService(MenuDatabase menuDatabase) {
        this.menuDatabase = menuDatabase;
    }

    public void insertMenu(String name, double price, int stock) {
        menuDatabase.insertMenu(name, price, stock);
    }

    public List<Menu> getMenus() {
        return menuDatabase.getMenus();
    }

    public void updateMenu(String code, double newPrice, int newStock) {
        menuDatabase.updateMenu(code, newPrice, newStock);
    }

    public void deleteMenu(String code) {
        menuDatabase.deleteMenu(code);
    }
}