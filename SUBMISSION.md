# Lab 1: Intro to ROS 2

## Written Questions

### Q1: During this assignment, you've probably ran these two following commands at some point: ```source /opt/ros/foxy/setup.bash``` and ```source install/local_setup.bash```. Functionally what is the difference between the two?

Answer: The former command sets up the ROS 2 environment, while the latter sets up the workspace environment (the packages and nodes created by the user).

### Q2: What does the ```queue_size``` argument control when creating a subscriber or a publisher? How does different ```queue_size``` affect how messages are handled?

Answer: This argument sets the number of extra messages stored in the queue. Too small ```queue_size``` will result in messages being lost, while too large will result in excess memory usage or processing delays.

### Q3: Do you have to call ```colcon build``` again after you've changed a launch file in your package? (Hint: consider two cases: calling ```ros2 launch``` in the directory where the launch file is, and calling it when the launch file is installed with the package.)

Answer: If the launch file is not installed with the package, then re-calling ```colcon build ``` is not necessary. But if it is, then the package must be rebuilt.
