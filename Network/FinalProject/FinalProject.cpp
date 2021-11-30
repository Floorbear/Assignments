#define HAVE_STRUCT_TIMESPEC
#define _CRT_SECURE_NO_WARNINGS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

/*void* thread_main(void* arg);
void* thread_main_1(void* arg);

pthread_t t_id;
pthread_t t_id_2;
int main(int argc, char* argv[])
{
	
	int thread_param = 5; //쓰레드 메인함수에 전달할 매개변수


	void* thr_ret; //쓰래드가 리턴하는 값
	void* thr_ret_2;

	if (pthread_create(&t_id, NULL, thread_main, &thread_param) != 0)
	{
		printf("pthread_creat error");
		return -1;
	}
	pthread_detach(t_id);
	int a = pthread_create(&t_id, NULL, thread_main_1, &thread_param);
	printf("%d", a);

	pthread_join(t_id, &thr_ret);
	
	

}

//메인 쓰레드 함수
void* thread_main(void* arg)
{
	int i;
	i = *((int*)arg);

	printf("쓰레드 1 작동중 \n");
	for (int i = 0; i < 10; i++)
	{
		printf("쓰레드 1 : 호출\n");
		Sleep(1000);
	}
	char* msg = (char*)malloc(sizeof(char) * 50);
	strcpy(msg, "쓰레드 1 종료");
	printf("%s", msg);

	return (void*)msg;
}

void* thread_main_1(void* arg)
{
	int i;
	i = *((int*)arg);

	printf("쓰레드2 작동중 \n");
	for (int i = 0; i < 3; i++)
	{
		printf("쓰레드 2 : 호출\n");
		Sleep(1000);
	}
	Sleep(1000);
	char* msg = (char*)malloc(sizeof(char) * 50);
	strcpy(msg, "쓰레드2 종료");
	printf("%s", msg);
	return (void*)msg;
}*/
int main(int argc, char* argv[])
{

	char str[] = "Block|D|Mask.";    //구분할 문자열
	char* ptr = strtok(str, "|");    //첫번째 strtok 사용.
	strcpy(str, ptr);
	printf("%s\n", str);
	ptr = strtok(NULL, "|");
	strcpy(str, ptr);
	printf("%s", str);


}