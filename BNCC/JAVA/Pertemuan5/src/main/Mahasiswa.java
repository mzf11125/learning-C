package main;

public class Mahasiswa extends Manusia{
	private String nim;
	
	@Override
	public void perkenalanDiri() {
		// TODO Auto-generated method stub
		super.perkenalanDiri();
	}
	
	public Mahasiswa(String nama, int umur, String gender) {
		super(nama, umur, gender); 
		this.nim = nim;
	}
	
	public String getNim() {
		return nim;
	}

	public void setNim(String nim) {
		this.nim = nim;
	}



}
