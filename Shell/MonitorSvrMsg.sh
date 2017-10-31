#!/bin/bash

OWNER=$(whoami)

TCONND_GAMESVR=tconnd.gamesvr
TCONND_GAMESVR_ID=$(ps aux | grep gaomin  | grep --color -e '\./tconnd.gamesvr' | grep -v 'grep' | awk '{printf $12}' | cut -d '=' -f2)

SVR_IDS=\\\(${TCONND_GAMESVR_ID}

for VAR in $@
do
    case $VAR in
        gamesvr)
            GAMESVR_ID=$(ps aux | grep $OWNER | grep --color -e '\./gamesvr' | grep -v 'grep' | grep -v 'tail' | awk '{printf $13}')
            SVR_IDS=${SVR_IDS}\\\|${GAMESVR_ID}
    ;;        
        globalsvr)
            GLOBALSVR_ID=$(ps aux | grep $OWNER | grep --color -e '\./globalsvr' | grep -v 'grep' | grep -v 'tail' | awk '{printf $13}')
            SVR_IDS=${SVR_IDS}\\\|${GLOBALSVR_ID}
 
    ;;        
        matchsvr)
            MATCHSVR_ID=$(ps aux | grep $OWNER | grep --color -e '\./globalsvr' | grep -v 'grep' | grep -v 'tail' |  awk '{printf $13}')
            SVR_IDS=${SVR_IDS}\\\|${MATCHSVR_ID}
    ;;        
        roomsvr)
            ROOMSVR_ID=$(ps aux | grep $OWNER | grep --color -e '\./roomsvr' | grep -v 'grep' | grep -v 'tail' |  awk '{printf $13}')
            SVR_IDS=${SVR_IDS}\\\|${ROOMSVR_ID}
    ;;        
        *)
        echo "$VAR not found"            
        exit 1
    ;;        
    esac
done

SVR_IDS=${SVR_IDS}\\\)
echo $SVR_IDS

PREFIX=gamesvr
FILE_NAME_REG=${PREFIX}_[0-9]*.log
#echo $FILE_NAME_REG

FILE_NAME=$(find . -name "$FILE_NAME_REG" -mmin -1)
#FILE_NAME=$(find . -name "gamesvr_[0-9]*.log" -mmin -1)

if [ x"$FILE_NAME" == x"" ];then
    echo "Log File doesnt exit"
else
    tail -f $FILE_NAME | grep --color -nir "Msg.*From.*$SVR_IDS.*CmdID"
fi    
