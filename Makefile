GCC_BIN ?= $(shell which gcc)
CARGO_BIN ?= $(shell which cargo)

run: clean build
	./examples/example
clean:
	$(CARGO_BIN) clean
	rm -f ./examples/example
build:
	$(CARGO_BIN) build --release
	$(GCC_BIN) -o ./examples/example ./examples/example.c -Isrc  -L. -l:target/release/libwhatlang.so
