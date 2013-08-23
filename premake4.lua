solution "ProjectIce"
	configurations { "Debug", "Release" }

	configuration { "windows" }
		defines   { "WINDOWS" }
		libdirs     { "C:/codelibs/pdcurses/lib/" }
		includedirs { "C:/codelibs/pdcurses/include/" }
		links       { "pdcurses" }
		defines     { "WINDOWS" }

	configuration { "linux" }
		defines { "LINUX" }
		links   { "m", "rt" , "termbox" }
		flags   { "ExtraWarnings", "FatalWarnings" }
		libdirs { "/usr/local/lib" } -- is this correct ?

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

