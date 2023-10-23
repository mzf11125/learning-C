package channel;

public class MasterServer extends Channel implements Runnable {
    private Channel channel;

    public MasterServer(Channel channel) {
        this.channel = channel;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            String message = "Message " + i;
            channel.send(message);
            System.out.println("Sent: " + message);
        }
    }
}
