#include<stdio.h> 
#include<string.h>

struct Database {
    char location[101];
    char location2[101];
    long int price;
    long int rooms;
    long int bathroom;
    long int park;
    char type[105];
    char furnish[101];
} DB[9999];

void scan(FILE* fd, struct Database DB[], int &idx) {
    char unused[1001];
    fscanf(fd, "%[^\n]\n", &unused);
    while(!feof(fd)) {
	    fscanf(fd, "%[^,],%[^,],%ld,%ld,%ld,%ld,%[^,],%[^\n]\n", &DB[idx].location, &DB[idx].location2, &DB[idx].price, &DB[idx].rooms, &DB[idx].bathroom, &DB[idx].park, &DB[idx].type, &DB[idx].furnish);
		idx++;
    }
}

void search(char Column[], struct Database DB[], int idx) {
	
	char input[101];
	
	
	//LOCATION SEARCH
	if(strcmp(Column,"Location")==0) {
		
		printf("What data do you want to find? ");
		scanf("%s", &input); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(strcmp(input, DB[i].location)==0){
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			} 
		}
		
		if(ind==1){
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(strcmp(input, DB[i].location)==0){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		} 
		//CITY
	} else if (strcmp(Column, "City")==0) {
		
		printf("What data do you want to find? ");
		scanf("%s", &input); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(strcmp(input, DB[i].location2)==0) {
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			}
		}
		
		if(ind==1) {
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(strcmp(input, DB[i].location2)==0){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		}
		//PRICE
	} else if(strcmp(Column, "Price")==0) {
		long int inputnum;
		printf("What data do you want to find? ");
		scanf("%ld", &inputnum); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(inputnum == DB[i].price){
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			} 
		}
		
		if(ind==1){
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(inputnum == DB[i].price){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		}
		//ROOMS
	} else if (strcmp(Column, "Rooms")==0) {
		long int room;
		printf("What data do you want to find? ");
		scanf("%ld", &room); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(room == DB[i].rooms){
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			} 
		}
		
		if(ind==1){
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(room == DB[i].rooms){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		}
		//carpark
	} else if(strcmp(Column, "Carpark")==0) {
		long int park;
		printf("What data do you want to find? ");
		scanf("%ld", &park); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(park == DB[i].park){
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			} 
		}
		
		if(ind==1){
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(park == DB[i].park){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		}
		//BATHROOM
	} else if (strcmp(Column, "Bathroom")==0) {
		long int bath;
		printf("What data do you want to find? ");
		scanf("%ld", &bath); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(bath == DB[i].bathroom){
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			} 
		}
		
		if(ind==1){
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(bath == DB[i].bathroom){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		}
		
	} else if (strcmp(Column, "Type")==0) {
		
		printf("What data do you want to find? ");
		scanf("%s", &input); getchar();
		int ind=0;
		
		for(int i=0; i<idx; i++){
			if(strcmp(input, DB[i].type)==0){
				ind =1;
				break;
			} else if(ind == 0) {
			printf("Data not Found!\n");
			break;
			} 
		}
		
		if(ind==1){
			printf("Data found. Detail of data:\n");
			printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
			for(int i=0; i<idx; i++){
				if(strcmp(input, DB[i].type)==0){
					printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
				} 
			}	
		}
		
	}
}

void output(int row, struct Database DB[]) {
    printf("Location\t\tCity\t\tPrice\t\tRooms\tBathroom\tCarpark\t\tType\t\tFurnish\n");
    for(int i=0; i<row; i++){
        printf("%-16s\t%-12s\t%-10ld\t%-7ld\t%-8ld\t%-7ld\t\t%-5s\t%-7s\n", DB[i].location, DB[i].location2, DB[i].price, DB[i].rooms, DB[i].bathroom, DB[i].park, DB[i].type, DB[i].furnish);
    }
}

int main () {
    int choice;
    do{
    int idx=0;
    FILE* fd = fopen("file.csv","r");
    printf("What do you want to do?\n1.\tDisplay Data\n2.\tSearch Data\n3.\tSort Data\n4.\tExport Data\n5.\tExit\nYour Choice: ");
    scanf("%d", &choice); getchar();
    scan(fd, DB, idx);
    //ngitung berapa data yang ada
    //printf("%d\n", idx);
    
	fclose(fd);
        if(choice == 1){
            int row;
            printf("Number of rows: ");
            scanf("%d", &row); getchar();
            output(row , DB);
        }
        else if (choice == 2){
        	char Column[101];
        	printf("Choose Column: ");
        	scanf("%s", &Column);
        	search(Column, DB, idx);
        } 
    
    
    } while(choice != 5);
    return 0;
}
