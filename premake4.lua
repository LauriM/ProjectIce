solution "ProjectIce"
	configurations { "Debug", "Release" }
	--startproject "ice" --enable this when we switch the new version of premake

	configuration { "windows" }
		defines     { "WINDOWS" , "NULLRENDER" }
		includedirs { "C:/codelibs/termbox/src/", "C:/codelibs/boost_1_53_0/" }
		--links       { "termbox" }
		--libdirs     { "C:/codelibs/termbox/build/src/" }

	configuration { "linux" }
		defines { "LINUX", "TERMRENDER" }
		links   { "m", "rt", "termrender" }
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
