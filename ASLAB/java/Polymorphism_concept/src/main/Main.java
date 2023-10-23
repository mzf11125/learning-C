package main;

import java.util.ArrayList;
import java.util.Scanner;

import blueprint.Animal;
import blueprint.Chicken;
import blueprint.Sheep;
import blueprint.Tiger;

public class Main {
	ArrayList <Animal> animalList = new ArrayList<Animal>();
	Scanner scan = new Scanner(System.in);
	public Main() {
//		Tiger tiger = new Tiger("Tigris", 3, "Orange", "Linear", 4);
//		tiger.move(5);
//		
		Chicken Chicken = new Chicken("Chickie", 1, "Brown", 900);
		animalList.add(Chicken);
		Sheep Sheep = new Sheep("Timmy", 2, "White", "Curly", 2);
		animalList.add(Sheep);
		Tiger Tiger = new Tiger("Tigris", 7, "Orange", "Linear", 4);
		animalList.add(Tiger);
		
		int choice = 0;
		do {
			System.out.println("1. View all animals");
			System.out.println("2. View all Tiger");
			System.out.println("3. View Chicken");
			System.out.println("4. Delete Animal");
			
			
			System.out.println("Input choice: ");
			choice = scan.nextInt();
			scan.nextLine();
			switch(choice) {
			case 1:
				viewAllAnimal();
				break;
			case 2: 
				viewAllTiger();
				break;
			case 3: 
				viewAllChicken();
				break;
			case 4:
				deleteAnimal();
				break;
			}
			scan.close();
			
		}while(choice < 1 || choice > 4);
		
		
		Chicken.move();
		Chicken.eatGrass();
	}
	
	public void deleteAnimal() {
		
		for (Animal animal : animalList) {
			System.out.println("-> ["+ animal.getName() + "]"
					+ "["+ animal.getColor() + "]");

		}
		System.out.println("Type the name of the animal that you want to delete: ");
		String name = scan.nextLine();
		for (int i = animalList.size() - 1; i >= 0; i--) {
			if(animalList.get(i).getName().equals(name))
				animalList.remove(i);
		}
		System.out.println("After deletion: ");
		for (Animal animal : animalList) {
				System.out.println("-> ["+ animal.getName() + "]"
						+ "["+ animal.getColor() + "]");
		}
		new Main();
		
		
	}

	public void viewAllTiger() {
		for (Animal animal : animalList) {
			if (animal instanceof Tiger) {
				System.out.println("-> ["+ animal.getName() + "]"
						+ "["+ animal.getColor() + "]");
			}
		}
		new Main();
		
	}
	
	public void viewAllChicken() {
		for (Animal animal : animalList) {
			if (animal instanceof Chicken) {
				System.out.println("-> ["+ animal.getName() + "]"
						+ "["+ animal.getColor() + "]");
			}
		}
		new Main();
	}

	public void viewAllAnimal() {
		for (Animal animal : animalList) {
			System.out.println("-> ["+ animal.getName() + "]"
					+ "["+ animal.getColor() + "]");
		}
		new Main();
	}
	

	public static void main(String[] args) {
		new Main();
		
	}

}

//[Overloading -> 
//	> Nama metgid sama tapi parameternya beda

//[Abstraction concept]
//	Bluepint untuk class

//Abstract method
//	Dia nggak punya isi
//	Wajib unuk diturunkan ke sub class

//Interface
// > Untuk menetapkan rules (dalam bentuk ,method yang dimiliki oleh sbuah klas, rules sbuah klas yang di bawah ini)






//Animal= 
//Name ->  
//Age -> 
//Color ->

