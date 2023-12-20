CPP=g++ -std=c++17
TEST_LIBS=-lgtest -lgmock -pthread
#TEST_LIBS=-isystem /opt/homebrew/Cellar/googletest/1.14.0/include -L/opt/homebrew/Cellar/googletest/1.14.0/lib -lgtest -lgtest_main -pthread -o test.out
GCOVFLAGS= -fprofile-arcs -ftest-coverage
SOURCES=model/tests.cc model/smartCalc.cc

all: clean test

test:
	$(CPP) $(SOURCES) $(TEST_SOURCES) -o test $(TEST_LIBS)
	./test

fmt:
	@clang-format -i --style=Google model/*.cc model/*.h view/*.cpp view/*.h controller/*.cc controller/*.h

fmt_check:
	@clang-format -n --style=Google model/*.cc model/*.h view/*.cpp view/*.h controller/*.cc controller/*.h

gcovr_report: clean
	$(CPP) $(SOURCES) $(TEST_SOURCES) -o test $(TEST_LIBS) $(GCOVFLAGS)
	./test.out
	mkdir gcovr/
	gcovr --html-details gcovr/report.details.html
	rm -rf ./*.gc*
	open gcovr/report.details.html

clean:
	@rm -rf test
	@rm -rf test.out
	@rm -rf gcovr
	@rm -rf report
	@rm -rf build*
	@rm -rf *.info
	@rm -rf ./*.gc*
	@rm -rf *.txt
	@rm -rf *.dSYM
	@rm -rf a.out
	@rm -rf archive_SmartCalc_v2
	@rm -rf archive_SmartCalc_v2.tgz

uninstall: clean
	rm -rf build*

install: uninstall
	mkdir build
	cmake -S ./view -B ./build
	cd build; make

dist: clean
	mkdir archive_SmartCalc_v2
	cp Makefile model/*.cc model/*.h view/*.cpp view/*.h controller/*.cc controller/*.h archive_SmartCalc_v2/
	tar cvzf archive_SmartCalc_v2.tgz archive_SmartCalc_v2/

dvi:
	open doc.html