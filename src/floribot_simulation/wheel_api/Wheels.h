// Generated by gencpp from file publish_data/Wheels.msg
// DO NOT EDIT!


#ifndef PUBLISH_DATA_MESSAGE_WHEELS_H
#define PUBLISH_DATA_MESSAGE_WHEELS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace publish_data
{
template <class ContainerAllocator>
struct Wheels_
{
  typedef Wheels_<ContainerAllocator> Type;

  Wheels_()
    : header()
    , frontLeft(0.0)
    , frontRight(0.0)
    , rearLeft(0.0)
    , rearRight(0.0)  {
    }
  Wheels_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , frontLeft(0.0)
    , frontRight(0.0)
    , rearLeft(0.0)
    , rearRight(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _frontLeft_type;
  _frontLeft_type frontLeft;

   typedef double _frontRight_type;
  _frontRight_type frontRight;

   typedef double _rearLeft_type;
  _rearLeft_type rearLeft;

   typedef double _rearRight_type;
  _rearRight_type rearRight;





  typedef boost::shared_ptr< ::publish_data::Wheels_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::publish_data::Wheels_<ContainerAllocator> const> ConstPtr;

}; // struct Wheels_

typedef ::publish_data::Wheels_<std::allocator<void> > Wheels;

typedef boost::shared_ptr< ::publish_data::Wheels > WheelsPtr;
typedef boost::shared_ptr< ::publish_data::Wheels const> WheelsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::publish_data::Wheels_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::publish_data::Wheels_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::publish_data::Wheels_<ContainerAllocator1> & lhs, const ::publish_data::Wheels_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.frontLeft == rhs.frontLeft &&
    lhs.frontRight == rhs.frontRight &&
    lhs.rearLeft == rhs.rearLeft &&
    lhs.rearRight == rhs.rearRight;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::publish_data::Wheels_<ContainerAllocator1> & lhs, const ::publish_data::Wheels_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace publish_data

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::publish_data::Wheels_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::publish_data::Wheels_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::publish_data::Wheels_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::publish_data::Wheels_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::publish_data::Wheels_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::publish_data::Wheels_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::publish_data::Wheels_<ContainerAllocator> >
{
  static const char* value()
  {
    return "88a446f832904937708e487c974640d3";
  }

  static const char* value(const ::publish_data::Wheels_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x88a446f832904937ULL;
  static const uint64_t static_value2 = 0x708e487c974640d3ULL;
};

template<class ContainerAllocator>
struct DataType< ::publish_data::Wheels_<ContainerAllocator> >
{
  static const char* value()
  {
    return "publish_data/Wheels";
  }

  static const char* value(const ::publish_data::Wheels_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::publish_data::Wheels_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"float64 frontLeft\n"
"float64 frontRight\n"
"float64 rearLeft\n"
"float64 rearRight\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::publish_data::Wheels_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::publish_data::Wheels_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.frontLeft);
      stream.next(m.frontRight);
      stream.next(m.rearLeft);
      stream.next(m.rearRight);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Wheels_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::publish_data::Wheels_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::publish_data::Wheels_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "frontLeft: ";
    Printer<double>::stream(s, indent + "  ", v.frontLeft);
    s << indent << "frontRight: ";
    Printer<double>::stream(s, indent + "  ", v.frontRight);
    s << indent << "rearLeft: ";
    Printer<double>::stream(s, indent + "  ", v.rearLeft);
    s << indent << "rearRight: ";
    Printer<double>::stream(s, indent + "  ", v.rearRight);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PUBLISH_DATA_MESSAGE_WHEELS_H