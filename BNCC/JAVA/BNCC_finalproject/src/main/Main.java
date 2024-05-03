package main;

import controller.HomeController;
import database.MenuDatabase;
import service.MenuService;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        MenuDatabase menuDatabase = new MenuDatabase();
        MenuService menuService = new MenuService(menuDatabase);
        HomeController homeController = new HomeController(menuService);

        GridPane rootPane = homeController.createRootPane();
        Scene scene = new Scene(rootPane, 600, 400);

        primaryStage.setTitle("Pudding Menu App");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}