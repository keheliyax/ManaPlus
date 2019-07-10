#!/usr/bin/env bash
sudo strace -u travis -f -r $SHELL '$1' >> strace_output.log 2>&1 &
PROC_ID=$!
while kill -0 "$PROC_ID" >/dev/null 2>&1; do echo "PROCESS IS RUNNING"; sleep 1m; done
echo "PROCESS TERMINATED" 
