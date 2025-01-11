from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

        Node(
            package='lab1_pkg',
            executable='talker',
            name='talker_node',
            output='screen',
            parameters=[
                {'v': 1.5},
                {'d': 0.3},
            ]
        ),

        Node(
            package='lab1_pkg',
            executable='relay',
            name='relay_node',
            output='screen'
        ),
    ])
