-- premake5.lua
workspace "RVMATgen"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "RVMATgen"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "RVMATgen"