package main;

import javafx.application.Application;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application{

	
	@Override
	public void start(Stage stage) throws Exception{
		//BorderPane
//		BorderPane root = new BorderPane();
//		Label label = new Label("Hello World!");
//		Button button = new Button("Click me");
//		
//		root.setCenter(label);
//		
//		root.setTop(button);
//		
//		GridPane
//		GridPane root = new GridPane();
//		root.add(new Button("Button 1"), 0, 0);
//		root.add(new Button("Button 2"), 1, 0);
//		root.add(new Button("Button 3"), 1, 1);
//		root.setGridLineVisible(true);
//		root.setHGap(50);
//		root.setVGap(50);
		
		//Hbox
//		HBox root = new HBox();
//		root.getChildren().addAll(new Label("Hello world!!!"), new Button("Tombol baru"), new Label("Halo lagi"));
//		Buat gap
//		root.setSpacing(20);
		
//		VBox
//		VBox root = new VBox();
//		root.getChildren().addAll(new Label("Hello world!!!"), new Button("Tombol baru"), new Label("Halo lagi"));
//		root.setSpacing(20);
		
//		FlowPane
		FlowPane root = new FlowPane();
		root.setOrientation(Orientation.VERTICAL);
		
		
		for(int i = 1; i <= 10; i++) {
			Button button = new Button("Button " + i);
			root.getChildren().add(button);
		}
//		
		Scene scene = new Scene(root, 700, 500);
//		stage.setResizable(false);
		stage.setScene(scene);
		stage.setTitle("aplikasi di UI utama");
		stage.show();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		launch(args);

	}

}
