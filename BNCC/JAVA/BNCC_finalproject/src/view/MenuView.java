package view;

import controller.MenuController;
import model.Menu;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;

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

        // Create labels and text fields
        Label nameLabel = new Label("Name:");
        nameField = new TextField();
        Label priceLabel = new Label("Price:");
        priceField = new TextField();
        Label stockLabel = new Label("Stock:");
        stockField = new TextField();

        // Add labels and text fields to GridPane
        add(nameLabel, 0, 0);
        add(nameField, 1, 0);
        add(priceLabel, 0, 1);
        add(priceField, 1, 1);
        add(stockLabel, 0, 2);
        add(stockField, 1, 2);

        // Create a horizontal box for buttons
        HBox buttonBox = new HBox();
        buttonBox.setSpacing(10);
        Button insertButton = new Button("Insert");
        insertButton.setOnAction(event -> handleInsertMenu());
        buttonBox.getChildren().add(insertButton);

        Button updateButton = new Button("Update");
        updateButton.setOnAction(event -> handleUpdateMenu());
        buttonBox.getChildren().add(updateButton);

        Button deleteButton = new Button("Delete");
        deleteButton.setOnAction(event -> handleDeleteMenu());
        buttonBox.getChildren().add(deleteButton);
        add(buttonBox, 0, 3, 2, 1);  // Span 2 columns

        // Create and configure menu list view
        menuListView = new ListView<>();
        menuListView.setPrefWidth(Integer.MAX_VALUE); 
        add(menuListView, 0, 4, 2, 1); // Span 2 columns
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

//	private void populateFields() {
//        Menu selectedMenu = menuListView.getSelectionModel().getSelectedItem();
//        if (selectedMenu != null) {
//            nameField.setText(selectedMenu.getName());
//            priceField.setText(String.valueOf(selectedMenu.getPrice()));
//            stockField.setText(String.valueOf(selectedMenu.getStock()));
//        }
//    }

    private void clearFields() {
        nameField.clear();
        priceField.clear();
        stockField.clear();
    }


    
    private void refreshMenuList() {
        ObservableList<Menu> menuData = FXCollections.observableArrayList(controller.getMenus());
        menuListView.setItems(menuData);

        // Set a custom cell factory to display the menu details
        menuListView.setCellFactory(lv -> new ListCell<Menu>() {
            @Override
            protected void updateItem(Menu menu, boolean empty) {
                super.updateItem(menu, empty);
                if (empty || menu == null) {
                    setText(null);
                } else {
                    setText(String.format("Code: %s, Name: %s, Price: $%.2f, Stock: %d", menu.getCode(), menu.getName(), menu.getPrice(), menu.getStock()));
                }
            }
        });
    }
    
    
}