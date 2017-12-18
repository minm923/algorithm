#!/bin/bash

BINDIR=`dirname $( readlink /proc/$$/fd/255 )`
ADMINLOG=$BINDIR/ServeAdmin.log
GAMEHOME=`cd $BINDIR/ && pwd`
SCRIPTDIR=$GAMEHOME/script
PYTHONDIR=/usr/local/bin
if [ -f $PYTHONDIR/python ]; then
	DUMMY=1
else
	PYTHONDIR=/usr/bin
fi

config(){
    CMD=$@
    if (cd $SCRIPTDIR && $PYTHONDIR/python GenerateConfig.py $@);then
# chmod +w `find . -name ctrl_svr_conf.xml`
# chmod +w `find . -name online_addr.xml`
	    echo successful
    	exit 0
    fi
	echo fail
    exit 1
}

function ClearLog(){
    cd $BINDIR
    for file in $BINDIR/*
	do
		if [ -d $file ];then
			cd $file > /dev/null
			for f in $file/*
			do
				if [ -d $f ];then
					if [ `basename $f` == "log" ];then
						echo "clear log in $f"
						cd $f > /dev/null
						for s in $f/*
						do
							if [ -f $s ];then
								rm -rf $s
							fi
						done
						cd - > /dev/null
					fi
				fi
			done
			cd - > /dev/null
		fi
	done
	echo "clear log done!"
}

clear(){
    touch $ADMINLOG
	if [ $# == 0 ];then
		echo   $"[`date`] clear log and shm!" | tee -a $ADMINLOG
		ClearLog $@
		(cd $BINDIR/script/ && sh shm_del.sh)
	elif [ $# == 1 ];then
		if [[ "$1" = "log" || "$1" = "LOG" ]];then
       	    echo   $"[`date`] clear log!" | tee -a $ADMINLOG
			ClearLog $@
    	elif [[ "$1" = "shm" || "$1" = "SHM" ]];then
	    	echo   $"[`date`] clear shm!" | tee -a $ADMINLOG
            (cd $BINDIR/script/ && sh shm_del.sh)
		fi
	fi
}

function StartAll()
{
# start tbusd
    start tconnd.gamesvr_g1_1;
# start tconnd.gamesvr_g1_2;
    start gamesvr;
    start tormsvr.game;

    start tconnd.balancesvr_b1_1;
# start tconnd.balancesvr_b1_2;
    start balancesvr;

    start tconnd.globalsvr_g1_1;
# start tconnd.globalsvr_g1_2;
    start globalsvr;

# start tconnd.gamesvr_g2_1;
# start tconnd.gamesvr_g2_2;
# start gamesvr_2;


# start tconnd.balancesvr_b2_1;
# start tconnd.balancesvr_b2_2;
# start balancesvr_2;

# start tconnd.globalsvr_g2_1;
# start tconnd.globalsvr_g2_2;
# start globalsvr_2;

#    start tconnd.matchsvr_m1_1;
    start matchsvr;

    start roomsvr;

#    start cachesvr;
#    start tormsvr.cache;

    start tormsvr;

    start udpsvr;

#    start udpsvr_2;

    start ranksvr;

    start tormsvr.rank;

    start pvprecordsvr;

    #start reportsvr;

    start friendsvr;

    start mailsvr;
    start tormsvr.mail;
}

function StopAll()
{
# stop tbusd
    stop tconnd.gamesvr_g1_1;
# stop tconnd.gamesvr_g1_2;
    stop gamesvr;
    stop tormsvr.game;

    stop tconnd.balancesvr_b1_1;
# stop tconnd.balancesvr_b1_2;
    stop balancesvr;

    stop tconnd.globalsvr_g1_1;
# stop tconnd.globalsvr_g1_2;
    stop globalsvr;

# stop tconnd.gamesvr_g2_1;
# stop tconnd.gamesvr_g2_2;
# stop gamesvr_2;


# stop tconnd.balancesvr_b2_1;
# stop tconnd.balancesvr_b2_2;
# stop balancesvr_2;

# stop tconnd.globalsvr_g2_1;
# stop tconnd.globalsvr_g2_2;
# stop globalsvr_2;

#    stop tconnd.matchsvr_m1_1;
    stop matchsvr;

    stop roomsvr;

#    stop cachesvr;
#    stop tormsvr.cache;

    stop tormsvr;

    stop udpsvr;

#    stop udpsvr_2;

    stop ranksvr;

    stop tormsvr.rank;

    stop pvprecordsvr;

    #stop reportsvr;

    stop friendsvr;

    stop mailsvr;
    stop tormsvr.mail
}

function ReloadAll()
{
# reload online
    reload tconnd.gamesvr_g1_1;
# reload tconnd.gamesvr_g1_2;
    reload gamesvr;

    reload tconnd.balancesvr_b1_1;
# reload tconnd.balancesvr_b1_2;
    reload balancesvr;

    reload tconnd.globalsvr_g1_1;
# reload tconnd.globalsvr_g1_2;
    reload globalsvr;

# reload tconnd.gamesvr_g2_1;
# reload tconnd.gamesvr_g2_2;
# reload gamesvr_2;


# reload tconnd.balancesvr_b2_1;
# reload tconnd.balancesvr_b2_2;
# reload balancesvr_2;

# reload tconnd.globalsvr_g2_1;
# reload tconnd.globalsvr_g2_2;
# reload globalsvr_2;

    reload matchsvr;

    reload roomsvr;

#    reload cachesvr;

    reload udpsvr;

#    reload udpsvr_2;

    reload ranksvr;

    reload pvprecordsvr;

    #reload reportsvr;

    reload friendsvr;

    reload mailsvr;
}

function InitBus()
{
	touch $ADMINLOG
	if (cd $BINDIR/tbusConf);then
		cd $BINDIR/tbusConf
		if (sh initTbusRoute.sh);then
			echo   $"[`date`] init bus shm!" | tee -a $ADMINLOG
# return 0
		fi
	fi

    if (cd $BINDIR/tbusd/conf);then
        cd $BINDIR/tbusd/conf
            if (sh initRelayRoute.sh);then
                echo   $"[`date`] init bus shm!" | tee -a $ADMINLOG
                    return 0
            fi
    fi

	echo   $"[`date`] init bus shm failed!" | tee -a $ADMINLOG
	echo   $"[`date`] init bus shm failed!"
	exit 1
}

function InitMeta()
{
	touch $ADMINLOG
    if (cd $BINDIR/tormsvr);then
        cd $BINDIR/tormsvr/conf
        if (sh addmeta.sh);then
            echo   $"[`date`] init meta !" | tee -a $ADMINLOG
            # return 0
        fi
    fi

    if (cd $BINDIR/tormsvr.game);then
        cd $BINDIR/tormsvr.game/conf
        if (sh addmeta.sh);then
            echo   $"[`date`] init meta !" | tee -a $ADMINLOG
# return 0
        fi
    fi

	if (cd $BINDIR/tormsvr.rank);then
        cd $BINDIR/tormsvr.rank/conf
        if (sh addmeta.sh);then
            echo   $"[`date`] init meta !" | tee -a $ADMINLOG
            #return 0
        fi
    fi

    if (cd $BINDIR/tormsvr.mail);then
        cd $BINDIR/tormsvr.mail/conf
        if (sh addmeta.sh);then
            echo $"[`date`] init meta !" | tee -a $ADMINLOG
            return 0
        fi
    fi

    echo   $"[`date`] init meta failed!" | tee -a $ADMINLOG
    echo   $"[`date`] init meta failed!"
    exit 1
}


start(){
	touch $ADMINLOG;
    echo "BINDIR: " $BINDIR;
    START_DIR=$BINDIR;
    if [[ $1 =~ 'tconnd' ]];
    then
        START_DIR=$BINDIR/tconnds;
    fi

	if [ $# == 1 ];then
		if (cd $START_DIR/$1/bin && sh start.sh);then
			echo $"[`date`] start $1!" | tee -a $ADMINLOG
			return 0
		fi
		echo fail
		return 1
	elif [ $# == 0 ];then
			if (StartAll $@);then
				echo $"[`date`] start allsvr!" | tee -a $ADMINLOG
				return 0
			fi
			echo fail
			return 1
	fi
	echo fail
	return 1
}

control(){
	touch $ADMINLOG
	if [ $# == 1 ];then
		if (cd $BINDIR/$1/bin && sh control_start.sh);then
			echo $"[`date`] control $1!" | tee -a $ADMINLOG
			return 0
		fi
	fi
	echo fail
	return 1
}

stop(){
    STOP_DIR=$BINDIR;
    if [[ $1 =~ 'tconnd' ]];
    then
        STOP_DIR=$BINDIR/tconnds;
    fi

	if [ $# == 1 ];then
		echo $1
		if (cd $STOP_DIR/$1/bin && sh stop.sh);then
			echo $"[`date`] stop $1!" | tee -a $ADMINLOG
			return 0
		fi
		echo fail
		return 1
	elif [ $# == 0 ];then
			if (StopAll $@);then
				echo $"[`date`] stop allsvr!" | tee -a $ADMINLOG
				return 0
			fi
			echo fail
			return 1
	fi
	echo fail
	return 1
}



function kill(){
    if [ $# == 1 ]; then
        KILL_DIR=$BINDIR/$1
        case $1 in
            gamesvr)
                if (cd $KILL_DIR/bin && sh kill.sh);then
			        echo $"[`date`] kill $1!" | tee -a $ADMINLOG
                fi
            ;;
            globalsvr)
                if (cd $KILL_DIR/bin && sh kill.sh);then
			        echo $"[`date`] kill $1!" | tee -a $ADMINLOG
                fi
            ;;
            *)
                echo "$1 not found"
                exit 1
        esac            
    elif [ $# == 0 ]; then        
        if (KillAll); then
            echo $"[`date`] kill allsvr!" | tee -a $ADMINLOG
        else            
            echo fail
            return 1
        fi            
    fi        
        
    clear shm 

    return 0
}

function KillAll()
{
    kill gamesvr;
    kill globalsvr;

    stop

    return 0
}

reload(){
    RELOAD_DIR=$BINDIR;
    if [[ $1 =~ 'tconnd' ]];
    then
        RELOAD_DIR=$BINDIR/tconnds;
    fi

	if [ $# == 1 ];then
		echo $1
		if (cd $RELOAD_DIR/$1/bin && sh reload.sh);then
			echo $"[`date`] reload $1!" | tee -a $ADMINLOG
			return 0
		fi
		echo fail
		return 1
	elif [ $# == 0 ];then
			if (ReloadAll $@);then
				echo $"[`date`] reload allsvr!" | tee -a $ADMINLOG
				return 0
			fi
			echo fail
			return 1
	fi
	echo fail
	return 1
}

usage(){
    echo
    echo "Usage:"
    echo "  ServeAdmin.sh [command],commands are:"
    echo "  config                      reset config."
	echo "  clear [log | shm]           clear shm log"
	echo "  start                       start SVRNAME"
	echo "  control                     control SVRNAME"
	echo "  stop                        stop  SVRNAME"
	echo "  kill                        kill  SVRNAME"
	echo "  restart                     restart SVRNAME"
	echo "  reload                      reload  SVRNAME"
	echo "  initbus                     initbus"
    echo "  initmeta                    initmeta"
	echo "  hotrestart                  hotrestart SVRNAME"
    echo
}

case $1 in
    config|CONFIG)
        shift
		config $@
    ;;
	clear|CLEAR)
        clear $2
    ;;
	start|START)
        start $2
	;;
	control|CONTROL)
        control $2
	;;
	stop|STOP)
        stop $2
	;;
    kill|KILL)
        kill $2
    ;;
	reload|RELOAD)
        reload $2
	;;
	restart|RESTART)
		stop  $2
		clear shm;
        # clear log;
		InitBus
        InitMeta
		sleep 2
		start $2
	;;
	initbus|INITBUS)
		InitBus
	;;
    initmeta|INITMETA)
        InitMeta
    ;;
	hotrestart|HOTRESTART)
		stop  $2
		sleep 2
		start $2
	;;
    *)
        usage
        exit 1
esac

