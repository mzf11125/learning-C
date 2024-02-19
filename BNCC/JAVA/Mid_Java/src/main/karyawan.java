package main;

public class karyawan {

	public class Karyawan {
	    private String kodeKaryawan;
	    private String namaKaryawan;
	    private String jenisKelamin;
	    private String jabatan;
	    private double gaji;
	    

	    // Constructor
		public Karyawan(String kodeKaryawan, String namaKaryawan, String jenisKelamin, String jabatan, double gaji) {
			super();
			this.kodeKaryawan = kodeKaryawan;
			this.namaKaryawan = namaKaryawan;
			this.jenisKelamin = jenisKelamin;
			this.jabatan = jabatan;
			this.gaji = gaji;
		}


		public String getKodeKaryawan() {
			return kodeKaryawan;
		}


		public void setKodeKaryawan(String kodeKaryawan) {
			this.kodeKaryawan = kodeKaryawan;
		}


		public String getNamaKaryawan() {
			return namaKaryawan;
		}


		public void setNamaKaryawan(String namaKaryawan) {
			this.namaKaryawan = namaKaryawan;
		}


		public String getJenisKelamin() {
			return jenisKelamin;
		}


		public void setJenisKelamin(String jenisKelamin) {
			this.jenisKelamin = jenisKelamin;
		}


		public String getJabatan() {
			return jabatan;
		}


		public void setJabatan(String jabatan) {
			this.jabatan = jabatan;
		}


		public double getGaji() {
			return gaji;
		}


		public void setGaji(double gaji) {
			this.gaji = gaji;
		}
	}


}
