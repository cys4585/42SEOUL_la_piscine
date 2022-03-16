# libft

> **Your very first own library**
> 나만의 첫 번째 라이브러리
>
> ***Summary: This project aims to code a C library regrouping usual functions that you’ll be use for all your next projects.**
> 요약: 이 프로젝트의 목적은 흔히 쓰이는 함수들을 재구성하여 이후의 모든 프로젝트에서 사용될 C 라이브러리를 제작하는 것입니다.*



## 1. 정적 라이브러리

- 라이브러리

  - 다른 프로그램들과 링크되기 위하여 존재하는, 하나 이상의 서브루틴(subroutine)이나 함수(function)들의 집합 파일
  - 라이브러리들은 사용자의 프로그램과 링크되어 실행이 가능한 완전한 프로그램을 이룬다.

- 정적 라이브러리

  - 프로그램 빌드 시에 라이브러리가 제공하는 코드를 실행 파일에 넣는 방식의 라이브러리

  - 컴파일된 오브젝트 파일들이 하나의 archive로 묶여있는 형태

  - 빌드 과정의 링크 단계에서 실행 파일에 결합된다.

    - 빌드 과정
      - ![img](https://blog.kakaocdn.net/dn/x8xPL/btq0HabcJAh/n5rCuGjzpUtynbDi3n00m0/img.png)
      
      - ```shell
        //STEP1. 전처리 단계 [ *.c -> *.i ]
        gcc -E main.c -o main.i
        gcc -E func.c -o func.i
        
        //STEP2. ~ 컴파일 단계 [ *.c -> (*.i) -> *.s ]
        gcc -S main.c func.c
        
        //STEP3. ~ 어셈블 단계 [ *.c -> (*.i) -> (*.s) -> *.o ]
        gcc -c main.c func.c
        
        //STEP4. ~ 링크 단계 [ *.c -> (*.i) -> (*.s) -> (*.o) -> executable ]
        gcc -o main main.c func.c
        ```
  
  - 장점
  
    - 라이브러리의 동작 코드가 이를 사용하는 실행 바이너리 속에 포함되기 때문에 별도의 추가작업 없이, 그리고 독립적으로 라이브러리 함수들을 사용할 수 있다.
    - 시스템 환경이 변해도 애플리케이션에 아무런 영향이 없고, 완성된 애플리케이션을 안정적으로 사용할 수 있다.
    - 컴파일시 필요한 라이브러리를 프로그램 내에 적재하기 때문에 이식성이 좋다.
    - 런타임시 외부를 참조할 필요가 없기 때문에 속도에서 장점이 있다.
  
  - 단점
  
    - 사용하는 모든 오브젝트 코드를 실행 파일에 내장하기 때문에 메모리에 로드되는 애플리케이션 코드 크기가 커진다.
    - 라이브러리 변경이 필요할 시, 변경된 라이브러리만 재배포하면 안되고, 프로그램을 다시 재배포 해야한다.

  - 확장자: *.a / *.lib
  
  - 정적 라이브러리 만들기
  
    - ```shell
      gcc -c test.c		# test.o
      ar rc test.a test.o		# test.a
      ```
  
    - gcc: c 언어 컴파일러 (GNU C Compiler / GNU Compiler Collection)
  
      - -c: 소스파일을 컴파일or어셈블하되, 링크는 하지 마라. (출력물은 각 소스파일들의 오브젝트 파일)
  
    - ar: 아카이브에서 생성, 수정 및 추출 (라이브러리 조작 명령어)
  
      - Archive: 기록보관소. 파일들을 한 곳에 모아둔 것 (라이브러리)
      - options
        - r
          - 파일 멤버를 아카이브에 삽입 (교체 포함)
          - 새로운 오브젝트 파일이면 추가, 기존 파일이면 교체
        - c
          - 아카이브(라이브러리) 생성
          - 존재하지 않는 아카이브를 작성or갱신하는 경우에 경고하지 않는다.
        - s
          - 아카이브 인덱스를 생성
          - 아카이브 인덱스를 생성하지 않으면 링크 속도가 느려지고, 시스템 환경에 따라서는 에러가 발생.



## 2. Makefile











## 3. Libc functions (Standard C Library)



### Part 1 - Libc functions

#### `isalpha()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int	isalpha(int c);
    ```

- DESCRIPTION

  - argument가 isupper or islower인지 test하는 함수
  - argument의 value는 (unsigned char or EOF 값)으로 표현되어야 한다.

- RETURN VALUE

  - True -> non-zero
  - False -> 0

- Solve

  - ```c
    int	ft_isalpha(int c)
    {
    	if (65 <= c && c <= 90)
    		return (1);
    	if (97 <= c && c <= 122)
    		return (1);
    	return (0);
    ```

- Questions

  1. argument를 int 타입으로 받아야 하는 이유? 받아도 되는 이유?
  
     - C언에서 문자를 넣으면 자동으로 아스키 코드에 해당하는 숫자로 들어가기 때문
  
     - 즉, 'a'와 같은 char 타입으로 집어 넣어도 자동으로 int 타입으로 형변환 되어서 들어가게 된다.

#### `isdigit()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int	isdigit(int c);
    ```

- DESCRIPTION

  - argument가 decimal digit character인지 test하는 함수

- RETURN VALUE

  - True -> non-zero
  - False -> 0

- Solve

  - ```c
    int	ft_isdigit(int c)
    {
    	if (48 <= c && c <= 57)
    		return (1);
    	return (0);
    }
    ```

#### `isalnum()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int	isalnum(int c);
    ```

- DESCRIPTION

  - argument가 isalpha() 또는 isdigit()이 참인지 test하는 함수

- RETURN VALUE

  - True -> non-zero
  - False -> 0

- Solve

  - ```c
    int	ft_isalnum(int c)
    {
    	if (ft_isalpha(c) || ft_isdigit(c))
    		return (1);
    	return (0);
    }
    ```

#### `isascii()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int	isascii(int c);
    ```

- DESCRIPTION

  - argument가 ASCII character인지 test하는 함수
  - 0 ~ 127 (10진수)

- RETURN VALUE

  - True -> non-zero
  - False -> 0

- Solve

  - ```c
    int	ft_isascii(int c)
    {
    	if (0 <= c && c <= 127)
    		return (1);
    	return (0);
    }
    ```

#### `isprint()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int isprint(int c);
    ```

- DESCRIPTION

  - argument가 printable한지 test하는 함수
  - 32 ~ 126 (10진수)

- RETURN VALUE

  - True -> non-zero
  - False -> 0

- Solve

  - ```c
    int	ft_isprint(int c)
    {
    	if (32 <= c && c <= 126)
    		return (1);
    	return (0);
    }
    ```

#### `strlen()`

- SYNOPSIS

  - ```c
    #include <string.h>
    size_t strlen(const char *s);
    ```

- DESCRIPTION

  - 문자열 `s`의 길이를 계산하는 함수

- RETURN VALUE

  - Terminating NUL character 앞에 오는 문자의 수

- Solve

  - ```c
    #include <stdlib.h>
    
    size_t	ft_strlen(const char *s)
    {
    	size_t size = 0;
    	while (s[size])
    		size++;
    	return (size);
    }
    ```

- Questions

  1. `size_t` 는 무엇인가?
     - 가장 큰 사이즈를 담을 수 있는 `unsigned 정수형`
     - 해당 시스템에서 최대 크기의 데이터를 표현하는 타입으로서, 반드시 `unsigned 정수형`으로 나타낸다.
     - 32bit 머신
       - 32bit 사이즈의 `unsigned 정수형 (unsigned int)` 
       - 크기: `4byte(32bit)`
     - 64bit머신
       - 64bit 사이즈의 `unsigned 정수형 (unsigned long long)`
       - 크기: `8byte(64bit)`
  2. 매개변수를 `const char *` 로 선언한 무엇인가?
     - char pointer 변수가 가리키는 곳의 값을 수정할 수 없도록 상수취급하기 위함
     -  `const char *s = "abc"`가 들어오면, s가 가리키는 곳의 값은 `"abc"`로 고정되고, 수정할 수 없다. 단, s의 값 자체를 바꿀 순 있다. (다른 곳을 가리키도록 할 수 있음)

