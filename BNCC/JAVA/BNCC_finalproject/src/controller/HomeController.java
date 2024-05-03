package controller;

import model.Menu;
import service.MenuService;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;

public class HomeController {
    private MenuService menuService;
    private TextField nameField;
    private TextField priceField;
    private TextField stockField;
    private ListView<Menu> menuListView;

    public HomeController(MenuService menuService) {
        this.menuService = menuService;
    }

    public GridPane createRootPane() {
        GridPane gridPane = new GridPane();
        gridPane.setHgap(10);
        gridPane.setVgap(10);

        Label nameLabel = new Label("Name:");
        gridPane.add(nameLabel, 0, 0);

        nameField = new TextField();
        gridPane.add(nameField, 1, 0);

        Label priceLabel = new Label("Price:");
        gridPane.add(priceLabel, 0, 1);

        priceField = new TextField();
        gridPane.add(priceField, 1, 1);

        Label stockLabel = new Label("Stock:");
        gridPane.add(stockLabel, 0, 2);

        stockField = new TextField();
        gridPane.add(stockField, 1, 2);

        Button insertButton = new Button("Insert");
        insertButton.setOnAction(event -> handleInsertMenu());
        gridPane.add(insertButton, 0, 3);

        Button updateButton = new Button("Update");
        updateButton.setOnAction(event -> handleUpdateMenu());
        gridPane.add(updateButton, 1, 3);

        Button deleteButton = new Button("Delete");
        deleteButton.setOnAction(event -> handleDeleteMenu());
        gridPane.add(deleteButton, 2, 3);

        menuListView = new ListView<>();
        menuListView.setOnMouseClicked(event -> populateFields());
        gridPane.add(menuListView, 0, 4, 3, 1);

        refreshMenuList();

        return gridPane;
    }

    private void handleInsertMenu() {
        String name = nameField.getText();
        double price = Double.parseDouble(priceField.getText());
        int stock = Integer.parseInt(stockField.getText());
        menuService.insertMenu(name, price, stock);
        refreshMenuList();
    }

    private void handleUpdateMenu() {
        Menu selectedMenu = menuListView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            double newPrice = Double.parseDouble(priceField.getText());
            int newStock = Integer.parseInt(stockField.getText());
            menuService.updateMenu(selectedMenu.getCode(), newPrice, newStock);
            refreshMenuList();
        }
    }

    private void handleDeleteMenu() {
        Menu selectedMenu = menuListView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            menuService.deleteMenu(selectedMenu.getCode());
            refreshMenuList();
        }
    }

    private void populateFields() {
        Menu selectedMenu = menuListView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            nameField.setText(selectedMenu.getName());
            priceField.setText(String.valueOf(selectedMenu.getPrice()));
            stockField.setText(String.valueOf(selectedMenu.getStock()));
        }
    }

    private void refreshMenuList() {
        ObservableList<Menu> menuData = FXCollections.observableArrayList(menuService.getMenus());
        menuListView.setItems(menuData);
    }
}