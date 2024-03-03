package main;

import java.util.ArrayList;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Spinner;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application{

	@Override
	public void start(Stage stage) throws Exception {
		// TODO Auto-generated method stub
		VBox root = new VBox();
		BorderPane bp = new BorderPane();
		
		//Menu Bar
		Menu menu1 = new Menu("File");
		MenuItem mi1 = new MenuItem("Open");
		MenuItem mi2 = new MenuItem("Save");
		MenuItem mi3 = new MenuItem("Exit");
		
		menu1.getItems().addAll(mi1, mi2, mi3);
		
		Menu menu2 = new Menu("Edit");
		MenuItem mi11 = new MenuItem("Cut");
		MenuItem mi22 = new MenuItem("Copy");
		MenuItem mi33 = new MenuItem("Paste");
		
		menu2.getItems().addAll(mi11, mi22, mi33);

		MenuBar menuBar = new MenuBar(menu1, menu2);
		
		
		root.getChildren().add(menuBar);
		
		RadioButton rb1 = new RadioButton("Male");
		RadioButton rb2 = new RadioButton("Female");
		
		ToggleGroup tg = new ToggleGroup();
		rb1.setToggleGroup(tg);
		rb2.setToggleGroup(tg);
		root.getChildren().addAll(rb1, rb2);
		
		//TextArea
		TextArea textArea = new TextArea();
		textArea.setWrapText(true);
		root.getChildren().add(textArea);
		
		//Combo box
		ArrayList<String> list = new ArrayList<>();
		for(int i = 0; i < 100; i++) {
			list.add("Opsi " + (i+1));
		}
		
		
		ObservableList<String> obsList = FXCollections.observableArrayList();
		for(int i = 0; i < 100; i++) {
			obsList.add("Opsi " + (i+1));
		}
		ComboBox<String> comboBox = new ComboBox<>();
		comboBox.setItems(obsList);
//		comboBox.getItems().addAll("Opsi 1", "Opsi 2", "opsi 3", "opsi 4");
		comboBox.setValue("Pilih: ");
		
		root.getChildren().add(comboBox);
		
		
		//Check Box
		
		CheckBox cB1 = new CheckBox("accept Cookies");
		CheckBox cB2 = new CheckBox("Checkbox lagi");
		
		root.getChildren().addAll(cB1, cB2);
		
		//List view
		
		ListView<String> listView = new ListView<>();
		listView.setItems(obsList);
		listView.setMaxHeight(100);
		
		//Spinner
		Spinner<Integer> spinner = new Spinner<>(0, 100, 1);
		spinner.setEditable(true);
		
		root.getChildren().add(spinner);
		
		//Tab
		Tab tab1 = new Tab("Module-into.java", new TextArea());
		Tab tab2 = new Tab("Module-into.java", new TextArea());
		
		TabPane tabPane = new TabPane(tab1, tab2);
		
		bp.setTop(new VBox(menuBar, tabPane));
		bp.setCenter(root);
		Scene scene = new Scene(root, 500, 800);
		stage.setScene(scene);
		
		stage.show();
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		launch(args);

	}

}
