solution "ProjectIce"
    configurations { "Debug", "Release" }
	flags { "ExtraWarnings", "FatalWarnings" }

    -- Platform-specific options
    configuration { "gmake" }
		--buildoptions { "-std=c99", "-pedantic" }

	configuration { "windows" }
		defines { "WINDOWS" }

    configuration { "linux" }
		defines { "LINUX" }
        links { "m", "rt" }

    -- Configuration-specific options
    configuration "Debug"
        defines { "DEBUG" }
        flags   { "Symbols" }

    configuration "Release"
        defines { "NDEBUG","RELEASE_BUILD" }
        flags   { "Optimize" }

    project "ice"
        kind "ConsoleApp"
        language "C++"
        files { "src/main.cpp", "src/engine/**.h", "src/engine/**.cpp" }
		includedirs { "src/" }

        configuration "windows"
            -- TODO: Remove hard-coded paths
            libdirs     { "C:/codelibs/pdcurses/lib/" }
            includedirs { "C:/codelibs/pdcurses/include/" }
            links       { "pdcurses" }

        configuration "linux"
            links { "ncurses" }
			libdirs { "/usr/local/lib" }

	project "test"
		kind "ConsoleApp"
		language "C++"
		files { "src/test.cpp", "src/engine/**.h", "src/engine/**.cpp" }
		includedirs { "src/" }

		configuration "linux"
			links { "ncurses" , }
			libdirs { "/usr/local/lib" }
