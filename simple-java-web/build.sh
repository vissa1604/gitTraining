#!/bin/bash

# enter script directory
cd "$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# execute build task
./gradlew clean build test