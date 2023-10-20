package javasesi4;

public class animal {

	String name;
	int age;
	static String warnaKulit; //static only stay in their class, cannot be inherited (in this case the class animal)
	

//	public private protected = nggak bisa di turunin
	
	public animal(String name, int age) {
		this.name = name;
		this.age = age; //this. is for the variable in class, not in aarameters
	}
	
	public void eat() {
		System.out.println("Eat.......");
		
	}
	
	public static void bengong() {
		System.out.println("Melamun.....");
	}


}
