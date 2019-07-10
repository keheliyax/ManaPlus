# !/bin/sh
set -e
travis_wait 150 sleep infinity &
./tools/ci/scripts/docker_run.sh
docker ps -a
