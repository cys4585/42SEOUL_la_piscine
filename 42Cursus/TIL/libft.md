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

     - C언에서 문자를 넣으면 자동으로 아스키 코드에 해당하는 숫자로 들어간다.
     - `char` 타입보다 범위가 더 큰 `int` 타입으로 받음으로써 인자를 안전하게 받을 수 있다. 
       - `char` 타입으로 받으면 언더플로우or오버플로우가 나는데, 이렇게 되면 의도한 동작을 할 수 없다. `int`로 받으면 보다 안전하게 받을 수 있다.

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
    	size_t	size;
    
    	size = 0;
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
     - `unsigned int`는 운영체제에 따라 사이즈가 달라지기 때문에 고정된 `size_t`를 사용한다.
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

  - 메모리 영역 `src` 에서 메모리 영역 `dst` 로 `n byte` 만큼 복사한다. 메모리 영역은 겹치지 않아야 한다. 메모리 영역이 겹치는 경우(overlap) `memmove()` 함수를 사용해야 한다.

- RETURN VALUE

  - 포인터 `dst`

- Solve

  - ```c
    #include <stddef.h>
    
    void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
    {
    	unsigned char	*dst_p;
    	unsigned char	*src_p;
    	size_t			i;
    
    	if (dst == src)
    		return (dst);
    	dst_p = (unsigned char *) dst;
    	src_p = (unsigned char *) src;
    	i = 0;
    	while (i < n)
    	{
    		dst_p[i] = src_p[i];
    		i++;
    	}
    	return (dst);
    }
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

#### `memmove()`

- SYNOPSIS

  - ```c
    #include <string.h>
    void	*memmove(void *dst, const void *src, size_t len);
    ```

- DESCRIPTION

  - `src`에서 `dst`로 `len byte` 만큼 복사한다. 
  - `src`와 `dst`는 overlap될 수 있다. 복사는 항상 non-destructive manner(비파괴적인 방식)으로 수행된다.

- RETURN VALUE

  - 포인터 `dst`

- Solve

  - ```c
    #include <stddef.h>
    
    void	*ft_memmove(void *dst, const void *src, size_t len)
    {
    	size_t	i;
    
    	if (len == 0 || dst == src)
    		return (dst);
      // src < dst이고, dst와 src가 overlap되면 뒤에서부터 copy한다.
    	if (src < dst && dst < src + len)
    	{
    		while (0 <= --len)
    		{
    			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
          // len은 항상 0 이상이기 때문에, break point를 설정해준다.
    			if (len == 0)
    				break ;
    		}
    	}
    	else
    	{
    		i = 0;
    		while (i < len)
    		{
    			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    			i++;
    		}
    	}
    	return (dst);
    }
    ```

- Questions

  1. **비파괴적인 방식으로 복사**한다는게 무엇인가?
     - `dst`와 `src`의 메모리 영역이 overlap되면 복사하는 과정에서 값이 오염될 수 있다. 이를 방지하는 방식을 비파괴적인 방식이라고 한다.

#### `strlcpy()`

- SYNOPSIS

  - ```c
    #include <string.h>
    size_t	strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
    ```

- DESCRIPTION

  - 문자열을 복사한다. `strncpy()` 보다 안전하고 일관성 있고 오류가 적은 대체품으로 설게되었다.
  - `dst` 버퍼의 전체 크기를 사용하고, 공간이 있는 경우 NUL-termination을 보장한다. NUL을 위한 공간은 `dstsize`에 포함되어야 한다.
  - `src`에서 `dst`로 `dstsiz - 1` 글자를 복사하고, `dstsize`가 0이 아닌 경우 결과를 NUL 종료한다.
  - `dst`와 `src`가 overlap되는 경우, 동작이 정의되지 않는다.

- RETURN VALUE

  - `src`의 길이(복사를 시도한 문자열의 총 길이)
  - `return value >= dstsize` 이면 복사가 제대로 된 것이 아니다. 이를 처리하는 것은 호출자의 책임이다.

- RETURN VALUE

- Solve

  - ```c
    #include <stddef.h>
    
    size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
    {
    	size_t	i;
    
    	i = 0;
      // dstsize - 1까지 반복 or src 문자열 끝까지 반복
    	while (i + 1 < dstsize && src[i] != '\0')
    	{
    		dst[i] = src[i];
    		i++;
    	}
    	dst[i] = '\0';
    	while (src[i] != '\0')
    		i++;
    	return (i);
    }
    ```

#### `strlcat()`

- SYNOPSIS

  - ```c
    #include <string.h>
    size_t	strlcat(char *dst, const char *src, size_t dstsize);
    ```

- DESCRIPTION

  - 문자을 연결한다. `strncat()`보다 안전하고 일관성 있고 오류가 적은 대체품으로 설계되었다.
  - `dst` 버퍼의 전체 크기를 사용하고, 공간이 있는 경우 NUL-termination을 보장한다. NUL을 위한 공간은 `dstsize`에 포함되어야 한다.
  - `dst`의 끝에 `src` 문자열을 연결한다. 최대 `dstsize - strlen(dst) - 1` 글자를 추가한다. 그런 다음 `dstsize == 0` 이거나 `dst` 문자열이 `dstsize`보다 길지 않는 한 NUL 종료된다. (실제로 이것은 `dstsize`가 올바르지 않거나 `dst`가 적절한 문자열이 아님을 의미하므로 발생해서는 안된다.)

- RETURN VALUE

  - (`dst` 초기 길이 / `dstsize` 중 작은 값) + `src`의 길이

- Solve

  - ```c
    #include <stddef.h>
    
    size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
    {
    	size_t	init_len_of_dst;
    	size_t	i;
    
    	init_len_of_dst = 0;
    	while (dst[init_len_of_dst])
    		init_len_of_dst++;
    	i = 0;
      // dstsize == 0 이거나 dst 문자열이 dstsize 보다 길면
      if (dstsize == 0 || dstsize < init_len_of_dst)
    	{
    		while (src[i])
    			i++;
    		return (dstsize + i);
    	}
    	while (init_len_of_dst + i + 1 < dstsize && src[i])
    	{
    		dst[init_len_of_dst + i] = src[i];
    		i++;
    	}
    	dst[init_len_of_dst + i] = '\0';
    	while (src[i])
    		i++;
    	return (init_len_of_dst + i);
    }
    ```

- Questions

  1. return value: **(`dst` 초기 길이 / `dstsize` 중 작은 값) + `src`의 길이**인 이유
     - `dst`가 `dstsize`보다 큰 경우는 문자열을 이어붙일 수가 없다. 
     - `dst` 문자열이 잘리는지를 감지를 간단하게 하기 위해 수행된다.

#### `toupper()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int	toupper(int c);
    ```

- DESCRIPTION

  - 소문자를 해당 대문자로 변환한다.
  - argument는 `unsigned char` or `EOF` 값으로 표현할 수 있어야 한다.

- RETURN VALUE

  - argument에 대응되는 대문자가 있는 경우 => return 해당 대문자
  - else => return argument 그대로

- Solve

  - ```c
    int	ft_toupper(int c)
    {
    	if ('a' <= c && c <= 'z')
    		return (c - ('a' - 'A'));
    	return (c);
    }
    ```

#### `tolower()`

- SYNOPSIS

  - ```c
    #include <ctype.h>
    int	tolower(int c);
    ```

- DESCRIPTION

  - 대문자를 해당 소문자로 변환한다.

  - argument는 `unsigned char` or `EOF` 값으로 표현할 수 있어야 한다.

- RETURN VALUE

  - argument에 대응되는 소문자가 있는 경우 => return 해당 소문자
  - else => return argument 그대로

- Solve

  - ```c
    int	ft_tolower(int c)
    {
    	if ('A' <= c && c <= 'Z')
    		return (c - ('A' - 'a'));
    	return (c);
    }
    ```

#### `strchr()`

- SYNOPSIS

  - ```c
    #include <string.h>
    char	*strchr(const char *s, int c);
    ```

- DESCRIPTION

  - `s`가 가리키는 문자열에서 `c` 문자가 처음 나타나는 위치를 찾는다. (Null 문자도 문자열의 일부로 간주)

- RETURN VALUE

  - 문자의 위치를 찾으면 => return 문자에 대한 포인터
  - 못찾으면 => return NULL

- Solve

  - ```c
    #include <stddef.h>
    
    char	*ft_strchr(const char *s, int c)
    {
    	int		i;
    
    	i = 0;
    	while (s[i])
    	{
    		if (s[i] == c)
    			return ((char *)s + i);
    		i++;
    	}
    	if (s[i] == c)
    		return ((char *)s + i);
    	return (NULL);
    }
    ```

#### `strrchr()`

- SYNOPSIS

  - ```c
    #include <string.h>
    char	*strrchr(const char *s, int c);
    ```

- DESCRIPTION

  - `s`가 가리키는 문자열에서 `c` 문자가 마지막으로 나타나는 위치를 찾는다. (Null 문자도 문자열의 일부로 간주)

- RETURN VALUE

  - 문자의 위치를 찾으면 => return (문자에 대한 포인터)
  - 못찾으면 => return NULL

- Solve

  - ```c
    #include <stddef.h>
    
    char	*ft_strrchr(const char *s, int c)
    {
    	char	*result;
    	int		i;
    
    	result = NULL;
    	i = 0;
    	while (s[i])
    	{
    		if (s[i] == c)
    			result = (char *)s + i;
    		i++;
    	}
    	if (s[i] == c)
    		result = (char *)s + i;
    	return (result);
    }
    ```

#### `strncmp()`

- SYNOPSIS

  - ```c
    #include <string.h>
    int	strncmp(const char *s1, const char *s2, size_t n);
    ```

- DESCRIPTION

  - null 문자로 끝나는 문자열 `s1`과 `s2`를 사전식으로 비교한다.
  - `n`개 이하의 문자를 비교한다. `strncmp()`는 바이너리 데이터가 아닌 문자열을 비교하도록 설계되었기 때문에 `'\0'` 문자 뒤에 나타나는 문자는 비교되지 않는다.
  - 아스키 코드값으로 비교한다.

- RETURN VALUE

  - `s1` 문자열과 `s2` 문자열의 문자가 다른 시점의 아스키 코드값의 차이를 리턴한다.
  - `s1 == s2` => `return 0`
  - `s1 < s2` => `return 음의 정수`
  - `s1 > s2` => `return 양의 정수`

- Solve

  - ```c
    #include <stddef.h>
    
    int	ft_strncmp(const char *s1, const char *s2, size_t n)
    {
    	size_t	i;
    
    	i = 0;
    	while (s1[i] && s2[i] && i < n)
    	{
    		if (s1[i] != s2[i])
    			return ((int)(s1[i] - s2[i]));
    		i++;
    	}
    	if (i == n)
    		return (0);
    	return ((int)(s1[i] - s2[i]));
    }
    ```

#### `memchr()`

- SYNOPSIS

  - ```c
    #include <string.h>
    void	*memchr(const void *s, int c, size_t n);
    ```

- DESCRIPTION

  - `c`의 첫 번째 인스턴스에 대해 `s`가 가리키는 메모리 영역의 초기 `n` byte를 스캔한다. `c`와 `s`가 가리키는 메모리 영역의 바이트는 모두 `unsigned char`로 해석된다.
  - 메모리 영역 `s`의 처음부터 `n` byte에서 `c`가 처음 나타나는 위치를 찾는다.

- RETURN VALUE

  - 위치를 찾으면 => return 그 위치에 대한 포인터
  - 못찾으면 => return NULL

- Solve

  -  ```c
     #include <stddef.h>
     
     void	*ft_memchr(const void *s, int c, size_t n)
     {
     	size_t	i;
     
     	i = 0;
     	while (i < n)
     	{
     		if (((unsigned char *)s)[i] == (unsigned char)c)
     			return ((void *)s + i);
     		i++;
     	}
     	return (NULL);
     }
     ```

#### `memcmp()`

- SYNOPSIS

  - ```c
    #include <string.h>
    int	memcmp(const void *s1, const void *s2, size_t n);
    ```

- DESCRIPTION

  - 메모리 영역 `s1`과 `s2`의 처음 `n` byte를 비교한다.

- RETURN VALUE

  - `s1`이 `s2` 보다 작으면 음의 정수, 같으면 0, 크면 양의 정수
  - ` https://www.google.com/webhp?hl=ko&sa=X&ved=0ahUKEwiA_tvWt9v2AhUTBd4KHRm0COwQPAgI s1 == s2` => `return 0`
  - `s1 < s2` => `return 음의 정수`
  - `s1 > s2` => `return 양의 정수`

