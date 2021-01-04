.PHONY: release

release:
	make clean
	mkdir build
	cd build && cmake .. && make

debug:
	make clean
	mkdir build
	cd build && cmake -DBUILD_RELEASE=OFF .. && make

clean:
	rm -rf build