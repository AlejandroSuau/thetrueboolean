
# Para obtener los repositoros
```
git clone https://github.com/libsdl-org/SDL.git
```
```
git clone https://github.com/libsdl-org/SDL_image.git
```

_Nota: Importante hacer checkout a las ramas SDL2 de ambos repositorios._
# Compilando SDL

### Compilamos para x86_64:
```
cd SDL
```
```
mkdir build_x86_64
```
```
cd build_x86_64
```
```
cmake -DCMAKE_OSX_ARCHITECTURES=x84_64 ..
```
```
make
```

### Compilamos para arm64:
```
cd SDL
```
```
mkdir build_arm64
```
```
cd build_arm64
```
```
cmake -DCMAKE_OSX_ARCHITECTURES=arm64 ..
```
```
make
```
# Compilando SDL_Image

### Compilamos para x86_64:
```
cd SDL_Image
```
```
mkdir build_x86_64
```
```
cd build_x86_64
```
```
cmake .. -DBUILD_SHARED_LIBS=OFF -DCMAKE_OSX_ARCHITECTURES=arm64 \ -DSDL2_DIR=../../SDL/build_x86_64 \ -DSDL2_INCLUDE_DIR=../../SDL/build_x86_64/include/SDL2 \ -DSDL2_LIBRARY=../../SDL/build_x86_64/libSDL2-
```
```
make
```

### Compilamos para arm64:
```
cd SDL_Image
```
```
mkdir build_arm64
```
```
cd build_arm64
```
```
cmake .. -DBUILD_SHARED_LIBS=OFF -DCMAKE_OSX_ARCHITECTURES=arm64 \ -DSDL2_DIR=../../SDL/build_arm64 \ -DSDL2_INCLUDE_DIR=../../SDL/build_arm64/include/SDL2 \ -DSDL2_LIBRARY=../../SDL/build_arm64/libSDL2-2.0.0.dylib
```
```
make
```

# Youtube
* [The True Boolean](https://www.youtube.com/@The.TrueBoolean)
