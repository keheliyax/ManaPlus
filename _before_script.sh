# !/bin/sh
set -e
uname -a
echo before_script
./tools/ci/scripts/retry.sh apt-get update
./tools/ci/scripts/retry.sh apt-get install docker
