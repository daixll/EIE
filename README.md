<h1 align="center">

[![](https://english.cqu.edu.cn/img/logo.png)](https://eie.cqu.edu.cn/)

</h1>

<h3 align="center">

国家（重庆）卓越工程师学院 2021级 智能网联汽车方向课程

</h3>

* 必修 1：[车载软件开发基础](./algorithm/)

* 必修 2：[智能驾驶算法基础](./dev/)

* 选修 1：[智能网联汽车数据工程](./data/)

* 选修 2：车联网系统与应用

* 选修 3：[智能座舱与人机交互](./android/)

* 选修 4：

* 毕业论文：智能网联汽车相关课题

<br>

---

# 一、搭建环境

## 安装Jetson Xavier镜像

松灵小车重庆大学卓工镜像：https://eie.cqu.edu.cn/Research/clwsys/sysb.htm

## 搭建OpenCV、Numpy等常见库

在Jetson Xavier中自带了适配Jetson的OpenCV、Numpy等常用库，可以利用GPU进行加速，可以通过python3激活环境，无需手动安装。

如果手动安装的OpenCV、Numpy等库，则无法使用Jetson的加速功能。

## 搭建Pytorch环境

Jetson所使用的Pytorch版本是**特殊的**，直接在Pytorch官网拉取安装**会报错**，应该使用Nvidia官方的**JetPack**所提供的Pytorch版本，`jtop`可以查看JetPack的版本

- **查看Nvidia版本**

```shell
nvcc -V
```

**注意：**`nvidia-smi`指令是无法在Jetson上查看cuda版本的，因为Jetson使用的驱动并非是Nvidia，而是L4T(Linux for Tegra)驱动。

- **安装步骤**

Jetson的操作系统是定制的，安装Pytorch跟一般的Ubuntu系统有很大的区别。

参考[安装Pytorch Nvidia官方指导](https://forums.developer.nvidia.com/t/pytorch-for-jetson/72048)

大致步骤如下：

1. `wget`下载上面链接中的本地包
2. `pip`本地安装`torch`
3. 安装`torch`对应版本的`torchvision`
4. 检查是否能够使用cuda

# 二、运行前的准备

## 启动ROS

```shell
roscore
```

## 查看所有的 topic

```shell
rostopic list
```

# 三、激光雷达

## 启动激光雷达

```shell
roslaunch scout_bringup open_rslidar.launch
```

**雷达打不开的情况：**

- 如果报错`ERRO：“base_link[某个映射]” passed to lookupTransform argument source_frame does not exist.`等映射的变换错误，是因为TF没有完全启动，完全启动之后会自动修正。
- 如果报错`Waiting for laser_scans...`，是因为和激光雷达的链接有问题。
  - 物理连接：检查线路是否稳定。如果稳定，就是网络配置有问题。
  - 检查主机ip地址是不是`192.168.1.102`

## 启动建图

```shell
roslaunch scout_bringup gmapping.launch
```

## 打开Rviz

```shell
rosrun rviz rviz
```

# 三、深度相机

## 启动深度相机

```shell
roslaunch realsense2_camera rs_camera.launch
```

## UI 界面

```shell
realsense-viewer
```

# 四、定位

## 启动定位

```shell
roslaunch scout_bringup open_rslidar.launch
```

# 五、Docker连接

## 1. 下载安装Docker

```shell
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
```

为了不用每次都用`sudo`管理员权限，可以把用户添加到docker组：

```shell
sudo usermod -aG docker $USER
```

## 2. 下载镜像

```shell
docker pull liujiboy/ros:3.0
```

PS: 下载需要科技上网

## 3. 进入镜像

```shell
docker run -p 5900:5900 -p 6080:80 --rm -e RESOLUTION=1920x1080 liujiboy/ros:3.0
```

进行了一个端口映射

**注意：**在VScode进行远程连接的时候需要手快一点，启动上述命令之后迅速用VSCode进行连接，不然登不上去

## 4. 进入网址

````
127.0.0.1:6080
````

即可进入图形化界面

# 开发、任务 1

（1）显示激光雷达、相机、定位

1. 启动 ros 内核 `roscore`
2. 发布激光雷达 `roslaunch scout_bringup open_rslidar.launch`
3. 发布相机 `roslaunch realsense2_camera rs_camera.launch`
4. 发布定位 `roslaunch scout_bringup open_rslidar.launch`
5. 订阅激光雷达 `rosrun show_ss point_cloud_by_pcl`
6. 订阅相机 `rosrun show_ss rgb_and_depth_by_opencv`
7. 订阅定位 `rosrun show_ss speed_by_ter`

（2）里程计计算距离

1. 启动 ros 内核 `roscore`
2. 发布激光雷达 `roslaunch scout_bringup open_rslidar.launch`
3. 订阅激光雷达 `rosrun calc_distance calc_distance`

# 开发、任务 2

1. 启动 ros 内核 `roscore`
2. 发布激光雷达 `roslaunch scout_bringup open_rslidar.launch`
3. 发布相机 `roslaunch realsense2_camera rs_camera.launch`
4. 订阅融合数据 `rosrun fusion_of_camera_and_lidar fusion_of_camera_and_lidar_node`

> 有 bug，有时候需要多订阅几次（失败的时候 kill 相机，再启动）

# 开发、任务 3