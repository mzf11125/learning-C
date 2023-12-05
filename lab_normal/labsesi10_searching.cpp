#include <stdio.h>

//Linear Search
int linearSearch(int arr[], int size,int find){
	for(int i = 0; i < size; i++){
		if(arr[i] == find){
			//elemen that is searched, found
			return i; 
		}
		
	}
	//Element not found
	return -1;
}

//Iterative Binary Search
int iterativeBinarySearch(int arr[], int left, int right, int find){
	while (left <= right){
		int mid = left + (right-left)/2;
		if(arr[mid] == find){
			return mid;
		}else if(arr[mid] < find){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			left = mid -1;
		}else{
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
			right = mid-1;
		}
		
	}
	return -1;
}

//Recursive binary search
int recursiveBinarySearch(int arr[], int left, int right, int find){
	if(left <= right){
		//Recursion continue
		int mid = left + (right - left)/2;
		if(arr[mid] == find){
			return mid;
		}else if(arr[mid] < find){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			return recursiveBinarySearch(arr, mid + 1, right,find);
		}else{
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
			return recursiveBinarySearch(arr, left, mid - 1, find);
		}
	}	
	return -1;
}

//Interpolation search
// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
//int iterativeInterpolationSearch(int arr[], int left, int right, int find)
//{
//	
//    int pos;
//    // Since array is sorted, an element present
//    // in array must be in range defined by corner
//    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
//        // Probing the position with keeping
//        // uniform distribution in mind.
//        pos = lo
//              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
//                 * (x - arr[lo]));
// 
//        // Condition of target found
//        if (arr[pos] == x)
//            return pos;
// 
//        // If x is larger, x is in right sub array
//        if (arr[pos] < x)
//            return interpolationSearch(arr, pos + 1, hi, x);
// 
//        // If x is smaller, x is in left sub array
//        if (arr[pos] > x)
//            return interpolationSearch(arr, lo, pos - 1, x);
//    }
//    return -1;
//}

//Iterative Interpolation Search
int iterativeInterpolationSearch(int arr[], int left, int right, int find){
	while (left <= right && find >= arr[left] && find <= arr[right]){
//		int mid = left + ((find - arr[left]) * (right-left) / (arr[right] - arr[left]));
//		int mid = left + ((find - arr[left]) * (right - left) / (arr[right] - arr[left]));
		int mid = left + (((right - left) / (arr[right] - arr[left])) * (find - arr[left]));
		if(arr[mid] == find){
			return mid;
		}else if(arr[mid] < find){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			left = mid -1;
		}else{
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
			right = mid-1;
		}
		
	}
	return -1;
}


//recursiveinterpolationsearch
int recursiveInterpolationSearch(int arr[], int left, int right, int find){
	while (left <= right && find >= arr[left] && find <= arr[right]){
//		int mid = left + ((find - arr[left]) * (right-left) / (arr[right] - arr[left]));
//		int mid = left + ((find - arr[left]) * (right - left) / (arr[right] - arr[left]));
		int mid = left + (((right - left) / (arr[right] - arr[left])) * (find - arr[left]));
		if(arr[mid] == find){
			return mid;
		}else if(arr[mid] < find){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			return recursiveInterpolationSearch(arr, mid + 1, right, find);
		}else{
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
			return recursiveInterpolationSearch(arr, left, mid - 1, find);
		}
		
	}
	return -1;
}

int main(){
	int arr[]={1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int position = linearSearch(arr, size, 4);
	int position1 = iterativeBinarySearch(arr, 0, size, 4);
	int position2 = recursiveBinarySearch(arr, 0, size, 4);
	int position3 = iterativeInterpolationSearch(arr, 0, size - 1, 4);//Size - 1, max index is 4
	int position4 = recursiveInterpolationSearch(arr, 0, size - 1, 4);//Size - 1, max index is 4
	printf("Number 4 is located at array: %d\n", position);
	printf("Number 4 is located at array: %d\n", position1);
	printf("Number 4 is located at array: %d\n", position2);
	printf("Number 4 is located at array: %d\n", position3);
	printf("Number 4 is located at array: %d\n", position4);
	return 0;
}