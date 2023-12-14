#!/bin/bash -e

[ -d aot-data ] && echo "ERROR: ${0##*/}: aot-data already exists" >&2 && exit 1

wget -q https://download.luwrain.org/third-party/aot-data.zip
unzip aot-data.zip > /dev/null
rm -f aot-data.zip
echo OK
