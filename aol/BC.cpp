#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
// Nama: Valent Nathanael
// NIM: 2702343706
// Kelas: LJ01
// AOL Algoritma Pemrograman
typedef long long lli;
#define fLoop(i,n,N) for(int i = (n); i < (N); i++)
typedef enum {

  UNKNOWN,
  WINDOWS,
  LINUX,
  OSX

} OS;

OS current_os();

OS current_os() {
  #ifdef _WIN32
    return WINDOWS;
  #elif (defined(__APPLE__) && defined(__MACH__))
    return OSX;
  #elif defined(__gnu_linux__)
    return LINUX;
  #else
    return UNKNOWN;
  #endif 
}
//Consts
const int MAX_CHAR_LENGTH = 200;
const int MAX_DATA_AMOUNT = 4500;
 char LOCATION[MAX_CHAR_LENGTH];
    char CITY[MAX_CHAR_LENGTH];
    char PRICE[MAX_CHAR_LENGTH];
    char ROOMS[MAX_CHAR_LENGTH];
    char BATHROOMS[MAX_CHAR_LENGTH];
    char CARPARK[MAX_CHAR_LENGTH];
    char TYPE[MAX_CHAR_LENGTH];
    char FURNISH[MAX_CHAR_LENGTH];
char* COLUMN_NAMES[8];

void initializeNames()
{
    COLUMN_NAMES[0] = LOCATION;
    COLUMN_NAMES[1] = CITY;
    COLUMN_NAMES[2] = PRICE;
    COLUMN_NAMES[3] = ROOMS;
    COLUMN_NAMES[4] = BATHROOMS;
    COLUMN_NAMES[5] = CARPARK;
    COLUMN_NAMES[6] = TYPE;
    COLUMN_NAMES[7] = FURNISH;
}
struct ColumnConvertion{
    char name[MAX_CHAR_LENGTH];
    char altName[MAX_CHAR_LENGTH];
};
struct ColumnConvertion columnConvertions[8];
void initializeColumnConvertions()
{
    strcpy(columnConvertions[0].name,"Location");
    strcpy(columnConvertions[0].altName,"Location 1");
    strcpy(columnConvertions[1].name,"City");
    strcpy(columnConvertions[1].altName,"Location 2");
    strcpy(columnConvertions[2].name,"Price");
    strcpy(columnConvertions[2].altName,"Price");
    strcpy(columnConvertions[3].name,"Rooms");
    strcpy(columnConvertions[3].altName,"Rooms");
    strcpy(columnConvertions[4].name,"Bathrooms");
    strcpy(columnConvertions[4].altName,"Bathrooms");
    strcpy(columnConvertions[5].name,"Carpark");
    strcpy(columnConvertions[5].altName,"CarParks");
    strcpy(columnConvertions[6].name,"Type");
    strcpy(columnConvertions[6].altName,"Type");
    strcpy(columnConvertions[7].name,"Furnish");
    strcpy(columnConvertions[7].altName,"Furnish");
}
char* convertColumnName(char *name)
{
    for(int i = 0; i < 8; i++)
    {
        if(strcmp(name,columnConvertions[i].altName) == 0)
        {
            return columnConvertions[i].name;
        }else if(strcmp(name,columnConvertions[i].name) == 0)
        {
            return columnConvertions[i].name;
        }
    }
    return name;
}
//Structs
struct Data{
    char location[MAX_CHAR_LENGTH];
    char city[MAX_CHAR_LENGTH];
    lli price;
    int rooms;
    int bathroom;
    int carpark;
    char type[MAX_CHAR_LENGTH];
    char furnish[MAX_CHAR_LENGTH];
}dataArray[MAX_DATA_AMOUNT];
struct SearchResult{
    struct Data *data;
    int count;
};

//Global
int dataCount = 0;
//Utilities
void clearScreen()
{
        if(current_os() == WINDOWS)
        {
            system("cls");
        }else if(current_os() == OSX)
        {
            system("clear");
        }
}
void displayMenu(){
    printf("What do you want to do?\n");
    printf("1. Display data\n");
    printf("2. Search data\n");
    printf("3. Sort data\n");
    printf("4. Export data\n");
    printf("5. Exit\n");
}

