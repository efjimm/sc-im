#!/bin/bash
## SEE https://github.com/lehmannro/assert.sh for usage

#Exit immediately if a command exits with a non-zero status.
set -e

NAME=test3

VALGRIND_CMD='valgrind -v --log-file=${NAME}_vallog --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all --show-reachable=no'
. assert.sh
assert "echo GETNUM A0 | $VALGRIND_CMD ../zig-out/bin/sc-im ${NAME}.sc --nocurses --nodebug --quit_afterload 2>&1 |grep -v '^$\|Interp\|left'" "3.3"

#we check valgrind log
assert_iffound_notcond ${NAME}_vallog "definitely lost.*bytes" "0 bytes"
assert_iffound_notcond ${NAME}_vallog "indirectly lost.*bytes" "0 bytes"
assert_iffound_notcond ${NAME}_vallog "possibly lost.*bytes" "0 bytes"
assert_iffound_notcond ${NAME}_vallog "Uninitialised value was created by a heap allocation"
assert_iffound_notcond ${NAME}_vallog "Conditional jump or move depends on uninitialised value"
assert_iffound_notcond ${NAME}_vallog "Invalid read of size"
assert_iffound_notcond ${NAME}_vallog "Invalid write of size"
assert_iffound_notcond ${NAME}_vallog "Invalid free() / delete"
if [ "$1" != "keep-vallog" ];then
    rm ${NAME}_vallog
fi

assert_end ${NAME}
