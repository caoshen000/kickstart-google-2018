#include <stdio.h>

/*
long double array_to_average(int* array, int number);
int low_aver_num(int* array, int number, int average);
long double low_average(int* array, int number, int average);
int high_aver_num(int* array, int number, int average);
long double high_average(int* array, int number, int average);
*/
long double get_expected_value(int *array, int number, int k_redips);

int main(){
	int	time;
	scanf("%d", &time);

	for(int i=0; i<time; i++){
		int number, k_redips;
		scanf("%d%d", &number, &k_redips);
		int array[number];
		long double  result;
		for(int j=0; j<number; j++){
			scanf("%d", &array[j]);
		}
		
		result = get_expected_value(array, number,  k_redips);
		printf("Case #%d: %.6LF\n",i+1, result);


/*
		int low, high;
		long double low_aver, high_aver;
		low = low_aver_num(array, number, average);
		low_aver = low_average(array, number, average);

		high = high_aver_num(array, number, average);
		high_aver = high_average(array, number, average);
*/



	}
	return 1;
}

long double get_expected_value(int *array, int number, int k_redips){
	long double sum = 0;
	long double temp;
	if(k_redips == 0){
		for(int i=0; i<number; i++){
			sum = sum + array[i];
		}
		return sum/number;
	}else{
		temp = get_expected_value(array, number, k_redips-1);
		for(int j=0; j<number; j++){
			if(array[j] >= temp){
				sum = sum + array[j];
			}else{
				sum = sum + temp;
			}
		}
		return sum/number;
	}
	
}
/*
int low_aver_num(int* array, int number, int average){
	int num = 0;
	for(int i=0; i<number; i++){
		if(array[i] <= average){
			num++;
		}else{
			continue;
		}
	}
	return num;
}
long double low_average(int* array, int number, int average){
	int num = 0;
	long double sum = 0;
	for(int i=0; i<number; i++){
		if(array[i] <= average){
			num++;
			sum = sum + array[i];
		}else{
			continue;
		}
	}
	if(num == 0){
		return 0;
	}
	return sum/num;
}
long double high_average(int* array, int number, int average){
	int num = 0;
	long double sum = 0;
	for(int i=0; i<number; i++){
		if(array[i] > average){
			num++;
			sum = sum + array[i];
		}else{
			continue;
		}
	}
	if(num == 0){
		return 0;
	}
	return sum/num;
}

int high_aver_num(int* array, int number, int average){
	int num = 0;
	for(int i=0; i<number; i++){
		if(array[i] > average){
			num++;
		}else{
			continue;
		}
	}
	return num;
}

long double array_to_average(int* array, int number){
	long double temp=0.0;
	for(int i=0; i<number; i++){
		temp = temp + array[i];
	}
	return temp/number;
}
*/
