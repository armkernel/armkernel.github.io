#!/bin/sh

VALUE="."

if [ $# -ne 0 ]; then
    VALUE=$1
fi

echo your commit comment is $VALUE !!

git pull

git add .
git commit -m $VALUE
git push origin master
