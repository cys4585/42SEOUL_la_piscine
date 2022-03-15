# libft



## 1. 정적 라이브러리

- 라이브러리

  - 다른 프로그램들과 링크되기 위하여 존재하는, 하나 이상의 서브루틴(subroutine)이나 함수(function)들의 집합 파일
  - 라이브러리들은 사용자의 프로그램과 링크되어 실행이 가능한 완전한 프로그램을 이룬다.

- 정적 라이브러리

  - 프로그램 빌드 시에 라이브러리가 제공하는 코드를 실행 파일에 넣는 방식의 라이브러리

  - 컴파일된 오브젝트 파일들이 하나의 archive로 묶여있는 형태

  - 컴파일의 링크 단계에서 실행 파일에 결합된다.

    - 컴파일 단계
      - ![img](https://blog.kakaocdn.net/dn/x8xPL/btq0HabcJAh/n5rCuGjzpUtynbDi3n00m0/img.png)	

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



## 2. Makefile



## 3. Libc functions (Standard C Library)

- `isalpha`

  - SYNOPSIS

    - `int isalpha(int c);`

  - DESCRIPTION

    - argument가 isupper or islower인지 test하는 함수
    - argument의 value는 (unsigned char or EOF 값)으로 표현되어야 한다.

  - RETURN VALUE

    - True -> 1
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

    - argument를 int 타입으로 받아야 하는 이유? 받아도 되는 이유?
      - C언에서 문자를 넣으면 자동으로 아스키 코드에 해당하는 숫자로 들어가기 때문
      - 즉, 'a'와 같은 char 타입으로 집어 넣어도 자동으로 int 타입으로 형변환 되어서 들어가게 된다.

- `isdigit`

  - SYNOPSIS

    - `int isdigit(int c);`

  - DESCRIPTION

    - argument가 decimal digit character인지 test하는 함수

  - RETURN VALUE

    - True -> 1
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