//getMyStr.c

#include <stdio.h>

#define MAX_CH 25

int getMyStr(char buffer[], int limit) {
	int i=0;
	int ch;
	
	while ((ch == getchar()) != '\n' && ch != EOF) {
		if (i < limit - 1) {
			buffer[i++] = (char)ch;
		}
		else {
			while (getchar() != '\n' && getchar() != EOF);
			buffer[i] = '\0';
			return 0;
		}
	}
}

int main(){
	char input_str[MAX_CH];
	int state; // 상태: 사용자에게 최대 MAX_CH 까지만 입력받겠다고 제안함.

	printf("Enter text(max %d chars): ", MAX_CH - 1);
	state = getMyStr(input_str, MAX_CH);

	if (state) printf("input : %sd\n", input_str);
	else printf("input : %s -> out of range\n",input_str);

	return 0;
}