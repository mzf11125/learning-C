package View;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class LoginPage {
	
	private Stage stage;
	private Scene scene;
	private GridPane root;
	
	private Label headerLbl;
	private Label usernameLbl;
	private Label passwordLbl;
	private TextField usernameField;
	private PasswordField passwordField;
	private Button loginBtn;
	
	public LoginPage(Stage stage) {
		this.stage = stage;
		this.init();
		this.setComponent();
		this.setStyle();
	}
	
//	Redundant
	private void init() {
		root = new GridPane();
		scene = new Scene(root);
		headerLbl = new Label("Welcome");
		usernameLbl = new Label("Username");
		passwordLbl = new Label("Password");
		usernameField = new TextField();
		passwordField = new PasswordField();
		loginBtn = new Button("Sign In");
	}

	
	private void setComponent() {
		root.add(headerLbl, 0, 0, 2, 1);
		root.add(usernameLbl, 0, 1);
		root.add(usernameField, 0, 2);
		root.add(passwordLbl, 1, 1);
		root.add(passwordField, 1, 2);
		root.add(loginBtn, 0, 3, 2, 1);
		root.setGridLinesVisible(false);

		stage.setScene(scene);
	}
	
	private void setStyle() {
		root.setAlignment(Pos.CENTER);
		root.setHgap(20);
		root.setVgap(20);
		headerLbl.setStyle("-fx-font-family: 'Times New Roman'; -fx-font-size: 50");
		usernameLbl.setStyle("-fx-font-size: 22");
		passwordLbl.setStyle("-fx-font-size: 22");
		loginBtn.setMaxWidth(Double.MAX_VALUE);
		
		usernameField.setPromptText("Enter your username");
		passwordField.setPromptText("Enter your password");
	}
}
