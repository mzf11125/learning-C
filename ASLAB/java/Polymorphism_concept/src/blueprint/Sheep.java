package blueprint;

import animaltype.Herbivore;

public class Sheep extends Animal implements Herbivore{

	protected String woolPatterns;
	protected int hornQuantity;
	
	public Sheep(String name, int age, String color, String woolPatterns, int hornQuantity) {
		super(name, age, color);
		this.woolPatterns = woolPatterns;
		this.hornQuantity = hornQuantity;
	}
	
	@Override
	public void move() {
		System.out.println(" Jumping around");
		
	}

	public String getWoolPatterns() {
		return woolPatterns;
	}
	public void setWoolPatterns(String woolPatterns) {
		this.woolPatterns = woolPatterns;
	}
	public int getHornQuantity() {
		return hornQuantity;
	}
	public void setHornQuantity(int hornQuantity) {
		this.hornQuantity = hornQuantity;
	}

	@Override
	public void eatGrass() {
		System.out.println("Eat grass chomp chomp chomp.....");
		
	}

	
	
	

}
