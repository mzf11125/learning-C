package main;

public class Counter {

	int C;
	
	public Counter(int C) {
		super();
		this.C = C;
	}
	public synchronized void increment() {
		C++;
//		Mutex --> Mutual exclusion
//		Satu objek mutual
		C = C +1;
		

	}

}