struct SearchResult searchStringTarget(struct Data *dataArr, char *query, char *target){
    int foundCount = 0;
    struct Data foundData[MAX_DATA_AMOUNT];
    for(int i = 0; i < MAX_DATA_AMOUNT; i++)
    {
        if(strcmp(query,LOCATION) == 0)
        {
            if(strcmp(dataArr[i].location,target) == 0)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }else if(strcmp(query,CITY) == 0)
        {
            if(strcmp(dataArr[i].city,target) == 0)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }else if(strcmp(query,TYPE) == 0)
        {
            if(strcmp(dataArr[i].type,target) == 0)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }else if(strcmp(query,FURNISH) == 0)
        {
            if(strcmp(dataArr[i].furnish,target) == 0)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }
    }
    struct SearchResult searchRes;
    searchRes.data = foundData;
    searchRes.count = foundCount;

    return searchRes;
}

struct SearchResult searchNumberTarget(struct Data *dataArr, char *query, lli target){
    int foundCount = 0;
    struct Data foundData[MAX_DATA_AMOUNT];
    for(int i = 0; i < MAX_DATA_AMOUNT; i++)
    {
        if(strcmp(query,PRICE) == 0)
        {
            if(dataArr[i].price == target)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }else if(strcmp(query,ROOMS) == 0)
        {
            if(dataArr[i].rooms == target)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }else if(strcmp(query,BATHROOMS) == 0)
        {
            if(dataArr[i].bathroom == target)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }else if(strcmp(query,CARPARK) == 0)
        {
            if(dataArr[i].carpark == target)
            {
                foundData[foundCount] = dataArr[i];
                foundCount++;
            }
        }
    }
    struct SearchResult searchRes;
    searchRes.data = foundData;
    searchRes.count = foundCount;

    return searchRes;
}

int compareTwoString(struct Data data1, struct Data data2, char *key)
{
    if(strcmp(key,LOCATION) == 0)
    {
        return strcmp(data1.location,data2.location);
    }else if(strcmp(key,CITY) == 0)
    {
        return strcmp(data1.city,data2.city);
    }else if(strcmp(key,TYPE) == 0)
    {
        return strcmp(data1.type,data2.type);
    }else if(strcmp(key,FURNISH) == 0)
    {
        return strcmp(data1.furnish,data2.furnish);
    }
    return 0;
}
int compareTwoNumber(struct Data data1, struct Data data2, char *key)
{
    if(strcmp(key,PRICE) == 0)
    {
        return data1.price - data2.price;
    }else if(strcmp(key,ROOMS) == 0)
    {
        return data1.rooms - data2.rooms;
    }else if(strcmp(key,BATHROOMS) == 0)
    {
        return data1.bathroom - data2.bathroom;
    }else if(strcmp(key,CARPARK) == 0)
    {
        return data1.carpark - data2.carpark;
    }
    return 0;
}
//Sorting
void sortMergeString(struct Data* arr,int low,int high, int mid, char *key, int invert)
{

    int subArrOne = mid - low + 1;
    int subArrTwo = high-mid;
    struct Data leftArr[subArrOne];
    struct Data rightArr[subArrTwo];
    for(int i =0;i<subArrOne;i++)
    {
        leftArr[i] = arr[low+i];
    }
    for(int i =0;i<subArrTwo;i++)
    {
        rightArr[i] = arr[mid+i + 1];
    }
    int subArrOneIndx =0, subarrTwoIndx = 0;
    int index = low;
    while(subArrOneIndx < subArrOne && subarrTwoIndx < subArrTwo)
    {
        if(invert * compareTwoString(leftArr[subArrOneIndx],rightArr[subarrTwoIndx],key) < 0)
        {
            arr[index++] = leftArr[subArrOneIndx++];
        }
        else{
            arr[index++] = rightArr[subarrTwoIndx++];
        }
    }
    while(subArrOneIndx < subArrOne)
    {
        arr[index++] = leftArr[subArrOneIndx++];
    }
    while(subarrTwoIndx < subArrTwo)
    {
        arr[index++] = rightArr[subarrTwoIndx++];
    }
}


