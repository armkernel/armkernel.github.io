#!/bin/zsh

echo "Hello~ TE!! "

NAME=$(date +%Y)-$(date +%m)-$(date +%d)-$1.md
YEAR=19
touch $NAME

echo "---" >> $NAME
echo "layout : post" >> $NAME
echo "title : $YEAR$(date +%m)$(date +%d)_TE" >> $NAME
echo "tags : [TE]" >> $NAME
echo "comments: true" >> $NAME
echo "---" >> $NAME
echo "### Today English" >> $NAME
echo "- " >> $NAME
chmod 755 $NAME

vi $NAME
