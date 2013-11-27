all: checkEnv clean pauseWrapper.o launcher launcherOMP launcherMPI

.PHONY: checkEnv clean

pauseWrapper.o: pauseWrapper.cu
	nvcc -c -arch=sm_35 pauseWrapper.cu
launcher: launcher.cpp pauseWrapper.o
	mkdir -p bin
	CC -o bin/launcher pauseWrapper.o launcher.cpp
launcherOMP: launcherOMP.cpp pauseWrapper.o
	mkdir -p bin
	CC -o bin/launcherOMP pauseWrapper.o launcherOMP.cpp
launcherMPI: launcherMPI.cpp pauseWrapper.o
	mkdir -p bin
	CC -o bin/launcherMPI pauseWrapper.o launcherMPI.cpp

checkEnv:
ifndef CRAY_CUDATOOLKIT_VERSION
	$(error cudatoolkit module not loaded)
endif

clean:
	rm -f *.o
	rm -rf bin
