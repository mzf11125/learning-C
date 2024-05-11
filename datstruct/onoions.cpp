// NAMA: saleh muhammad
// NIM: 2702303091
// AOL DATA STRUCTURE
#include <stdio.h>		// Library ini di gunakan untuk operasi input-output
#include <string.h>		// Library ini untuk menyediakan fungsi-fungsi untuk manipulasi string 
#include <stdlib.h>		// Library  ini untuk ini berisi fungsi-fungsi untuk alokasi memori 
#include <windows.h>	// Library ini untuk header khusus yang berisi fungsi-fungsi khusus untuk sistem operasi Windows


// Menetapkan ukuran array untuk menyimpan anak-anak setiap  Trie
#define ALphabet 26

// Struktur yang digunakan untuk merepresentasikan dalam trie
struct TrieNode{

// Membuat sebuah array pointer ke struct Nodetrie untuk menyimpan anak-anak node, dengan jumlah sesuai dengan ALphabet
	struct TrieNode *childNodes[ALphabet];
	
	// Penanda apakah node saat ini adalah akhir dari sebuah kata dalam Trie
	int kataAkhir;
	// Digunakan untuk menyimpan deskripsi yang terkait dengan slang yang disimpan dalam Trie
	char definition[255];		
}*root; // membuat variable pointer yang menunjuk ke akar Node 

// untuk variable struct pointer yang berfungsi untuk trie dari struct (TrieNode)
struct TrieNode *buatNode(){ 
	//melakukan alokasi memori untuk node baru 
	struct TrieNode *newNode = (TrieNode*)malloc(sizeof(TrieNode));
	//Inisialisasi bahwa akhir kata tidak tercapai (0 menandakan tidak akhir kata)
	newNode->kataAkhir = 0;
	//Melakukan loop untuk mengatur setiap elemen dari array pointer struct *childNodes menjadi NULL (tidak terisi)
	for(int i = 0; i< ALphabet;i++){
		newNode->childNodes[i] = NULL;
	}
	
	return newNode; // untuk mengembalikan node bru
}
// fungsi 'masukanData' bertanggung jawab untuk memasukkan data ke dalam trie (slang)
struct TrieNode *masukanData(TrieNode *root, char slang[], char definition []){
	//kalo misalnya root masih kosong, maka kita membuat root baru
	if(root == NULL){
		root = buatNode();
	}
	// variable *curr adalah variable yang berfungsi untuk traversal dalam Trie
	struct TrieNode *curr = root;
	// variable length berfungsi untuk menapung panjang kata slang
	int length = strlen(slang);
	
	//for loop berfungsi untuk mengakses masing-masing index string slang
	for(int i = 0; i< length; i++){
		
		//Variable menjadi patokan posisi insert ke dalam index childNodes[]
		int index;
		
		//if-else digunakan untuk memvalidasi apakah huruf dalam input adalah huruf kapital atau huruf kecil
		if(slang[i] >= 'a' && slang[i] <='z'){
			index = slang[i] - 'a';
		}
		else if(slang[i] >= 'A' && slang[i] < 'Z'){
			index = slang[i] - 'A';
		}
		
		//kalo misalnya data pada childNodes[index] masih kosong, maka dibuat node baru
		if(curr->childNodes[index] == NULL){
			curr->childNodes[index] = buatNode();
		}
		
		//Pindahkan posisi curr (posisi sekarang) ke childNodes[index]
		curr = curr->childNodes[index];
	}
	
	
	//If-else statement untuk mengecek kalo slang yang kita input sudah pernah diinput
	if(curr->kataAkhir == 1){
		puts("");
		puts("Successfully updated a slang word.");
		printf("Press Enter to continue..."); getchar();
	}
	else{
		puts("");
		puts("Successfully released a new slang word.");
		printf("Press Enter to continue..."); getchar();
	}
	
	//Memberitau bahwa posisi sekarang (curr) adalah akhir dari sebuah kata slang
	curr->kataAkhir = 1;
	
	//Memasukkan definition slang ke posisi sekarang yaitu (curr)
	strcpy(curr->definition, definition);
	
