#!/bin/sh

HOME_DIR=`pwd`
BUILD_HOME=$HOME_DIR/build
SRC_HOME=$HOME_DIR/src
RUN_HOME=$HOME_DIR/run
PROTO_HOME=$HOME_DIR/protocol
# RMD_DAILY_BUILD_BIN=$HOME_DIR/bin

function IfErrorExit()
{
# set -x
    if [[ $1 != 0 ]];then
        echo "complier failed";
        exit -1
    fi
# set +x
}

function MakeSrcPkg()
{
    tolua=${HOME_DIR}/dep/toluapp/bin/tolua++
    for pkg in `find ${SRC_HOME} -regex ".*\.pkg"`; do out=${pkg%.pkg}".tl.cpp"; ${tolua} -o ${out} ${pkg}; done
}

function MakeServer()
{
    help="usage:$FUNCNAME servername [clean|debug|realease]"

    if [[ $# < 2 ]];then
        echo $help
        exit
    fi
    
    if [ "debug" == $1 ];then
        echo "incremental-build project mode(DEBUG) [$2] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$2);then
            cd $BUILD_HOME/$2
            cmake $SRC_HOME/$2 -DCMAKE_BUILD_TYPE=DEBUG 
            make -j 4
            dbgret=$?
            IfErrorExit $dbgret
            DBGSVR=$2.debug
            BINNAME=$2
            cp $RUN_HOME/${BINNAME}/bin/$2  $RUN_HOME/${BINNAME}/bin/$DBGSVR -rf
            cp $RUN_HOME/${BINNAME}/bin/$2  $RUN_HOME/${BINNAME}_2/bin/ -rf
            return $dbgret
        else
            echo "cd $2 failed" 1>&2
            return 1
        fi
    elif [ "release" == $1 ];then
        echo "incremental-build project mode(RELEASE) [$2] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$2);then
            cd $BUILD_HOME/$2
            cmake $SRC_HOME/$2 -DCMAKE_BUILD_TYPE=RELEASE
            make -j 4
            rlsret=$?
            IfErrorExit $rlsret
            RELEASESVR=$2.release
            BINNAME=$2
            cp $RUN_HOME/${BINNAME}/bin/$2  $RUN_HOME/${BINNAME}/bin/$RELEASESVR -rf
            cp $RUN_HOME/${BINNAME}/bin/$2  $RUN_HOME/${BINNAME}_2/bin/$RELEASESVR -rf
            return $rlsret
        else
            echo "cd $2 failed" 1>&2
            return 1
        fi
    elif [ "clean" == $1 ];then
        echo "clean project mode(CLEAN) [$2] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$2);then
            cd $BUILD_HOME/$2
            make clean
            IfErrorExit $?
            rm -rf * &>/dev/null
            echo "clean $2 done!" 1>&2
            return 0    
        else
            echo "clean $2 failed" 1>&2
            return 1
        fi
        exit 1
    elif [ "verbose" == $1 ];then
        echo "incremental-build project mode(DEBUG&&VERBOSE) [$2] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$2);then
            cd $BUILD_HOME/$2
            cmake $SRC_HOME/$2 -DCMAKE_BUILD_TYPE=DEBUG 
            make -j 9 VERBOSE=1
            vbsret=$?
            IfErrorExit $vbsret
            return $vbsret
        else
            echo "cd $2 failed" 1>&2
            return 1
        fi
    fi
    
    echo "$help"
    return 1;
}

function MakeBaseLib()
{
    TW_BASE_LIB=libtwbase.a
    BASE_DIR=base
    if [ "debug" == $1 ];then
        echo "incremental-build project mode(DEBUG) [$BASE_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$BASE_DIR);then
            cd $BUILD_HOME/$BASE_DIR
            cmake $SRC_HOME/$BASE_DIR -DCMAKE_BUILD_TYPE=DEBUG 
            make -j 9
            dbgret=$?
            IfErrorExit $dbgret
            # DBGSVR=$BASE_DIR.debug
            # cp $RUN_HOME/$BASE_DIR/bin/$BASE_DIR  $RUN_HOME/$BASE_DIR/bin/$DBGSVR
            cp ${TW_BASE_LIB} $SRC_HOME/$BASE_DIR
            return $dbgret
        else
            echo "cd $BASE_DIR failed" 1>&2
            return 1
        fi
    elif [ "release" == $1 ];then
        echo "incremental-build project mode(RELEASE) [$BASE_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$BASE_DIR);then
            cd $BUILD_HOME/$BASE_DIR
            cmake $SRC_HOME/$BASE_DIR -DCMAKE_BUILD_TYPE=RELEASE
            make -j 9
            rlsret=$?
            IfErrorExit $rlsret
            # RELEASESVR=$BASE_DIR.release
            # cp $RUN_HOME/$BASE_DIR/bin/$BASE_DIR  $RUN_HOME/$BASE_DIR/bin/$RELEASESVR
            cp ${TW_BASE_LIB} $SRC_HOME/$BASE_DIR
            return $rlsret
        else
            echo "cd $BASE_DIR failed" 1>&2
            return 1
        fi
    elif [ "clean" == $1 ];then
        echo "clean project mode(CLEAN) [$BASE_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$BASE_DIR);then
            cd $BUILD_HOME/$BASE_DIR
            make clean
            IfErrorExit $?
            rm -rf * &>/dev/null
            echo "clean $BASE_DIR done!" 1>&2
            return 0    
        else
            echo "clean $BASE_DIR failed" 1>&2
            return 1
        fi
        exit 1
    elif [ "verbose" == $1 ];then
        echo "incremental-build project mode(DEBUG&&VERBOSE) [$BASE_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$BASE_DIR);then
            cd $BUILD_HOME/$BASE_DIR
            cmake $SRC_HOME/$BASE_DIR -DCMAKE_BUILD_TYPE=DEBUG 
            make -j 9 VERBOSE=1
            vbsret=$?
            IfErrorExit $vbsret
            cp ${TW_BASE_LIB} $SRC_HOME/$BASE_DIR
            return $vbsret
        else
            echo "cd $BASE_DIR failed" 1>&2
            return 1
        fi
    fi
    
    echo "$help"
    return 1;
}

function MakeProtoLib()
{
    TW_PROTO_LIB=libtwproto.a
    PROTO_DIR=protocol
    if [ "debug" == $1 ];then
        echo "incremental-build project mode(DEBUG) [$PROTO_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        # echo "BUILD_HOME: $BUILD_HOME, SRC_HOME: $SRC_HOME"
        if (cd $BUILD_HOME/$PROTO_DIR);then
            cd $BUILD_HOME/$PROTO_DIR
            cmake $PROTO_HOME -DCMAKE_BUILD_TYPE=DEBUG 
            make -j 9
            dbgret=$?
            IfErrorExit $dbgret
            # DBGSVR=$PROTO_DIR.debug
            # cp $RUN_HOME/$PROTO_DIR/bin/$PROTO_DIR  $RUN_HOME/$PROTO_DIR/bin/$DBGSVR
            cp $TW_PROTO_LIB $PROTO_HOME
            return $dbgret
        else
            echo "cd $PROTO_DIR failed" 1>&2
            return 1
        fi
    elif [ "release" == $1 ];then
        echo "incremental-build project mode(RELEASE) [$PROTO_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$PROTO_DIR);then
            cd $BUILD_HOME/$PROTO_DIR
            cmake $PROTO_HOME -DCMAKE_BUILD_TYPE=RELEASE
            make -j 9
            rlsret=$?
            IfErrorExit $rlsret
            # RELEASESVR=$PROTO_DIR.release
            # cp $RUN_HOME/$PROTO_DIR/bin/$PROTO_DIR  $RUN_HOME/$PROTO_DIR/bin/$RELEASESVR
            cp $TW_PROTO_LIB $PROTO_HOME
            return $rlsret
        else
            echo "cd $PROTO_DIR failed" 1>&2
            return 1
        fi
    elif [ "clean" == $1 ];then
        echo "clean project mode(CLEAN) [$PROTO_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$PROTO_DIR);then
            cd $BUILD_HOME/$PROTO_DIR
            make clean
            IfErrorExit $?
            rm -rf * &>/dev/null
            echo "clean $PROTO_DIR done!" 1>&2
            return 0    
        else
            echo "clean $PROTO_DIR failed" 1>&2
            return 1
        fi
        exit 1
    elif [ "verbose" == $1 ];then
        echo "incremental-build project mode(DEBUG&&VERBOSE) [$PROTO_DIR] at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2
        if (cd $BUILD_HOME/$PROTO_DIR);then
            cd $BUILD_HOME/$PROTO_DIR
            cmake $PROTO_HOME -DCMAKE_BUILD_TYPE=DEBUG 
            make -j 9 VERBOSE=1
            vbsret=$?
            IfErrorExit $vbsret
            cp $TW_PROTO_LIB $PROTO_HOME
            return $vbsret
        else
            echo "cd $PROTO_DIR failed" 1>&2
            return 1
        fi
    fi
    
    echo "$help"
    return 1;
}

#转换协议
function MakeProto()
{
    help="usage:$FUNCNAME servername [proto [check] ]"
    if [ $# -gt 2 ];then
        #echo $help
        return
    fi
    
    if [ "$1" != "proto" ];then
        #echo $help
        return
    fi
  
    echo "make proto at `date +"%Y-%m-%d %H:%M:%S"`" 1>&2

    # 生成协议文件 
    cd ${PROTO_HOME}
    ./convert.sh
    cd ${PROTO_HOME}

    return 0;
}

function MakeAll()
{
    MakeProtoLib $@
    mkret=$?

    MakeBaseLib $@
    mkret=$?

    MakeServer $@ mysvr
    mkret=$[$mkret|$?]

#    MakeServer $@ globalsvr
#    mkret=$[$mkret|$?]
#
#    MakeServer $@ balancesvr
#    mkret=$[$mkret|$?]
#
#    MakeServer $@ matchsvr
#    mkret=$[$mkret|$?]
#
#    MakeServer $@ roomsvr
#    mkret=$[$mkret|$?]
#
#    #MakeServer $@ cachesvr
#    #mkret=$[$mkret|$?]
#
#    MakeServer $@ udpsvr
#    mkret=$[$mkret|$?]
#
#    MakeServer $@ ranksvr 
#    mkret=$[$mkret|$?]
#
#    MakeServer $@ pvprecordsvr 
#    mkret=$[$mkret|$?]
#
#    #MakeServer $@ reportsvr 
#    #mkret=$[$mkret|$?]
#
#    MakeServer $@ friendsvr 
#    mkret=$[$mkret|$?]
#
#    MakeServer $@ mailsvr
#    mkret=$[$mkret|$?]

    return $mkret
}

if [[ 0 ]];
    then
function UpConf()
{
    cur_dir=`pwd`
    cd deploy/comm/
    chmod +x up_conf.sh
    ./up_conf.sh
    cd $cur_dir
}
fi

function CreateNewSvr()
{
	ServerPrefix=$2
	Server=$2"svr"
	LowerServer=`echo $Server | awk '{print tolower($0)}'`
	LowerPrefix=`echo $ServerPrefix | awk '{print tolower($0)}'`
	UpperPrefix=`echo $ServerPrefix | awk '{print toupper($0)}'`
    MyPrefix=`echo ${ServerPrefix:0:1} | tr '[a-z]' '[A-Z]'`${ServerPrefix:1}

	# 建立相应目录
	if [ ! -d src/$LowerServer ]
	then
		echo "[mkdir: src/$LowerServer]"
		mkdir -p src/$LowerServer
	fi

	if [ ! -d build/$LowerServer ]
	then
		echo "[mkdir: build/$LowerServer]"
		mkdir -p build/$LowerServer
	fi

	if [ ! -d run/$LowerServer ]
	then
		echo "[mkdir: run/$LowerServer]"
		mkdir -p run/$LowerServer/bin run/$LowerServer/log run/$LowerServer/conf
	fi

	#建立服务框架
	echo "[create server: src/$LowerServer ...]"
	cp -r src/demosvr/* src/$LowerServer/
	cd src/$LowerServer/
    find . -regex ".*svn.*" -exec rm -rf {} \;

	SRC_FILE=`find  ! -type d`
	for FILE in $SRC_FILE
	do
		cat $FILE | sed "s/Demo/$MyPrefix/g" > $FILE.tmp
		cat $FILE.tmp | sed "s/DEMO/$UpperPrefix/g" > $FILE
        rm ${FILE}.tmp
# mv $FILE.tmp $FILE
	done

	cat CMakeLists.txt | sed "s/demo/$LowerPrefix/g" > CMakeLists.txt.tmp
	mv CMakeLists.txt.tmp CMakeLists.txt

    echo "MyPrefix: " $MyPrefix;
	rename "Demo" "$MyPrefix" $SRC_FILE
	echo "[done.]"
	
	cd ../../
}

if [[ 0 ]];
then
function CheckOss()
{
    struct_num=`grep struct protocol/osslog/wl_oss_log.xml | wc -l`
    struct_num=`echo "$struct_num/2"|bc`
    key1_num=`grep dtEventTime protocol/osslog/wl_oss_log.xml | wc -l`
    key2_num=`grep vGameSvrId protocol/osslog/wl_oss_log.xml | wc -l`
    key3_num=`grep vGameAppId protocol/osslog/wl_oss_log.xml | wc -l`   #SnsFlow,ItemFlow
    key3_num=`echo "$key3_num+2"|bc`
    key4_num=`grep vOpenID protocol/osslog/wl_oss_log.xml | wc -l`   #ItemFlow,SnsFlow,MoneyFlow
    key4_num=`echo "$key4_num+3"|bc`
    key5_num=`grep iPlatID protocol/osslog/wl_oss_log.xml | wc -l`   #MoneyFlow,SnsFlow,ItemFlow
    key5_num=`echo "$key5_num+3"|bc`

    if [ $struct_num -ne $key1_num -o $struct_num -ne $key2_num -o $struct_num -ne $key3_num -o $struct_num -ne $key4_num -o $struct_num -ne $key5_num ];then
        echo "Check oss failed!"
    else
        echo "Check oss succ!"
    fi
    echo "StuctNum:$struct_num"
    echo "dtEventTime:$key1_num"
    echo "vGameSvrId:$key2_num"
    echo "vGameAppId:$key3_num"
    echo "vOpenID:$key4_num"
    echo "iPlatID:$key5_num"
}
fi

usage(){
    echo
    echo "Usage:"
    echo "  AllMake.sh [command],commands are:"
    echo "  proto                  proto    [check]   "
    echo "  pkg                    pkg" 
    echo "  debug                  debug    SVRNAME"
    echo "  clean                  clean    SVRNAME"
    echo "  release                release  SVRNAME"
    echo "  verbose                verbose  SVRNAME [note : mode[debug]]"
    echo "  conf"
    echo "  create                 server_prefix"
    echo
}

case $1 in
    proto)
       MakeProto $@
    ;;
    pkg)
        MakeSrcPkg
    ;;
    clean)
        if [ $# == 1 ];then
            MakeAll $1
        else
            MakeServer $@
        fi
    ;;
    debug)
        if [ $# == 1 ];then
            MakeAll $1
        elif [ "x$2" == "xprotocol" ];
        then
            MakeProtoLib $@
        elif [ "x$2" == "xbase" ];
        then
            MakeBaseLib $@
        else
            MakeServer $@
        fi
        ;;
    release)
        if [ $# == 1 ];then
            MakeAll $1
        elif [ "x$2" == "xprotocol" ];
        then
            MakeProtoLib $@
        elif [ "x$2" == "xbase" ];
        then
            MakeBaseLib $@
        else
            MakeServer $@
        fi
        ;;
    verbose)
        if [ $# == 1 ];then
            MakeAll $1
        else
            MakeServer $@
        fi
    ;;
    conf)
        UpConf $@
    ;;
    create)
        CreateNewSvr $@
    ;;
    *)
        usage
#    return $?
esac

