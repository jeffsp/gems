all:
	waf configure
	waf

run: all
	./build/debug/main_boilerplate
	./build/debug/algo
	./build/debug/io
	./build/debug/metaprogramming
