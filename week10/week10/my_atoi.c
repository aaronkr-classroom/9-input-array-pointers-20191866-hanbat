// atoi.c

#include <stdio.h>

#define STR_MAX 16

//문자열을 정수로 바꾸는 함수입니다.
// string = '123'
// string[0] = '1'; '1' - '0'; 0 * 19 + 49 - 48; => 정수 1
// string[1] = '2'; '2' - '0'; 1 * 10 + '2' - '0'; 10 + 2; => 정수 12
// string[2] = '3'; '3' - '0'; 12 * 10 + '3' - '0'; 120 + 3; => 정수 123

int my_atoi(char* string) {
	int count = 0, num = 0;

	//문자열이 끝날 때까지반복함
	while (string[count] != 0) {
		if (string[count] == '\n')break; //줄바꿈이면 중단
		//반복할 때마다 이전 값에 10을 곱해서 자릿수를 증가시킴
		num = (num * 10) + (string[count] - '0');// '0' = 48
		count++;//다음 문자로 이동
	}
	return num;
}

int main(void) {
	int first_num, second_num;
	char first_str[STR_MAX], second_str[STR_MAX];

	printf("1st num: ");
	fgets(first_str,STR_MAX,stdin); // '\n' = 10이기 때문에 
	printf("2nd num: ");
	fgets(second_str, STR_MAX, stdin);

	/*printf("문자합: \n"); 못해요 ㅠㅠ OTL
	printf("%s + %s = %s",first_str,second_str,first_str+second_str);*/

	first_num = my_atoi(first_str);
	second_num = my_atoi(second_str);

	printf("정수합: \n");
	printf("%d + %d = %d\n", first_num, second_num, first_num + second_num);

	return 0;
}