#!/bin/bash -e

export RML=aot-data


export LD_LIBRARY_PATH=.
exec mvn package -B

