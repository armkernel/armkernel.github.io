#!/bin/sh
# TIL, TE posting 담당 script
YEAR=19
POST=$1_$YEAR$(date +%m)$(date +%d)

if [ $1 = "TIL" ];
then ./TIL_post.sh $POST
else ./TE_post.sh $POST
fi
