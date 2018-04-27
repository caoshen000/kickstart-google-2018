#include <stdio.h>
#include <stdlib.h>

int compare(char* string, int num, char* array);
int set_zero(int* letter);
int compare_letter(int* letter1, int* letter2);

int main(int argc, int* argv){
	int times;
	scanf("%d\n",&times);
	for(int i=0; i<times; i++){
		int l_word;
		scanf("%d\n",&l_word);
		char *array[l_word];

		for(int j=0; j < l_word; j++){
			char* str = (char*)malloc(1 << 20);
			scanf("%s ", str);
			array[j] = str;
//			printf("array[%d]=%s\n",j,array[j]);
		}
		scanf("\n");
		char s1;
		char s2;
		scanf("%c %c",&s1 ,&s2);
		int num,a,b,c,d;
		scanf("%d %d %d %d %d\n",&num, &a, &b, &c, &d);

		char string[num];
		string[0] = s1;
		string[1] = s2;
		long long x1 = (long long)s1;
		long long x2 = (long long)s2;
		for(int k=3; k<=num; k++){
			long long x3 = 0;
			x3 =(long long)((a * x2 + b *x1 + c) % d);
			string[k-1] = (char)(97 + (x3 % 26));
			x1 = x2;
			x2 = x3;
		}
//		printf("num = %d string = %s\n", num, string);
		
		int result = 0;
		for(int k=0; k<l_word; k++){
			result = result + compare(string, num, array[k]);
		}
		printf("Case #%d: %d\n", i+1, result);
		for(int m=0; m<l_word; m++){
			free(array[m]);
		}

	}

	return 1;
}

int compare(char* string, int num, char* array){
	int begin = 0;
	int end = 0;
	int letter1[26];
	int letter2[26];
	int result;
	
	set_zero(letter1);
	set_zero(letter2);

	while(array[end] != '\0'){
		end++;
	}
	end--;
//	printf("end = %d\n",end);
//	printf("num = %d\n",num);
//	printf("string =%s\n,array=%s\n",string,array);
	for(int i=0; i<num; i++){
		if(i+end == num){
			return 0;
		}else if(string[i] == array[0] && string[i+end] == array[end]){
//			printf("string i = %d\n",i);
			if(end == 1){
				return 1;
			}else{
				for(int j=0; j<end-1; j++){
					int temp1=0;
					int	temp2=0;
					temp1 = ((int)string[i+1+j]) - 97;
					letter1[temp1] = letter1[temp1] + 1;
					temp2 = ((int)array[1+j]) - 97;
					letter2[temp2] = letter2[temp2] + 1;
				}
				result = compare_letter(letter1,letter2);
				set_zero(letter1);
				set_zero(letter2);
				if(result == 1){
					return 1;
				}else{
					continue;
				}
			}
		}
	}
	return 0;
}

int compare_letter(int* letter1, int* letter2){
//	printf("*******************\n");
	for(int i=0; i<26; i++){
//		printf("i=%d,letter1 = %d,letter2=%d\n", i, letter1[i], letter2[i]);
		if(letter1[i] == letter2[i]){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}

int set_zero(int* letter){
	for(int i=0; i<26; i++){
		letter[i] = 0;
	}
	return 1;
}
