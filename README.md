# Carom

Carom is an ideal gas physics simulator developed in C++. The primary goal of this project is twofold: to accurately model the thermodynamic behavior of real gases and to experiment with unique simulation mechanics.

## Requirements

To build and run this project, your system must meet the following requirements:
* A compiler with **C++20** support.
* **CMake** (v3.25+) for generating build files.
* **SFML 3**. The project requires the `Graphics`, `Window`, and `System` components.

### Installing SFML

**On macOS:**
Since CMake looks for the library via `find_package`, SFML must be installed on your system prior to building. The easiest way to install it is using Homebrew:
```bash
brew install sfml
```

**On Windows:**
The recommended way to install SFML on Windows so that CMake can easily find it is by using the [vcpkg](https://vcpkg.io/) package manager:
```powershell
vcpkg install sfml
```
*(Note: If you use vcpkg, remember to pass the vcpkg toolchain file during the CMake configuration step: `-DCMAKE_TOOLCHAIN_FILE=[path_to_vcpkg]/scripts/buildsystems/vcpkg.cmake`)*

## Build and Run

The project uses an out-of-source build system with CMake. 

### macOS / Linux
Run the following commands in your terminal:
```bash
# 1. Configure the project
cmake -S . -B build

# 2. Compile the project
cmake --build build

# 3. Run the executable
./build/carom
```

### Windows (PowerShell)
Run the following commands:
```powershell
# 1. Configure the project
cmake -S . -B build

# 2. Compile the project
cmake --build build

# 3. Run the executable (MSVC creates a Debug subfolder by default)
.\build\Debug\carom.exe
```
