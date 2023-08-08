#! /usr/bin/bash

function writeFile(){
    FILENAME=$1
    POKETYPE=$2

    if [ ! -d "${POKETYPE}" ]
    then
        mkdir ${POKETYPE}
    else
        rm ${POKETYPE}/${POKETYPE}_Pokemon.txt
    fi

    while read -r CURRENTLINE
    do
        read -ra elements <<< "$CURRENTLINE"
        if [ "${elements[2]}" = "$POKETYPE" ]
        then
            echo "$CURRENTLINE" >> ${POKETYPE}/${POKETYPE}_Pokemon.txt
        fi
        
    done < "$FILENAME"
}

IFS=","
FILENAME="Pokemon.csv"
echo "Reading from $FILENAME"

#read -p "Enter file name to Partition: " FILENAME

if [ ! -e "$FILENAME" ]
then
    echo "The file you are trying to use doesn't exist."

else
    read -p "Enter Pokemon type name to Partition: " POKETYPE
    writeFile $FILENAME $POKETYPE

fi

echo "Finished partitioning"




