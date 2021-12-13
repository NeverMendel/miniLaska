.PHONY: release

release:
	mkdir -p build
	cd build && cmake .. && make

debug:
	mkdir -p debug
	cd debug && cmake -DBUILD_RELEASE=OFF .. && make

clean:
	rm -rf build debug