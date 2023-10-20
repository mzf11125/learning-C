package javasesi4;

public class fish extends animal{
	
	String type;

	public fish(String name, int age, String type) {
		super(name, age);
		this.type = type;
	}

	public void swim() {
		System.out.println(this.name + " Blub blub....");
	}
	
	public void jalan() {
		System.out.println(this.name + " Blub blub....");
	}

}