- Solve

  - ```c
    #include <stddef.h>
    
    int	ft_memcmp(const void *s1, const void *s2, size_t n)
    {
    	unsigned char	*s1_p;
    	unsigned char	*s2_p;
    	size_t			i;
    
    	s1_p = (unsigned char *)s1;
    	s2_p = (unsigned char *)s2;
    	i = 0;
    	while (i < n)
    	{
    		if (s1_p[i] != s2_p[i])
    			return (s1_p[i] - s2_p[i]);
    		i++;
    	}
    	return (0);
    }
    ```

#### `strnstr()`

- SYNOPSIS

  - ```c
    #include <string.h>
    char *strnstr(const char *haystack, const char *needle, size_t len);
    ```

- DESCRIPTION

  - `haystack` 문자열의 `len` 길이 만큼에서 null 종료되는 문자열 `needle`의 첫 번째 발생 위치를 찾는다.
  - `strnstr()`은 freeBSD specific API이기 때문에 이식성이 문제가 되지 않는 경우에만 사용해야 한다.

- RETURN VALUE

  - `needle`이 빈 문자열이면 => return `haystack`
  - `needle`을 못찾으면 => return `NULL`
  - `needle`을 찾으면 => return (`needle`의 첫 번째 문자에 대한 포인터)

- Solve

  - ```c
    #include "libft.h"
    // ft_strlen(), ft_strncmp()
    
    char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
    {
    	size_t	len_h;
    	size_t	len_n;
    	size_t	i;
    
    	if (needle[0] == '\0')
    		return ((char *)haystack);
    	len_h = ft_strlen(haystack);
    	len_n = ft_strlen(needle);
    	i = 0;
    	while ((i + len_n <= len) && (i + len_n <= len_h))
    	{
    		if (haystack[i] == needle[0]
    			&& ft_strncmp(&haystack[i], needle, len_n) == 0)
    			return ((char *)&haystack[i]);
    		i++;
    	}
    	return (NULL);
    }
    ```

