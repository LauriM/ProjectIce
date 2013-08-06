solution "ProjectIce"
	configurations { "Debug", "Release" }

	configuration { "windows" }
		defines { "WINDOWS" }

	configuration { "linux" }
		defines { "LINUX" }
		links { "m", "rt" }

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

		configuration "windows"
			-- TODO: Remove hard-coded paths
			libdirs     { "C:/codelibs/pdcurses/lib/" }
			includedirs { "C:/codelibs/pdcurses/include/" }
			links       { "pdcurses" }
			defines     { "WINDOWS" }

		configuration "linux"
			links { "ncurses" }
			libdirs { "/usr/local/lib" }
			flags { "ExtraWarnings", "FatalWarnings" }

	project "test"
		-- Test only for linux systems
		kind "ConsoleApp"
		language "C++"
		files { "src/test.cpp", "src/engine/**.h", "src/engine/**.cpp", "src/game/**.h", "src/game/**.cpp" }
		includedirs { "src/" }

		configuration "linux"
			links { "ncurses" , }
			libdirs { "/usr/local/lib" }
			flags { "ExtraWarnings", "FatalWarnings" }
