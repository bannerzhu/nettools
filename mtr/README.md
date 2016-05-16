# mtr.py，使用mtr测试网络质量

一个Python程序，使用mtr来测试、记录网络丢包、延时，并且进行分析。

原理是，每隔60秒记录每个主机的mtr报告，也就是每个主机的丢包、延时以及途径的路由器的丢包和延时。

这个程序原来是自用的，用来测试江苏到各省的网络情况，现在公开出来。

## 安装说明

    git clone https://github.com/pubyun/mtr.git
    yum -y install mtr tmux
    setcap cap_net_raw+ep /usr/sbin/mtr
    getcap /usr/sbin/mtr

## 使用方法

### 设定被监测的主机

修改 hosts.txt 文件。注意IP地址和说明之间要用空格分开。

### 监测并且记录

    python mtr.py

文件将记录到 log 目录下

### 分析日志

#### 生成网络丢包的报告

    python mtr.py log > report.txt

这个报告，将所有主机的丢包记录帅选出来，形成报告。

#### 对检测主机的丢包情况排序

    grep 丢包 report.txt |sort -n -k 5

将主机按照丢包情况，进行排序。

## 一些记录

### 2016.5.16 江苏到各省的情况(12小时的数据)

丢包严重的省份：
广州、江西、云南、上海、河北、山东、湖南

人口少的省份:
海口、兰州、贵州、西宁、太原

    112.67.252.202 - 海口电信: 丢包次数 0 丢包数 0
    115.236.73.179 - 杭州电信: 丢包次数 0 丢包数 0
    123.58.191.105 - 杭州网易: 丢包次数 0 丢包数 0
    125.64.34.155 - 四川成都电信: 丢包次数 0 丢包数 0
    219.153.15.15 - 重庆电信: 丢包次数 0 丢包数 0
    60.190.249.9 - 杭州电信: 丢包次数 0 丢包数 0
    125.77.22.251 - 福州电信: 丢包次数 1 丢包数 1
    202.100.85.45 - 兰州电信: 丢包次数 1 丢包数 1
    220.162.247.170 - 福州电信: 丢包次数 1 丢包数 1
    36.49.31.162 - 长春电信: 丢包次数 1 丢包数 1
    59.49.46.141 - 太原电信: 丢包次数 1 丢包数 1
    119.97.137.62 - 湖北武汉电信: 丢包次数 2 丢包数 2
    219.148.38.26 - 石家庄电信: 丢包次数 2 丢包数 12
    60.191.221.23 - 温州电信: 丢包次数 2 丢包数 3
    61.155.6.21 - 南京电信: 丢包次数 2 丢包数 4
    115.182.105.140 - 北京电信通: 丢包次数 3 丢包数 3
    59.46.13.57 - 沈阳电信: 丢包次数 3 丢包数 9
    117.34.17.60 - 西安电信: 丢包次数 4 丢包数 19
    219.142.106.139 - 北京电信: 丢包次数 4 丢包数 10
    223.220.250.110 - 西宁电信: 丢包次数 4 丢包数 37
    1.192.125.180 - 郑州电信: 丢包次数 5 丢包数 61
    59.63.158.181 - 江西电信: 丢包次数 6 丢包数 7
    222.87.128.4 - 贵州电信: 丢包次数 7 丢包数 41
    222.85.126.17 - 河南郑州电信: 丢包次数 8 丢包数 41
    61.147.75.88 - 扬州电信: 丢包次数 8 丢包数 220
    222.216.28.58 - 广西电信: 丢包次数 10 丢包数 90
    219.153.49.183 - 重庆电信: 丢包次数 12 丢包数 41
    175.6.7.12 - 湖南长沙电信: 丢包次数 17 丢包数 22
    183.57.73.118 - 广州电信: 丢包次数 20 丢包数 113
    220.165.13.182 - 昆明电信: 丢包次数 30 丢包数 128
    113.12.80.114 - 南宁电信: 丢包次数 31 丢包数 54
    124.232.137.185 - 长沙电信: 丢包次数 49 丢包数 51
    58.56.66.58 - 济南电信: 丢包次数 64 丢包数 444
    219.148.7.17 - 河北石家庄电信: 丢包次数 100 丢包数 151
    222.68.185.189 - 上海电信: 丢包次数 114 丢包数 202
    220.165.8.156 - 云南昆明电信: 丢包次数 119 丢包数 1206
    117.41.229.242 - 南昌电信: 丢包次数 352 丢包数 2096
    14.29.84.52 - 广州电信: 丢包次数 383 丢包数 825