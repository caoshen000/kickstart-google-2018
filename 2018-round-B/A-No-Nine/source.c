#include <stdio.h>


int is_contain_nine(unsigned long begin){
	int temp = 0;
	while(begin != 0){
		temp = begin % 10;
//		printf("begin = %d temp = %d\n", begin, temp);
		if(temp == 9){
			return 1;
		}
		begin = begin / 10;
	}
	return 0;
}

int is_divide_nine(unsigned long begin){
	return (begin % 9 == 0)?1:0;
}

unsigned long legal_num(unsigned long number){
	unsigned long result = 0;
	unsigned long temp_result = 0;
	unsigned long temp = 0;
	int temp_i = 0;
	int is_contain_nine_return = 0;
	int is_divide_nine_return = 0;

	unsigned long temp_num = number;
	int array[20];

	for(int i = 0; i < 20; i++){
		array[i] = 0;
	}
	while(temp_num != 0){
		array[temp_i] = temp_num % 10;
//		printf("array[%d] = %d\n", temp_i, array[temp_i]);
		temp_num = temp_num / 10;
		temp_i++;	
	}

	temp = number - array[0];
	while(temp <= number){
		is_contain_nine_return = is_contain_nine(temp);
		is_divide_nine_return = is_divide_nine(temp);
		if(is_contain_nine_return == 1){
			temp++;
			continue;
		}else if(is_divide_nine_return == 1){
			temp++;
			continue;
		}else{
			result++;
			temp++;
		}
	}

	array[0] = 0;

	for(int j = temp_i-1; j >= 0; j--){
		temp_result = temp_result * 9 + array[j];
	}	
	
	result = result + temp_result * 8 / 9;
	return result;
}

int main(){
	int time = 0;
	scanf("%d\n", &time);
	for(int i = 0; i < time; i++){
		unsigned long begin = 0;
		unsigned long end = 0;
		unsigned long result = 0;
		int contain_return = 0;
		int divide_return = 0;

		scanf("%lu %lu\n", &begin, &end);
		
		result = legal_num(end) - legal_num(begin) + 1;
			
		printf("Case #%d: %lu\n", i+1, result);
	}
	return 1;
}
