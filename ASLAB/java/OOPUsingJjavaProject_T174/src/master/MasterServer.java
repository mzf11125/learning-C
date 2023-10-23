package master;

import java.util.Vector;

public class MasterServer {
    private Vector<String> clientList = new Vector<>();
    private Vector<String> channelList = new Vector<>();

    public static void main(String[] args) {
        MasterServer master = new MasterServer();
        master.start();
    }
    long startTime();
    public void start() {
        System.out.println("Getting clientList directory");
        System.out.println("Getting clients database");
        System.out.println("Loading clients");
        System.out.println("Initializing PubSubManager");
        System.out.println("Running startup check");
        System.out.println("Checking datastore directory");
        System.out.println("Checking checkup file");
        

        System.out.println("Getting pubSub directory");
       

        System.out.println("Starting readFile task");
        
        long endTime = System.currentTimeMillis(); // Record the end time
        long initializationTime = endTime - startTime;
        System.out.println("\nDone (0.019s)! For help type \"help\" or \"?\"");
        System.out.println("____________________________________________________________________________________________________");
        Help();
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

    public void showChannelList() {
        // Implement logic to display the list of channels
        System.out.println("List of channels: ");
        for (String channel : channelList) {
            System.out.println(channel);
        }
    }

    public void showClientList() {
        // Implement logic to display the list of connected clients
        System.out.println("List of connected clients: ");
        for (String client : clientList) {
            System.out.println(client);
        }
    }

    public void addChannel(String channel) {
        // Implement logic to add a channel
        channelList.add(channel);
        System.out.println("Channel '" + channel + "' added.");
    }

    public void removeChannel(String channel) {
        // Implement logic to remove a channel
        if (channelList.contains(channel)) {
            channelList.remove(channel);
            System.out.println("Channel '" + channel + "' removed.");
        } else {
            System.out.println("Channel not found: '" + channel + "'");
        }
    }
}
