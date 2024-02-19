package main;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class logic {
    private ArrayList<karyawan.Karyawan> daftarKaryawan = new ArrayList<>();
    private Map<String, Integer> countJabatan = new HashMap<>();
    private final double BONUS_MANAGER = 0.10;
    private final double BONUS_SUPERVISOR = 0.075;
    private final double BONUS_ADMIN = 0.05;

    Scanner input = new Scanner(System.in);
    // Method to insert data karyawan
    public void insertDataKaryawan() {

        // Input data karyawan
        System.out.println("Masukkan kode karyawan (format: MM-XXXX): ");
        String kodeKaryawan = input.nextLine();

        // Validasi kode karyawan 
        while (kodeKaryawanExists(kodeKaryawan)) {
            System.out.println("Kode karyawan sudah ada. Masukkan kode karyawan lain: ");
            kodeKaryawan = input.nextLine();
        }

        System.out.println("Masukkan nama karyawan (minimal 3 huruf): ");
        String namaKaryawan = input.nextLine();

        // Validasi nama karyawan minimal 3 huruf
        while (namaKaryawan.length() < 3) {
            System.out.println("Nama karyawan minimal terdiri dari 3 huruf. Masukkan nama karyawan lagi: ");
            namaKaryawan = input.nextLine();
        }

        System.out.println("Masukkan jenis kelamin (Laki-Laki / Perempuan): ");
        String jenisKelamin = input.nextLine();

        // Validasi jenis kelamin
        while (!jenisKelamin.equals("Laki-Laki") && !jenisKelamin.equals("Perempuan")) {
            System.out.println("Jenis kelamin tidak valid. Masukkan jenis kelamin lagi (Laki-Laki / Perempuan): ");
            jenisKelamin = input.nextLine();
        }

        System.out.println("Masukkan jabatan (Manager / Supervisor / Admin): ");
        String jabatan = input.nextLine();

        // Validasi jabatan
        while (!jabatan.equals("Manager") && !jabatan.equals("Supervisor") && !jabatan.equals("Admin")) {
            System.out.println("Jabatan tidak valid. Masukkan jabatan lagi (Manager / Supervisor / Admin): ");
            jabatan = input.nextLine();
        }

        double gaji = 0;

        // Menghitung gaji berdasarkan jabatan
        switch (jabatan) {
            case "Manager":
                gaji = 8000000;
                break;
            case "Supervisor":
                gaji = 6000000;
                break;
            case "Admin":
                gaji = 4000000;
                break;
        }

        // Menambahkan karyawan ke dalam jumlah karyawan
        karyawan.Karyawan karyawan = new karyawan().new Karyawan(kodeKaryawan, namaKaryawan, jenisKelamin, jabatan, gaji);
        daftarKaryawan.add(karyawan);

        // Update berapa banyak jabatan yang ada
        countJabatan.put(jabatan, countJabatan.getOrDefault(jabatan, 0) + 1);

        // Mengecek apakah perlu memberikan bonus
        checkAndGiveBonus(jabatan);
    }

    // Method untuk melihat data karyawan
    public void viewDataKaryawan() {
        if (daftarKaryawan.isEmpty()) {
            System.out.println("Belum ada data karyawan.");
        } else {
            Collections.sort(daftarKaryawan, Comparator.comparing(karyawan.Karyawan::getNamaKaryawan));
            for (karyawan.Karyawan karyawan : daftarKaryawan) {
                System.out.println("Kode Karyawan: " + karyawan.getKodeKaryawan());
                System.out.println("Nama Karyawan: " + karyawan.getNamaKaryawan());
                System.out.println("Jenis Kelamin: " + karyawan.getJenisKelamin());
                System.out.println("Jabatan: " + karyawan.getJabatan());
                System.out.println("Gaji: Rp " + karyawan.getGaji());
                System.out.println();
            }
        }
    }

    // Method untuk mengupdate data karyawan
    public void updateDataKaryawan() {
        if (daftarKaryawan.isEmpty()) {
            System.out.println("Belum ada data karyawan.");
            return;
        }

        System.out.println("===== Data Karyawan =====");
        Collections.sort(daftarKaryawan, Comparator.comparing(karyawan.Karyawan::getNamaKaryawan));
        for (int i = 0; i < daftarKaryawan.size(); i++) {
            karyawan.Karyawan karyawan = daftarKaryawan.get(i);
            System.out.println((i + 1) + ". " + karyawan.getNamaKaryawan());
        }
        System.out.println("==========================");
        System.out.print("Pilih nomor karyawan yang ingin diupdate (0 untuk batal): ");
        int choice = input.nextInt();
        input.nextLine(); 

        if (choice < 0 || choice > daftarKaryawan.size()) {
            System.out.println("Pilihan tidak valid.");
            return;
        }

        if (choice == 0) {
            System.out.println("Update data karyawan dibatalkan.");
            return;
        }

        karyawan.Karyawan karyawan = daftarKaryawan.get(choice - 1);
        System.out.println("Masukkan kode karyawan (format: MM-XXXX) atau 0 untuk mempertahankan yang lama: ");
        String kodeKaryawan = input.nextLine();
        if (!kodeKaryawan.equals("0")) {
            karyawan.setKodeKaryawan(kodeKaryawan);
        }

        System.out.println("Masukkan nama karyawan (minimal 3 huruf) atau 0 untuk mempertahankan yang lama: ");
        String namaKaryawan = input.nextLine();
        if (!namaKaryawan.equals("0") && namaKaryawan.length() >= 3) {
            karyawan.setNamaKaryawan(namaKaryawan);
        }

        System.out.println("Masukkan jenis kelamin (Laki-Laki / Perempuan) atau 0 untuk mempertahankan yang lama: ");
        String jenisKelamin = input.nextLine();
        if (!jenisKelamin.equals("0")) {
            karyawan.setJenisKelamin(jenisKelamin);
        }

        System.out.println("Masukkan jabatan (Manager / Supervisor / Admin) atau 0 untuk mempertahankan yang lama: ");
        String jabatan = input.nextLine();
        if (!jabatan.equals("0")) {
            karyawan.setJabatan(jabatan);
            // Update jumlah jabatan
            countJabatan.put(jabatan, countJabatan.getOrDefault(jabatan, 0) + 1);
            // Mengecek apakah perusahaan perlu memberikan bonus
            checkAndGiveBonus(jabatan);
        }

        System.out.println("Masukkan gaji karyawan atau 0 untuk mempertahankan yang lama: ");
        double gaji = input.nextDouble();
        input.nextLine(); 
        if (gaji != 0) {
            karyawan.setGaji(gaji);
        }

        System.out.println("Data karyawan berhasil diupdate.");
    }

    // Method untuk delete data karyawan
    public void deleteDataKaryawan() {
        if (daftarKaryawan.isEmpty()) {
            System.out.println("Belum ada data karyawan.");
            return;
        }

        System.out.println("===== Data Karyawan =====");
        Collections.sort(daftarKaryawan, Comparator.comparing(karyawan.Karyawan::getNamaKaryawan));
        for (int i = 0; i < daftarKaryawan.size(); i++) {
            karyawan.Karyawan karyawan = daftarKaryawan.get(i);
            System.out.println((i + 1) + ". " + karyawan.getNamaKaryawan());
        }
        System.out.println("==========================");
        System.out.print("Pilih nomor karyawan yang ingin dihapus (0 untuk batal): ");
        int choice = input.nextInt();
        input.nextLine(); 

        if (choice < 0 || choice > daftarKaryawan.size()) {
            System.out.println("Pilihan tidak valid.");
            return;
        }

        if (choice == 0) {
            System.out.println("Penghapusan data karyawan dibatalkan.");
            return;
        }

        karyawan.Karyawan karyawan = daftarKaryawan.remove(choice - 1);
        System.out.println("Data karyawan berhasil dihapus: " + karyawan.getNamaKaryawan());
    }

    // Method untuk mengecek apakah kode karyawan sudah ada
    private boolean kodeKaryawanExists(String kodeKaryawan) {
        for (karyawan.Karyawan karyawan : daftarKaryawan) {
            if (karyawan.getKodeKaryawan().equals(kodeKaryawan)) {
                return true;
            }
        }
        return false;
    }

    // Method untuk mengecek apakah perusahaan perlu memberikan bonus atau tidak
    private void checkAndGiveBonus(String jabatan) {
        int count = countJabatan.getOrDefault(jabatan, 0);
        if (count % 3 == 0) {
            for (karyawan.Karyawan karyawan : daftarKaryawan) {
                if (karyawan.getJabatan().equals(jabatan)) {
                    double bonus = 0;
                    switch (jabatan) {
                        case "Manager":
                            bonus = karyawan.getGaji() * BONUS_MANAGER;
                            break;
                        case "Supervisor":
                            bonus = karyawan.getGaji() * BONUS_SUPERVISOR;
                            break;
                        case "Admin":
                            bonus = karyawan.getGaji() * BONUS_ADMIN;
                            break;
                    }
                    karyawan.setGaji(karyawan.getGaji() + bonus);
                }
            }
        }
    }
}
