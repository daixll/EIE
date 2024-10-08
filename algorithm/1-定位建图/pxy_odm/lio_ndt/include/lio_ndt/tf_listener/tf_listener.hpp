#pragma once

#include <string>
#include <Eigen/Dense>
#include <ros/ros.h>
#include <tf/transform_listener.h>

namespace lio_ndt
{
    class TFListener
    {
    public:
        TFListener(ros::NodeHandle& nh, std::string base_frame_id, std::string child_frame_id);
        TFListener() = default;
        bool LookupData(Eigen::Matrix4f& transform_matrix);
    
    private:
        bool TransformToMatrix(const tf::StampedTransform& transform, Eigen::Matrix4f& transform_matrix);

    private:
        ros::NodeHandle nh_;
        tf::TransformListener listener_; // 定义tf监听器
        std::string base_frame_id_;
        std::string child_frame_id_;
    };
}