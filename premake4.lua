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

    -- Client project
    project "ice"
        kind "ConsoleApp"
        language "C++"
        files { "src/**.h", "src/**.cpp" }
		includedirs { "src/" } --check if needed

        configuration "windows"
            -- TODO: Remove hard-coded paths
            libdirs     { "C:/codelibs/pdcurses/lib/" }
            includedirs { "C:/codelibs/pdcurses/include/" }
            links       { "pdcurses" }

        configuration "linux"
            links { "ncurses" }
