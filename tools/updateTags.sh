#!/bin/sh

cscope -R -b
ctags -R --c-kinds=+p --fields=+iaS --extra=+q -R .
