#include <gazebo_plugins/gazebo_ros_template.h>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>
#include <thread>
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "Wheels.h"


namespace gazebo
{
  class ModelPush : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
    {
      // Store the pointer to the model
      this->model = _parent;

      // Listen to the update event. This event is broadcast every
      // simulation iteration.
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          std::bind(&ModelPush::OnUpdate, this));

      // Initialize ros, if it has not already bee initialized.
      if (!ros::isInitialized())
      {
        int argc = 0;
        char **argv = NULL;
        ros::init(argc, argv, "gazebo_client",
            ros::init_options::NoSigintHandler);
      }

      // Create our ROS node. This acts in a similar manner to
      // the Gazebo node
      this->rosNode.reset(new ros::NodeHandle("gazebo_client"));

      // Create a named topic, and subscribe to it.
      ros::SubscribeOptions so =
        ros::SubscribeOptions::create<publish_data::Wheels>(
            "/engine/targetSpeed",
            1,
            boost::bind(&ModelPush::OnRosMsg, this, _1),
            ros::VoidPtr(), &this->rosQueue);
      this->rosSub = this->rosNode->subscribe(so);

      // Spin up the queue helper thread.
      this->rosQueueThread =
        std::thread(std::bind(&ModelPush::QueueThread, this));
    }

    // Called by the world update start event
    public: void OnUpdate()
    {
      // Apply a small linear velocity to the model.
      // ROS_INFO("FL >> %f", this->velFL);
      this->model->GetJoint("joint_frontLeft")->SetParam("fmax", 0, 100.0);
      this->model->GetJoint("joint_frontLeft")->SetParam("vel", 0, this->velFL);
      
      // ROS_INFO("FR >> %f", this->velFR);
      this->model->GetJoint("joint_frontRight")->SetParam("fmax", 0, 100.0);
      this->model->GetJoint("joint_frontRight")->SetParam("vel", 0, this->velFR);
      
      // ROS_INFO("RL >> %f", this->velRL);
      this->model->GetJoint("joint_rearLeft")->SetParam("fmax", 0, 100.0);
      this->model->GetJoint("joint_rearLeft")->SetParam("vel", 0, this->velRL);
      // ROS_INFO("RR >> %f", this->velRR);
      this->model->GetJoint("joint_rearRight")->SetParam("fmax", 0, 100.0);
      this->model->GetJoint("joint_rearRight")->SetParam("vel", 0, this->velRR);

     /* // ROS_INFO("FL >> %f", this->velFL);
      this->model->GetJoint("joint_frontLeft")->SetVelocity(0, 0.5);
      
      // ROS_INFO("FR >> %f", this->velFR);
      this->model->GetJoint("joint_frontRight")->SetVelocity(0, 0.5);

      // ROS_INFO("RL >> %f", this->velRL);
      this->model->GetJoint("joint_rearLeft")->SetVelocity(0, 0.5);

      
      // ROS_INFO("RR >> %f", this->velRR);
      this->model->GetJoint("joint_rearRight")->SetVelocity(0, 0.5);*/
      }

    public: void OnRosMsg(const publish_data::WheelsConstPtr &_msg)
    {
      //this->setVel(_msg->rearLeft);
      this->velFL = _msg->frontLeft;
      this->velFR = _msg->frontRight;
      this->velRL = _msg->rearLeft;
      this->velRR = _msg->rearRight;

    } 

    /*public: void setVel(const double &_vel)
    {
      this->velRL = _vel;
      ROS_WARN("velRL >> %f", this->velRL);
    }*/

    // \brief ROS helper function that processes messages
    private: void QueueThread()
    {
      static const double timeout = 0.01;
      while (this->rosNode->ok())
      {
        this->rosQueue.callAvailable(ros::WallDuration(timeout));
      }
    }


    // Pointer to the model
    private: physics::ModelPtr model;

    // \brief Pointer to the joint.
    private: physics::JointPtr joint;

    // \brief A PID controller for the joint.
    private: common::PID pid;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;

    // \brief A node use for ROS transport
    private: std::unique_ptr<ros::NodeHandle> rosNode;

    // \brief A ROS subscriber
    private: ros::Subscriber rosSub;

    // \brief A ROS callbackqueue that helps process messages
    private: ros::CallbackQueue rosQueue;

    // \brief A thread the keeps running the rosQueue
    private: std::thread rosQueueThread;

    double velFL = 0.0;
    double velFR = 0.0;
    double velRL = 0.0;
    double velRR = 0.0;

    };

    

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}
