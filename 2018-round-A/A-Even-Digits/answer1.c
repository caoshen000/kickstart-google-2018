#include<stdio.h>
#include<math.h>

long create_1(long length);
long create_10(long* array, long index, long length);
long create_end(long *array, long index, long length);
long create_444(long length);
long from_arr_to_num(long* array,long index, long length);

int main(int argc, char* argv){
	long t;
	long n;
	long i;
	long length = 0;
	long count = 0;
	int flag = 0;
	scanf("%ld",&t);
	for(i=0; i<t; i++){
		scanf("%ld",&n);
		long temp = n;
		long tempn = n;
		length = 1;
		while(temp/10 != 0){
			length++;
			temp = temp/10;
		}
		
		long array[length];
		for(long index=0; index<length; index++){
			array[index] = tempn/(long)(pow(10,length - 1 - index));
			tempn = tempn - array[index]*(long)(pow(10,length - 1 - index));
		}

		for(long index2=0; index2<length; index2++ ){
			count = 0;
			if(array[index2] % 2 == 0){
				flag = 0;
				continue;
			}else{
				if(index2 + 1 == length){
						count = 1;
						printf("Case #%ld: %ld\n",i+1,count);
						flag = 1;
						break;	
				}else{
				
					if(array[index2] == 9 || array[index2+1] < 4 ){
						count = create_end(array,index2,length)-array[index2]*(long)(pow(10,length - 1 -index2)) + 1 + create_1(length - 1 - index2);
						printf("Case #%ld: %ld\n",i+1,count);
						flag = 1;
						break;
					}else if(array[index2+1] == 4){
						if(from_arr_to_num(array,index2+1,length) < create_444(length-index2-2)){
							count = create_end(array,index2,length)-array[index2]*(long)(pow(10,length - 1 -index2)) + 1 + create_1(length - 1 - index2);
							printf("Case #%ld: %ld\n",i+1,count);
							flag = 1;
							break;
						}else{
							count = create_10(array, index2 , length);
							printf("Case #%ld: %ld\n",i+1,count);
							flag = 1;
							break;	
						}
					}else{
						count = create_10(array, index2 , length);
						printf("Case #%ld: %ld\n",i+1,count);
						flag = 1;
						break;	
					}
				}
			}
		}
		if(flag == 0){
			count = 0;
			printf("Case #%ld: %ld\n",i+1,count);
		}
	}
	return 1;

}

long create_444(long length){
	long result = 4;
	for(int i =0; i<length; i++){
		result = result*10 + 4;
	}
	return result;
}


long from_arr_to_num(long* array,long index, long length){
	long result =0;
	for(int i=index; i<length; i++){
		result = result * 10 +array[i];
	}
	return result;
}

long create_end(long *array, long index, long length){
	long result = 0;
	for(long k = index; k<length; k++){
		result = result * 10 + array[k];
	}
	return result;
}
long create_1(long length){
	long result =0;
	for(long i=0; i<length; i++){
		result = result*10 +1;
	}
	return result;
}


long create_10(long* array, long index, long length){
	long sum = 0;
	long result = 1;
	for(long k=index+1; k<length; k++){
		sum = sum * 10 +array[k];
		result = result *10;
	}
	return result-sum;

}


