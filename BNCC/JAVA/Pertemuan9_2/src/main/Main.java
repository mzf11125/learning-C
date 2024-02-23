package main;

import View.LoginPage;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application{
	
	public static final int WIDTH = 700;
	public static final int HEIGHT = 500;
	
	@Override
	public void start(Stage stage) throws Exception {
		// TODO Auto-generated method stub
		new LoginPage(stage);
		stage.setTitle("Aplikasi Login");
		stage.show();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		launch(args);
	}


}
