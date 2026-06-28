*This project has been created as part of the 42 corriculum by cybourge and jdelattr*

**Description**
This project consists in making a simple ray tracer in C according to the 42 C Norm.
It uses the mlx : https://github.com/42paris/minilibx-linux.git for its graphic library.

The ray tracer implements a simple Phong reflection model, unto which was added the capacity for
reflections and transparency.
It also implements the ability to add textures and height-maps either from a .xpm file of from source code,
and allows the user to specify how those should map to the geometric objects.
The ray tracer can draw :
 - Spheres, Cones, Cylinders and Planes.
It can also perform linear transformations on them :
 - Translation, Rotation, Scaling and Shearing.
The ray tracer supports multiple colored point lights.
The ray tracer can take a .rt file as an input for a scene description.

**Instructions**
The project requires the mlx and its dependecies.
To run:
make
./miniRT {optional .rt file for scene description}

**Resources**
The external resources used for this ray tracer are :
The book "Ray Tracing in One Weekend" : https://raytracing.github.io/
The book "The Ray Tracer Challenge" : http://raytracerchallenge.com/

AI usage:
AI was used at the beginning of the project to implement vectors and matrices.
AI model was ChatGPT : Basic one.
A header file consisting of function headers and description comments was given to it to
generate source code. That code was then reviewed and normed accordingly.
AI was used further along the project to generate parts of the .rt files when implementing many transformations
became either tedius due to repetitiveness or hard to visualize.

**.rt file syntax**
Each element is defined on a single line.
'#' mark comment lines and are ignored.
Each element starts with an identifier and is then followed by space-seperated parameters.
Example:
 - Ambient Light : A 0.5 255,255,255
	Identifier 			: 'A'
	Intensity [0,1] 	: 0.5
	RGB Color [0,255]	: 255,255,255
	Only one per scene.
 - Camera : C 0,0,0 0,0,1 130
	Identifier				: 'C'
	Viewpoint Coordinates	: 0,0,0
	3D Orientation Vector	: 0,0,1
	Horizontal FOV	[0,180]	: 130
	Only one per scene.
 - Light : L 1,1,1 0.5 255,255,255
	Identifier				: 'L'
	Position				: 1,1,1
	Intensity [0.0, 1.0]	: 0.5
	RGB Color [0,255]		: 255,255,255
 - Sphere : sp 2,3,4 5 255,255,0
	Identifier				: 'sp'
	Center					: 2,3,4
	Diameter				: 5
	RGB Color [0,255]		: 255,255,0
 - Plane : pl 5,5,5 0,1,0 0,255,0
	Identifier				: 'pl'
	Point in the Plane		: 5,5,5
	Normal Vector			: 0,1,0
	RGB Color [0,255]		: 0,255,0
 - Cylinder : cy 0,2,0 1,1,0 5 10 0,0,255
	Identifier				: 'cy'
	Center of the cylinder	: 0,2,0
	Axis					: 1,1,0
	Diameter				: 5
	Height					: 10
	RGB Color [0,255]		: 0,0,255
 - Cone : co 0,2,0 1,1,0 5 10 0,0,255
	Identifier				: 'cy'
	Center of the cylinder	: 0,2,0
	Axis					: 1,1,0
	Diameter				: 5
	Height					: 10
	RGB Color [0,255]		: 0,0,255




