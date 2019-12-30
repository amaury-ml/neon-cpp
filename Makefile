neon.o: neon.h neon_types.h neon.inl arm-neon.cpp
	clang++ --std=c++11 arm-neon.cpp --target=aarch64-linux-gnu -I /usr/aarch64-linux-gnu/include/ -I /usr/aarch64-linux-gnu/include/c++/8 -I . -c -O2 -g -o $@

neon.inl: gen/gen-intrin.py
	python gen/gen-intrin.py > neon.inl

