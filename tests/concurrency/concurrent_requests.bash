#!/bin/bash
for N in {1..150}
do
    ruby ./request_time.rb &
done
wait
pkill server