- Questions

  1. `haystack`과 `needle`은 무슨 뜻인가?

     - 속담: Needle in a haystack. (건초더미에서 바늘 찾기)

     - `haystack` - 스캔할 기본 C 문자열을 비유

     - `needle` - `haystack` 내에서 검색할 작은 문자열을 비유

  2. freeBSD specific API는 무슨 뜻인가?

     - freeBSD란 유닉스 계열 운영체제를 말한다. freeBSD specific API란 말은 strnstr 함수는 운영체제에 specific하므로 다른 운영체제에 이식할 때는 쓰지 않는다는 뜻이다.

#### `atoi()`

- SYNOPSIS

  - ```c
    #include <stdlib.h>
    int	atoi(const char *str);
    ```

- DESCRIPTION

  - `str`이 가리키는 문자열의 초기 부분을 int 타입으로 변환한다.

- RETURN VALUE

  - 변환성공 => return 변환한 int형 숫자
  - 변환가능한 숫자가 없는 경우 => return 0

- Solve

  - ```c
    char	*pass_space(const char *str)
    {
    	int	i;
    
    	i = 0;
    	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
    		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
    		i++;
    	return ((char *)str + i);
    }
    
    int	check_sign(char **str_p)
    {
    	if (**str_p == '-')
    	{
    		(*str_p)++;
    		return (-1);
    	}
    	else if (**str_p == '+')
    		(*str_p)++;
    	return (1);
    }
    
    int	convert_to_int(char *str)
    {
    	int	num;
    	int	i;
    
    	num = 0;
    	i = 0;
    	while ('0' <= str[i] && str[i] <= '9' && str[i])
    	{
    		num = num * 10 + (str[i] - '0');
    		i++;
    	}
    	return (num);
    }
    
    int	ft_atoi(const char *str)
    {
    	char	*tmp_str;
    	int		sign;
    
    	tmp_str = pass_space(str);
    	sign = check_sign(&tmp_str);
    	return (sign * convert_to_int(tmp_str));
    }
    ```

