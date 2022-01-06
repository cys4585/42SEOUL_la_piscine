#!/bin/sh

# grep -v "#" : "#" 패턴과 매칭되지 않는 라인 선택
# sed "s/:.*//g" : ":"으로 시작하는 뒷부분을 삭제
# awk "NR % 2 == 0" : 짝수 라인만 출력
# rev : 행 좌우 반전
# sort -r : 알파벳 역순으로 정렬
# sed -n '7,15p' : 7~15 라인만 출력
# sed에서 환경변수 사용하려면 그 외의 부분을 ''으로 묶어주고, 환경변수는 ""로 묶어줘야 한다.
# tr '\n' ' ' : new line -> space
# sed 's/ /, /g' : ' ' -> ', '
# sed 's/, $/ ./' : 라인 끝에서 ', ' -> ' .' 치환
# tr -d '\n' : new line 삭제

cat /etc/passwd | grep -v "#" | sed "s/:.*//g" | awk "NR % 2 == 0" | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2"p | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/ ./' | tr -d '\n'
