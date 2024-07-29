
# Linux 3D-engine Library

Version: 1.0.0

A static library for a future 3D game engine using SDL2.

## Features


* Basic 2D rendering using SDL2
* Point, direction, matrix classes
* Simple game loop and event handling

## Installation

### Prerequisites

* CMake 3.10 or later
* SDL2 development libraries (libsdl2-dev on Ubuntu/Debian, SDL2.framework on macOS)

### Build Instructions

1. Clone or download this repository.
2. Create a build directory and navigate to it:

```bash
mkdir build
cd build
```

3. Run CMake to configure the build:

```bash
cmake ..
```

4. Build the library:

```bash
make
```

This will create a static library named `libengine_lib.a` in the `build` directory.

### Linking and Including

To use this library in your project, follow these steps:

1. Link the library to your project. In CMake, you can use the `target_link_libraries` command:

```cmake
target_link_libraries(your_project_name engine_lib)
```

2. Include the necessary header files from the `include` directory. In C++, you can use the `#include` directive:

```cpp
#include <engine_lib/point/point.hpp>
#include <engine_lib/direction/direction.hpp>
```

## License

This project is licensed under the MIT License. See the [License.md](LICENSE.md) file for details.