export FILE=`find source -name "*.c" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_SRC :=.*#LST_SRC := $FILE#g" Makefile
export FILE=`find include -name "*.h" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_INC :=.*#LST_INC := $FILE#g" Makefile