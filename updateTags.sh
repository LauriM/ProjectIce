#!/bin/sh

premake4 gmake
cscope -R -b
ctags -R --c-kinds=+p --fields=+iaS --extra=+q -R .