void mergeSortString(struct Data* arr, int low, int high, char *key, int invert)
{
    if(low == high){return;}
    int mid = low + (high-low)/2;
    mergeSortString(arr,low,mid,key,invert);
    mergeSortString(arr,mid+1,high,key,invert);
    sortMergeString(arr,low,high,mid,key,invert);
}

void sortMergeNumber(struct Data* arr,int low,int high, int mid, char *key, int invert)
{

    int subArrOne = mid - low + 1;
    int subArrTwo = high-mid;
    struct Data leftArr[subArrOne];
    struct Data rightArr[subArrTwo];
    for(int i =0;i<subArrOne;i++)
    {
        leftArr[i] = arr[low+i];
    }
    for(int i =0;i<subArrTwo;i++)
    {
        rightArr[i] = arr[mid+i + 1];
    }
    int subArrOneIndx =0, subarrTwoIndx = 0;
    int index = low;
    while(subArrOneIndx < subArrOne && subarrTwoIndx < subArrTwo)
    {
        if(invert * compareTwoNumber(leftArr[subArrOneIndx],rightArr[subarrTwoIndx],key) < 0)
        {
            arr[index++] = leftArr[subArrOneIndx++];
        }
        else{
            arr[index++] = rightArr[subarrTwoIndx++];
        }
    }
    while(subArrOneIndx < subArrOne)
    {
        arr[index++] = leftArr[subArrOneIndx++];
    }
    while(subarrTwoIndx < subArrTwo)
    {
        arr[index++] = rightArr[subarrTwoIndx++];
    }
}