- Questions
  1. 특정 값 이상부터는 `atoi`랑 결과가 다른데? 
     - 원본 `atoi`는 int 오버플로우는 그냥 무시되고 long 오버플로우부터 결과값이 바뀐다.
     - 그러나 이 부분은 Undefined Behavior이기 때문에 똑같을 필요는 없다.

#### `calloc()`

- 이 함수는 외부 함수 `malloc` 을 사용해 구현

- SYNOPSIS

  - ```c
    #include <stdlib.h>
    void	*calloc(size_t count, size_t size);
    ```

- DESCRIPTION
  - 메모리를 할당한다. 할당된 메모리는 AltiVec 및 SSE 관련 유형을 포함한 모든 데이터 유형에 사용할수 있도록 정렬된다.
  - `free()` 함수로 할당된 메모리를 해제한다.
  - `malloc()` 함수는 size 바이트의 메모리를 할당하고 할당된 메모리에 대한 포인터를 반환한다.
  - `calloc()` 함수는 `size` 바이트의 개체를 `count` 만큼 메모리를 할당하고 할당된 메모리에 대한 포인터를 반환한다. 할당된 메모리는 값이 0인 바이트로 채워진다.

- RETURN VALUE

  - 메모리 할당 성공 => return (할당된 메모리에 대한 포인터)
  - 실패 => return NULL

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    void	*ft_calloc(size_t count, size_t size)
    {
    	void	*memory;
    
    	memory = malloc(count * size);
    	if (memory == NULL)
    		return (NULL);
    	ft_bzero(memory, count * size);
    	return (memory);
    }
    ```

#### `strdup()`

- SYNOPSIS

  - ```c
    #include <string.h>
    char	*strdup(const char *s1);
    ```

- DESCRIPTION
  - 문자열 `s1`의 복사본을 위한 충분한 메모리를 할당하고 복사를 수행하고 이에 대한 포인터를 반환한다.

- RETURN VALUE

  - 성공 => return 복사한 공간에 대한 포인터
  - 실패 => return NULL

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strdup(const char *s1)
    {
    	int		len;
    	char	*dst;
    	int		i;
    
    	len = ft_strlen(s1);
    	dst = (char *)malloc(sizeof(char) * len);
    	if (dst == NULL)
    		return (NULL);
    	i = 0;
    	while (i < len)
    	{
    		dst[i] = s1[i];
    		i++;
    	}
    	return (dst);
    }
    ```



### Part 2 - Additional functions

#### `substr()`

- Prototype

  - ```c
    char	*ft_substr(char const *s, unsigned int start, size_t len);
    ```

- Parameters

  - `s` : 부분 문자열(substring)을 생성할 원본 문자열

    > The string from which to create the substring.
  - `start`: 부분 문자열에 넣을 문자열 `s`의 맨 처음 인덱스

    > The start index of the substring in the string `s`.
  - `len`: 부분 문자열의 최대 길이

    > The maximum length of the substring.

- Return value

  > The substring.
  > NULL if the allocation fails.

- External functions

  - `malloc`

