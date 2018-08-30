#! /bin/bash

build="build"

if [ ! -d $build ]
then
	mkdir $build
fi

cd build
cmake ../