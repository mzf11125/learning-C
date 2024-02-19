package main;

import java.util.Random;
import java.util.Scanner;
//import java.util.Vector;

public class Main {
	
	Random random = new Random();
	Scanner scan = new Scanner(System.in);


//	public Main(Scanner scan) {
//		super();
//		this.scan = scan;
//	}
	protected String username;
	protected String password;


	
	public void display() {
		System.out.println("███████████████████████████████████████████████\r\n"
				+ "  ███████ ███████       ██████  ██████   ██████\r\n"
				+ "  ██      ██            ██   ██ ██   ██ ██\r\n"
				+ "  █████   █████   █████ ██████  ██████  ██\r\n"
				+ "  ██      ██            ██   ██ ██      ██\r\n"
				+ "  ███████ ██            ██   ██ ██       ██████\r\n"
				+ "\r\n"
				+ "\r\n"
				+ "1. Start as Master\r\n"
				+ "2. Start as Client\r\n"
				+ "3. Exit");
		System.out.print(">> ");
	}
	
	public void mainMenu() {
		try {
			int input;
			do {
				display();
				input = scan.nextInt();scan.nextLine();
				switch(input) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					System.exit(0);
					break;
				}
				
			}while(input > 3 || input <  1);
		} catch (Exception e) {
			
		}
	}
	
	public Main() {
		mainMenu();
		
//	    Channel channel = new Channel();

//	    Thread producerThread = new Thread(new MasterChannel(channel));
//	    Thread consumerThread = new Thread(new ClientChannel(channel));

//	    producerThread.start();
//	    consumerThread.start();
		
	
	}
	public static void main(String[] args) {
		new Main();
		
	}
}