- Description

  - `malloc()`을 이용하여 메모리를 할당받은 후, 원본 문자열 `s`로부터 부분 문자열을 생성하여 반환한다. 부분 문자열은 인덱스 `start` 부터 시작하며, 최대 길이 `len`을 갖는다.

    > Allocates (with malloc(3)) and returns a substring from the string `s`.
    > The substring begins at index `start` and is of maximum size `len`.

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_substr(char const *s, unsigned int start, size_t len)
    {
    	char			*sub;
    	unsigned int	i;
    	size_t			s_len;
    
      if (s == NULL)
        return (NULL);
    	s_len = ft_strlen(s);
      // start 인덱스가 말이 안되면 빈문자열을 만들어주기 위함
    	if (s_len <= start)
    		len = 0;
      // s 문자열로부터 복사할 수 있는 문자열의 길이가 len 값 보다 작으면 할당할 메모리 크기가 len 보다 작아도 됨
    	else if (s_len - start < len)
    		len = s_len - start;
      //  null 문자 자리 +1 해주기
    	sub = (char *)malloc(sizeof(char) * (len + 1));
      // 공간 할당 실패 시 return NULL
    	if (sub == NULL)
    		return (NULL);
    	i = 0;
    	while (i < len)
    	{
    		sub[i] = s[start + i];
    		i++;
    	}
    	sub[i] = '\0';
    	return (sub);
    }
    ```

- Questions

  1.  `char const *s`의 의미?
     - `const char *s`는 `char const *s`와 같은 의미이다. 포인터 변수 `s`가 가리키는 곳의 값을 수정할 수 없다. 포인터 변수 `s`의 값은 수정할 수 있다. (다른 곳을 가리키게 할 수 있다.)
     - `char * const s`는 포인터 변수 `s`의 값을 수정할 수 없다. (다른 곳을 가리키게 할 수 없다.) 포인터 자체가 상수화 된 것이다.

#### `strjoin()`

- Prototype

  - ```c
    char	*ft_strjoin(char const *s1, char const *s2);
    ```

- Parameters

  - `s1`: 접두 문자열

    > The prefix string.

  - `s2`:  접미 문자열

    > The suffix string.

- Return value

  > The new string.
  > NULL if the allocation fails.

- External functions

  - `malloc`

- Description

  - `malloc()`을 활용해 새로운 문자열 공간을 할당하고, 문자열 `s1`과 `s2`를 연결한 새로운 문자열을 반환한다.

    > Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of `s1` and `s2`.

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strjoin(char const *s1, char const *s2)
    {
    	char	*new_str;
    	size_t	len_s1;
    	size_t	len_s2;
    
    	if (s1 == NULL && s2 == NULL)
    		return (NULL);
    	if (s1 == NULL)
    		return (ft_strdup(s2));
    	if (s2 == NULL)
    		return (ft_strdup(s1));
    	len_s1 = ft_strlen(s1);
    	len_s2 = ft_strlen(s2);
    	new_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    	if (new_str == NULL)
    		return (NULL);
    	ft_strlcpy(new_str, s1, len_s1 + 1);
    	ft_strlcat(new_str, s2, len_s1 + len_s2 + 1);
    	return (new_str);
    }
    ```

#### `strtrim()`

- Prototype

  - ```c
    char	*ft_strtrim(char const *s1, char const *set);
    ```

- Parameters

  - `s1`: 양 쪽을 잘라낼 원본 문자열

    > The string to be split.

  - `s2`: 제거될 문자들의 집합

    > The delimiter character.

- Return value

  - 문자가 제거된 문자열. 할당 실패 시, NULL

    > The trimmed string.
    > NULL if the allocation fails.

- External functions

  - `malloc`

