package channel;

public class MasterChannel extends Channel implements Runnable {
    private Channel channel;

    public MasterChannel(Channel channel) {
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
