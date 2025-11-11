//gets.c

#include <stdio.h>

#define MAX_CHAR 50

int main() {
	// 문자열을 마지막에 NUL 문자 0을 포함해야 함으로
	// 최대 MAX_CAHR -1 개 문자까지 저장 가능함.
	char input_str[MAX_CHAR];

	printf("카카오뱅크 등록\n");
	printf("이름 입력: ");

	// gets(input_str); 주의! 버퍼 오버플로우 취약
	// fgets(입력받을 변수, 길이, 입력 스트림)
	fgets(input_str, MAX_CHAR, stdin);

	printf("%s님,환영합니다!", input_str);
	return 0;
}