# RVMAT Generator 3000

This is a simple RVMAT file generation and batch image conversion tool for DayZ modders. It's built on the [Walnut](https://github.com/TheCherno/Walnut) Framework from the Cherno which uses the Dear Imgui Library from Omar Ocornut [DearImGui](https://github.com/ocornut/imgui).
You can build it yourself or just use the precompiled version. However, this is a work in progress and i don't guarantee that it works properly and or doesn't burn down your house.

## Use it
### Installation
Just move the executable to it's own folder and run it from there.

### How to use
1. add the path to your source textures, your output folder and your copy of ImageToPaa.exe
2. (optional) add a Prefix if you want to scan only prefixed files, otherwise leave empty
3. press the `Scan` button
4. adjust rvmat parameters
5. press the `Create RVMAT Files from Texture Sets` button to create the RVMAT files in the output directory
6. press the `Convert Scanned Files to PAA` to convert the scanned files to PAA files in the output directory

## Build it
### Requirements
- [Visual Studio 2022](https://visualstudio.com) (not strictly required, however included setup scripts only support this)
- [Vulkan SDK](https://vulkan.lunarg.com/sdk/home#windows) (I use version 1.3.261.1, the latest version throws validation errors in Debug when using the walnut template)

### How to build
Clone the Repo recursively and run `scripts/Setup.bat` to generate Visual Studio 2022 solution/project files. Once you've opened the solution, you can build it from visual studio.

### 3rd party libaries
- [Dear ImGui](https://github.com/ocornut/imgui)
- [GLFW](https://github.com/glfw/glfw)
- [stb_image](https://github.com/nothings/stb)
- [GLM](https://github.com/g-truc/glm) (included for convenience)