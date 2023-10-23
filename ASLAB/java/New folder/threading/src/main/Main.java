package main;
//This is the file for multithreading

import java.util.Vector;

import food.Food;
import food.MyThread;
import food.NasiUduk;
import food.Sushi;

public class Main {
	
	public static Counter counter = new Counter(0);

	public Main() {
		
	}

	public static void main(String[] args) {
//		new Main();
		MyThread t1 = new MyThread();
		t1.start();
		
		MyThread t2 = new MyThread();
		t2.start();
		
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		System.out.println(counter.C);
		
		
//		Vector<Food> foods = new Vector<>();
//		NasiUduk nu1 = new NasiUduk(5, 5, "Nasi Uduk punya Vito", 50, t2);
//		foods.add(nu1);
//		for (Food food : foods) {
//			Thread t3 = new Thread(nu1);
//			t3.start();
//		}
//		
//		Sushi s1 = new Sushi(15, "Sushi ikan lele", 200, "Lele");
		
	}

}


//Foood(I'm hungry)
// int cooing
// int price
// string name

//Sushi
//




//Nasi uduk
//


//Synchronize 
