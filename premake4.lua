solution "ProjectIce"
	configurations { "Debug", "Release" }
	--startproject "ice" --enable this when we switch the new version of premake

	configuration { "windows" }
		defines     { "WINDOWS" , "SFMLRENDER" }
		includedirs { "C:/codelibs/boost_1_53_0/" , "C:/codelibs/SFML-2.1/include/" }
		links       { "sfml-main" }
		links       { "sfml-graphics-d", "sfml-window-d", "sfml-system-d" }
		libdirs     { "C:/codelibs/SFML-2.1/lib/" }

	configuration { "linux" }
		defines { "LINUX", "TERMRENDER" }
		links   { "m", "rt", "termbox" }
		flags   { }
		buildoptions { "-std=c++11" }

	configuration "Debug"
		defines { "DEBUG" }
		flags   { "Symbols" }

    configuration "Release"
		defines { "NDEBUG","RELEASE_BUILD" }
		flags   { "Optimize" }

	project "ice"
		kind "ConsoleApp"
		language "C++"
        files { "src/main.cpp", "src/engine/**.h", "src/engine/**.cpp", "src/game/**.h", "src/game/**.cpp" }
		includedirs { "src/" }

	project "test"
		kind "ConsoleApp"
		language "C++"
		files { "src/test.cpp", "src/engine/**.h", "src/engine/**.cpp", "src/game/**.h", "src/game/**.cpp" }
		includedirs { "src/" }
