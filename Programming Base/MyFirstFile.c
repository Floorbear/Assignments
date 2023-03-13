#include <stdio.h>

int main()
{
	int iNo1, iNo2;

	//등호 왼쪽에 있는것은 "주소" < 반드시 기억해야함 ㄹㅇ
	iNo1 = 2;
	iNo2 = 4;

	iNo1 = iNo1 + 1;
	//왼쪽은 주소이고 오른쪽은 값임.
	//iNo1 주소에 있는 값과 1의 주소에 있는 값을 iNo1의 주소에 넣어라
	//이거 시험문제에 나올지도..?

	//int iSum = iNo1 + iNo2;






	int iKor, iEng, iMath;
	int iSum;
	
	iKor = 90;
	iEng = 85;
	iMath =  60;

	//선언과 정의를 구분하자!!
	//int iSum = ~~~   ( X ) 
	iSum = (iKor + iEng + iMath);
	int iAverage = iSum / 3;
	printf("Sum : %d입니다 \n", iSum);
	printf("Average : %d입니다 \n", iAverage);
	return 0;
}



//리터럴, 상수 헷갈린것 공부하기

//상수 : 초기화되고 주소를 변경할 수 없음.  (단 주소에 있는 값은 변경이 가능하다)
//상수 : 내가 Const로 초기화할수도 있지
//매크로 상수도 상수에 해당
// const int Hi = 4;
// 
//리터럴 : 주소를 변경할 수 없고, 주소 값도 변경할 수 없음....


//초기화 
//변수의 선언과 동시에 값을 부여하는 행위
//이것만 초기화로 인정
//int x = 10 << 초기화 문장
//x = 12; << 대입 문장