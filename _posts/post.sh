#!/bin/zsh

NAME=$(date +%Y)-$(date +%m)-$(date +%d)-$1.md

touch $NAME

chmod 755 $NAME

vi $NAME
