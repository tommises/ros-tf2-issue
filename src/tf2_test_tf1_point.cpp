#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
	
#include <tf/transform_listener.h>	

tf::TransformListener tfListener;

void ellipsevsCallback(const geometry_msgs::PointStamped::ConstPtr& point_raw){
	geometry_msgs::PointStamped point_tf;
	/* This works. */
	tfListener.transformPoint("local", *point_raw, point_tf);
}

int main(int argc, char** argv){
	ros::init(argc, argv, "tf2_test_tf1_point");
	
	ros::NodeHandle node;
	ros::Subscriber topic_sub = node.subscribe("test/point", 1, &ellipsevsCallback);
	
	ros::spin();
	return 0;
};