package main;

import java.util.Random;
import java.util.Scanner;
import java.util.Vector;
import channel.Channel;
import channel.ClientChannel;
import channel.MasterChannel;
import client.clientFunction;
import auth.Authmain;
import master.MasterServer;

public class Main {
	
	Random random = new Random();
	Scanner scan = new Scanner(System.in);
	clientFunction client = new clientFunction();

//	public Main(Scanner scan) {
//		super();
//		this.scan = scan;
//	}
	protected String username;
	protected String password;


	Authmain user = new Authmain(username, password);
	MasterServer master = new MasterServer(); 
	
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
					master.start();
					break;
				case 2:
					client.client();
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
		
	    Channel channel = new Channel();

	    Thread producerThread = new Thread(new MasterChannel(channel));
	    Thread consumerThread = new Thread(new ClientChannel(channel));

	    producerThread.start();
	    consumerThread.start();
		
	
	}
	public static void main(String[] args) {
		new Main();
		
	}
}
