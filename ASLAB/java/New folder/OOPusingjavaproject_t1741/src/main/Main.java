package main;

import java.util.Scanner;

import clients.Clients;
//import 

//import auth.Authmain;

public class Main {

	Scanner scan = new Scanner(System.in);
	Clients client = new Clients();
//
//	public Main(Scanner scan) {
//		super();
//		this.scan = scan;
//	}
	protected String sus;
	protected String su1s;
	
//	Authmain user = new Authmain(sus, su1s);
	
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
		int input;
		do {
			display();
			input = scan.nextInt();scan.nextLine();
			switch(input) {
			case 1:
				master();
				break;
			case 2:
				client();
				break;
			case 3:
				System.exit(0);
				break;
			}
			
		}while(input > 3 || input <  1);
	}
	
	public void client() {
		client.clients();
	}

	public void master() {
		
		
	}

	public Main() {
		mainMenu();	
	}
	
	public static void main(String[] args) {
		new Main();
	}
}
