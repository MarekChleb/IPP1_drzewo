#!/bin/bash

ALL=0
PASS=0
FAIL=0

if [ $# == 2 ]; then
    DEBUG=0
    PROG=$1
    DIR=$2
elif [ $# == 3 ]; then
    DEBUG=1
    PARAM="-v"
    PROG=$2
    DIR=$3
else
    echo "WRONG NUMBER OF ARGUMENTS"
    exit 1
fi

if [ -f $PROG ] && [ -d $DIR ]; then
    PROG="./$PROG"
else
    echo "BAD PARAMETERS"
    exit 1
fi

for test in $DIR/*.in; do
    TEST_NAME=${test##$DIR/}
    echo "${TEST_NAME%.in}: "
    $PROG ${PARAM-} <$test >output 2>errs
    if diff output "${test%.in}.out" >/dev/null 2>&1; then
        echo "PASS"
        if [ $DEBUG == 1 ]; then
            echo "${TEST_NAME%.in}.err: "
            if diff errs "${test%.in}.err" >/dev/null 2>&1; then
                echo "PASS"
                PASS=$((PASS+1))
            else
                echo "FAIL"
            fi
        else
            PASS=$((PASS+1))
        fi
    else
        echo "FAIL"
    fi

    echo ""
    ALL=$((ALL+1))
done

echo "TESTS PASSED: ${PASS}/${ALL}"
if [ $PASS == $ALL ]; then
    echo "BRAWO"
fi    

rm -f output
rm -f errs

exit 0