	return root; // kembalikan return value root (akar)
	
}
//Variable struct pointer yang digunakan untuk mencari data (slang) di dalam Trie
struct TrieNode *search(TrieNode * root, char slang[]){
	
	//kalo root kosong maka kembali ke NULL
	if(root == NULL){
		return NULL;
	}
	//Variabel 'curr' digunakan untuk melakukan perjalanan melalui Trie.
	struct TrieNode *curr = root;
	//Variabel length digunakan untuk mendapatkan jumlah karakter dalam string slang.
	int length = strlen(slang);
	//Variabel index digunakan untuk mengakses indeks dalam array childNodes[].
	int index;
	
	// for loop panjang string length
	for(int i = 0; i< length; i++){
		
		//If-else statement untuk validasi jika kalo ada huruf kapital atau huruf kecil saat input
		if(slang[i] >= 'a' && slang[i] <= 'z'){
			index = slang[i] - 'a';
		}
		else if (slang[i] >= 'A' && slang[i] <= 'Z'){
			index = slang[i] - 'A';
		}
		
		// Jika pada childNodes[index] kosong, maka kata tidak ada, kembalikan NULL
		if(curr->childNodes[index] == NULL){
			return NULL;
		}
		
		// pindahkan posisi sekarang ke childNodes[index]
		curr = curr->childNodes[index];
	}
	
	
	//Kalo misalnya kataAkhir == 1 maka sudah di akhiran kata dan benar ada slang tersebut
	if(curr->kataAkhir == 1){
		return curr; // kembali ke node sekarang ke (curr)
	}
	else{
		return NULL; // kalo tidak maka kembali ke NULL (tidak ke temu)
	}
}

//Function untuk mengecek apakah Trie kosong atau tidak
int checkTrieKosong(TrieNode *root){
	
	if(root == NULL){
		return 0; // balikan ke 0 berati kosong
	}
	else{
		return 1; // balikan ke 1 berati ada isinya
	}
}

// Variable number hanya digunakan untuk penomoran saat display output
int number = 1;

