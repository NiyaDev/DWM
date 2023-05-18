#!/bin/bash

clear

git add *
git commit -m "$1"

if [ "$2" = "-p" ]
then
	git push -u origin main
fi