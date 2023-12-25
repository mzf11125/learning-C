package main;

import abstraction.Kendaraan;
import abstraction.Mobil;
import abstraction.Motor;

public class Main {

	public Main() {
		
		
		//Method overloading
		
//		dokter.bicara("Sata seorang dokter jantung");
		
		Mobil mobil = new Mobil(); 
		mobil.start();
		mobil.go();
		mobil.stop();

		Motor motor = new Motor();
		motor.start();
		motor.go();
		motor.stop();

		Kendaraan mobil2 = new Mobil();
		Mobil tampung = (Mobil) mobil2;
		tampung.bukaPintu();
		((Mobil)mobil2).bukaPintu();
	}

	public static void main(String[] args) {
		new Main();

	}

}