- Description

  - `malloc()`을 이용하여 메모리를 할당하고,  `set`에 지정된 문자들이 문자열의 시작과 끝에서 제거된 `s1` 문자열의 사본을 반환한다.

    > Allocates (with malloc()) and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string.

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strtrim(char const *s1, char const *set)
    {
    	int		begin_idx;
    	int		end_idx;
    
    	if (s1 == NULL)
    		return (NULL);
    	if (set == NULL)
    		return (ft_strdup(s1));
    	begin_idx = 0;
    	while (s1[begin_idx] && ft_strchr(set, s1[begin_idx]))
    		begin_idx++;
    	end_idx = ft_strlen(s1) - 1;
    	while (0 <= end_idx && ft_strchr(set, s1[end_idx]))
    		end_idx--;
    	if (end_idx < begin_idx)
    		return (ft_strdup(""));
    	return (ft_substr(s1, begin_idx, end_idx - begin_idx + 1));
    }
    ```

#### `split()`

- Prototype

  - ```c
    char	**ft_split(char const *s, char c);
    ```

- Parameters

  - `s`: 분할할 문자열

    > The string to be split.

  - `c`: 구분자

    > The delimiter character.

- Return value

  - split을 통해 분할된 문자열의 배열

    > The array of new strings resulting from the split.
    > NULL if the allocation fails.

- External functions

  - `malloc`, `free`

- Description

  - `malloc()`을 이용하여 메모리를 할당하고, 구분자 `c`를 기준으로 문자열 `s`를 분할하여 그 결과를 담은 새로운 문자열 배열을 반환한다. 문자열 배열의 끝은 NULL 포인터로 끝나야 한다.

    > Allocates (with malloc()) and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must end with a NULL pointer.

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    // 문자열을 분할해서 담을 배열의 크기를 계산하는 함수
    int	count_size(char const *s, char c)
    {
    	int	cnt;
    	int	flag;
    	int	i;
    
    	cnt = 0;
      // split 할 지점을 판별하기 위한 flag
    	flag = 0;
    	i = 0;
    	while (s[i])
    	{
    		if (flag == 0 && s[i] != c)
    			flag = 1;
    		else if (flag == 1 && s[i] == c)
    		{
    			cnt++;
    			flag = 0;
    		}
    		i++;
    	}
    	if (flag == 1)
    		cnt++;
    	return (cnt);
    }
    
    // 문자열을 delimiter를 기준으로 분할해서 배열에 담는 함수
    int	split_str(char **dst_arr, char const *s, char c, int s_len)
    {
    	int		start;
    	int		flag;
    	int		i;
    
    	start = 0;
    	flag = 0;
    	i = 0;
      // s 문자열의 null-terminate 문자까지 반복문 돈다. (마지막이 c 가 아닌 문자로 끝나도 배열에 분할한 문자열을 담을 수 있도록 하기 위함)
    	while (i <= s_len)
    	{
    		if (flag == 0 && s[i] != c)
    		{
    			start = i;
    			flag = 1;
    		}
    		else if (flag == 1 && (s[i] == c || s[i] == '\0'))
    		{
    			*dst_arr = ft_substr(s, start, i - start);
          // 공간할당에 실패하면 비정상종료임을 알려줌으로써 공간 해제(free)를 할 수 있도록 한다.
    			if (*dst_arr == NULL)
    				return (0);
    			dst_arr++;
    			flag = 0;
    		}
    		i++;
    	}
    	return (1);
    }
    
    // 할당했던 모든 공간을 해제 (각 배열의 요소들도 각각 동적할당을 해줬기 때문에 직접 해제해줘야 한다.)
    void	array_free(char **arr)
    {
    	int	i;
    
    	i = 0;
    	while (arr[i])
    		free(arr[i++]);
    	free(arr);
    }
    
    char	**ft_split(char const *s, char c)
    {
    	int		size;
    	char	**dst_arr;
    
      // 1. 필요한 공간의 크기를 구한다.
    	size = count_size(s, c);
      // 2. (필요한 공간 + 1)만큼 공간할당을 한다. (마지막 NULL 자리)
    	dst_arr = (char **)malloc(sizeof(char **) * (size + 1));
    	if (dst_arr == NULL)
    		return (NULL);
    	dst_arr[size] = NULL;
      // 3. 문자열을 split 해서 공간할당을 한 배열에 각각 담는다.
    	if (split_str(dst_arr, s, c, ft_strlen(s)) == 0)
    	{
        // split한 문자열을 담을 공간할당에 실패하면 이 때까지 할당했던 공간을 모두 수거한다.
    		array_free(dst_arr);
    		return (NULL);
    	}
    	return (dst_arr);
    }
    ```

