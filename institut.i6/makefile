

GAME=cqvdle
GAME=institut
COMPILER=../I6_puny/compiler/inform6.35


all:
	make z3
	make z5
	
	
z3:
	${COMPILER} -v3 +../I6_puny/lib ${GAME}

z5:
	${COMPILER} -v5 +../I6_puny/lib ${GAME}

run3: 
	gargoyle-free ${GAME}.z3
	

run: 
	gargoyle-free ${GAME}.z5
	
	
edit:
	code ${GAME}.inf
	


# converter koala https://alex.kazik.de/2/c64-converter/

# c64 http://microheaven.com/ozmooonline/