@echo off
cd ../../
rmdir /s /q "build"
rmdir /s /q "libs/win64debug"
mkdir "build"
mkdir "libs/win64debug"
cd "build"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
cmake ../libs/ -DCMAKE_BUILD_TYPE=DEBUG -G "NMake Makefiles"
nmake
cd "../libs/boost/"
start /wait bootstrap.bat
start /wait b2 -j8 --without-python --build-dir="../../build" toolset=msvc architecture=x86 address-model=64 link=static threading=multi debug
cd "../../build/"
for /r %%f in (*.lib) do @xcopy /yq "%%f" "../libs/win64debug"
cd "../"
rmdir /s /q "build"