void mergeSortNumber(struct Data* arr, int low, int high, char *key, int invert)
{
    if(low == high){return;}
    int mid = low + (high-low)/2;
    mergeSortNumber(arr,low,mid,key,invert);
    mergeSortNumber(arr,mid+1,high,key,invert);
    sortMergeNumber(arr,low,high,mid,key,invert);
}
//Validation
int validate_column(char *column)
{
    for(int i = 0; i < 8; i++)
    {
        if(strcmp(column,COLUMN_NAMES[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

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
//Functions
void SelectRow()
{
    char searchQuery[MAX_CHAR_LENGTH],searchTarget[MAX_CHAR_LENGTH];
    lli searchTargetNum;
    while(true)
    {
        printf("Choose column: " );
        scanf("%s",searchQuery);
        if(validate_column(searchQuery))
        {
            break;
        }
        printf("Invalid column\n");
    }
    if(strcmp(searchQuery,LOCATION) == 0 || strcmp(searchQuery,CITY) == 0 || strcmp(searchQuery,TYPE) == 0 || strcmp(searchQuery,FURNISH) == 0)
    {
        printf("What data do you want to find? ");
        scanf("%s",searchTarget);
        struct SearchResult searchRes = searchStringTarget(dataArray,searchQuery,searchTarget);
        if(searchRes.count == 0)
        {
            printf("Not Found\n");
            return;
        }else{
            printf("Data found. Detail of data:\n");
            displayData(searchRes.data,searchRes.count);
        }
    }else{
        printf("What data do you want to find? ");
        scanf("%lld",&searchTargetNum);
        struct SearchResult searchRes = searchNumberTarget(dataArray,searchQuery,searchTargetNum);
        if(searchRes.count == 0)
        {
            printf("Not Found\n");
            return;
        }else{
            printf("Data found. Detail of data:\n");
            displayData(searchRes.data,searchRes.count);
        }
    }
}
void DisplayData()
{
    int rows;
    printf("Number of rows: ");
    scanf("%d",&rows);
    rows = rows > dataCount ? dataCount : rows;
    displayData(dataArray,rows);
}
void SortBy()
{
    char searchQuery[MAX_CHAR_LENGTH],searchTarget[MAX_CHAR_LENGTH];
    lli searchTargetNum;
    while(true)
    {
        printf("Choose column: " );
        scanf("%s",searchQuery);
        if(validate_column(searchQuery))
        {
            break;
        }
        printf("Invalid column\n");
    }
            int invert = 1;
        char invertStr[10];
        while(true){
        printf("Sort ascending or descending? ");
        scanf("%s",invertStr);
        if(strcmp(invertStr,"ascending") == 0 || strcmp(invertStr,"descending") == 0)
        {
            break;
        }
        }
        if(strcmp(invertStr,"descending") == 0)
        {
            invert = -1;
        }
        if(strcmp(searchQuery,LOCATION) == 0 || strcmp(searchQuery,CITY) == 0 || strcmp(searchQuery,TYPE) == 0 || strcmp(searchQuery,FURNISH) == 0)
        {
            mergeSortString(dataArray,0,dataCount-1,searchQuery,invert);
        }else{
            mergeSortNumber(dataArray,0,dataCount-1,searchQuery,invert);
        }
        printf("Data sorted\n");
        displayData(dataArray,dataCount > 10 ? 10 : dataCount);

}
void Export()
{
    char fileName[MAX_CHAR_LENGTH];
    char extension[] = ".csv";
    printf("File name: ");
    scanf("%s",fileName);
    strcat(fileName, extension);
    FILE *writeFile = fopen(fileName,"w");
    fprintf(writeFile, "%s,%s,%s,%s,%s,%s,%s,%s\n",convertColumnName(LOCATION),convertColumnName(CITY),convertColumnName(PRICE),convertColumnName(ROOMS),convertColumnName(BATHROOMS),convertColumnName(CARPARK),convertColumnName(TYPE),convertColumnName(FURNISH));
    for(int i = 0; i < dataCount; i++)
    {
        fprintf(writeFile, "%s,%s,%lld,%d,%d,%d,%s,%s\n",dataArray[i].location,dataArray[i].city,dataArray[i].price,dataArray[i].rooms,dataArray[i].bathroom,dataArray[i].carpark,dataArray[i].type,dataArray[i].furnish);
    }
    printf("Data successfully written to file %s\n",fileName);
}
int main()
{
    initializeColumnConvertions();
    FILE *readFile = fopen("file.csv","r");
    char tittleString[9000]; fscanf(readFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",LOCATION,CITY,PRICE,ROOMS,BATHROOMS,CARPARK,TYPE,FURNISH);
    strcpy(LOCATION,convertColumnName(LOCATION));
    strcpy(CITY,convertColumnName(CITY));
    strcpy(PRICE,convertColumnName(PRICE));
    strcpy(ROOMS,convertColumnName(ROOMS));
    strcpy(BATHROOMS,convertColumnName(BATHROOMS));
    strcpy(CARPARK,convertColumnName(CARPARK));
    strcpy(TYPE,convertColumnName(TYPE));
    strcpy(FURNISH,convertColumnName(FURNISH));
    initializeNames();


    while((fscanf(readFile,"%[^,],%[^,],%lld,%d,%d,%d,%[^,],%s\n",dataArray[dataCount].location,dataArray[dataCount].city,&dataArray[dataCount].price,&dataArray[dataCount].rooms,&dataArray[dataCount].bathroom,&dataArray[dataCount].carpark,dataArray[dataCount].type,dataArray[dataCount].furnish)) == 8)
    {
        dataCount++;
    }
    char yesNo[10];
    while(true){
        clearScreen();
        displayMenu();
        printf("Your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            DisplayData();
            break;
            case 2:
            SelectRow();
            break;
            case 3:
            SortBy();
            break;
            case 4:
            Export();
            break;
            case 5:
            printf("Bye!\n");
            break;
        }
        if(choice == 5)
        {
            return 0;
        }
        printf("Want to do something else? (y/n) ");
        scanf("%s",yesNo);
        if(strcmp(yesNo,"n") == 0)
        {
            printf("\nBye!\n");
            break;
        }
    }

    return 0;
}