- Notes

  1. 문자열의 양 쪽 끝 문자가 delimiter 일수도, 일반 문자 일수도 있다.

     - `s = "abc&def&"`
     - `s = "abc&def"`
       - '\0'` 문자까지 반복문이 돌도록 해서, delimiter와 같은 케이스로 묶음으로써 해결

     - `s = "&abc&def"`
       - `flag`의 init을 통해 첫 글자가 delimiter인 경우 그냥 지나가도록 해결

  2. delimiter가 이어질 수도 있다.

     -  `s = "abc&def&&abc"`
       - `flag` 를 둬서 (delimiter or 일반 문자)가 이어지는 경우는 그냥 지나가도록 해결

  3. 공간 할당 실패 시

     - 이 때까지 할당해줬던 모든 공간을 해제해야 한다.

#### `itoa()`

- Prototype

  - ```c
    char	*ft_itoa(int n);
    ```

- Parameters

  - `n`: 변환할 정수

    > The integer to convert.

- Return value

  - 정수를 표현할 문자열. 할당 실패 시 NULL

    > The string representing the integer.
    > NULL if the allocation fails.

- External functions

  - `malloc`

- Description

  - `malloc()`을 이용하여 메모리를 할당하고, 인자로 받은 정수를 나타내는 문자열을 반환한다. 음수 또한 무조건 처리되어야 한다.

    > Allocates (with malloc()) and returns a string representing the integer received as an argument.
    > Negative numbers must be handled.

- Solve

  - ```c
    #include <stdlib.h>
    
    // 정수를 문자열로 변환할 때 필요한 문자열의 크기를 계산하는 함수 (null-terminating 문자 자리 포함)
    int	count_size_to_allocate(int n)
    {
    	int	cnt;
    
    	if (n == 0)
    		return (2);
    	cnt = 0;
      // 음수면 (- 부호) 자리 추가
    	if (n < 0)
    		cnt++;
    	while (n != 0)
    	{
    		n /= 10;
    		cnt++;
    	}
      // null-terminating 자리 추가
    	return (cnt + 1);
    }
    
    // 한 자리씩 (정수 -> 문자)로 변환하는 재귀함수
    void	recursion_convert(char *str, int idx, int n)
    {
    	if (n < 0)
    	{
    		str[0] = '-';
    		recursion_convert(str, idx - 1, -(n / 10));
    		str[idx] = -(n % 10) + '0';
    	}
    	else if (n > 0)
    	{
    		recursion_convert(str, idx - 1, n / 10);
    		str[idx] = (n % 10) + '0';
    	}
    }
    
    char	*ft_itoa(int n)
    {
    	int		size;
    	char	*str;
    	
      // 1. 할당할 공간의 크기를 계산한다.
    	size = count_size_to_allocate(n);
      // 2. 공간을 할당하고 null-terminating 문자를 넣어준다.
    	str = (char *)malloc(sizeof(char) * size);
    	if (str == NULL)
    		return (NULL);
    	str[size - 1] = '\0';
      // exception handling
    	if (n == 0)
    	{
    		str[0] = '0';
    		return (str);
    	}
      // 3. 재귀로 한자리씩 변환한다. (정수 -> 문자)
    	recursion_convert(str, size - 2, n);
    	return (str);
    }
    ```

#### `strmapi()`

- Prototype

  - ```c
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
    ```

- Parameters

  - `s`: 함수를 적용할 문자열

    > The string on which to iterate.

  - `f`: 문자열의 각 문자에 적용할 함수

    > The function to apply to each character.

- Return value

  - 원본 문자열에서 함수 `f`를 성공적으로 적용하여 생성된 결과 문자열. 할당 실패시, NULL

    > The string created from the successive applications of `f`.
    > Returns NULL if the allocation fails.

- External functions

  - `malloc`

- Description

  - 문자열 `s`의  각 문자에 함수 `f`를 적용하고, 해당 문자의 인덱스를 함수 `f`의 첫 번째 인자로 전달하여 `f`를 연속적으로 적용한 새로운 문자열을 생성한다. (`malloc()`)을 이용하여 메모리를 할당

    > Applies the function `f` to each character of the string `s`, and passing its index as first argument to create a new string (with `malloc()`) resulting from successive applications of `f`.

- Solve

  - ```c
    #include <stdlib.h>
    #include "libft.h"
    
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
    {
    	char	*dst;
    	int		i;
    
    	if (s == NULL || f == NULL)
    		return (NULL);
    	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    	if (dst == NULL)
    		return (NULL);
    	i = 0;
    	while (s[i])
    	{
    		dst[i] = f((unsigned int)i, s[i]);
    		i++;
    	}
    	dst[i] = '\0';
    	return (dst);
    }
    ```

- Notes

  1. 함수 포인터

     - `반환타입 (*함수포인터이름)(매개변수타입))`

     - 함수 포인터는 반환타입과 매개변수타입이 모두 일치해야 할당이 가능하다.

     - 함수 포인터 할당 ex)

       - ```c
         #include <stdio.h>
         
         int	sum(int a, int b)
         {
         	return (a + b);  
         }
         
         int	main(void)
         {
           // 함수 포인터 선언
           int (*f_p)(int, int);
           
           // 함수 포인터에 함수 할당
           f_p = &sum;
           // 같은 의미 (함수이름 자체에도 함수의 주소가 저장되어 있다.)
           // f_p = sum;
           
           // 함수 포인터를 통한 함수 호출
           int num = f_p(10, 20);
          	printf("f_p(%d, %d) returns %d\n", 10, 20, num);
           return (0);
         }
         ```

#### `striteri()`

- Prototype

  - ```c
    void	ft_striteri(char *s, void (*f)(unsigned int, char *));
    ```

- Parameters

  - `s`: 함수를 적용할 문자열

    > The string on which to iterate.

  - `f`: 문자열의 각 문자에 적용할 함수

    > The function to apply to each character.

- Return value

  > None

- External functions

  > None

- Description

  - 인자로 전달된 문자열의 각 문자를 순회하며 함수 `f`를 적용하고, 해당 문자의 인덱스를 함수 `f`의 첫 번째 인자로 전달한다. 각 문자는 주소를 통해  `f` 함수에 전달되어 필요한 경우 수정된다.

    > Applies the function `f` to each character of the string passed as argument, passing its index as first argument. Each character is passed by address to `f` to the be modified if necessary.

- Solve

  - ```c
    void	ft_striteri(char *s, void (*f)(unsigned int, char *))
    {
    	unsigned int	i;
    
    	i = 0;
    	while (s[i])
    	{
    		f(i, &s[i]);
    		i++;
    	}
    }
    ```


#### `putchar_fd()`

- Prototype

  - ```c
    void	ft_putchar_fd(char *c, int fd);
    ```

- Parameters

  - `c`: 출력할 문자

    > The character to output.

  - `fd`: 값이 쓰여질 파일 식별자 (file descriptor)

    > The file descriptor on which to write.

- Return value

  - > None

- External functions

  - `write`

- Description

  - 제공받은 파일 식별자에 문자 `c`를 출력한다.

    > Outputs the character `c` to the given file descriptor.

- Solve

  - ```c
    #include <unistd.h>
    
    void	ft_putchar_fd(char c, int fd)
    {
    	if (fd < 0)
    		return ;
    	write(fd, &c, 1);
    }
    ```

- Questions

  1. `write` 함수는 무엇인가?

     - ```c
       #include <unistd.h>
       ssize_t	write(int fd, const void *buf, size_t count);
       ```

     - `write()`는  `buf`에서 시작하는 버퍼에서 file descriptor `fd`가 참조하는 파일에 `count` 바이트까지 쓰는 함수

  2. `fd` 파일 디스크립터?

     - 리눅스와 유닉스에서는 시스템을 전부 파일로 처리하여 관리한다. 시스템에서 프로세스가 파일에 접근하기 위한 방법으로 파일 디스크립터(File Descriptor)라는 핸들이 필요하다.
     - 해당 파일을 open할 때 (해당 파일에 접근할 때) 파일 디스크립터는 0부터 N까지 즉, 음수가 아닌 0부터 차례대로 숫자를 부여받는다.
     - 0, 1, 2는 프로세스가 메모리에서 실행을 시작할 때 기본적으로 할당되는 파일 디스크립터이다.
       - 0: 표준 입력(stdin)
       - 1: 표준 출력(stdout)
       - 2: 표준 오류(stderr)
     - 그러므로 우리가 생성하는 파일 디스크립터들은 3번부터 차례대로 할당받게 된다. 쉽게 생각하면, 파일 디스크립터는 파일을 다루기 위해서 해당파일의 주소를 참조하여 접근하는 형태라고 생각하면 된다.
     - https://wonillism.tistory.com/166

  3. `ssize_t`는 무엇인가?

     - signed size_t
     - 가장 큰 사이즈를 담을 수 있는 signed 데이터 타입 (음수를 포함하기 위해 사용)
       - 32bit 머신 -> signed int
       - 64bit 머신 -> signed long long

#### `putstr_fd()`

- Prototype

  - ```c
    void	ft_putstr_fd(char *s, int fd);
    ```

- Parameters

  - `s`: 출력할 문자열

    > The string to output.

  - `fd`: 값이 쓰여질 파일 식별자

    > The file descriptor on which to write.

- Return value

  > None

- External functions

  - `write`

- Description

  - 제공받은 파일 식별자에 문자열 `s`를 출력한다.

    > Outputs the string `s` to the given file descriptor.

- Solve

  - ```c
    #include <unistd.h>
    #include "libft.h"
    
    void	ft_putstr_fd(char *s, int fd)
    {
    	if (s == NULL || fd < 0)
    		return ;
    	write(fd, s, ft_strlen(s));
    }
    ```

#### `putendl_fd()`

- Prototype

  - ```c
    void	ft_putendl_fd(char *s, int fd);
    ```

- Parameters

  - `s`: 출력할 문자열

    > The string to output.

  - `fd`: 값이 쓰여질 파일 식별자

    > The file descriptor on which to write.

- Return value

  > None

- External functions

  - `write`

- Description

  - 제공받은 파일 식별자에 문자열 `s`를 출력하고, 개행을 출력한다.

    > Outputs the string `s` to the given file descriptor followed by a newline.

- Solve

  - ```c
    #include <unistd.h>
    #include "libft.h"
    
    void	ft_putendl_fd(char *s, int fd)
    {
    	if (s == NULL || fd < 0)
    		return ;
    	write(fd, s, ft_strlen(s));
    	write(fd, "\n", 1);
    }
    ```

#### `putnbr_fd()`

- Prototype

  - ```c
    void	putnbr_fd(int n, int fd);
    ```

- Parameters

  - `n`: 출력할 정수

    > The string to output.

  - `fd`: 값이 쓰여질 파일 식별자

    > The file descriptor on which to write.

- Return value

  > None

- External functions

  - `write`

- Description

  - 제공받은 파일 식별자에 정수 `n`을 출력한다.

    > Outputs the integer `n` to the given file descriptor.

- Solve

  - ```c
    #include <unistd.h>
    
    void	recursion_write(int n, int fd)
    {
    	if (n > 0)
    	{
    		recursion_write(n / 10, fd);
    		write(fd, &"0123456789"[n % 10], 1);
    	}
    	else if (n < 0)
    	{
    		write(fd, "-", 1);
    		recursion_write(-(n / 10), fd);
    		write(fd, &"0123456789"[-(n % 10)], 1);
    	}
    }
    
    void	ft_putnbr_fd(int n, int fd)
    {
    	if (fd < 0)
    		return ;
    	if (n == 0)
    		write(fd, "0", 1);
    	else
    		recursion_write(n, fd);
    }
    ```











