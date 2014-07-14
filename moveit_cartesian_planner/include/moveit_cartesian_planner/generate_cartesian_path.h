// MoveIt!
#include <moveit/move_group_interface/move_group.h>
#include <moveit/robot_trajectory/robot_trajectory.h>
#include <moveit/robot_model_loader/robot_model_loader.h>


#include <pluginlib/class_loader.h>

#include <QObject>


#ifndef GENERATE_CARTESIAN_PATH_H_
#define GENERATE_CARTESIAN_PATH_H_

class GenerateCartesianPath: public QObject
{
Q_OBJECT

public:

public:
	GenerateCartesianPath(QObject* parent = 0);
	virtual ~GenerateCartesianPath();
	void init();
public Q_SLOTS:
	void move_to_pose(std::vector<geometry_msgs::Pose> waypoints);
	void checkWayPointValidity(const geometry_msgs::Pose& waypoints,const int marker_name);
	void initRviz_done();
Q_SIGNALS:
	void wayPointOutOfIK(int point_number, int out_of_range); 
	void getRobotModelFrame_signal(const std::string robot_model_frame);
protected:
	robot_model_loader::RobotModelLoader robot_model_loader;
	moveit::core::RobotModelPtr kinematic_model;
	moveit::core::RobotStatePtr kinematic_state;
	const moveit::core::JointModelGroup* joint_model_group;

public:
	//std::string getRobotModelFrame();

};

#endif // GENERATE_CARTESIAN_PATH_H_
