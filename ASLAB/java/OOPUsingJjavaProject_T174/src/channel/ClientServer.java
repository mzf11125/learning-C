package channel;

public class ClientServer extends Channel implements Runnable {
    private Channel channel;

    public ClientServer(Channel channel) {
        this.channel = channel;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                String message = channel.receive();
                System.out.println("Received: " + message);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}