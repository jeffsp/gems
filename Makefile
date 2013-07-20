all:
	waf configure
	waf

run: all
	./build/debug/main_boilerplate
	./build/debug/io
	./build/debug/algo
