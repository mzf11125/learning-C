package blueprint;

import animaltype.Carnivore;
import animaltype.Herbivore;

public class Chicken extends Animal implements Carnivore, Herbivore{
	protected int featherQuantity;

	public Chicken(String name, int age, String color, int featherQuantity) {
		super(name, age, color);
		this.featherQuantity = featherQuantity;
	}

	public int getFeatherQuantity() {
		return featherQuantity;
	}

	public void setFeatherQuantity(int featherQuantity) {
		this.featherQuantity = featherQuantity;
	}

	@Override
	public void eatGrass() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void eatMeat() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void move() {
//		System.out.println("Terbang");
	}
}
