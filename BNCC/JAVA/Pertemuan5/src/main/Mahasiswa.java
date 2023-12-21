package main;

public class Mahasiswa extends Manusia{
	private String nim;
	
	@Override  //Method in parent parent but different tasks or functions
	public void perkenalanDiri() {
		// TODO Auto-generated method stub
		super.perkenalanDiri();
	}
	
	public Mahasiswa(String nama, int umur, String gender) {
		this.nim = nim;
		super(nama, umur, nim, gender); 

	}
	
	public String getNim() {
		return nim;
	}

	public void setNim(String nim) {
		this.nim = nim;
	}



}
