package main;

import java.util.Scanner;
import java.util.Vector;
import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;

import main.Customer;
import main.Saloon;

public class Main {
	String name;
	int number1;
	int number2;
	Saloon saloon = new Saloon(name, number1, number2);
	Customer customer = new Customer();
	File f = new File("src/highscore.txt");
	Scanner scan = new Scanner(System.in); 	
	Vector<String> highScores = new Vector<>();
	public Main() {
		menu();
	}
	
	public void createfile() {
        if(f.exists()) {
            System.out.println("Exists");
        }
        else{
        	try {
				f.createNewFile();
			} catch (IOException e) {
				
				e.printStackTrace();
			}	
        	return;
        }
	}
	
	public void HighScore() {
		createfile();
		try (BufferedReader br = new BufferedReader(new FileReader(f))) {
		    String text;
		    while ((text = br.readLine()) != null) {
		        text = text.replace("#", ", ");
		        System.out.println(text);
		    }
		} catch (IOException e) {
		    e.printStackTrace();
		}
	}
	
	public void newHairSaloon() {
		do {
			System.out.println("Input your hairsalon's name [5..20 characters]: ");
			
		}
	}
	
	void menu() {
		int choice = 0;
		
		do {
			System.out.println("  ____  _             _   _               __  __\r\n"
					+ " / ___|| |_ __ _ _ __| |_(_)_ __   __ _  |  \\/  | ___ _ __  _   _\r\n"
					+ " \\___ \\| __/ _` | '__| __| | '_ \\ / _` | | |\\/| |/ _ \\ '_ \\| | | |\r\n"
					+ "  ___) | || (_| | |  | |_| | | | | (_| | | |  | |  __/ | | | |_| |\r\n"
					+ " |____/ \\__\\__,_|_|   \\__|_|_| |_|\\__, | |_|  |_|\\___|_| |_|\\__,_|\r\n"
					+ "                                  |___/\r\n"
					+ "\r\n"
					+ "1. Play New Hairsalon\r\n"
					+ "2. High Score\r\n"
					+ "3. Exit\r\n"
					+ "Input [1..3]:\r\n"
					+ "");
			choice = scan.nextInt();scan.nextLine();
			switch(choice) {
			case 1:
				newHairSaloon();
				break;
			case 2:
				HighScore();
				break;
			case 3:
				System.exit(0);
				break;
			}
		}while(choice >= 3 && choice >= 1);
	}
	

	public static void main(String[] args) {
		new Main();
	}

}
