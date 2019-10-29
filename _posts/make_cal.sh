
# post를 7일 단위로 뽑아 적어주는 걸 의미합니다.

YEAR=19
MONTH=`expr $(date +%m)`
DAY=`expr $(date +%d)`

# 변수 설정 시, 꼭 붙여써라
LAST_MONTH=$MONTH
LAST_DAY=`expr $DAY + 6`

# ,가 아닌 띄어쓰기로 구별한다
DAY_LIST=(31 28 31 30 31 30 31 31 30 31 30 31)

NOW_MONTH_DAY=${DAY_LIST[`expr $MONTH - 1`]}

echo "$LAST_DAY $NOW_MONTH_DAY"

if [ $LAST_DAY -gt $NOW_MONTH_DAY ]; then
  LAST_DAY="0`expr $LAST_DAY - $NOW_MONTH_DAY`"
  LAST_MONTH=`expr $MONTH + 1`
  
  if [ $LAST_MONTH -eq 13 ]; then
    LAST_MONTH=1  
    echo "$LAST_MONTH 월 입니다. 한 해가 지났습니다!!"
  fi
fi

NEW_FILE_NAME=$(date +%Y)-$(date +%m)-$(date +%d)-TIL_"$YEAR$MONTH$DAY"_"$LAST_MONTH$LAST_DAY".md

echo $NEW_FILE_NAME



#echo "$DAY $NEXT_DAY"
