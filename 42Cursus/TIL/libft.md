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
     - `const char *s = "abc"`가 들어오면, s가 가리키는 곳의 값은 `"abc"`로 고정되고, 수정할 수 없다. 단, s의 값 자체를 바꿀 순 있다. (다른 곳을 가리키도록 할 수 있음)

#### `memset()`

- SYNOPSIS

  - ```c
    #include <string.h>
    void *	memset(void *b, int c, size_t len);
    ```

- DESCRIPTION

  - `pointer b` 가 가리키는 메모리 영역의 `len byte` 만큼을 모두 `(unsigned char) c` 로 채운다.
  - Byte 단위로 메모리 영역을 세팅한다.

- RETURN VALUE

  - first argument (`pointer b`)

- Solve

  - ```c
    #include <stdlib.h>
    
    void	*ft_memset(void *b, int c, size_t len)
    {
    	unsigned char	*ptr;
    	size_t			i;
    
    	ptr = (unsigned char *)b;
    	i = 0;
    	while (i < len)
    		ptr[i++] = (unsigned char)c;
    	return (b);
    }
    ```

- Questions

  1. pointer를 `void *` 타입으로 받고, `unsigned char *` 로 형변환하는 이유

     - `void *` 로 받는 이유

       - 기본적으로 C 언어는 자료형이 다른 포인터끼리 메모리 주소를 저장하면 컴파일 경고(warning)가 발생한다. 하지만 void 포인터는 자료형이 정해지지 않은 특성때문에 어떤 자료형으로 된 포인터든 모두 저장할 수 있다. 반대로 다양한 자료형으로 된 포인터에도 void 포인터를 저장할 수 있다. 이런 특성 때문에 void 포인터는 범용 포인터라고 한다.

       - 모든 타입의 포인터를 인자로 받을 수 있게 하도록하기 위해 `void *` 타입으로 선언
     - `unsigned char *` 로 형변환하는 이유
       - void 포인터는 역참조를 할 수 없기 때문에 함수 내부에서 참조하기 위해서는 다른 자료형으로 형변환을 해줘야한다.
       - `metset()` 함수는 byte 단위로 메모리 영역을 setting하는 함수이기 때문에 자료형의 크기가 1 byte인 `unsigned char` 타입으로 형변환을 해줘야한다.
       - `unsigned` 로 형변환을 해주는 이유는 **C 언어 표준에서는 unsigned char만을 패딩이 없는 자료형으로 보증**하기 때문이다.
         - 패딩은 길이를 맞추기 위해 추가하는 쓸 데 없는 비트를 의미한다.
         - ex) `true, false` 를 표현하기 위해 1, 0 만을 값으로 갖는 자료형을 만든다고 하면 1, 0만 있으면 되기 때문에 1비트만 있으면 충분하다. 하지만, 메모리에 데이터를 쓰고 읽는 것은 최소 바이트 단위로 이루어지기 때문에, 1바이트(8비트)를 모두 써서 `00000000, 00000001` 라는 형태로 0과 1을 표현할 수 밖에 없다. 이 때 위처럼 깔끔하게 유효한 비트를 맨 오른쪽에 넣을 수도 있지만 "우리는 유효한 비트를 세 번째 자리에 넣읍시다" 라고 약속하고 `true, false` 를  `00000000, 00100000` 로 정의할 수도 있다. 이 때 저 무의미한 0들, 오직 자릿수 맞추기 용도인 저 0들을 패딩비트라고 부른다.
         - C 언어 표준에서는 문자 단위로 조작할 때는 `char`, byte 단위로 조작할 때는 `unsigned char` 를 사용하라고 한다.
  2. memory 영역을 setting할 argument를 `int` 타입으로 받는 이유

     - `unsigned char` 타입으로 받으면 0 ~ 255 외의 값에 대해 알 수 없기 때문에 `int` 로 받는다.

#### `bzero()`

- SYNOPSIS

  - ```c
    #include <strings.h>
    void	bzero(void *s, size_t n);
    ```

- DESCRIPTION

  - `pointer s` 가 가리키는 메모리 영역의 `n byte` 만큼을 0으로 채운다.

- RETURN VALUE

  - X

- Solve

  - ```c
    #include <stddef.h>
    
    void	ft_bzero(void *s, size_t n)
    {
    	unsigned char	*ptr;
    	size_t			i;
    
    	ptr = (unsigned char *) s;
    	i = 0;
    	while (i < n)
    		ptr[i++] = 0;
    }
    ```

#### `memcpy()`

- SYNOPSIS

  - ```c
    #include <string.h>
    
    void *	memcpy(void *restrict dst, const void *restrict src, size_t n);
    ```

- DESCRIPTION

  - 메모리 영역 `src` 에서 메모리 영역 `dst` 로 `n byte` 만큼 복사한다. 메모리 영역은 겹치지 않아야 한다. 메모리 영역이 겹치는 경우 `memmove()` 함수를 사용해야 한다.

- RETURN VALUE

  - `dst`

- Solve

  - ```c
    
    ```

- Questions

  1. `restrict`

     - **'포인터 변수의 주소가 겹치지 않는다'**고 컴파일러에게 알려줌으로써, 최적화를 할 수있도록 하는 키워드

     - ex)
     
       - 위와 같이 포인터를 역참조하여 값을 증가시키는 두 함수가 있다고 하면, 컴파일러는 이 두 함수를 다르게 해석한다.
     
       - ```c
         // add1()
         load R1 ← *c
         load R2 ← *a
         add R2 += R1
         set R2 → *a
         
         load R1 ← *c
         load R2 ← *b
         add R2 += R1
         set R2 → *b
         ```
     
       - ```c
         // add2()
         load R1 ← *c
         load R2 ← *a
         add R2 += R1
         set R2 → *a
         
         load R2 ← *b
         add R2 += R1
         set R2 → *b
         ```
     
       - `add1()` 에서는 이미 R1 레지스터(임시공간)에 로드했던 `c` 를 또 한번 로드한다. 그 이유는 다른 포인터에 의해서 `c` 의 값이 바뀌었을 가능성이 있기 때문이다.
     
       - `add2()` 에서는 이전에 로드했던 `c` 값이 아직 R1 레지스터에 존재하고, 컴파일러는 이 공간이 **다른 포인터에 의해 값이 변경되지 않는다**고 알고있기 때문에 기존 R1의 값을 그대로 사용한다.
     
       - `restrict` 키워드는 명시적 제약이다. `restrict` 포인터를 써놓고 같은 메모리를 역참조하는 포인터를 만들어도 컴파일 에러를 발생하지 않기 때문에 논리적 오류를 범할 가능성이 있다.

  2. 원본함수와 어느정도 같아야 하는가?
     - [libft]
       library 함수들을 구현할 때, 원본 함수와 어느정도까지 똑같아야 할까요..?
       예를들면 지금 memcpy를 구현하는 중인데, 같은 상황에서 원본 함수는 'illegal hardware instruction'가 뜨는데, 제 함수는 'segmentation fault'가 뜬다던지, 
       원본 함수는 에러가 발생하는데, 제 함수는 에러가 발생하지 않는다던지 하면 똑같이 되도록 해야할까요..?
