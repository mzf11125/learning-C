package thread;

//import main.Main;

public class MyThread extends Thread{
	@Override
	public void run() {
		// TODO Auto-generated method stub
		super.run();
		for(int i = 1; i <= 10000; i++) {
//			try {
//				Thread.sleep(1000);
//				System.out.println(i);
//			} catch (InterruptedException e) {
//				// TODO Auto-generated catch block
////				e.printStackTrace();
//			}
			System.out.println(i);
//			Main.counter.increment();
		}
	}
}