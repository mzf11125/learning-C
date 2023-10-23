package blueprint;

public abstract class Animal {
	
	//Security measure = protected and private
	protected String name;
	protected int age;
	protected String color;
	public Animal(String name, int age, String color) {
//		super(); Not needed -> o call constructor in Superclass
		this.name = name;
		this.age = age;
		this.color = color;
	}
	
	
	
	public abstract void move();
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	
	
}
