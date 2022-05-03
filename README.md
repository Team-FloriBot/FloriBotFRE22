# Floribot_Simulation

In diesem Git liegen die Dateien für die Floribot Simulation ab.
Um das Repository zu klonen folgenden Befehl benutzen:

    git clone https://github.com/Euleeee/Floribot_Simulation catkin_ws

Existiert der Ordner bereits, muss er zuerst gelöscht werden. Optional könnte man auch das <catkin_ws> durch einen anderen Zielordnernamen ersetzen.

# Benötigte Software
-   ROS Noetic: http://wiki.ros.org/noetic/Installation/Ubuntu 
-   Gazebo 11:
    curl -sSL http://get.gazebosim.org | sh
-   Python: 
    sudo apt-get install python3 
-   XACRO: -> Besonderheit beachten
    sudo apt install ros-neotic-xacro 
    
# Installation Realsense Dependencies

-	Zunächst sudo apt-get install ros-noetic-ddynamic-reconfigure ausführen
-	Danach die Installationsanleitung unter https://github.com/IntelRealSense/librealsense/blob/master/doc/distribution_linux.md befolgen, wichtig auch librealsense2-dev Paket installieren
