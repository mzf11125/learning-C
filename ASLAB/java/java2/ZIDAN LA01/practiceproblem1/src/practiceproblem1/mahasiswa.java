package practiceproblem1;

public class mahasiswa extends Main{
	private String nama;
	private int umur;
	private String nim;
	
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

	public String getNim() {
		return nim;
	}

	public void setNim(String nim) {
		this.nim = nim;
	}

	public mahasiswa(String nama, int umur, String nim) {
		super();
		this.umur = umur;
		this.nim = nim;
	}
	
	
	
	
	
	

}
