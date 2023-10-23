package master;

import java.util.Random;
import java.util.Scanner;


import 

public class MasterServer {
Scanner scan = new Scanner (System.in);
	public MasterServer() {
		do {}while(true);
		System.out.println("Booting master application...\r\n"
			+ "\r\n"
			+ "Initializing MasterDatastore\r\n"
			+ "Starting clearDeadClients task\r\n"
			+ "Initializing AuthController\r\n"
			+ "Getting clientList directory\r\n"
			+ "Getting clients database\r\n"
			+ "Loading clients\r\n"
			+ "Initializing PubSubManager\r\n"
			+ "Running startup check\r\n"
			+ "Checking datastore directory\r\n"
			+ "Checking checkup file\r\n"
			+ "Getting pubSub directory\r\n"
			+ "Starting readFile task\r\n"
			+ "\r\n"
			+ "Done ()! For help type \"help\" or \"?\"\r\n"
			+ "____________________________________________________________________________________________________");
			String input = scan.nextLine();
			if (input == "/register") {
				
				
			}
			else if(input == "channelist" || input == "channels" || input == "chlist") {
				
			}
			else if(input == "/iooisda") {
				
			}
			else if(input == "") {
				
			}	
			else if(input == "clientlist" || input == "clients" || input == "clist") {
				
			}
			else if(input == "?" || input == "help") {
				System.out.println("Available commands:\r\n"
						+ "\r\n"
						+ " > stop, exit, quit, end\r\n"
						+ "    Stops the application.\r\n"
						+ "\r\n"
						+ " > help, ?\r\n"
						+ "    Shows this help message.\r\n"
						+ "\r\n"
						+ " > channellist, channels, chlist\r\n"
						+ "    Shows a list of all channels.\r\n"
						+ "\r\n"
						+ " > clientlist, clients, clist\r\n"
						+ "    Shows a list of all connected clients.\r\n"
						+ "\r\n"
						+ " > addchannel, addchan, addch\r\n"
						+ "    Adds a channel.\r\n"
						+ "\r\n"
						+ " > removechannel, removechan, removech\r\n"
						+ "    Removes a channel.");
				
			}
			else {
				System.out.println("Please type a valid input");
			}
			
		}
	}


