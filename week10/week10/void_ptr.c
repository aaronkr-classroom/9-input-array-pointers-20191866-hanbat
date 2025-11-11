//void_ptr.c

#include <stdio.h>

int get_data(void* p_data, char type) {
	int result = 0;
	// type 변수에 저장된 값을 기준으로 형 변환을 다르게 함
	if (type == 1) result = *(char*)p_data; // 0x78(1byte)
	else if (type == 2) result = *(short*)p_data; // 0x5678(2byte)
	else if (type == 4)result = *(int*)p_data; // 0x12345678(4byte)
	return result;
}

int main() {
	int data = 0x78654321;
	//data변수에서 2바이트크기만 출력함
	printf("0x%x\n", get_data(&data, 2)); // 0x5678
	printf("0x%x\n", get_data(&data, 1)); // 0x78
	printf("0x%x\n", get_data(&data, 4)); // 0x12345678

	return 0;
}