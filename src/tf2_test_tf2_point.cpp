#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
	
#include <tf2_ros/transform_listener.h>	

tf2_ros::Buffer tfBuffer;

void ellipsevsCallback(const geometry_msgs::PointStamped::ConstPtr& point_raw){
	geometry_msgs::TransformStamped transformStamped;
	transformStamped = tfBuffer.lookupTransform("global", "local", ros::Time(0));
	
	geometry_msgs::PointStamped point_tf;
	/* This is the line which fails to compile. */
	tfBuffer.transform(*point_raw, point_tf, "local");
}

int main(int argc, char** argv){
	ros::init(argc, argv, "tf2_test_tf2_point");
	tf2_ros::TransformListener tfListener(tfBuffer);
	
	ros::NodeHandle node;
	ros::Subscriber topic_sub = node.subscribe("test/point", 1, &ellipsevsCallback);
	
	ros::spin();
	return 0;
};