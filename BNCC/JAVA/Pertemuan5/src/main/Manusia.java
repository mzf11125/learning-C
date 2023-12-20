package main;

//Final class tidak bis di extends oleh class lain
public final class Manusia{
	//Encapsulation -> Membungkus data dalam kelas dengan cara membuat semua atribut menjadi privat
	//Membuat getter dan setter untuk semua attribut
	
	private String nama;
	private int umur;
	private String gender;

	public Manusia(String nama, int umur, String gender) {
//		super();
		this.nama = nama;
		this.umur = umur;
		this.gender = gender;
	}

	//Final void tidak boleh di ubah oleh child
	public void perkenalanDiri() {
		
		
		System.out.println("Halo! Nama saya " + nama + ". Saya umur" + umur + "." + gender);
	}
	
	public String getNama() {
		return nama;
	}
	
	public void setNama(String nama) {
		this.nama = nama;
		
	}

	public int getUmur() {
		return umur;
	}

	public void setUmur(int umur) {
		this.umur = umur;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}
}
