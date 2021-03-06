Judge Server
=============

depndes on
----------

    1. zmq-3.2
    2. jsoncpp
    3. boost


tools
----------

    1. cmake
    2. g++


installation steps
------------------

    // code clone
    git clone git@acm.swust.edu.cn:wyang/newjudge.git

    // install zmq
    wget http://download.zeromq.org/zeromq-3.2.3.tar.gz

    tar -zxf zeromq-3.2.3.tar.gz

    apt-get install g++ make cmake

    cd zeromq-3.2.3 && ./configure

    make && make install

    // install jsoncpp
    wget http://softlayer-dal.dl.sourceforge.net/project/jsoncpp/jsoncpp/0.5.0/jsoncpp-src-0.5.0.tar.gz

    wget http://sourceforge.net/projects/scons/files/scons/2.1.0/scons-2.1.0.tar.gz

    tar -zxf jsoncpp-src-0.5.0.tar.gz
    tar -zxf scons-2.1.0.tar.gz

    export MYSCONS=`pwd`/scons-2.1.0
    export SCONS_LIB_DIR=$MYSCONS/engine

    cd jsoncpp-src-0.5.0 && python $MYSCONS/script/scons platform=linux-gcc

    mkdir /usr/include/jsoncpp
    cp -r include/json/* /usr/include/jsoncpp/
    cp libs/linux-gcc-4.6/libjson_linux-gcc-4.6_libmt.a /usr/lib/libjsoncpp.a
    cp libs/linux-gcc-4.6/libjson_linux-gcc-4.6_libmt.so /usr/lib/libjsoncpp.so

    // install boost
    wget http://hivelocity.dl.sourceforge.net/project/boost/boost/1.54.0/boost_1_54_0.tar.gz
    tar -zxf boost_1_54_0.tar.gz
    cp -r boost_1_54_0/boost /usr/include/


    // install judgeServer
    cd newjudge
    mkdir build && cd build
    cmake ../judge-server
    make


instruction
------------

    ./judgeServer ../judge-server/judge.conf


default configure
--------------

    {
      "iothreads": 4,
      "worker_nums": 8,
      "daemon": true,

      "sock_front_addr": "tcp://0.0.0.0:7878",
      // "sock_back_addr": "ipc://dealer.ipc",
      "sock_back_addr": "inproc://dealer",

      "tmp_dir": "/tmp/oj",
      "program_dir": "/oj/program",
      "log_path": "/var/log/oj/judge.log",

      "judge_server_prefix": "JudgeServer",
      "judge_worker_prefix": "JudgeWorker",
    }





