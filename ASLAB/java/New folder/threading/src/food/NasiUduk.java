package food;

public class NasiUduk extends Food implements Runnable{
	private int Spiciness;
	private Thread t;
	
	public NasiUduk(int cookinigTime, int price, String name, int spiciness, Thread t) {
		super(cookinigTime, price, name);
		Spiciness = spiciness;
		this.t = t;
	}


	public int getSpiciness() {
		return Spiciness;
	}

	public void setSpiciness(int spiciness) {
		Spiciness = spiciness;
	}

	@Override
	public void run() {
		cooking();
		
	}
	
	@Override
	public void start() {
		t = new Thread(this);
		t.start();
		
	}
	
	public void cooking() {
		try {
			while(getCookinigTime() > 0) {
				System.out.println();
				Thread.sleep(10000);
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(this.getName() + "is being cooked" + getCookinigTime() + "left");
		setCookinigTime(getCookinigTime()-1);
		System.out.println(getName() + "sudah matang");
	}
}
