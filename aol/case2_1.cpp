#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>



struct data{
	char location[5005];
	char city[5005];
	int price;
	int room;
	int bathroom;
	int carpark;
	char type[5005];
	char furnish[5005];
} searchData[10005];



//void searchData

void displayData(struct Data *dataArr, int rows)
{
    printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",
                        "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark", "Type", "Furnish");
                for (int i = 0; i < rows; i++)
                {
                    printf("%-20s\t%-20s\t%-10lld\t%-10d\t%-10d\t%-10d\t%-10s\t%-10s\n",
                        dataArr[i].location, dataArr[i].city, dataArr[i].price, dataArr[i].rooms, dataArr[i].bathroom,
                        dataArr[i].carpark, dataArr[i].type, dataArr[i].furnish);
                }
}


int main() {
	FILE *f = fopen("file.csv", "r");
	char filename[1005];
	int size = 0;
	fscanf(f, "%[^\n]\n", &filename);
    int choice = 0;
    while(!feof(f)){
    	fscanf(f, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n", &searchData[size].location, &searchData[size].city, &searchData[size].price, &searchData[size].room,&searchData[size].bathroom, &searchData[size].carpark, &searchData[size].type, searchData[size].furnish);
		size++;	
	}
	displayData();
 	for(int i = 0; i < size; i++){
			
	}   
	do {
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);getchar();
        switch (choice) {
            case 1:
                printf("Number of rows: ");
//                scanf("%d", &num_rows_to_display);
                display(num_rows_to_display);
                break;
            case 2:
            	
            	
                select_row(column, query_value);
				  puts("Choose your column: ");
				  scanf("");
				  
                break;
            case 3:
                sort_by(column, order);
                break;
            case 4:
                printf("File name: ");
                scanf("%s", filename); //Enter the filename
                export(*filename); 
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}







