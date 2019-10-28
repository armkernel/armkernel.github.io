#!/bin/zsh

echo " Hello~ TIL post!! "

NAME=$(date +%Y)-$(date +%m)-$(date +%d)-$1.md
YEAR=19
touch $NAME

echo "---" >> $NAME
echo "layout : post" >> $NAME
echo "title : $YEAR$(date +%m)$(date +%d)_TIL (Today I Learn)" >> $NAME
echo "tags : [TIL]" >> $NAME
echo "comments: true" >> $NAME
echo "---" >> $NAME
echo "### 오늘 한 일" >> $NAME
echo "- "  >> $NAME
echo >> $NAME
echo "---" >> $NAME
echo "### 백지 노트" >> $NAME

chmod 755 $NAME

vi $NAME
