

package main;


import java.util.Scanner;
import java.util.*;
import java.util.Random;
import java.io.File;
import client.clientFunction;
//import 

import auth.Authmain;
import channel.Channel;
import channel.Consumer;
import channel.Producer;
import master.MasterServer;
import client.clientFunction;

public class Main {
	
	Vector<> 
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
					master.MasterServer1();
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
			// TODO Auto-generated catch block
			//e.printStackTrace();
		}
	}
	
	public Main() {
		mainMenu();
		
	    Channel channel = new Channel();

	    Thread producerThread = new Thread(new Producer(channel));
	    Thread consumerThread = new Thread(new Consumer(channel));

	    producerThread.start();
	    consumerThread.start();
		
//		Main.mainMenu();		
	}
	public static void main(String[] args) {
		new Main();
	}
}
