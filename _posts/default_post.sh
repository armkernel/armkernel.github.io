#!/bin/zsh

echo "Hello~ $1"

NAME=$(date +%Y)-$(date +%m)-$(date +%d)-$1.md
touch $NAME

echo "---" >> $NAME
echo "layout : post" >> $NAME
echo "title : " >> $NAME
echo "tags : []" >> $NAME
echo "comments: true" >> $NAME
echo "---" >> $NAME
chmod 755 $NAME

vi $NAME
