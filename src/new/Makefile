OS = $(shell uname)
ifeq ($(OS), Linux)
	GCC = gcc -pedantic -std=c++17 -Wall -Wextra -Werror
	CHECK_FLAGS = -lgtest -lcheck -pthread -lstdc++ -lm 
	MEM_CHECK = valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full -s
else
	GCC = gcc -pedantic -std=c++17 -Wall -Wextra -Werror
	CHECK_FLAGS = -lgtest -pthread -lstdc++
	MEM_CHECK = leaks --atExit -- ./test
endif

all: install open

install:
	mkdir build
	cd View && qmake && make && make clean && rm Makefile && cd ../ && mv View/s21_cal.app build

open:
	cd build && open s21_cal.app

dvi:
	open readme.md

dist: install
	cd .. && tar -czf s21_SmartCalc_v2.0.tgz src

uninstall:
	rm -rf build

tests: s21_calc.a
	$(GCC) test/s21_test.cc -o test_run $(CHECK_FLAGS) -L. -ls21_calc
	./test_run

s21_calc.o:
	$(GCC) -c Controller/s21_controller.cc Model/s21_model.cc

s21_calc.a: s21_calc.o
	ar rcs libs21_calc.a *.o
	rm -rf *.o
	ranlib libs21_calc.a

gcov_report:
	$(GCC) test/s21_test.cc Controller/s21_controller.cc Model/s21_model.cc $(CHECK_FLAGS) -lstdc++ --coverage -o ./gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

check:
	make test
	CK_FORK=no $(MEM_CHECK) ./test_run

check_style:
	cp ../materials/linters/.clang-format ./
	clang-format -n Controller/*.cc Controller/*.h Model/*.cc Model/*.h test/*.cc View/*.cpp View/*.h

style:
	cp ../materials/linters/.clang-format ./
	clang-format -i Controller/*.cc Controller/*.h Model/*.cc Model/*.h test/*.cc View/*.cpp View/*.h

clean:
	rm -rf gcov*
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf libs21_calc.a
	rm -rf report.info
	rm -rf test_run
	rm -rf report