# RVMAT Generator 3000

This is a simple RVMAT file generation and batch image conversion tool for DayZ modders. It's built on the [Walnut](https://github.com/TheCherno/Walnut) Framework from the Cherno which uses the Dear Imgui Library from Omar Ocornut [DearImGui](https://github.com/ocornut/imgui).

## Build it
### Requirements
- [Visual Studio 2022](https://visualstudio.com) (not strictly required, however included setup scripts only support this)
- [Vulkan SDK](https://vulkan.lunarg.com/sdk/home#windows) (I use version 1.3.261.1, the latest version throws validation errors when using the walnut template)

Once you've cloned , you can run `scripts/Setup.bat` files to your liking (eg. change the name from "WalnutApp" to something else).  Once you're happy, run `scripts/Setup.bat` to generate Visual Studio 2022 solution/project files. Your app is located in the `WalnutApp/` directory, which some basic example code to get you going in `WalnutApp/src/WalnutApp.cpp`. I recommend modifying that WalnutApp project to create your own application, as everything should be setup and ready to go.

### How to
Clone the Repo recursively and run `scripts/Setup.bat` to generate Visual Studio 2022 solution/project files. Once you've opened the solution, you can build it from visual studio.

### 3rd party libaries
- [Dear ImGui](https://github.com/ocornut/imgui)
- [GLFW](https://github.com/glfw/glfw)
- [stb_image](https://github.com/nothings/stb)
- [GLM](https://github.com/g-truc/glm) (included for convenience)