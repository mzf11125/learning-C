package food;

public class Sushi extends Food implements Runnable{
	private String FishType;
	private Thread t;
		
	public Sushi(int cookinigTime, int price, String name) {
		super(cookinigTime, price, name);
		
	}

	public String getFishType() {
		return FishType;
	}

	public void setFishType(String fishType) {
		FishType = fishType;
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
		System.out.println(getName() + "sudah jadi");
	}

	
}
