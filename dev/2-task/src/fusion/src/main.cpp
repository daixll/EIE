#include "fusion/my_lidar.hpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "fusion"); // 初始化 ROS 节点
    my_lidar lidar; // 创建 my_lidar 类对象

    // 创建 NodeHandle 对象
    ros::NodeHandle n;

    // 订阅点云数据
    ros::Subscriber lidar_sub = n.subscribe("/rslidar_points", 1, &my_lidar::point_cloud_callback, &lidar); 

    ros::spin(); // 进入 ROS 事件循环
    return 0; // 返回
}