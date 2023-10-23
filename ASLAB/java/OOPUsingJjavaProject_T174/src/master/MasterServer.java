package master;

import java.util.Random;
import java.util.Scanner;


public class MasterServer {
Scanner scan = new Scanner (System.in);
Random random = new Random();
int randomInt = random.nextInt(100);
//	public MasterServer() {
//	
//			
//		}
	public void MasterServer1() {
		do {
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
					+ "Done ("+ randomInt +")! For help type \"help\" or \"?\"\r\n"
					+ "____________________________________________________________________________________________________");
					String input1 = scan.nextLine();

					
					if (input1.equals("clientlist") || input1.equals("clients") || input1.equals("clist")) {
					     // Handle client list action
					} else if (input1.equals("channellist") || input1.equals("channels") || input1.equals("chlist")) {
					     // Handle channel list action
					} else if (input1.equals("")) {
					    
						
					} else if (input1.isEmpty()) {
					    // Handle empty input action
					 } else if (input1.equals("?") || input1.equals("help")) {
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
					    } else {
					        System.out.println("Please type a valid input.");
					    }
					} while (true);
	}
}



