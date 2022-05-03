# Floribot_Simulation

In diesem Git liegen die Dateien für die Floribot Simulation ab.
Um das Repository zu klonen folgenden Befehl benutzen:

    git clone https://github.com/Euleeee/Floribot_Simulation catkin_ws

Existiert der Ordner bereits, muss er zuerst gelöscht werden. Optional könnte man auch das <catkin_ws> durch einen anderen Zielordnernamen ersetzen.

# Benötigte Software
ROS Noetic: http://wiki.ros.org/noetic/Installation/Ubuntu <br>
Gazebo 11: 

    curl -sSL http://get.gazebosim.org | sh
    
Python: 

    sudo apt-get install python3 
    
XACRO:

    sudo apt install ros-neotic-xacro
    
Anmerkung XACRO: Nach dem sudo apt install Befehl die xacro.py aus dem Git herunterladen und per folgenden Befehl in den Zielordner kopieren.

    sudo cp <Downloadort> /opt/ros/noetic/share/xacro 

# Installation Realsense Dependencies

-	Zunächst sudo apt-get install ros-noetic-ddynamic-reconfigure ausführen
-	Danach die Installationsanleitung unter https://github.com/IntelRealSense/librealsense/blob/master/doc/distribution_linux.md befolgen, wichtig auch librealsense2-dev Paket installieren

# Starten der Simulation
In dieser Anleitung wird davon ausgegangen, dass der Catkin Workspace im Ordner catkin_ws abliegt. <br>
Ein neues Terminal öffnen und folgenden Befehl eingeben:

    cd ~/catkin_ws && catkin_make && source ~/.bashrc 

Nachdem der Befehl eingegeben wurde, wirde der Catkin Workspace über catkin_make erstellt und es erscheinen im Ordner catkin_ws zwei neue Unterordner: "build" und "devel". <br>
Anschließend kann die Simulation mit dem folgendem Befehel gestartet werdeb:

    roslaunch floribot_simulation FloriBot.launch 

Sollte eine Fehlermeldung kommen, folgenden Befehl eingeben und anschließend erneut den roslaunch.. Befehl ausführen. (Zu Beachten: Euren Nutzernamen ohne die eckigen Klammern einsetzen)

    source  /home/<nutzername>/catkin_ws/devel/setup.bash 
    
Sobald die Simulation läuft, kann mit dem Roboter mit folgendem Befehl eine Geschwindigkeit vorgegeben werden, dazu muss jedoch ein neues Terminal geöffnet werden: 

    rostopic pub /cmd_vel geometry_msgs/Twist -r 10 -- '[0.2, 0.0, 0.0]' '[0.0, 0.0, 0.0]' 
    
Die Simulation kann mit der Tastenkombination Strg+C beendet werden. 
