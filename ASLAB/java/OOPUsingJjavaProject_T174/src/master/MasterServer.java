package master;

import java.util.Scanner;
import java.util.Vector;

public class MasterServer {
    protected Vector<String> clientList = new Vector<>();
    protected Vector<String> channelList = new Vector<>();
    Scanner scan = new Scanner(System.in);
    
    public static void main(String[] args) {
        MasterServer master = new MasterServer();
        master.start();
    }

    public void start() {
    	String input;
    	System.out.println("> Getting clientList directory\n"
    			+ "> Getting clients database\n"
    			+ "> Loading clients\n"
    			+ "> Initializing PubSubManager\n"
    			+ "> Running startup check\n"
    			+ "> Checking datastore directory\n"
    			+ "> Checking checkup file\n"
    			+ "> Getting pubSub directory\n"
    			+ "> Starting readFile task\n\n"
    			+ "> Done (0.019s)! For help type \"help\" or \"?\"\n"
    			+ "____________________________________________________________________________________________________");
        do {
        	System.out.print(">> ");
            input = scan.nextLine();
        	if (input.equals("stop") || input.equals("exit") || input.equals("quit") || input.equals("end")) {
                System.exit(0);
            } else if (input.equals("help") || input.equals("?")) {
                Help();
            } else if (input.equals("channellist") || input.equals("channels") || input.equals("chlist")) {
            	ChannelList();
            } else if (input.equals("clientlist") || input.equals("clients") || input.equals("clist")) {
            	ClientList();
            } else if (input.equals("addchannel") || input.equals("addchan") || input.equals("addch")) {
                System.out.println("Adds a channel.");
                String addChannel = scan.nextLine();
                channelList.add(addChannel);
            } else if (input.equals("removechannel") || input.equals("removechan") || input.equals("removech")) {
                System.out.println("Removes a channel.");
                String removeChannel = scan.nextLine();
                removeChannel(removeChannel);
            } else {
                System.out.println("Invalid command");
                System.out.println(">> ");
            }
          }while(true);  
        }
    

    public void Help() {
        System.out.println("Available commands:\n" +
                "> stop, exit, quit, end\n    Stops the application.\n" +
                "> help, ?\n    Shows this help message.\n" +
                "> channellist, channels, chlist\n    Shows a list of all channels.\n" +
                "> clientlist, clients, clist\n    Shows a list of all connected clients.\n" +
                "> addchannel, addchan, addch\n    Adds a channel.\n" +
                "> removechannel, removechan, removech\n    Removes a channel.\n" +
                "____________________________________________________________________________________________________\n");
    }

    public void ChannelList() {
        System.out.println("List of channels: ");
        for (String channel : channelList) {
            System.out.println(channel);
        }
    }

    public void ClientList() {
        System.out.println("List of connected clients: ");
        for (String client : clientList) {
            System.out.println(client);
        }
    }

    public void addChannel(String channel) {
        channelList.add(channel);
        System.out.println("Channel '" + channel + "' added.");
    }

    public void removeChannel(String channel) {
        if (channelList.contains(channel)) {
            channelList.remove(channel);
            System.out.println("Channel '" + channel + "' removed.");
        } else {
            System.out.println("Channel not found: '" + channel + "'");
        }
    }
}
