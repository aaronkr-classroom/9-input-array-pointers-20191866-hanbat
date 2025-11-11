// calculator.c

#include <stdio.h>
#include <stdlib.h> // atoi() 함수
#include <ctype.h>  // isdigit() 함수(정수 확인하는 함수)

#define MAX_CH 100
#define NUM_CH MAX_CH/2

// 우리 만든 isdigit 함수
int numCheck(char ch) {
	return (int)ch >= '0' && ch <= '9'; // T/F 반환(1/0) 
}

int checkOp(char op) {
		return op == '+' || op == '-' || op == '*' || op == '/';
}
int main() {
	char input[MAX_CH],
		numStr1[NUM_CH], numStr2[NUM_CH],
		operator = '\0'; //NULL
	int i = 0,	// 원래 입력한 문자열의 인덱스
		j = 0;  // 받고 시은 숫자의 인덱스
	// 사용자에게 수학함수 받기: ex) "12 + 34"
	printf("Enter a simple math fomula (12 + 34) :\n");
	fgets(input, MAX_CH, stdin);

	// #1, 첫 번째 숫자를 추출하기
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr1[j++] = input[i++];
	}
	numStr1[j] = '\0'; // 문자열 종료

	// #2, 연산자를 확인하기
	if (checkOp(input[i])) {
		operator = input[i++];
	}
	else {
		printf("Invalid operator!\n");
		return 1; // main 함수가 문제 있기에 종료하기
	}
	
	// #3, 두 번째 숫자를 추출하기
	i, j = 0;
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr2[j++] = input[i++];
	}

	numStr2[j] = '\0'; // 문자열 종료

	// input = '123 + 456'
	// numStr1 = '123'
	// // opertor = '+'
	// numStr2 = '456'
	
	// 두 numStr이 숫자로 변경하기
	int num1 = atoi(numStr1);
	int num2 = atoi(numStr2);
	int result = 0;

	// 계산하기
	switch (operator) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 != 0)
				result = num1 / num2;
			else {
				printf("Error: Division by 0!\n");
				return 1; // 오류 발생
			}
			break;
		default:
			printf("Error : Invalid operator, User '+', '-', '*', '/'\n");
			return 1; // 오류 발생
	}
	printf("Result : %d %c %d = %d\n", num1, operator, num2, result);

	return 0; // 오류 없이 종료하기
}