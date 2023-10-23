package blueprint;

import animaltype.Carnivore;

public class Tiger extends Animal implements Carnivore{
	protected String skinPattern;
	protected int pawQuantiy;
	
	public Tiger(String name, int age, String color, String skinPattern, int pawQuantiy) {
		super(name, age, color);

		this.skinPattern = skinPattern;
		this.pawQuantiy = pawQuantiy;
	}

	@Override //polymorphism
	public void move() {
		System.out.println(" Running");
		
	}
	
	public void move(int distance) {
		System.out.println(this.name + " " + "is running for " + distance + " km");		
	}

	public String getSkinPattern() {
		return skinPattern;
	}

	public void setSkinPattern(String skinPattern) {
		this.skinPattern = skinPattern;
	}

	public int getPawQuantiy() {
		return pawQuantiy;
	}

	public void setPawQuantiy(int pawQuantiy) {
		this.pawQuantiy = pawQuantiy;
	}

	@Override
	public void eatMeat() {
		System.out.println("Eat meat yum yum yum yum.........");
		
	}
	
	
	

	
//	void eat(){
//		this.name = "Yippie";
//	}
	
	
	
	

}
