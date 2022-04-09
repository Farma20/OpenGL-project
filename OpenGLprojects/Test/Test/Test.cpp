#include <iostream>
#include "MyVector.h"

using namespace std;

int main() {

	Vector2 A (1, 5);
	Vector2 B(2, 3);
	Vector2 C;
	C.getVec();
	C += A+B;
	C.getVec();
	C = A + A;
	C.getVec();
	C -= A;
	C.getVec();
	C = C - B;
	C.getVec();
	C = C * 2;
	C.getVec();
	C *= 2;
	C.getVec();

	Vector2 D;
	D = C.reverse();
	D.getVec();

	double scalar = D.sclarMulti(C);
	std::cout << scalar << std::endl;

	Vector3 F(2, 6, 5), G(-4, -8, -2), Ortog;
	Ortog = F.vectorMulti(G);
	Ortog.getVec();

	Vector4 Am(1, 2, 3, 4), Dm(5, 6, 7, 8), Cm(9, 10, 11, 12), Em(13, 14, 15, 16);

	//--------------------------------------------------

	Matrix3 Mx;
	Mx.GetMatrix();

	Matrix3 Mx1(1, 2, 3, 1, 2, 3, 1, 2, 3);
	Mx1.GetMatrix();

	Matrix3 Mx2(F, G, Ortog);
	Mx2.GetMatrix();

	Matrix4 Md(1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4);
	Md.GetMatrix();

	Matrix4 Git(Am, Dm, Cm, Em);
	Git.GetMatrix();

	Mx2 = Mx2 + Mx1;
	Mx2.GetMatrix();

	Mx2 = Mx2 * 2;
	Mx2.GetMatrix();

	Mx2.GetMatrix();
	Mx1.GetMatrix();

	Matrix3 multip = Mx2 * Mx1;
	multip.GetMatrix();

	Matrix3 SVG = multip.Transposition();
	SVG.GetMatrix();

	Git = Md * Git;
	Git.GetMatrix();

	Matrix4 Translate(10, 0, 15, 'T');
	Translate.GetMatrix();

	Matrix4 Scale(12, 11, 7, 'S');
	Scale.GetMatrix();
}
























////glew
//#include <GL/glew.h>
//
////sfml
//#include <SFML/Window.hpp>
//
//using namespace std;
//
//int main() {
//	sf::ContextSettings settings;
//	settings.depthBits = 24; // количество битов буффера глубины
//	settings.stencilBits = 8; //количество битов буфера трафарета
//	settings.majorVersion = 4;
//	settings.minorVersion = 3;
//	settings.attributeFlags = sf::ContextSettings::Core;
//
//	sf::Window window(sf::VideoMode(800, 600, 32), "First Window",
//		sf::Style::Titlebar | sf::Style::Close);
//
//	glewExperimental = GL_TRUE; // включить все современные функции ogl
//
//	if (GLEW_OK != glewInit()) { // включить glew
//		cout << "Error:: glew not init =(" << endl;
//		return -1;
//	}
//
//	bool isGo = true;
//
//	while (isGo) {
//		sf::Event windowEvent;
//
//		while (window.pollEvent(windowEvent)) { // обработка ивентов
//			switch (windowEvent.type)
//			{
//			case sf::Event::Closed:
//				isGo = false;
//				break;
//			default:
//				break;
//			}
//		}
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //отчистка экрана
//		glClear(GL_COLOR_BUFFER_BIT); //отчистка экрана
//
//		//...
//
//		window.display();
//	}
//
//
//	window.close();
//	return 0;
//}