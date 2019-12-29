neon.o: neon.h neon_types.h neon.inl
	clang++ --std=c++11 -x c++ neon.h --target=aarch64-linux-gnu -I /usr/aarch64-linux-gnu/include/ -I /usr/aarch64-linux-gnu/include/c++/8 -I . -c -o $@

neon.inl: gen/gen-intrin.py
	python gen/gen-intrin.py > neon.inl

