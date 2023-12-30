#include <stdio.h>
#include <string.h>

// struct pointer ada jg di file yg satu lagi

struct MenuMakanan{
	char namaMenu[100];
	int harga;
};

void isiMenu(struct MenuMakanan *menu1){
	
	strcpy(menu1->namaMenu, "Nasi Goreng");	// klo pointer pke -> bukan .
	menu1->harga = 50000;
	
}

int main(){
	
	struct MenuMakanan mn1;
	
	isiMenu(&mn1);
	printf("Menu 1 adalah %s dengan harga %d\n", mn1.namaMenu, mn1.harga);
	
	return 0;
}
