#!/bin/bash
#sudo strace -u travis -f -r $SHELL "$1" >> strace_output.log 2>&1 || (tail -n 200 strace_output.log && exit 1)
#PROC_ID=$!
#while kill -0 "$PROC_ID" >/dev/null 2>&1; do echo "PROCESS IS RUNNING"; sleep 10; done
#echo "PROCESS TERMINATED" 

_COMMAND="$1"  # Needs to be quoted http://stackoverflow.com/questions/1983048/passing-a-string-with-spaces-as-a-function-argument-in-bash
_SLEEP_LENGTH=$2; _SLEEP_LENGTH=${_SLEEP_LENGTH:=60}
sudo strace -u travis -f -r $SHELL $_COMMAND >> strace_output.log 2>&1
pid=$!

_COUNT_LOOP=0
set +x  # Need to disable command print to silence the output during "while".
while kill -0 $pid 2> /dev/null; do
  # Do stuff
  echo "A command '$_COMMAND' is running quiet mode. Elapsed: ${_COUNT_LOOP}"
  sleep $_SLEEP_LENGTH
  _COUNT_LOOP=$(($_COUNT_LOOP+$_SLEEP_LENGTH))
done
set -x  # Re-enable command print now that long part is over.

