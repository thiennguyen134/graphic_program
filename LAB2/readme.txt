Name: Thien Nguyen
Student id: AA7772
About project
The project is to build a tank using three boxes and place them into the scenegraph so that the turret follows the base and the pipe follows the turret. The tank will have simple controls where the arrow keys left and right turn the tank base and the arrow keys up and down move the tank base forward and backward. Also, 'A' and 'D' rotate the turret to the left and right, and 'W' and 'S' rotate the pipe up and down.

To complete the project, the following tools and technologies are needed:

Microsoft Visual Studio (Community edition)
OpenGL / OpenGL ES
glm (open source library)
stb (open source library)
Git Bash
The project can be developed on desktop PCs (Windows/Linux) and mobile devices (Android, iOS).

In addition, the project requires declaring three Geometry objects, one for each piece of the tank. A material can be used for all tank pieces. The IApplication::IsKeyDown function can be used to check if a certain key is pressed down. For example, if (IsKeyDown(KEY_LEFT)) { // arrow key left is down } and if (IsKeyDown('A')) { // 'A' is down }.