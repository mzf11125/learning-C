package channel;

public class ClientChannel extends Channel implements Runnable {
    private Channel channel;

    public ClientChannel(Channel channel) {
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