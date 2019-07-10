#!/bin/bash
sudo strace -u travis -f -r $SHELL "$1" >> strace_output.log 2>&1 || (tail -n 200 strace_output.log && exit 1)
#sudo strace -u travis -f -r $SHELL '$1' >> strace_output.log 2>&1 &
#PROC_ID=$!
#while kill -0 "$PROC_ID" >/dev/null 2>&1; do echo "PROCESS IS RUNNING"; sleep 10; done
#echo "PROCESS TERMINATED" 
