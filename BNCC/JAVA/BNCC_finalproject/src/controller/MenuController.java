package controller;

import model.Menu;
import service.MenuService;

import java.util.List;

public class MenuController {
    private MenuService menuService;

    public MenuController(MenuService menuService) {
        this.menuService = menuService;
    }

    public void insertMenu(String name, double price, int stock) {
        menuService.insertMenu(name, price, stock);
    }

    public List<Menu> getMenus() {
        return menuService.getMenus();
    }

    public void updateMenu(String code, double newPrice, int newStock) {
        menuService.updateMenu(code, newPrice, newStock);
    }

    public void deleteMenu(String code) {
        menuService.deleteMenu(code);
    }
}