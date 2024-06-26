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
    private TableView<Menu> menuTableView;

    private MenuController controller;

    public MenuView(MenuController controller) {
        this.controller = controller;
        createView();
        refreshMenuList();
    }

    @SuppressWarnings("unchecked")
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

        // Create and configure menu table view
        menuTableView = new TableView<>();
        menuTableView.setPrefWidth(Integer.MAX_VALUE);

        // Create table columns
        TableColumn<Menu, String> codeColumn = new TableColumn<>("Code");
        codeColumn.setCellValueFactory(cellData -> cellData.getValue().codeProperty());

        TableColumn<Menu, String> nameColumn = new TableColumn<>("Name");
        nameColumn.setCellValueFactory(cellData -> cellData.getValue().nameProperty());

        TableColumn<Menu, Double> priceColumn = new TableColumn<>("Price");
        priceColumn.setCellValueFactory(cellData -> cellData.getValue().priceProperty().asObject());

        TableColumn<Menu, Integer> stockColumn = new TableColumn<>("Stock");
        stockColumn.setCellValueFactory(cellData -> cellData.getValue().stockProperty().asObject());

        menuTableView.getColumns().addAll(codeColumn, nameColumn, priceColumn, stockColumn);
        add(menuTableView, 0, 4, 2, 1); // Span 2 columns
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
        Menu selectedMenu = menuTableView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            double newPrice = Double.parseDouble(priceField.getText());
            int newStock = Integer.parseInt(stockField.getText());
            controller.updateMenu(selectedMenu.getCode(), newPrice, newStock);
            refreshMenuList();
            clearFields();
        }
    }

    private void handleDeleteMenu() {
        Menu selectedMenu = menuTableView.getSelectionModel().getSelectedItem();
        if (selectedMenu != null) {
            controller.deleteMenu(selectedMenu.getCode());
            refreshMenuList();
            clearFields();
        }
    }

    private void clearFields() {
        nameField.clear();
        priceField.clear();
        stockField.clear();
    }


    
    private void refreshMenuList() {
        ObservableList<Menu> menuData = FXCollections.observableArrayList(controller.getMenus());
        menuTableView.setItems(menuData);
    }
    
    
}