//Function displayAll untuk men-display output semua slang yang ada dalam Trie
void displayAll(TrieNode *root, char slangs[], int index){
	
	if(root == NULL){ // kalo root kosong maka kembali ke NULL
		return;
	}
	// variable 'curr' adalah ponter yg  digunakan untuk traversal trie yang di mualai dari (root)
	struct TrieNode *curr = root;
	// jika misalnya curr akan mengecek apakah node saat ini menandakan akhir dari sebuah kata dalam Trie. 
	if(curr->kataAkhir == 1){
		slangs[index] = '\0';
		printf("%d. %s\n", number, slangs);
		number++;
	}
	// for loop digunakan untuk iterasi melalui childNodes  loop tersebut memeriksa setiap child node untuk menentukan apakah ada node yang tidak kosong (berisi data) dalam Trie
	for(int i = 0; i < ALphabet; i++){
	// pada bagian ini childNodes yg tidak kosong pada indeks ke -i index sebesar 1 untuk menunjukkan posisi selanjutnya dalam array slangs. Ini memungkinkan penelusuran semua cabang dalam Trie
	   if(curr->childNodes[i] != NULL){
	   	slangs[index] = 'a' + i;
	   	displayAll(curr->childNodes[i], slangs, index+1);
	   }	
	}
}
//Function displayPrefix untuk menyipan pointer akar Trie yang akan digunakan sebagai awal untuk pencarian kata-kata yang dimulai dengan prefix
void displayPrefix(TrieNode *root, char prefix[]){
	// Variabel 'curr' digunakan untuk melakukan perjalanan melalui Trie.
	struct TrieNode *curr = root;
	//Variabel length digunakan menapung panjang kata (prefix)
	int length = strlen(prefix);
	char temp[255]; //variable 'temp' digunakan untuk menyipan salinan prefix
	int index;// Variabel index digunakan untuk menunjukkan indeks dalam array childNodes yang akan diakses saat mencari atau menelusuri Trie
	// variable strncpy akan mengambil (length) karakter pertama yaitu 'prefik' temp sekarang berisi prefix yang akan dicari dalam Trie.
	strncpy(temp, prefix, length);
	temp[length] = '\0'; 
	// for loop length adalah panjang dari string prefix untuk memeriksa setiap karakter dalam string prefix.
	for(int i = 0; i < length; i++){
		//If-else statement untuk validasi jika kalo ada huruf kecil atau huruf kapital saat input
		if(prefix[i] >= 'a' && prefix[i] <= 'z'){
			index = prefix[i] - 'a';
		}
		else if(prefix[i] >= 'A' && prefix[i] <= 'Z'){
			index = prefix[i] - 'A';
		}
		
		// jika childNodes[index] sesaui dengan prefix kalo tidak ada berarti bahwa prefix yang sedang dicari tidak ada dalam 
		if(curr->childNodes[index] == NULL){
			printf("There is no prefix \"%s\" in the dictionary.\n", prefix);
			printf("Press Enter to continue..."); getchar();
			return;
		}
		// pindahkan posisi sekarang ke childNodes[index]
		curr = curr->childNodes[index];
	}
	// fungsidisplayPrefix yang bertanggung jawab untuk menampilkan pesan bahwa kata-kata dimulai dengan awalan tertentu
	printf("Words starts with \"%s\":\n", prefix);
	displayAll(curr, temp, length);
	printf("Press Enter to continue..."); getchar();
	
}
// main berfungsi untuk mempanggil fungsi-fungsi lain
int main (){
	
	int choice = 0;// variabel chouce digunakan untuk menyimpan pilihan yg dimasukkan pengguna melalui input
	char slangs[255];// variable slangs digunakan untuk menyimpan string yg merupakan slang word
	char definition[255];// variabel definition untuk  menyimpan definisi slang word yang dimasukkan oleh pengguna
	//variabel while bertujuan untuk terus terus berjalan selama choice tidak sama dengan 5
	while(choice != 5){
		// variable system("cls") digunakan untuk membersihkan layar konsol sebelum menampilkan menu
		system("cls");
		// pust 1 sampai 'enter choice' digunakan untuk meminta pengguna memasukkan pilihan mereka. 
		puts("1. Release a new slang word");
		puts("2. Search a slang word");
		puts("3. View all slang words starting with a certain prefix word");
		puts("4. View all slang words");
		puts("5. Exit");
		printf("Enter choice: ");
		scanf("%d", &choice); getchar();// scanf digunakan untuk mengambil input angka yang mempresentasikan pilihan menu 
		// getchar() digunakan untuk membersihkan buffer input.
		
		puts("");
		puts("");
		switch(choice){ // variable switch(choice) digunakan untuk memilih tindakan yang sesuai berdasarkan pilihan pengguna yang dimasukkan sebelumnya
			case 1:{// case 1 merupakan bagian dari switch statement yang mengatur tindakan yang akan diambil berdasarkan pilihan pengguna
				
				int checkSpace = 0;// variabel 'checkSpace' digunakan untuk memeriksa apakah kata slang atau definisi yang dimasukkan mengandung spasi.
				int length;// Variabel length digunakan untuk menyimpan panjang kata slang atau definisi.
				
				do{//  variable do Ini adalah loop do-while yang memungkinkan pengguna untuk memasukkan kata slang dan definisi sampai masukan yang valid diberikan
					
					checkSpace = 0; // // Variabel checkSpace diatur kembali ke 0 untuk memulai pengujian dari awal.
					// variable printf digunakan untuk membaca string dari input pengguna hingga karakter newline (\n) ditemukan, yang berarti akan membaca seluruh baris yang dimasukkan pengguna kecuali newline tersebut. Ini memungkinkan pengguna untuk memasukkan kata slang yang mungkin mengandung spasi.
					printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
					scanf("%[^\n]", &slangs); getchar();
					
					length = strlen(slangs); // variable strlen(slangs) kita dapat mengetahui panjang string slangs, yang nantinya akan digunakan untuk melakukan validasi terhadap panjang kata slang yang dimasukkan.
					
					for(int i = 0; i < length; i++){// Di dalam loop pertama, pengguna diminta untuk memasukkan kata slang. Loop tersebut akan terus berjalan sampai kondisi di dalam while terpenuhi
						if(slangs[i] == ' '){
							checkSpace = 1;
							break;// Ini digunakan untuk keluar dari blok case 1 setelah operasi pemasukan kata slang selesai dilakukan
						}
					}
			     //checkSpace == 1: Memeriksa apakah kata slang mengandung spasi / length == 1: Memastikan kata slang memiliki lebih dari satu karakter./ length == 0: Memastikan kata slang tidak kosong
				}while(checkSpace == 1 || length == 1 || length == 0);
				
				
				checkSpace = 0; // Variabel checkSpace diatur kembali ke 0 untuk memulai pengujian dari awal.
				
				do{// variable do Ini adalah loop do-while yang memungkinkan pengguna untuk memasukkan kata slang dan definisi sampai masukan yang valid diberikan
					
					checkSpace = 0;//Variabel checkSpace diatur kembali ke 0 untuk memulai pengujian dari awal.
					// fungsin printf di bawah ini menampilkan pesan kepada pengguna yang memberitahu mereka untuk memasukkan definisi baru. Pesan tersebut memberikan pedoman bahwa definisi harus terdiri dari lebih dari dua kata.
					printf("Input a new slang word definition [Must be more than 2 words]: ");
					scanf("%[^\n]", &definition); getchar();
					
					length = strlen(definition); // digunakan untuk menghitung panjang dari string definition
					
					for(int i = 0; i < length; i++){//Di dalam loop kedua, pengguna diminta untuk memasukkan definisi slang. Loop tersebut akan terus berjalan sampai kondisi di dalam while terpenuhi
						if(definition[i] == ' '){
							checkSpace++;
						}
					}
				// variable tersebut akan terus berjalan selama salah satu dari kondisi tersebut tidak terpenuhi 						
				}while(checkSpace < 2 || (checkSpace == 2 && definition[length-1] == ' ') || length == 0);
				//fungsi masukanData dengan argumen root, slangs, dan definition, dan kemudian mengatur kembali nilai root sesuai dengan hasil yang dikembalikan oleh fungsi tersebut.
				root = masukanData (root, slangs, definition);
				
				break;// variable break Ini digunakan untuk keluar dari blok case 1 setelah operasi pemasukan kata slang selesai dilakukan
			}
			case 2:{// case 2  tersebut bertujuan untuk mencari kata slang yang sudah dibuat. 
				
				char searchFor[255]; // Variabel searchFor digunakan untuk menyimpan kata slang yang ingin dicari oleh pengguna.
				int checkSpace = 0; // Variabel checkSpace digunakan untuk memeriksa apakah kata slang yang dimasukkan oleh pengguna mengandung spasi.
				int length; // Variabel length digunakan untuk menyimpan panjang kata slang yang dimasukkan oleh pengguna.
				
				do{ // Loop do-while digunakan untuk memastikan bahwa input yang dimasukkan oleh pengguna memenuhi kriteria tertentu sebelum melanjutkan ke langkah selanjutnya
					
					checkSpace = 0;// Variabel checkSpace diatur ulang ke nilai 0 untuk memulai pengujian dari awal
					//printf di bawah ini  ditampilkan kepada pengguna untuk meminta mereka memasukkan kata slang yang ingin dicari
					printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
					scanf("%[^\n]", &searchFor); getchar();
					// length = strlen(searchFor); digunakan untuk menghitung panjang string yang dimasukkan oleh pengguna ke dalam variabel searchFor
					length = strlen(searchFor);
					// for loop  ini mengiterasi melalui setiap karakter dalam string searchFor Jika ditemukan spasi, variabel checkSpace diatur ke 1, menandakan bahwa string searchFor
					for(int i = 0; i < length; i++){
						if(searchFor[i] == ' '){
							checkSpace = 1;
							break; // break digunakan untuk keluar dari loop for
						}
					}
				//while tersebut mengecek apakah checkSpace sama dengan 1 atau length sama dengan 1
				}while(checkSpace == 1 || length == 1);
				
				// pada baris ini, sebuah fungsi pencarian (search) dipanggil dengan dua argumen: root yg merupakan pointer searchFor, yang merupakan kata slang yang ingin dicari dalam trie.
				struct TrieNode *found = search(root, searchFor);
				// jika kata slang ditemukan akan mencetak kata slang beserta definisinya				
				if(found == NULL){
					printf("There is no word \"%s\" in the dictionary.\n", searchFor);
					printf("Press Enter to continue..."); getchar();
				}
				else{ // Jika tidak ditemukan, program akan memberi tahu pengguna bahwa kata tersebut tidak ada dalam kamus
					printf("Slang word	: %s\n", searchFor);
					printf("definition	: %s\n", found->definition);
					puts("");
					printf("Press Enter to continue..."); getchar();
				}
				
				
				break; // menanadakan akhir dari blok case
			}
			case 3:{// case 3 bertujuan untuk mencari dan menampilkan semua kata slang yang dimulai dengan sebuah awalan tertentu (prefix)
				
				char prefix[255]; // variable prefix digunakan untuk menyimpan prefix yang dimasukkan oleh pengguna untuk mencari kata slang yang dimulai dengan prefix yang diberikan
				printf("Input a prefix to be searched: "); // digunakan untuk menampilkan pesan instruksi kepada pengguna untuk memasukkan prefix
				scanf("%[^\n]", &prefix); getchar();// scanf digunakan untuk membaca string hingga karakter newline// getchar digunakan untuk membersihkan newline yang tersisa di input buffer.
				puts(""); // digunakan untuk menambahkan baris kosong setelah pengguna memasukkan prefix.
				
				number = 1;//Variabel number diatur kembali ke 1 menampilkan daftar kata-kata yang dimulai dengan prefix tertentu. 
				displayPrefix(root, prefix);//Ini digunakan untuk menampilkan semua kata-kata dalam Trie yang dimulai dengan prefix yang diberikan.
				
				break; // menandakan akhir dari blok case
			}
			case 4:{// case 4 menampilkan daftar semua kata slang dalam kamus
				
				number = 1; //ariabel number dengan nilai 1 sebelum menampilkan daftar semua kata slang dalam kamus
				int checkIfEmpty = checkTrieKosong(root);// rogram memanggil fungsi checkTrieKosong() untuk memeriksa apakah kamus slang kosong atau tidak
				//Jika kosong, program menampilkan pesan bahwa tidak ada kata slang dalam kamus dan menunggu pengguna menekan tombol Enter
				if(checkIfEmpty == 0){
					puts("There is no slang word yet in the dictionary.");
					printf("Press Enter to continue..."); getchar();
				}//ika tidak kosong, program menampilkan daftar semua kata slang dalam kamus dan menunggu pengguna menekan tombol Enter 
				else if(checkIfEmpty == 1){
					puts("List of all slang words in the dictionary:");
					displayAll(root, slangs, 0);
					
					puts("");
					printf("Press Enter to continue..."); getchar();
				}
				
				break; // digunakan untuk keluar dari blok case 4
			}
			case 5:{ //Dalam case 5, yang dimasukkan adalah pernyataan "Thank you... Have a nice day :)
				printf("Thank you... Have a nice day :)");// mencetak pesan "Thank you... Have a nice day :)" ke layar sebagai pesan penutup sebelum program berakhir.
				break;// reak digunakan untuk keluar dari switch case dan melanjutkan eksekusi kode setelah switch case tersebut. 
			}
			default:{ // default digunakan ketika tidak ada kondisi dari case yang cocok dengan nilai yang dievaluasi dalam switch
				printf("Wrong choice, please try again!"); getchar();// jika pilihan yg di masukan tidak cocok dengan pesan untuk mencoba lagi
				break;// digunakan untuk menghentikan eksekusi dari blok switch
			}
		}
		
		
	}
	
	return 0; // untuk mengakhiri eksekusi program dan mengembalikan nilai 0
}




		