package view;

import controller.MenuController;
import model.Menu;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;

public class MenuView extends GridPane {
    private TextField nameField;
    private TextField priceField;
    private TextField stockField;
    private ListView<Menu> menuListView;

    private MenuController controller;

    public MenuView(MenuController controller) {
        this.controller = controller;
        createView();
        refreshMenuList();
    }

    private void createView() {
        setPadding(new Insets(10));
        setHgap(10);
        setVgap(10);

        Label nameLabel = new Label("Name:");
        add(nameLabel, 0, 0);

        nameField = new TextField();
        add(nameField, 1, 0);

        Label priceLabel = new Label("Price:");
        add(priceLabel, 0, 1);

        priceField = new TextField();
        add(priceField, 1, 1);

        Label stockLabel = new Label("Stock:");
        add(stockLabel, 0, 2);

        stockField = new TextField();
        add(stockField, 1, 2);

        Button insertButton = new Button("Insert");
        insertButton.setOnAction(event -> handleInsertMenu());
        add(insertButton, 0, 3);

        Button updateButton = new Button("Update");
        updateButton.setOnAction(event -> handleUpdateMenu());
        add(updateButton, 1, 3);

        Button deleteButton = new Button("Delete");
        deleteButton.setOnAction(event -> handleDeleteMenu());
        add(deleteButton, 2, 3);

        menuListView = new ListView<>();
        menuListView.setOnMouseClicked(event -> populateFields());
        add(menuListView, 0, 4, 3, 1);
    }

    private void handleInsertMenu() {
        String name = nameField.getText();
        double price = Double.parseDouble(priceField.getText());
        int stock = Integer.parseInt(stockField.getText());
        controller.insertMenu(name, price, stock);
        refreshMenuList();
        clearFields();
    }

    private void handleUpdateMenu() {
        Menu selectedMenu = menuListView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            double newPrice = Double.parseDouble(priceField.getText());
            int newStock = Integer.parseInt(stockField.getText());
            controller.updateMenu(selectedMenu.getCode(), newPrice, newStock);
            refreshMenuList();
            clearFields();
        }
    }

    private void handleDeleteMenu() {
        Menu selectedMenu = menuListView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            controller.deleteMenu(selectedMenu.getCode());
            refreshMenuList();
            clearFields();
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

    private void clearFields() {
        nameField.clear();
        priceField.clear();
        stockField.clear();
    }

    private void refreshMenuList() {
        ObservableList<Menu> menuData = FXCollections.observableArrayList(controller.getMenus());
        menuListView.setItems(menuData);
    }
}