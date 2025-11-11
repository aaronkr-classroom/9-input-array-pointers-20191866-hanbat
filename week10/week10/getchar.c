// getchar

#include <stdio.h>
#include <conio.h> //ms 표준 라이브러리

int main() {
	char c = getchar(); // 버퍼 사용하고 엔터키 필수
	printf("입력한 문자: %c\n", c);

	//qjvjdptj skadms answk dlTdmaus
	printf("버퍼에서 남은 문자: ");
	while ((c = getchar()) != '\n' && c != EOF) {
		putchar(c); //문자 한개 씩 출력
	}
	return 0;


}