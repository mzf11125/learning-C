package channel;

import java.util.Vector;

class Channel {
    private Vector<String> messages;

    public Channel() {
        messages = new Vector<>();
    }

    public synchronized void send(String message) {
        messages.add(message);
        notify(); 
    }

    public synchronized String receive() throws InterruptedException {
        while (messages.isEmpty()) {
            wait(); 
        }
        String message = messages.remove(0);
        return message;
    }
}





