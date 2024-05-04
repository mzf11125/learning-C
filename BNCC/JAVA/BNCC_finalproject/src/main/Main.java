package main;

import controller.MenuController;
import database.MenuDatabase;
import service.MenuService;
import view.MenuView;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
	
    @Override
    public void start(Stage primaryStage) {
        MenuDatabase menuDatabase = new MenuDatabase();
        MenuService menuService = new MenuService(menuDatabase);
        MenuController controller = new MenuController(menuService);
        MenuView view = new MenuView(controller);

        Scene scene = new Scene(view);
        primaryStage.setTitle("Pudding Menu App");
        primaryStage.setScene(scene);
        primaryStage.show();
        
    }

    public static void main(String[] args) {
        launch(args);
    }
}