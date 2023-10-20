package OOPusingJavaH4_T174;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;

public class Main {
	ArrayList<user> datauser= new ArrayList<>();
	Scanner scan = new Scanner(System.in);
	
	public int length;
	
	void mainMenu(){
		try {
			int input = 0;
			do {
				System.out.println("        NijiMart\r\n" + 
						"        ========\r\n" + 
						"        1. Login\r\n" + 
								"        2. Register\r\n" + 
								"        3. Exit");
				System.out.print("        >> ");
				input = scan.nextInt();scan.nextLine();
				
				switch(input) {
				case 1:
					login();
					break;
				case 2:
					register();
					break;
				case 3:
					System.exit(0);
				}
				
				
			}while(input <= 3 && input >= 1 || input > 3 || input < 1);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private void login() {
		try {
			String username;
			String password;
			
			while(true)
			{
				System.out.println("        Input your username (input 0 to go back): ");
				username = scan.nextLine();
				if(username == "0") {
					break;
				}
				System.out.println("        Input your username (input 0 to go back): ");
				password = scan.nextLine();
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
		
		
		
		
	}

	private void register() {
		String username;
		String password;
		
		try {
			while(true) {
				System.out.println("        Register\r\n" + 
						"        ========");
				System.out.print("        Input your username (username length 5-20 characters and unique | 0 to cancel): ");
						username = scan.nextLine();scan.nextLine();
						if(username.length() >=  5 && username.length() <= 20){
							continue;
						}
						else if(username == "0") {
							break;
						}
						else{
							System.out.println("Username length has to be greater than 5 and less than 20 characters\r\n" + 
									"        Input your username (username length 5-20 characters and unique | 0 to cancel):");
						}
				System.out.println("        Input your password (password length 8-20 characters and alphanumeric | 0 to cancel): ");
						password = scan.nextLine();scan.nextLine();
						if(username.length() >=  5 || username.length() <= 20){
							continue;
						}
						else if(username == "0") {
							break;
						}
						else{
							System.out.println("Username length has to be greater than 5 and less than 20 characters\r\n" + 
									"        Input your username (username length 5-20 characters and unique | 0 to cancel):");
						}
				System.out.println("");
				
			   	
				
						
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		
		
		
	}
	
	
	
	
	private void productsfile(){
		File* file = new File("src/products.csv");
		FileWriter fw= ;
		
	}
	
	private void usersfile(){
		File* file = new file("src/productscsv");
		FileWriter fw = ;
		
	}

//	private void displayMenu(){
//		System.out.println("        NijiMart\r\n" + 
//		"        ========\r\n" + 
//		"        1. Login\r\n" + 
//				"        2. Register\r\n" + 
//				"        3. Exit\r\n" + 
//				"        >> ");
//	}
	
	public Main() {
		mainMenu();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();

	}

}
